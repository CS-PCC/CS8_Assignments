#ifndef PAIR_H
#define PAIR_H

template <typename K, typename V>
struct Pair
{
  K key;
  V value;

  Pair(const K& k=K(), const V& v=V());
  friend std::ostream& operator << (std::ostream& outs, const Pair<K, V>& print_me);
  friend bool operator == (const Pair<K, V>& lhs, const Pair<K, V>& rhs);
  friend bool operator < (const Pair<K, V>& lhs, const Pair<K, V>& rhs);
  friend bool operator > (const Pair<K, V>& lhs, const Pair<K, V>& rhs);
  friend bool operator <= (const Pair<K, V>& lhs, const Pair<K, V>& rhs);
  friend Pair<K, V> operator + (const Pair<K, V>& lhs, const Pair<K, V>& rhs);
};

#endif // PAIR_H