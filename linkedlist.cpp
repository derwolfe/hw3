#include <stdlib.h>
#include <cassert>

using namespace std;

#include "linkedlist.h"
/* 
 * The indexing for this linkedlist implementation will start at ZERO!
 */
 
/* 
 * default constructor that creates a list of no length
 * pointing the head pointer to null
 * 1. Do you need to make the pointers point to a new instance of a list? Yes.
 */
Double_list::d_list (): 
{
  size = 0;
  head = NULL;
  tail = NULL;
}

void Double_list::d_list ( const d_list& a_list )
{
  size = a_list.size;
  if ( a_list.head == NULL ) {
    head = NULL;
    tail = NULL;
  }
  /* 
   * checks to see if list is empty, if so, set the head to null
   * and you're finished, otherwise go through the deep copy set
   */
  else {
    /* 
     * this copies the head item and only the head item, so it 
     * needs to set the head to itself, tail to itself, prev to null
     * and next to null
     */
    head = new Double_node;
    assert ( head != NULL );
    head->item = a_list.head->item;
    head->prev = NULL;
    head->next = NULL;
    tail = head;
    /*
     * Now that the first item of the list has been set, we can
     * go about copying the rest. new_ptr points to the current
     * head in the list.
     */
    Double_node *new_ptr  = head; 
    Double_node *orig_ptr = a_list.head->next;
    Double_node *tmp_ptr;

    for ( ; orig_ptr != NULL; orig_ptr = orig_ptr->next ) {
      new_ptr->next = new Double_node;
      assert ( new_ptr->next != NULL );
      tmp_ptr       = new_ptr;
      new_ptr       = new_ptr->next;
      new_ptr->prev = tmp_ptr;
      new_ptr->item = orig_ptr->item;
    }
    /* 
     * now that the loop has finished, the last element's 
     * next pointer needs to point to null
     * the tail pointer should point to the last element on the 
     * list.
     */
    new_ptr->next = NULL;
    tmp_ptr       = NULL;
    tail          = new_ptr;
  }
}

/* 
 * this will remove the first element of the loop on EACH 
 * iteration of the loop. Once, the list is empty it will 
 * stop. How to implement without index???
 */
void Double_list::~d_list () 
{
  while ( !is_empty ()) {
    remove ( 0 );
  }    
}

/* 
 * Checks if the list's size = 0 and makes sure that head 
 * and tail are pointing to null. An assert statement
 * may not be the best way to check that head & tail are set to NULL
 */
bool Double_list::is_empty () const 
{
  if ( size == 0 ) {
    assert ( head == NULL );
    return true;
  }
  return false;
}

/*
 * Accesses the private size variable
 */
int Double_list::get_length () const
{
  return size;
}

/* 
 * finds the list item located at the given index
 */

Double_list::Double_node *Double_list::find ( int index ) const
{
  if (( index < 1 ) || ( index > new_length )) {
    throw list_index_out_of_range_exception(
        "List Index Out of Range Exception: the index you provided is out of range");
  } else {
    Double_node *target = head;
    int inc = 0;
    for ( ; inc <= size; ++inc ) {
      target = target->next
    }
    return target;
  }
}
/* 
 * this is a variation of the find function, instead of searching by index
 * it searches for a SPECIFIC item,. thus allowing the user to 
 * search for bob, without any indexing.
 */
Double_list::Double_node *Double_list::find ( list_item_type data_item ) const
{
  if ( data_item == NULL ) {
    return NULL;
  } else {
    Double_node *target = head;
    int inc = 0;
    while ( inc <= size ) {
      if ( data_item == target->item ) {
        return target;
      } else {
        target = target->next;
        inc++;
      }
    }
  }
}

/* 
 * item_add - this should be used for UNORDERED lists, such as queues,
 * where adding to the tail, without indexing won't cause problems. 
 * The convention will be tail addition.
 */
bool Double_list::item_add ( list_item_type new_item )
{
  /* Two cases (1) the list is empty, and (2) the list isn't empty
   * CASE 1 - add initial node to the list, populate the item
   */
  int new_length        = get_length() + 1;
  Double_node *new_ptr  = new Double_node; 
  new_ptr->item         = new_item;
  
  if ( is_empty ()) {
    head          = new_ptr;
    tail          = new_ptr;
    new_ptr->prev = NULL;
    new_ptr->next = NULL;
  /* 
   * CASE 2 - add on to the end. The head pointer doesn't
   * change because of the tail-addition.
   */
  } else {
    new_ptr->prev       = tail;
    new_ptr->prev->next = new_ptr;
    tail                = new_ptr;
  }
}

void Double_list::remove ( int index )
/* 
 * Traverse the doubly linked list to find the item located
 * at the given index, remove the item, decrement the size counter
 */
{
  if (( index < 1 ) || ( index > new_length )) {
    throw list_index_out_of_range_exception(
      "List Index Out of Range Exception: the index you provided is out of range");
  } else {
    Double_node *target;
    target = find ( index );
   /* several cases, remove head, remove somewhere in the middle
    * and remove tail
    *
    * find the node to be deleted, set the pointers
    * to different nodes, then deallocate
    * CASE 1 - remove head
    */
    if ( index == 0 ) {
      assert ( head != NULL );
      head = target->next;
      delete target;
      target = NULL;
      size--;
    /* 
     * CASE 2: remove item inside the list
     */
    } else if (( index > 0 ) && ( index < size )) {
      target->prev->next = target->next;
      target->next->prev = target->prev;
      delete target;
      target = NULL;
      size--;
    /* 
     * CASE 3: target is what tail points to 
     */
    } else {
      assert ( tail != NULL );
      tail = target->prev;
      delete target;
      target = NULL;
      size--;
}

void Double_list::remove ( list_item_type& data_item )
{
  Double_node *target = find ( data_item );
  /* CASE 1 - this is the first node, pointed at by head
   */
  if ( size == 1 ) {
    target->prev = NULL;
    target->next = NULL;
    head = NULL;
    tail = NULL;
    delete target;
    size = 0;
  /* CASE 2 - if target is first item in list with more than
   * one item.
   */
  } else if (( size > 1 ) && ( head == target )) {
    head = target->next;
    target->next->prev = NULL;
    delete target;
    target = NULL;
    size--;
  /* CASE 3 - the item is somewhere in the middle of the list
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
  /* CASE 4 - item is located at the tail, the edge case
   * of the size = 1, where head = node = tail, is 
   * already handled.
   */
  } else if ( tail == target ) {
    tail = target->prev;
    target-prev->next = NULL;
    delete target;
    target = NULL;
}
/* 
 * this should "peek" at the item. I am not sure whether the
 * function should return the item, or be void, and go to os
 * As programmed now, the function will assign a pointer to the
 */

void Double_list::retrieve ( int index, list_item_type& data_item ) const
{
  if (( index < 1 ) || ( index > new_length )) {
    throw list_index_out_of_range_exception(
      "List Index Out of Range Exception: the index you provided is out of range");
  } else {
    Double_node *target = find ( index );
    data_item = target->item;
  }
}
