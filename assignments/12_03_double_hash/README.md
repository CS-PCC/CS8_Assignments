# Double Hash

- Accept [12_03_double_hash](https://classroom.github.com/a/vlsjJCAk)
- Get [basic_test.cpp](basic_test.cpp)

---

Double hashing is if a collision occurs after applying a hash function h(k), then another hash function is calculated for finding the next slot.

```cpp
hash = key % CAPACITY;
hash2 = 1 + (key % (CAPACITY - 2));
next_hash = (index + hash2(key)) % CAPACITY;
```

1. Implement `DoubleHash` class in [double_hash.h](double_hash.h)
2. Do NOT modify [hash_record.h](hash_record.h) file. `HashRecord` is a type of object is going to store into hash table. The `ChainedHash` object will never make reference to the `item` field of the `HashRecord` structure. You may only assume the `HashRecord` used will have a `key` field.
3. Toggle the following line between basic_test and submit to github

```cpp
static const std::size_t CAPACITY = 19;  // basic_test
static const std::size_t CAPACITY = 811; // for submission
```
