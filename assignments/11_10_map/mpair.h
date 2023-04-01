#ifndef MPAIR_H
#define MPAIR_H

#include <cstdlib>    // Provides std::size_t
#include <vector>     // Provides std::vector

template <typename K, typename V>
struct MPair
{
  K key;
  std::vector<V> value_list;

  //--------------------------------------------------------------------------------
  /*      MPair CTORs:
   *  must have these CTORs:
   *  - default CTOR / CTOR with a key and no value: this will create an empty vector
   *  - CTOR with a key AND a value: pushes the value into the value_list
   *  - CTOR with a key and a vector of values (to replace value_list)
   */
  //--------------------------------------------------------------------------------
  MPair(const K& k=K());
  MPair(const K& k, const V& v);
  MPair(const K& k, const std::vector<V>& vlist);
  //--------------------------------------------------------------------------------

  // Overloaded operators
  friend std::ostream& operator << (std::ostream& outs, const MPair<K, V>& print_me);
  friend bool operator == (const MPair<K, V>& lhs, const MPair<K, V>& rhs);
  friend bool operator < (const MPair<K, V>& lhs, const MPair<K, V>& rhs);
  friend bool operator <= (const MPair<K, V>& lhs, const MPair<K, V>& rhs);
  friend bool operator > (const MPair<K, V>& lhs, const MPair<K, V>& rhs);
  friend MPair<K, V> operator + (MPair<K, V>& lhs, const MPair<K, V>& rhs);
};

#endif // MPAIR_H