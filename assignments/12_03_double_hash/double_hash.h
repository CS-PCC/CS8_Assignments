// FILE: double_hash.h
// TEMPLATE CLASS PROVIDED: DoubleHash<RecordType> (a table of records with keys).
//    This class is a container template class for a table of records.
//    The template parameter, RecordType, is the data type of the records in the
//    table. It may be any of the built-in C++ types (int, char, etc.), or a
//    class with a default constructor, an assignment operator, and an integer
//    member variable called key.
// 
// MEMBER CONSTANT for the DoubleHash<RecordType> class:
//   static const size_type CAPACITY = ________
//     DoubleHash<RecordType>::CAPACITY is the maximum number of records held by a table.
//
// CONSTRUCTOR for the DoubleHash<RecordType> template class:
//   DoubleHash()
//     Postcondition: The table has been initialized as an empty table.
//
// MODIFICATION MEMBER FUNCTIONS for the DoubleHash<RecordType> class:
//   void insert(const RecordType& entry)
//     Precondition: entry.key >= 0. Also if entry.key is not already a key in
//     the table, then the table has space for another record
//     (i.e., size() < CAPACITY).
//     Postcondition: If the table already had a record with a key equal to
//     entry.key, then that record is replaced by entry. Otherwise, entry has
//     been added as a new record of the table.
//
//   void remove(int key)
//     Postcondition: If a record was in the table with the specified key, then
//     that record has been removed; otherwise the table is unchanged.
//
// CONSTANT MEMBER FUNCTIONS for the DoubleHash<RecordType> class:
//   bool is_present(int key) const
//     Postcondition: The return value is true if there is a record in the
//     table with the specified key. Otherwise, the return value is false.
//
//   void find(int key, bool& found, RecordType& result) const
//     Postcondition: If a record is in the table with the specified key, then
//     found is true and result is set to a copy of the record with that key.
//     Otherwise found is false and the result contains garbage.
//
//    size_type size() const
//      Postcondition: Return value is the total number of records in the
//      table.
//
//  VALUE SEMANTICS for the DoubleHash<RecordType> template class:
//    Assignments and the copy constructor may be used with table objects.

#ifndef DOUBLE_HASH_H
#define DOUBLE_HASH_H

#include <cstdlib>    // Provides size_t
#include <cassert>    // Provides assert
#include <iomanip>    // Provides std::setw
#include <iostream>   // Provides std::cout

template <class RecordType>
class DoubleHash
{
public:
  // TYPEDEF
  typedef RecordType record_type;
  // MEMBER CONSTANT
  static const std::size_t CAPACITY = 19;  // basic_test
  // static const std::size_t CAPACITY = 811; // for submission
  // CONSTRUCTOR
  DoubleHash();
  DoubleHash(const DoubleHash& source);
  ~DoubleHash();
  DoubleHash& operator = (const DoubleHash& source);
  // MODIFICATION MEMBER FUNCTIONS
  void insert(const RecordType& entry);
  void remove(int key);
  // CONSTANT MEMBER FUNCTIONS
  bool is_present(int key) const;
  void find(int key, bool& found, RecordType& result) const;
  std::size_t size() const { return used; }
  std::size_t capacity() const { return CAPACITY; }
  std::size_t collision() const { return collisions; }
  // OVERLOAD OPERATOR FUNCTIONS
  template<class U>
  friend std::ostream& operator << (std::ostream& outs, const DoubleHash<U>& hash);
private:
  // MEMBER CONSTANTS -- These are used in the key field of special records.
  // this cell has never had a value
  static const int NEVER_USED = -1;
   // this cell has previously held a value that has since been deleted.
  static const int PREVIOUSLY_USED = -2;
  // MEMBER VARIABLES
  RecordType data[CAPACITY];
  std::size_t used;
  std::size_t collisions;
  // HELPER FUNCTIONS
  std::size_t hash(int key) const;
  std::size_t hash2(int key) const;
  std::size_t next_index(std::size_t index, int key) const;
  void find_index(int key, bool& found, std::size_t& index) const;
  bool never_used(std::size_t index) const;
  bool is_vacant(std::size_t index) const;
  void print_hash(std::ostream& outs = std::cout) const;
};  

// Implementation NON-MEMBER FUNCTIONS

template <class Item>
void print_item(const Item& data)
{
  std::cout << data;
}

// Implementation MEMBER FUNCTIONS


#endif // DOUBLE_HASH_H