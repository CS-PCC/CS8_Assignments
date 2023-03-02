// FILE: chained_hash.h
// TEMPLATE CLASS PROVIDED: ChainedHash<RecordType>
//   This class is a container template class for a Table(ChainedHash) of records.
//   The template parameter, RecordType, is the data type of the records in the
//   ChainedHash. It may any type with a default constructor, a copy constructor,
//   an assignment operator, and an integer member variable called key.
//
// CONSTRUCTOR for the ChainedHash<RecordType> template class:
//   ChainedHash()
//     Postcondition: The ChainedHash has been initialized as an empty ChainedHash.
//
// VALUE SEMANTICS for the ChainedHash<RecordType> template class:
//   Assignments and the copy constructor may be used with ChainedHash objects.
//
// MODIFICATION MEMBER FUNCTIONS for the ChainedHash<RecordType> class:
//   void insert(const RecordType& entry)
//     Precondition: entry.key >= 0. Also if entry.key is not already a key in
//     the table, then the ChainedHash has space for another record
//     (i.e., size() < CAPACITY).
//     Postcondition: If the table already had a record with a key equal to
//     entry.key, then that record is replaced by entry. Otherwise, entry has
//     been added as a new record of the ChainedHash.
//
//   void remove(int key)
//     Postcondition: If a record was in the ChainedHash with the specified key, then
//     that record has been removed; otherwise the table is unchanged.
//
// CONSTANT MEMBER FUNCTIONS for the ChainedHash<RecordType> class:
//   bool is_present(const int key) const
//     Postcondition: The return value is true if there is a record in the
//     ChainedHash with the specified key. Otherwise, the return value is false.
//
//   void find(int key, bool& found, RecordType& result) const
//     Postcondition: If a record is in the ChainedHash with the specified key, then
//     found is true and result is set to a copy of the record with that key.
//     Otherwise found is false and the result contains garbage (initial RecordType).
//
//   size_t size() const
//     Postcondition: Return value is the total number of records in the ChainedHash.
//
//   size_t capacity() const
//     Postcondition: Return value is the capacity of records in the ChainedHash.

#ifndef CHAINED_HASH_H
#define CHAINED_HASH_H

#include <cstdlib>    // Provides size_t
#include <cassert>    // Provides assert
#include <iomanip>    // Provides std::setw
#include <iostream>   // Provides std::cout

#include "../avl_tree/avl_tree.h"

template <class RecordType>
class ChainedHash
{
public:
  // TYPEDEF
  typedef RecordType record_type;
  // MEMBER CONSTANT
  static const std::size_t TABLE_SIZE = 19;  // basic_test
  // static const std::size_t TABLE_SIZE = 811; // for submission
  // CONSTRUCTORS AND DESTRUCTOR
  ChainedHash();
  ChainedHash(const ChainedHash& source);
  ~ChainedHash();
  ChainedHash& operator = (const ChainedHash& source);
  // MODIFICATION MEMBER FUNCTIONS
  void insert(const RecordType& entry);
  void remove(int key);
  // CONSTANT MEMBER FUNCTIONS
  bool is_present(const int key) const;
  void find(int key, bool& found, RecordType& result) const;
  std::size_t size() const { return total_records; }
  std::size_t capacity() const { return TABLE_SIZE; }
  // OVERLOAD OPERATOR FUNCTIONS
  template<class U>
  friend std::ostream& operator << (std::ostream& outs, const ChainedHash<U>& hash);
private:
  // MEMBER VARIABLES
  AVL<RecordType> data[TABLE_SIZE];
  std::size_t total_records;
  // HELPER MEMBER FUNCTION
  std::size_t hash(int key) const;
  void print_hash(std::ostream& outs = std::cout) const;
};


// Implementation NON-MEMBER FUNCTIONS

template <class Item>
void print_item(const Item& data)
{
  std::cout << data;
}

// Implementation MEMBER FUNCTIONS

// TODO


#endif // CHAINED_HASH_H