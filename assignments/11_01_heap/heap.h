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
  // MODIFICATION MEMBER FUNCTIONS
  void insert(const Item& insert_me); //insert into the heap
  Item remove();                      //remove and return top value 
  Item top()                          //return the value at the top of heap
  // CONST MEMBER FUNCTIONS
  bool is_empty() const;
  int size() const;
  int capacity() const;
  bool verify() const;                //true if tree is verified to be a heap
  Item *heap_array();                 //returns a copy of underlying array:
                                      //  don't forget to delete when done
  // OVERLOAD OPERATOR FUNCTIONS
  friend std::ostream& operator << (std::ostream& outs, const Heap<Item>& print_me) {
    print_me.print_tree();
    return outs;
  }
private:
  static const int CAPACITY = 1000;
  Item _heap[CAPACITY]; //static array
  int _size;            //num used

  void print_tree(std::ostream& outs = std::cout) const;
  void print_tree(int root, int level = 0, std::ostream& outs = std::cout) const;

  bool verify(int root) const;

  bool is_root(int i) const;
  bool is_leaf(int i) const;
  int parent_index(int i) const;
  int left_child_index(int i) const;
  int right_child_index(int i) const;
  int big_child_index(int i) const;
  void swap_with_parent(int i);
};


// Implementation

// TODO

#endif // HEAP_H