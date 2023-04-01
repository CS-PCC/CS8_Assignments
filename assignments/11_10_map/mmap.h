#ifndef MMAP_H
#define MMAP_H

#include <cstdlib>    // Provides std::size_t

#include "bplustree.h"
#include "mpair.h"

template <typename K, typename V>
class MMap
{
public:
  // TYPEDEFS and MEMBER CONSTANTS
  typedef BPlusTree<MPair<K, V>> map_base;
  // NESTED CLASS DEFINITION
  class Iterator
  {
  public:
    friend class MMap;
    // CONSTRUCTORS
    Iterator(typename map_base::Iterator it);
    // OPERATORS
    Iterator operator ++ (int unused);
    Iterator operator ++ ();
    MPair<K, V> operator * ();
    friend bool operator == (const Iterator& lhs, const Iterator& rhs);
    friend bool operator != (const Iterator& lhs, const Iterator& rhs);
  private:
      typename map_base::Iterator _it;
  };

  // CONSTRUCTORS
  MMap();
  // ITERATORS
  Iterator begin();
  Iterator end();
  // CAPACITY
  std::size_t size();
  std::size_t size_list();
  std::size_t count() const;
  bool empty() const;
  // ELEMENT ACCESS
  const std::vector<V>& operator [] (const K& key) const;
  std::vector<V>& operator [] (const K& key);
  std::vector<V>& at(const K& key);
  const std::vector<V>& at(const K& key) const;
  // MODIFIERS
  void insert(const K& k, const V& v);
  void erase(const K& key);
  void clear();
  // OPERATIONS
  Iterator find(const K& key);
  bool contains(const K& key) const;
  std::vector<V>& get(const K& key);
  Iterator lower_bound(const K& key);
  Iterator upper_bound(const K& key);
  bool is_valid() { return mmap.is_valid(); }
  // OVERLOADED OPERATORS
  friend std::ostream& operator << (std::ostream& outs, const MMap<K, V>& print_me) {
    outs << print_me.mmap << std::endl;
    return outs;
  }
private:
  BPlusTree<MPair<K, V>> mmap;
};

#endif // MMAP_H