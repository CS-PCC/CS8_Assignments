#ifndef HEAP_H
#define HEAP_H

#include <cassert>    // Provides assert
#include <iomanip>    // Provides std::setw
#include <iostream>   // Provides std::cout

template <class Item>
class Heap
{
public:
  // TYPEDEF
  typedef Item value_type;
  // CONSTRUCTOR
  Heap();
  Heap(Item* arr, int size);
  // BIG 3
  Heap(const Heap& x);                //Constructs a container with a copy of each of the elements in x, in the same order.
  ~Heap();                            //Destroys the container object.
  Heap& operator = (const Heap& x);   //Assigns new contents to the container, replacing its current contents, and modifying its size accordingly.
  // MODIFICATION MEMBER FUNCTIONS
  void heapify(int i);                //heapify the new node following a Bottom-up approach
  void heapify(Item*& arr, int n, int i);//heapify the new node following a Bottom-up approach
  void insert(const Item& insert_me); //insert into the heap
  void remove();                      //remove top value
  void remove_node(const Item& delete_me); //remove a node from the heap
  Item top()                          //return the value at the top of heap
  // CONST MEMBER FUNCTIONS
  bool is_empty() const;
  int size() const;
  int capacity() const;
  bool verify() const;                //true if tree is verified to be a heap
  Item *heap_array() const;           //returns a copy of underlying array:
                                      //  don't forget to delete when done
  Item *heap_sort();                  //returns a copy of sorted array
  // OVERLOAD OPERATOR FUNCTIONS
  friend std::ostream& operator << (std::ostream& outs, const Heap<Item>& print_me) {
    print_me.print_tree();
    return outs;
  }
private:
  static const int CAPACITY = 1000;
  int _size;   // the space used
  Item* _heap; // dynamic array

  void print_tree(std::ostream& outs = std::cout) const;
  void print_tree(int root, int level = 0, std::ostream& outs = std::cout) const;

  bool verify(int root) const;

  bool is_root(int i) const;
  bool is_leaf(int i) const;
  int parent_index(int i) const;
  int left_child_index(int i) const;
  int right_child_index(int i) const;
  int first_nonleaf() const;
  void swap_with_parent(int i);
};


// Implementation

// TODO

#endif // HEAP_H