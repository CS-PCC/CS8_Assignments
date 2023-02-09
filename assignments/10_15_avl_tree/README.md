# AVL Tree

- Accept [10_15_avl_tree](https://classroom.github.com/a/ja-m8p3s)
- Get [basic_test.cpp](basic_test.cpp)

---

1. Implement `AVL` class in `avl_tree.h`
  - Rename `BST` class to `AVL`
1. Implement three **rotation** non-member functions.
2. Test implementations by creating more complicated trees in `testB.cpp` file.

Note: The value in AVL should be unique!


## Rotation Functions

```cpp
// ---------------- ROTATIONS ----------------
template <class Item>
binary_tree_node<Item>* rotate_right(binary_tree_node<Item>* root);
template <class Item>
binary_tree_node<Item>* rotate_left(binary_tree_node<Item>* root);
// decide which rotate is needed based on balance factor
template <class Item>
binary_tree_node<Item>* rotate(binary_tree_node<Item>* root);
```
