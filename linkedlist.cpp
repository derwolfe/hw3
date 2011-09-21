#include <stdlib.h>
#include <assert.h>

using namespace std;

#include "linkedlist.h"

/*
 * default constructor that creates a list of no length
 * pointing the head pointer to null
 */
Double_list::d_list ():
{
  size ( 0 );
  head ( NULL );
}

Double_list::d_list ( const d_list& a_list ) : size(a_list.size)
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
    new_ptr->next = NULL;
    tail = new_ptr;
  }
}

