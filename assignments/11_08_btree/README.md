# B-Tree

- Accept [11_08_btree](https://classroom.github.com/a/kDZyYBYy)
- Get [basic_test.cpp](basic_test.cpp)

---

B-tree is a special type of self-balancing search tree in which each node can contain more than one key and can have more than two children.

```
     |----|----|----|
     |    |    |    |  data[MAX+1]
   __|____|____|____|___
   |____|____|____|____|  subset[MAX+2]
    /     |    |     \
   /      |    |      \
  /       |    |       \
```

## 1. Implement btree array functions

BTree class functions are heavily dependant on the utility [array functions](btree_array_functions.h) to do the low level moving of data and subtrees.

## 2. Implement BTree class

[BTree class](btree.h) has tree operations:

- Search
- Insert
- Delete

### Implement Search

```cpp
Item* find(const Item& entry);
```

### Implement Insert

```cpp
bool insert(const Item& entry);
bool loose_insert(const Item& entry);
void fix_excess(std::size_t i);
```

### Implement Print

```cpp
// Print the Bree in readable version
void print(int indent=0, std::ostream& outs = std::cout) const
{
  //1. print the last child (if any)
  //2. print all the rest of the data and children
}
```

### Implement Delete

```cpp
bool erase(const Item& target);
bool loose_erase(const Item& target);
void remove_biggest(Item& removed_entry);
void fix_shortage(std::size_t i);
void transfer_from_left(std::size_t i);
void transfer_from_right(std::size_t i);
void merge_with_next_subset(std::size_t i);
```
