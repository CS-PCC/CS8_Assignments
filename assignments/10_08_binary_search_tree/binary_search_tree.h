#ifndef BST_H
#define BST_H

#include <iostream>
#include <iomanip>

#include "../binary_tree/binary_tree.h"

// NON-MEMBER FUNCTIONS for the BST<Item>:
template <class Item>
binary_tree_node<Item>* sortedArrayToBST(const Item* nums, int left, int right);
template <class Item>
binary_tree_node<Item>* searchBST(binary_tree_node<Item>* root, int val);
template <class Item>
binary_tree_node<Item>* insertIntoBST(binary_tree_node<Item>* root, int val);
template <class Item>
binary_tree_node<Item>* deleteNode(binary_tree_node<Item>* root, int key);
template <class Item>
binary_tree_node<Item>* mergeTrees(binary_tree_node<Item>* t1, binary_tree_node<Item>* t2);

template <class Item>
class BST
{
public:
  // TYPEDEFS
  typedef std::size_t size_type;
  typedef Item value_type;
  // CONSTRUCTORS and DESTRUCTOR
  BST() : root_ptr(nullptr) {}
  BST(const Item *nums, int size=-1); // nums is a sorted list
  BST(const BST<Item> &copy_me);
  ~BST();
  BST<Item>& operator = (const BST<Item> &rhs);
  // MODIFICATION FUNCTIONS
  binary_tree_node<Item>* root();
  binary_tree_node<Item>* search(const Item& target);
  void insert(const Item &val);
  void erase(const Item &val);
  void clear_all();
  // CONST FUNCTIONS
  const binary_tree_node<Item>* root() const;
  bool empty() const;
  // OVERLOAD OPERATOR FUNCTIONS
  template <class U>
  friend std::ostream& operator << (std::ostream &outs, const BST<U>& tree);
  BST<Item> operator += (const BST<Item>& rhs);
private:
  binary_tree_node<Item> *root_ptr; // Root pointer of binary search tree
};


// Implementation MEMBER FUNCTIONS

// TODO

// Implementation NON-MEMBER FUNCTIONS

// TODO

#endif // BST_H