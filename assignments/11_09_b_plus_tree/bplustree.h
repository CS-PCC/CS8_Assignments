// FILE: bplustree.h
// TEMPLATE CLASS PROVIDED: BPlusTree<Item>
//   (a container template class for a BPlusTree of items)
//
// TYPEDEFS for the BPlusTree<Item> class:
//   BPlusTree<Item>::value_type
//     BPlusTree<Item>::value_type is the data type of the items in the BPlusTree. It may be
//     any of the C++ built-in types (int, char, etc.), or a class with a
//     default constructor, a copy constructor, an assignment operator, and a
//     less-than operator forming a strict weak ordering.
//
// CONSTRUCTOR for the BPlusTree<Item> class:
//   BPlusTree()
//     Postcondition: The BPlusTree is empty.
//
//   BPlusTree(const BPlusTree& source)
//     Postcondition: The BPlusTree is same as source. (copy constructor)
//
//   BPlusTree(Item* a, std::size_t size)
//     Postcondition: Insert entry from array to BPlusTree.
//
// MODIFICATION MEMBER FUNCTIONS for the BPlusTree<Item> class:
//   void clear()
//     Postcondition: The BPlusTree is empty, delete all nodes etc.
//
//   void copy(const BPlusTree& source)
//     Postcondition: The BPlusTree is copied.
//
//   void copy(const BPlusTree& source)
//     Postcondition: The BPlusTree is copied.
//
//   bool insert(const Item& entry)
//     Postcondition: If an equal entry was already in the BPlusTree, the BPlusTree is
//     unchanged and the return value is false. Otherwise, entry was added
//     to the BPlusTree and the return value is true.
//
//   bool erase(const Item& target)
//     Postcondition: If target was in the BPlusTree, then it has been removed from
//     the BPlusTree and the return value is true. Otherwise the BPlusTree is unchanged
//     and the return value is false.
//
// NON-CONSTANT MEMBER FUNCTIONS for the BPlusTree<Item> class:
//   Item* find(const Item& entry)
//     Postcondition: Returns a pointer of found entry, otherwise return nullptr.
//
//   bool contains(const Item& entry)
//     Postcondition: Returns true if entry can be found, otherwise return false.
//
//   Item& get(const Item& entry)
//     Postcondition: Returns a reference of entry.
//
//   std::size_t size() const
//     Postcondition: Returns count the number of elements in the leaves of tree
//
//   Iterator lower_bound(const Item& key)
//     Postcondition: Returns an iterator pointing to the first element in the
//     leaves of the BPlusTree that is not less than (i.e. greater or equal to) key.
//
//   Iterator upper_bound(const Item& key)
//     Postcondition: Returns an iterator pointing to the first element in the
//     leaves of the BPlusTree that is greater than key.
//
//   Iterator begin()
//     Postcondition: Returns an iterator pointing to the first element in the
//     leaves of the BPlusTree.
//
//   Iterator end()
//     Postcondition: Returns an empty iterator.
//
// CONSTANT MEMBER FUNCTIONS for the BPlusTree<Item> class:
//   const Item& get(const Item& entry) const
//     Postcondition: Returns a reference of entry.
//
//   std::size_t n_items() const
//     Postcondition: Returns count the number of elements in the tree
//
//   bool empty() const
//     Postcondition: Returns true if the BPlusTree is empty; otherwise returns false.
//
//   void print(int indent=0, std::ostream& outs = std::cout) const
//     Postcondition: Print the BPlusTree in readable version
//
//   bool is_valid() const
//     Postcondition: Returns true if the BPlusTree is valid, otherwise return false.
//
// SUGGESTED FUNCTION FOR DEBUGGING
//   std::string in_order()
//     Postcondition: traverse the tree in_order, return a string of all the 
//     data items with vertical delimiters
//
//   std::string pre_order()
//     Postcondition: traverse the tree pre_order, return a string of all the
//     data items with vertical delimiters
//
//   std::string post_order()
//     Postcondition: traverse the tree post_order, return a string of all the
//     data items with vertical delimiters
//
// HELPER MEMBER FUNCTIONS
//   bool is_leaf() const
//     Postcondition: Returns true if the BPlusTree is a leaf, otherwise return false.
//
//   BPlusTree<Item>* get_smallest_node()
//     Postcondition: Returns a pointer to the smallest node in the BPlusTree.
//
//   bool loose_insert(const Item& entry)
//     Precondition: The entire B-tree is valid.
//     Postcondition: If entry was already in the BPlusTree, then the BPlusTree is unchanged
//     and the return value is false. Otherwise, the entry has been added to the
//     BPlusTree, the return value is true, and the entire B-tree is still
//     valid EXCEPT that the number of entries in the root of this BPlusTree might be
//     one more than the allowed maximum.
//
//   void fix_excess(std::size_t i);
//     Precondition: (i < child_count) and the entire B-tree is valid EXCEPT that
//     subset[i] has MAXIMUM + 1 entries.
//     Postcondition: The tree has been rearranged so that the entire B-tree is
//     valid EXCEPT that the number of entries in the root of this BPlusTree might be
//     one more than the allowed maximum.
//
//   bool loose_erase(const Item& target);
//     Precondition: The entire B-tree is valid.
//     Postcondition: If target was not in the BPlusTree, then the BPlusTree is unchanged and
//     the return value is false. Otherwise, the target has been removed, the
//     return value is true, and the entire B-tree is still valid
//     EXCEPT that the number of entries in the root of this BPlusTree might be one
//     less than the allowed minimum.
//
//   void fix_shortage(std::size_t i);
//     Precondition: (i < child_count) and the entire B-tree is valid EXCEPT that
//     subset[i] has MINIMUM - 1 entries.
//     Postcondition: The tree has been rearranged so that the entire B-tree is
//     valid EXCEPT that the number of entries in the root of this BPlusTree might be
//     one less than the allowed minimum.
//
//    void delete_inner(std::size_t i, const Item& target, const Item& next_smallest)
//       Precondition: subset[i] is an internal node.
//       Postcondition: find target in data[i] or subset[i] or subset[i+1], 
//       if so, replace it with next_smallest.
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


#ifndef BPLUSTREE_H
#define BPLUSTREE_H

#include <iostream>   // Provides std::cout
#include <iomanip>    // Provides std::setw
#include <cassert>    // Provides assert
#include <cstdlib>    // Provides size_t
#include <string>     // Provides std::to_string

#include "btree_array_functions.h" // Include the implementation.


template <class Item>
class BPlusTree
{
public:
  // TYPEDEFS and MEMBER CONSTANTS
  typedef Item value_type;
  // NESTED CLASS DEFINITION
  class Iterator
  {
    public:
      friend class BPlusTree;
      // CONSTRUCTORS
      Iterator(BPlusTree* _it=nullptr, std::size_t _key_ptr = 0) : it(_it), key_ptr(_key_ptr) {}
      // MODIFICATION MEMBER FUNCTIONS
      Item operator * ();
      const Item operator *() const;
      Iterator operator ++ (int un_used); // Postfix ++ (it++)
      Iterator operator ++ ();// Prefix ++ (++it)
      // OVERLOADED OPERATORS
      friend bool operator == (const Iterator& lhs, const Iterator& rhs);
      friend bool operator != (const Iterator& lhs, const Iterator& rhs) {
        return !(lhs == rhs);
      }
      // HELPER FUNCTIONS
      bool is_null () { return !it; }
      void print_Iterator();
      void info() const;
    private:
      BPlusTree<Item>* it;
      std::size_t key_ptr;
  };

  // CONSTRUCTORS and DESTRUCTOR
  BPlusTree();
  BPlusTree(const BPlusTree& source);
  BPlusTree(Item* a, std::size_t size);
  ~BPlusTree() { clear(); }
  // MODIFICATION MEMBER FUNCTIONS
  BPlusTree& operator = (const BPlusTree& source);
  void clear();
  void copy(const BPlusTree& source);
  void copy(const BPlusTree& source, BPlusTree*& last_node);
  bool insert(const Item& entry);
  bool erase(const Item& target);
  // NON-CONSTANT MEMBER FUNCTIONS
  Iterator find(const Item& entry);
  bool contains(const Item& entry);
  Item& get(const Item& entry);
  std::size_t size();
  Iterator lower_bound(const Item& key);
  Iterator upper_bound(const Item& key);
  Iterator begin();
  Iterator end() { return Iterator(); }
  // CONSTANT MEMBER FUNCTIONS
  const Item& get(const Item& entry) const;
  std::size_t n_items() const;
  bool empty() const { return (data_count == 0 && is_leaf()); }
  void print(int indent=0, std::ostream& outs = std::cout) const;
  bool is_valid() const;
  // OVERLOAD OPERATOR FUNCTIONS
  template<class U>
  friend std::ostream& operator << (std::ostream& outs, const BPlusTree<U>& btree) {
    btree.print(0, outs);
    return outs;
  }
  // SUGGESTED FUNCTION FOR DEBUGGING
  std::string in_order();
  std::string pre_order();
  std::string post_order();
private:
  // MEMBER CONSTANTS
  static const std::size_t MINIMUM = 1;
  static const std::size_t MAXIMUM = 2 * MINIMUM;
  // MEMBER VARIABLES
  std::size_t data_count;
  Item data[MAXIMUM+1];
  std::size_t child_count;
  BPlusTree* subset[MAXIMUM+2];
  BPlusTree* next;
  // HELPER MEMBER FUNCTIONS
  bool is_leaf() const { return (child_count == 0); }
  BPlusTree<Item>* get_smallest_node();
  // insert element functions
  bool loose_insert(const Item& entry);
  void fix_excess(std::size_t i);
  // remove element functions
  bool loose_erase(const Item& target);
  void fix_shortage(std::size_t i);
  void delete_inner(std::size_t i, const Item& target, const Item& next_smallest);
  void transfer_from_left(std::size_t i);
  void transfer_from_right(std::size_t i);
  void merge_with_next_subset(std::size_t i);
};

// Implementation ITERATOR MEMBER FUNCTIONS

// TODO

// Implementation BPlusTree MEMBER FUNCTIONS

// TODO

#endif // BPLUSTREE_H