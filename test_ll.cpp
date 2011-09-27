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
  list_p->pop ();
  list_p->find ( 9 );
//  list_p->remove ( 9 );
  list_p->item_add ( 1241 );
  cout << "size:    "  << list_p->get_length() << endl;
  cout << "empty?:  "  << list_p->is_empty() << endl;
  return 1;
}

  
