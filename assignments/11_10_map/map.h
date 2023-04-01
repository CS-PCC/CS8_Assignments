#ifndef MAP_H
#define MAP_H

#include <cstdlib>    // Provides std::size_t

#include "bplustree.h"
#include "pair.h"

template<typename K, typename V>
class Map
{
public:
  // TYPEDEFS and MEMBER CONSTANTS
  typedef BPlusTree<Pair<K, V>> map_base;
  // NESTED CLASS DEFINITION
  class Iterator
  {
  public:
    friend class Map;
    // CONSTRUCTORS
    Iterator(typename map_base::Iterator it);
    // OPERATORS
    Iterator operator ++ (int unused);
    Iterator operator ++ ();
    Pair<K, V> operator * ();
    friend bool operator == (const Iterator& lhs, const Iterator& rhs);
    friend bool operator != (const Iterator& lhs, const Iterator& rhs);
  private:
    typename map_base::Iterator _it;
  };

  // CONSTRUCTORS
  Map();
  // ITERATORS
  Iterator begin();
  Iterator end();
  // CAPACITY
  std::size_t size();
  std::size_t count() const;
  bool empty() const;
  // ELEMENT ACCESS
  V& operator [] (const K& key);
  const V& operator [] (const K& key) const;
  V& at(const K& key);
  const V& at(const K& key) const;
  // MODIFIERS
  void insert(const K& k, const V& v);
  void erase(const K& key);
  void clear();
  // OPERATIONS
  Iterator find(const K& key);
  bool contains(const Pair<K, V>& target) const;
  V get(const K& key);
  Iterator lower_bound(const K& key);
  Iterator upper_bound(const K& key);
  bool is_valid() { return map.is_valid(); }
  // OVERLOADED OPERATORS
  friend std::ostream& operator << (std::ostream& outs, const Map<K, V>& print_me) {
    outs << print_me.map << std::endl;
    return outs;
  }
private:
  BPlusTree<Pair<K, V>> map;
};

#endif // MAP_H