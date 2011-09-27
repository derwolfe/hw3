#include <stdlib.h>
#include <cassert>
#include <iostream>
#include <fstream>

using namespace std;

#include "linkedlist.h"

typedef int list_item_type;
/* 
 * default constructor that creates a list of no length
 * pointing the head, initializing the head and null pointers
 */
Double_list::Double_list ( ) 
{
  size = 0;
  head = NULL;
  tail = NULL;
}

//void Double_list::Double_list ( const Double_list& a_list )
//{
//  size = a_list.size;
//  if ( a_list.head == NULL ) {
//    head = NULL;
//    tail = NULL;
//  
//  /* 
//   * checks to see if list is empty, if so, set the head to null
//   * and you're finished, otherwise go through the deep copy set
//   */
//  } else {
//    /* 
//     * this copies the head item and only the head item, so it 
//     * needs to set the head to itself, tail to itself, prev to null
//     * and next to null
//     */
//    head = new Double_node;
//    assert ( head != NULL );
//    head->item = a_list.head->item;
//    head->prev = NULL;
//    head->next = NULL;
//    tail = head;
//    /*
//     * Now that the first item of the list has been set, we can
//     * go about copying the rest. new_ptr points to the current
//     * head in the list.
//     */
//    Double_node *new_ptr  = head; 
//    Double_node *orig_ptr = a_list.head->next;
//    Double_node *tmp_ptr;
//
//    for ( ; orig_ptr != NULL; orig_ptr = orig_ptr->next ) {
//      new_ptr->next = new Double_node;
//      assert ( new_ptr->next != NULL );
//      tmp_ptr       = new_ptr;
//      new_ptr       = new_ptr->next;
//      new_ptr->prev = tmp_ptr;
//      new_ptr->item = orig_ptr->item;
//    }
//    /* 
//     * now that the loop has finished, the last element's 
//     * next pointer needs to point to null
//     * the tail pointer should point to the last element on the 
//     * list.
//     */
//    new_ptr->next = NULL;
//    tmp_ptr       = NULL;
//    tail          = new_ptr;
//  }
//}
//
///* 
// * this will remove the first element of the loop on EACH 
// * iteration of the loop. Once, the list is empty it will 
// * stop. How to implement without index???
// */
//void Double_list::~Double_list () 
//{
//  while ( !is_empty ()) {
//    pop ();     
//  }
//}
//
///* 
// * Checks if the list's size = 0 and makes sure that head 
// * and tail are pointing to null. An assert statement
// * may not be the best way to check that head & tail are set to NULL
// */
bool Double_list::is_empty () const 
{
  if ( size == 0 ) {
    //assert ( head == NULL );
    return true;
  } else {
    return false;
  }
}

/* Accesses the private size variable */ 
int Double_list::get_length () const
{
  return size;
}


/* 
 * item_add - this should be used for UNORDERED lists, such as queues,
 * where adding to the tail, without indexing won't cause problems. 
 * The convention will be tail addition.
 */
void Double_list::item_add ( list_item_type new_item )
{
  /* Two cases (1) the list is empty, and (2) the list isn't empty
   * CASE 1 - add initial node to the list, populate the item
   */
  Double_node *new_ptr  = new Double_node; 
  new_ptr->item         = new_item;
  if ( size == 0 ) {
    head          = new_ptr;
    tail          = new_ptr;
    new_ptr->prev = NULL;
    new_ptr->next = NULL;
  /* 
   * CASE 2 - add on to the end. The head pointer doesn't
   * change because of the tail-addition.
   */
  } else if ( size > 0 ) {
    new_ptr->prev       = tail;
    new_ptr->prev->next = new_ptr;
    tail                = new_ptr;
  }
  size++;
}

void Double_list::remove ( list_item_type data_item )
{
  /* you should throw an exception */
  Double_node *target = find ( data_item );
  if ( target == NULL ) {
    return;
  
  /* CASE 1 - this is the first node, pointed at by head
   */
  } else if ( size == 1 ) {
    target->prev = NULL;
    target->next = NULL;
    head = NULL;
    tail = NULL;
    delete target;
    size = 0;
   /* CASE 2 - item is located at the tail, the edge case
   * of the size = 1, where head = node = tail, is 
   * already handled.
   */
  } else if ( tail == target ) {
    tail = target->prev;
    target-prev->next = NULL;
    delete target;
    target = NULL;
    size--;
  /* CASE 3 - if target is first item in list with more than
   * one item.
   */
  } else if (( size > 1 ) && ( head == target )) {
    head = target->next;
    target->next->prev = NULL;
    delete target;
    target = NULL;
    size--;
  /* CASE 4 - the item is somewhere in the middle of the list
   * this only requires, finding it, moving several
   * pointers, deleting, decrementing size.
   */
  } else if (( size > 1 ) && 
      ( head != target ) && 
      ( tail != target )) {
    target->prev->next = target->next;
    target->next->prev = target->prev;
    target = NULL;
    delete target;
    size--;
  }
}

void Double_list::pop ()
{
  /* 3 cases - 
   * (1) empty list 
   * (2) one element in list
   * (3) more than one element in list
   */
  if ( is_empty ()) {
    size = 0;
  } else {
    Double_node *target = tail;
    if ( size > 1 ) {
      tail    = tail->prev;
      delete target;
      target  = NULL;
      size--;
    } else if ( size == 1 ) {
      delete target;
      tail    = NULL;
      head    = NULL;
      target  = NULL;
      size    = 0;
    }
  }
}
///* 
// * goal is to send contents of the node to the output stream
// */
//std::ostream& operator<<(std::ostream &os, Double_list::Double_node &in_node)
//{
//  os << in_node->item << endl;
//  os << endl;
//}
// TEST function using cout
void Double_list::print ( )
{
  Double_node *new_ptr = tail;
  cout << "Item:  " << new_ptr->item  << endl;
}
/* 
 * PRIVATE find method that should search the list for the data item
 * once found, it should return a pointer to the node. Now other functions
 * can use find,
 */
Double_node* Double_list::find ( list_item_type data_item ) const
{
//  if ( data_item == NULL ) {
//    return NULL;
  
//  } else {
  Double_node *target = head;
  int inc = 1;
  while ( inc <= size ) {
    if ( data_item == target->item ) {
      return target;
    } else {
      target = target->next;
      inc++;
    }
//    }
  }
}

Double_node* Double_list::retrieve ( list_item_type data_item ) const
{
  return ( find ( data_item ));
}

