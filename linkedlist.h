//#include "empty_list_exception.h"

typedef int list_item_type;
// THIS IS WRONG - you need a template, not a typedef
// template <class T>
    
/* 
 * the actual node in the doubly linked list
 * item of list_item_type is an item in the list
 * and prev is a pointer to the next node
 *
 * this is where you could feed in the template for item.
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
    

class Double_list 
{
  public:
    /* constructor for empty object */
    Double_list ();

    /* 
     * copy constructor needed to be able to make deep copies
     * of objects. Should the assignment operator have been overloaded
     * I cannot figure out how to call this constructor explicitly.
     */
    
    Double_list ( const Double_list& a_list );
    
    /* destructor - basically a tail ended pop */
    ~Double_list ();

    /* checks if the node is empty */
    bool is_empty () const;

    /* returns the length */
    int get_length () const;

    /* adds the item to the end of the list.*/
    void item_add ( list_item_type new_item );

    /* finds then remove the  node */
    void remove ( list_item_type data_item );
   
    /* pop function - tail end pop */
    void pop ();
    /* returns a sought item searched by item name, i don't
     * think this will work
     */
 //   friend std::ostream& operator<<(std::ostream &os, Double_list::Double_node &in_node);
    void print ();

    Double_node *retrieve ( list_item_type data_item ) const;
  
  private:

    /* 
     * the total size of the list
     * and and a pointer to the node
     */
    int size;
    Double_node   *head;
    Double_node   *tail;
    Double_node   *find ( list_item_type data_item ) const;
};

