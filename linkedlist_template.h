#ifndef LINKEDLIST_TEMPLATE_H_
#define LINKEDLIST_TEMPLATE_H_

#include <stdlib.h>
#include <cassert>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/* 
 * The types I am intending to use with this container are
 * the classes:
 *  - Patient
 *  - Doctor
 *
 *  Deep Copy does not seem to work. Though I don't believe 
 *  this is called at any point in the assignment.
 */
template <class T>
struct Double_node 
{
  /* the object contained in the doubly linked list
   */
  T                 item;
  
  /* 
   * pointers to the previous and next nodes, 
   * this is the distinguishing feature of the doubly
   * linked list
   */
  Double_node<T>    *prev;
  Double_node<T>    *next;
};
    
template <class T>
class Double_list 
{
  public:
    /* constructor for empty object */
    Double_list ();

    /* copy constructor needed to be able to make deep copies of objects */
    Double_list ( const Double_list& a_list );
    
    /* destructor - basically a tail ended pop */
    ~Double_list ();

    /* checks if the node is empty */
    bool is_empty () const;

    /* returns the length */
    int get_length () const;

    /* adds the item to the end of the list.*/
    void item_add (const T& data_item );

    /* finds then remove the  node */
    void remove ( Double_node<T>* target );
   
    /* pop function - tail end pop */
    void pop ();
    /* returns a sought item searched by item name, 
     */
    Double_node<T> *retrieve ( string first_name, string last_name ) const;

    void print_items ( std::ostream &os );

  private:

    int             size;
    Double_node<T>  *head;
    Double_node<T>  *tail;
    Double_node<T>  *find ( string first_name, string last_name ) const;
};
/*
 * Implementation of the template
 *
 * default constructor that creates a list of no length
 * pointing the head, initializing the head and null pointers
 */
template <class T>
Double_list<T>::Double_list () 
{
  size = 0;
  head = NULL;
  tail = NULL;
}

template <class T>
Double_list<T>::Double_list ( const Double_list<T>& a_list )
{
  size = a_list.size;
  if ( a_list.head == NULL ) {
    head = NULL;
    tail = NULL;
  
  /* 
   * checks to see if list is empty, if so, set the head to null
   * and you're finished, otherwise go through the deep copy set
   */
  } else {
    /* 
     * this copies the head item and only the head item, so it 
     * points head and tail 
     */
    head = new Double_node<T>();
    assert ( head != NULL );
    head->item = a_list.head->item;
    head->prev = NULL;
    head->next = NULL;
    tail = head;
    /*
     * Now that the first item of the list has been set, we can
     * go about copying the rest. data_ptr points to the current
     * head in the list.
     */
    Double_node<T>  *data_ptr = head; 
    Double_node<T>  *orig_ptr = a_list.head->next;
    Double_node<T>  *tmp_ptr;

    for ( ; orig_ptr != NULL; orig_ptr = orig_ptr->next ) {
      data_ptr->next = new Double_node<T>();
      assert ( data_ptr->next != NULL );
      tmp_ptr = data_ptr;
      data_ptr = data_ptr->next;
      data_ptr->prev = tmp_ptr;
      data_ptr->item = orig_ptr->item;
    }
    /* 
     * now that the loop has finished, the last element's 
     * next pointer needs to point to null
     * the tail pointer should point to the last element on the 
     * list.
     */
    data_ptr->next = NULL;
    tmp_ptr = NULL;
    tail = data_ptr;
  }
}

/* 
 * this will remove the first element of the loop on EACH 
 * iteration of the loop. Once, the list is empty it will 
 * stop. How to implement without index???
 */
template <class T>
Double_list<T>::~Double_list () 
{
  while ( !is_empty ()) {
    pop ();     
  }
}

/* 
 * Checks if the list's size = 0 and makes sure that head 
 * and tail are pointing to null. An assert statement
 * may not be the best way to check that head & tail are set to NULL
 */
template <class T>
bool Double_list<T>::is_empty () const 
{
  if ( size == 0 ) {
    //assert ( head == NULL );
    return true;
  } else {
    return false;
  }
}

/* Accesses the private size variable */
template <class T>
int Double_list<T>::get_length () const
{
  return size;
}


/* 
 * item_add - this should be used for UNORDERED lists, such as queues,
 * where adding to the tail, without indexing won't cause problems. 
 * The convention will be tail addition.
 */

template <class T>
void Double_list<T>::item_add (const T& data_item )
{
  /* Two cases (1) the list is empty, and (2) the list isn't empty
   * CASE 1 - add initial node to the list, populate the item
   */
  Double_node<T> *data_ptr; 
  data_ptr = new Double_node<T>;
  data_ptr->item  = data_item;
  if ( size == 0 ) {
    head            = data_ptr;
    tail            = data_ptr;
    data_ptr->prev  = NULL;
    data_ptr->next  = NULL;
  /* 
   * CASE 2 - add on to the end. The head pointer doesn't
   * change because of the tail-addition.
   */
  } else if ( size > 0 ) {
    data_ptr->prev        = tail;
    data_ptr->prev->next  = data_ptr;
    tail                  = data_ptr;
  }
  size++;
}

template <class T>
void Double_list<T>::remove ( Double_node<T> *target )
{  /* you should throw an exception
   */
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
    target->prev->next = NULL;
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
template <class T>
void Double_list<T>::pop ()
{
  /* 3 cases - 
   * (1) empty list 
   * (2) one element in list
   * (3) more than one element in list
   */
  if ( is_empty ()) {
    size = 0;
  } else {
    Double_node<T> *target = tail;
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


/* PRIVATE find method that should search the list for the data item
 * once found, it should return a pointer to the node. Now other functions
 * can use find,
 */

template <class T>
Double_node<T>* Double_list<T>::find ( string first_name, string last_name ) const
{
  Double_node<T> *target = head;
  int inc = 1;
  /* loop through the items. If the counter is ever greater than size, then 
   * the item isn't in the list, return a NULL pointer. I could also try throwing
   * an exception. the exception should be thrown at the first if loop.
   *
   * Get set routines needed to access these first and last name variables
   * that or they need to be public
   */
  while ( inc <= ( size + 1 )) {
    if ( inc == ( size + 1)) {
      return NULL;
    } else if (( first_name == target->item.get_first_name() ) &&
       ( last_name == target->item.get_last_name() )) {
      return target;
    } else {
      target = target->next;
      inc++;
    }
  } 
}

template <class T>
Double_node<T>* Double_list<T>::retrieve ( string first_name, string last_name ) const
{
  return ( find ( first_name, last_name ));
}
/* this doesn't work correctly, it isn't accessing what i think it should
 */
template <class T>
void Double_list<T>::print_items ( std::ostream &os )
{
  if ( head == NULL ) {
    os << endl;
  } 
  else if ( size == 1 ) {
    os << head->item << endl;
  } else {

  Double_node<T> *start = head;
  /* loop through the nodes until start = tail,
   * then stop
   */
  while ( start->next != NULL ) {
    os << start->item << endl;
    start = start->next;
    }
  }
}

#endif
