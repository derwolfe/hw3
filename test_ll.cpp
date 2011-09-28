#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

#include "linkedlist.h"

int main ( )
{
  Double_list *list_p;
  
  list_p = new Double_list ();
  list_p->item_add ( 7 );
  list_p->item_add ( 9 );
  list_p->item_add ( 10 );
  //cout << "mem address for 7 in list_n" << list_n->retrieve(7)->next << endl; 
  cout << "mem address for 7 in list_p " << list_p->retrieve(7)->next << endl; 
 
  list_p->pop ();
  list_p->print ();
  list_p->retrieve( 7 );
  cout << "node after 7, should be 9, is it? " << list_p->retrieve(7)->next->item << endl;
  list_p->remove ( 9 );
  cout << "node after 7, should be a null pointer, is it? " << list_p->retrieve(7)->next << endl;
  list_p->item_add ( 1241 );
  list_p->remove ( 12 );
  cout << "size:    "  << list_p->get_length() << endl;
  cout << "empty?:  "  << list_p->is_empty() << endl;
  return 1;
}

  
