#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

#include "linkedlist.h"

int main ( )
{
  Double_list *list_p;
  Double_list *list_n;
  list_p = new Double_list ();
  /* copy constructor DOES NOT work, or I don't know how to call it.
   */
  list_p->item_add ( 7 );
  list_p->item_add ( 9 );
  list_p->item_add ( 10 );
  
  list_n = new Double_list ( *list_p);
  cout << "MEM tests" << endl;
  cout << "mem address for 7 in list_n " << list_n->retrieve(7)->next << endl;
  cout << "mem address for 7 in list_p " << list_p->retrieve(7)->next << endl;
  /* the following retrieve statement seg faults. Since 5 doesn't exist in the list,
   * next obviously cannot either. I should throw an exception instead of returning null
   */
  cout << "Mem address where 5 is: "<< list_p->retrieve(5) << endl;
  cout << "Print tests" << endl;
  list_n->print();
  list_p->print(); 
  list_p->pop ();
  
  list_p->retrieve( 7 );
  cout << "node after 7, should be 9, is it? " << list_p->retrieve(7)->next->item << endl;
  list_p->remove ( 9 );
  cout << "node after 7, should be a null pointer, is it? " << list_p->retrieve(7)->next << endl;
  list_p->item_add ( 1241 );
  list_p->remove ( 12 );
  list_p->pop();
  list_p->pop();
  list_p->pop();
  list_p->pop();
  list_p->pop();
  cout << "size:    "  << list_p->get_length() << endl;
  cout << "empty?:  "  << list_p->is_empty() << endl;
  return 1;
}

  
