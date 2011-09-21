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
 */
Double_list::d_list (): 
{
  size ( 0 );
  head ( NULL );
}

void Double_list::d_list ( const d_list& a_list ) : size(a_list.size) 
{
  if ( a_list.head == NULL ) {
    head = NULL;
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
    
    /*
     * Now that the first item of the list has been set, we can
     * go about copying the rest. new_ptr points to the current
     * head in the list.
     */
    
    Double_node *new_ptr = head; 
    Double_node *orig_ptr = a_list.head->next;
    Double_node *tmp_ptr;
    for ( ; orig_ptr != NULL; orig_ptr = orig_ptr->next ) {
      new_ptr->next = new Double_node;
      assert ( new_ptr->next != NULL );
      tmp_ptr = new_ptr;
      new_ptr = new_ptr->next;
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
    tail = new_ptr;
  }
}

/* 
 * An OBJECT desctructor  
 * this will remove the first element of the loop on EACH 
 * iteration of the loop. Once, the list is empty it will 
 * stop.
 */
void Double_list::~d_list () 
{
    while ( !is_empty ) {
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
 /*       assert ( tail == NULL ); --removed from header file*/
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


bool Double_list::insert ( int index, list_item_type new_item )
{
    int new_length = get_length() + 1;
    if (( index < 1 ) || ( index > new_length )) {
        throw list_index_out_of_range_exception(
                "List Index Out of Range Exception: the index you provided is out of range");
    } else {
        /* 
         * Normal execution of the subroutine, initialiases a new_ptr for the NEW
         * double node
         */
        Double_node *new_ptr = new Double_node;
        if ( new_ptr == NULL ) {
            throw list_exception("No more memory for new node");
        } else {
            size = new_length;
            new_ptr->item = new_item;
            /* 
             * Insert to the head of the list, set the negative values NULL as they
             * are out of bound/
             */
            if ( index == 0 ) {
                new_ptr->next = head;
                new_ptr->prev = NULL;
                /*
                 * If the insertion is occuring in a list that isn't empty
                 * do the following, the following initializes the 2nd element
                 * in the list
                 */
                if ( head != NULL ) {
                /* 
                 *  based on the order of the dereferences, 
                 *  (new_ptr->next)->prev sets the next
                 *  element's 'prev' pointer to the newly minted node
                 */
                    new_ptr->next->prev = new_ptr;
                }
                head = new_ptr;
            /* 
             * Now we get to see what happens if there are elements
             * in the list. cur will point directly to the item located
             * behind the index. 
             */
            } else {
                /* three steps, first set new_ptr's next to the current item,
                 * this way no information is destroyed but a reference is produced
                 * second, set the next pointer of the item  previously preceding cur
                 * to point to the new item
                 * third set curs previous pointer to the new item.
                 */
                Double_node *cur = find ( index );
                new_ptr->next = cur;
                cur->prev->next = new_ptr;
                cur->prev = new_ptr;
            }
        }
    }
}

void Double_list::remove ( int index )
{
    if (( index < 1 ) || ( index > new_length )) {
        throw list_index_out_of_range_exception(
                "List Index Out of Range Exception: the index you provided is out of range");
    } else {




