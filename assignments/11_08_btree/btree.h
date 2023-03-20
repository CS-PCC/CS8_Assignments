// FILE: btree.h
// TEMPLATE CLASS PROVIDED: BTree<Item>
//   (a container template class for a BTree of items)
//
// TYPEDEFS for the BTree<Item> class:
//   BTree<Item>::value_type
//     BTree<Item>::value_type is the data type of the items in the BTree. It may be
//     any of the C++ built-in types (int, char, etc.), or a class with a
//     default constructor, a copy constructor, an assignment operator, and a
//     less-than operator forming a strict weak ordering.
//
// CONSTRUCTOR for the BTree<Item> class:
//   BTree()
//     Postcondition: The BTree is empty.
//
//   BTree(const BTree& source)
//     Postcondition: The BTree is same as source. (copy constructor)
//
//   BTree(Item* a, std::size_t size)
//     Postcondition: Insert entry from array to BTree.
//
// MODIFICATION MEMBER FUNCTIONS for the BTree<Item> class:
//   void clear()
//     Postcondition: The BTree is empty, delete all nodes etc.
//
//   void copy(const BTree& source)
//     Postcondition: The BTree is copied.
//
//   bool insert(const Item& entry)
//     Postcondition: If an equal entry was already in the BTree, the BTree is
//     unchanged and the return value is false. Otherwise, entry was added
//     to the BTree and the return value is true.
//
//   bool erase(const Item& target)
//     Postcondition: If target was in the BTree, then it has been removed from
//     the BTree and the return value is true. Otherwise the BTree is unchanged
//     and the return value is false.
//
// NON-CONSTANT MEMBER FUNCTIONS for the BTree<Item> class:
//   Item* find(const Item& entry)
//     Postcondition: Returns a pointer of found entry, otherwise return nullptr.
//
//   bool contains(const Item& entry)
//     Postcondition: Returns true if entry can be found, otherwise return false.
//
//   Item& get(const Item& entry)
//     Postcondition: Returns a reference of entry.
//
// CONSTANT MEMBER FUNCTIONS for the BTree<Item> class:
//   std::size_t size() const
//     Postcondition: Returns count the number of elements in the tree
//
//   bool empty() const
//     Postcondition: Returns true if the BTree is empty; otherwise returns false.
//
//   void print(int indent=0, std::ostream& outs = std::cout) const
//     Postcondition: Print the Bree in readable version
//
// SUGGESTED FUNCTION FOR DEBUGGING
//   std::string in_order()
//     Postcondition: traverse the tree in_order, return a string of all the 
//     data items with vertical delimiters
//
// HELPER MEMBER FUNCTIONS
//   bool loose_insert(const Item& entry)
//     Precondition: The entire B-tree is valid.
//     Postcondition: If entry was already in the BTree, then the BTree is unchanged
//     and the return value is false. Otherwise, the entry has been added to the
//     BTree, the return value is true, and the entire B-tree is still
//     valid EXCEPT that the number of entries in the root of this BTree might be
//     one more than the allowed maximum.
//
//   void fix_excess(std::size_t i);
//     Precondition: (i < child_count) and the entire B-tree is valid EXCEPT that
//     subset[i] has MAXIMUM + 1 entries.
//     Postcondition: The tree has been rearranged so that the entire B-tree is
//     valid EXCEPT that the number of entries in the root of this BTree might be
//     one more than the allowed maximum.
//
//   bool loose_erase(const Item& target);
//     Precondition: The entire B-tree is valid.
//     Postcondition: If target was not in the BTree, then the BTree is unchanged and
//     the return value is false. Otherwise, the target has been removed, the
//     return value is true, and the entire B-tree is still valid
//     EXCEPT that the number of entries in the root of this BTree might be one
//     less than the allowed minimum.
//
//    void remove_biggest(Item& removed_entry);
//      Precondition: (data_count > 0) and the entire B-tree is valid.
//      Postcondition: The largest item in the BTree has been removed, and a copy
//      of this removed entry has been placed in removed_entry. The entire
//      B-tree is still valid, EXCEPT that the number of entries in the root of this
//      BTree might be one less than the allowed minimum.
//
//   void fix_shortage(std::size_t i);
//     Precondition: (i < child_count) and the entire B-tree is valid EXCEPT that
//     subset[i] has MINIMUM - 1 entries.
//     Postcondition: The tree has been rearranged so that the entire B-tree is
//     valid EXCEPT that the number of entries in the root of this BTree might be
//     one less than the allowed minimum.
//
//    void transfer_from_left(std::size_t i)
//       Precondition: subset[i] has only MINIMUM - 1 entries, and
//       subset[i-1] has more than the minimum number of entries.
//       Postcondition: transfer an extra entry from subset[i-1].
//
//    void transfer_from_right(std::size_t i)
//       Precondition: subset[i] has only MINIMUM - 1 entries, and
//       subset[i+1] has more than the minimum number of entries.
//       Postcondition: transfer an extra entry from subset[i+1].
//
//    void merge_with_next_subset(std::size_t i)
//       Precondition: subset[i+1] has only MINIMUM - 1 entries, and
//       subset[i] has only minimum number of entries.
//       Postcondition: combine subset[i] with subset[i+1].


#ifndef BTREE_H
#define BTREE_H

#include <iostream>   // Provides std::cout
#include <iomanip>    // Provides std::setw
#include <cassert>    // Provides assert
#include <cstdlib>    // Provides size_t
#include <string>     // Provides std::to_string

#include "../btree_array_functions/btree_array_functions.h" // Include the implementation.


template <class Item>
class BTree
{
public:
  // TYPEDEFS
  typedef Item value_type;
  // CONSTRUCTORS and DESTRUCTOR
  BTree();
  BTree(const BTree& source);
  BTree(Item* a, std::size_t size);
  ~BTree() { clear(); }
  // MODIFICATION MEMBER FUNCTIONS
  BTree& operator = (const BTree& source);
  void clear();
  void copy(const BTree& source);
  bool insert(const Item& entry);
  bool erase(const Item& target);
  // NON-CONSTANT MEMBER FUNCTIONS
  Item* find(const Item& entry);
  bool contains(const Item& entry);
  Item& get(const Item& entry);
  // CONSTANT MEMBER FUNCTIONS
  std::size_t size() const;
  bool empty() const { return (data_count == 0); }
  void print(int indent=0, std::ostream& outs = std::cout) const;
  // OVERLOAD OPERATOR FUNCTIONS
  template<class U>
  friend std::ostream& operator << (std::ostream& outs, const BTree<U>& btree);
  // SUGGESTED FUNCTION FOR DEBUGGING
  std::string in_order();
private:
  // MEMBER CONSTANTS
  static const std::size_t MINIMUM = 1;
  static const std::size_t MAXIMUM = 2 * MINIMUM;
  // MEMBER VARIABLES
  std::size_t data_count;
  Item data[MAXIMUM+1];
  std::size_t child_count;
  BTree* subset[MAXIMUM+2];
  // HELPER MEMBER FUNCTIONS
  bool is_leaf() const { return (child_count == 0); }
  // insert element functions
  bool loose_insert(const Item& entry);
  void fix_excess(std::size_t i);
  // remove element functions
  bool loose_erase(const Item& target);
  void remove_biggest(Item& removed_entry);
  void fix_shortage(std::size_t i);
  void transfer_from_left(std::size_t i);
  void transfer_from_right(std::size_t i);
  void merge_with_next_subset(std::size_t i);
};

// Implementation MEMBER FUNCTIONS

// TODO


#endif // BTREE_H