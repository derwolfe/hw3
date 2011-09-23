#include "list_index_out_of_range_exception.h"
#include "list_exception.h"

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
    
    /* destructor */
    ~d_list ();

    /* checks if the node is empty */
    bool is_empty () const;

    /* returns the length */
    int get_length () const;

    /* 
     * inserts node at index, unless it is out the range,
     * throws an error 
     */
    void insert ( int index, list_item_type new_item)
      throw ( list_index_out_of_range_exception, list_exception );

    /* 
     * removes the node located at the given index,
     * unless the index given is greater than the range of the 
     * list
     */
    void remove ( int index )
      throw ( list_index_out_of_range_exception );
    
    /* 
     * returns the item of type list_item_type located at
     * the given index, unless of course you've asked for 
     * an index that's out of bounds
     */
    void retrieve ( int index, list_item_type& data_item ) const
      throw ( list_index_out_of_range_exception );

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
    
    /* 
     * The tail-node could speed adding new objects to the end of list
     * however, it could also take extra time implementing
     */
    Double_node   *tail;
    Double_node   *find ( int index ) const;
};

