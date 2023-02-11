#ifndef CHAINED_HASH_H
#define CHAINED_HASH_H

#include <cstdlib> // Provides size_t
#include <cassert> // Provides assert

#include "../avl_tree/avl_tree.h"

template <class RecordType>
class ChainedHash
{
public:
  // MEMBER CONSTANT
  static const std::size_t TABLE_SIZE = 811;
  // CONSTRUCTORS AND DESTRUCTOR
  ChainedHash();
  ChainedHash(const ChainedHash& source);
  ~ChainedHash();
  // MODIFICATION MEMBER FUNCTIONS
  bool insert(const RecordType& entry);
  bool remove(int key);
  void operator =(const ChainedHash& source);
  // CONSTANT MEMBER FUNCTIONS
  bool find(int key, bool& found, RecordType& result) const;
  bool is_present(int key) const;
  std::size_t size() const { return total_records; }
  // OVERLOAD OPERATOR FUNCTIONS
  template<class U>
  friend std::ostream& operator << (std::ostream& outs, const ChainedHash<U>& hash);
private:
  // MEMBER VARIABLES
  AVL<RecordType> data[TABLE_SIZE];
  std::size_t total_records;
  // HELPER MEMBER FUNCTION
  std::size_t hash(int key) const;
};

#endif // CHAINED_HASH_H