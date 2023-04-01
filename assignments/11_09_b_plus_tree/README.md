# B-Tree

- Accept [11_09_b_plus_tree](https://classroom.github.com/a/IDowRNpR)
- Get [basic_test.cpp](basic_test.cpp)

---

A B+ tree is an advanced form of a self-balancing tree in which all the values are present in the leaf level.

```
     |----|----|----|
     |    |    |    |  data[MAX+1]
   __|____|____|____|___
   |____|____|____|____|  subset[MAX+2]
    /     |    |     \
   /      |    |      \
  /       |    |       \
```

## 1. Implement Iterator class

Iterator class is an nested class of BPlusTree class.

## 2. Implement BPlusTree class

[BPlusTree class](bplustree.h) has tree operations:

- Search
- Insert
- Delete

### Implement Insert

```cpp
bool insert(const Item& entry);
bool loose_insert(const Item& entry);
void fix_excess(std::size_t i);
```

### Implement Search

```cpp
Iterator find(const Item& entry);
```

### Implement Delete

```cpp
bool erase(const Item& target);
bool loose_erase(const Item& target);
void fix_shortage(std::size_t i);
void delete_internal_node(std::size_t i, const Item& target, const Item& next_smallest);
void transfer_from_left(std::size_t i);
void transfer_from_right(std::size_t i);
void merge_with_next_subset(std::size_t i);
```
