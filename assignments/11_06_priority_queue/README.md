# Priority Queue

- Accept [11_06_priority_queue](https://classroom.github.com/a/Ufo-GSTI)
- Get [basic_test.cpp](basic_test.cpp)

---

A priority queue is a structure that keeps the largest element handy so that when it is popped, it will remove the largest item. Comparisons between items is usually done on a structure with a member variable representing the priority of the item. A heap is the traditional data structure used to implement a priority queue.

1. Implement `Heap` class in `heap.h`
2. Implement `info` structure in `info.h`
3. Implement `PQueue` class in `pqueue.h`
4. Test implementations by creating more complicated trees in `testB.cpp` file.


## The info struct

The templated info struct is the data to be saved in priority queue. You need to overload the comparison operators: less than and the greater than.

```cpp
template <typename T>
struct info
{
  T item;
  int priority;

  info() : item(T()), priority(0) {}
  info(T i, int p) : item(i), priority(p) {}

  friend ostream& operator << (ostream& outs, const info<T>& print_me) {
    const bool tldr = true;
    outs << print_me.item;
    if (!tldr) outs << " priority: " << print_me.priority << endl;
    return outs;
  }

  friend bool operator < (const info<T>& lhs, const info<T>& rhs) {}

  friend bool operator > (const info<T>& lhs, const info<T>& rhs) {}
};
```

## The PQueue class

Priority queue use a heap to be the underlie data structure with the templated info structure.

The PQueue class functions rely on Heap class.

```cpp
template <typename T>
class PQueue
{
public:
  // CONSTRUCTOR
  PQueue() {}
  // MODIFICATION MEMBER FUNCTIONS
  void push(const T& value, int p);
  void pop();
  T top();
  // CONST MEMBER FUNCTIONS
  bool empty() const;
  int size() const;
  void print_tree() const;
  bool verify() const;
  // OVERLOAD OPERATOR FUNCTIONS
  friend ostream& operator << (ostream& outs, const PQueue<T>& print_me) {
    outs << print_me._heap;
    return outs;
  }
private:
  Heap<info<T>> _heap;
};
```

Using a random generating function push 100 elements into the queue and then pop and print them. The items should show print in descending order of info priority:

```cpp
PQueue<int> pq;
for (int i = 0; i<100; i++)
{
  pq.insert(Random(1,1000), Random(1,10));
}
```

As you see, the user end (test program) knows nothing of the info structure.
