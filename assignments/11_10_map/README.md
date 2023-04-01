# Map and MultiMap

- Accept [11_10_map](https://classroom.github.com/a/eykGidsN)
- Get [basic_test.cpp](basic_test.cpp)

---

## 1. Implement Map class

Map is a way to store a key-value pair

[Map](map.h) is implemented by BPlusTree containing [Pair](pair.h) of key and value.

## 2. Implement MultiMap class

Multimap can store more than one value against a key.

[MultiMap](mmap.h) is implemented by BPlusTree containing [MultiPair](mpair.h) of key and value list.

### About Multimap Subscript Operator []

The MMap subscript operator returns a reference to the vector associated with the key.

In the const version of the operator, the underlying const get function will assert that the key is in the Tree. In the non_cost version, the underlying get function will add a new node with the key and an empty vector.

NOTE: Accessing the non-existent elements of an empty array crashes the program. So, if you need to print or access values of a key, make sure the key exists in your tree.

```cpp
cout << "read key G: " << m["G"] << endl;

//  reading a non_existent key will crash without warning.
//  we will need to deal with this.
//  perhaps the operator that will take m["Z"] 
//  (operator << in this example) can verify that 
//  it is not an empty vector. 

// cout << "read non_existent key Z: " << m["Z"] << endl;

cout << "add 99 to the non_existent key Z: ";
m["Z"]+=99; //returns a reference to an empty vector to which we are pushing back
            // the value 99 could also use m["Z"].push_back(99);

cout << m["Z"]; 

// or simply:
cout << "add 99 to the non_existent key Z: " << (m["Z"]+=99) << endl; //could also push_back
```
