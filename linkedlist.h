#include "empty_list_exception.h"

typedef desired-type-of-list-item list_item_type;

class Double_list 
{
  public:
    /* constructor for empty object */
    d_list ();

    /* 
     * copy constructor needed to be able to make deep copies
     * of objects
     */
    d_list ( const d_list& a_list );
    
    /* destructor - basically a tail ended pop */
    ~d_list ();

    /* pop function - tail end pop */
    void pop ();
      throw ( empty_list_exception );
    /* checks if the node is empty */
    bool is_empty () const;

    /* returns the length */
    int get_length () const;

    /* adds the item to the end of the list.*/
    void item_add ( int index, list_item_type new_item )

    /* finds then remove the  node */
    void remove ( list_item_type data_item )
    
    /*returns a sought item searched by item name, i don't
     * think this will work
     */
    list_item_type get_item ( list_item_type& data_item ) const

  private:
    
    /* 
     * the actual node in the doubly linked list
     * item of list_item_type is an item in the list
     * and prev is a pointer to the next node
     */
    struct Double_node {
      list_item_type  item;
      
      /* 
       * pointers to the previous and next nodes, 
       * this is the distinguishing feature of the doubly
       * linked list
       */
      Double_node   *prev;
      Double_node   *next;
    };
    
    /* 
     * the total size of the list
     * and and a pointer to the node
     */
    int size;
    Double_node   *head;
    Double_node   *tail;
    
    Double_node   *find ( list_item_type data_item ) const
};

