# Chained Hash

- Accept [12_05_chained_hash](https://classroom.github.com/a/HNUiIZuU)
- Get [basic_test.cpp](basic_test.cpp)

---

In chaining, if a hash function produces the same index for multiple elements, these elements are stored in the same index by using an AVL tree.

```cpp
hash = key % CAPACITY;
```

1. Implement `ChainedHash` class in [chained_hash.h](chained_hash.h)
2. Toggle the following line between basic_test and submit to github

```cpp
static const std::size_t TABLE_SIZE = 19;  // basic_test
static const std::size_t TABLE_SIZE = 811; // for submission
```

### [Hash Demo](hash_demo.md)
