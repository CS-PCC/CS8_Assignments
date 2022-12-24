# Doubly Linked list

- Accept [08_01_doubly_linkedlist](https://classroom.github.com/a/m-KEoqnZ)
- Get [basic_test.cpp](basic_test.cpp)

---

Build a Stack and a Queue class based on the doubly linked list.

**NO** `linked list code` should be visible inside Stack and a Queue classes. If you need something done, call a function.

## Iterators

Iterators are classes that encapsulate pointers. We wrap a pointer we want to be protected in an Iterator and in doing so, we control how the pointer will be used and in what context and we decide what to allow and disallow in the use of this pointer. 

Once the Iterator is in place, we will not be thinking of pointers, only Iterators. Iterators allow you to traverse data structures (such as linked lists) safely and without worrying about the calling function altering the nodes because they only get an iterator and not a pointer.


## Nested Classes
Please see [A Simple Iterator (Nested Classes)](https://docs.google.com/document/d/1hZQyeSlvRJq8xhVYjJklljzhKJxa5q0ByKfnydfKKKc/edit?usp=sharing) for an explanation of nested classes


## Node

```c++
#ifndef NODE_H 
#define NODE_H 

#include <iostream> 

using namespace std;
 
template <typename T>
struct node
{
public:
    node(const T& item = T(), node* next = nullptr);

    template <typename U>
    friend ostream& operator <<(ostream& outs, const node<U> &printMe);

    T _item;
    node* _next;
    node* _prev;
};

// Definition 

// TODO 

#endif // NODE_H 
```


## Linked List functions

```c++
#ifndef LINKED_LIST_FUNCTIONS_H
#define LINKED_LIST_FUNCTIONS_H

#include <cassert>

#include "../node/node.h"

using namespace std;

// Declaration
//Linked List General Functions:
template <typename T>
void _print_list(node<T>* head);

//recursive fun! :)
template <typename T>
void _print_list_backwards(node<T>* head);

//return ptr to key or NULL
template <typename T>
node<T>* _search_list(node<T>* head, T key);

template <typename T>
node<T>* _insert_head(node<T>* &head, T insert_this);

//insert after ptr
template <typename T>
node<T>* _insert_after(node<T>* &head, node<T>* after_this, T insert_this);

//insert before ptr
template <typename T>
node<T>* _insert_before(node<T>* &head, node<T>* before_this, T insert_this);

//ptr to previous node
template <typename T>
node<T>* _previous_node(node<T>* head, node<T>* prev_to_this);

//delete, return item
template <typename T>
T _delete_node(node<T>* &head, node<T>* delete_this);

//duplicate the list
template <typename T>
node<T>* _copy_list(node<T>* head);

//duplicate list and return the last node of the copy
template <typename T>
node<T>* _copy_list(node<T>* &dest, node<T>* src);

//delete all the nodes
template <typename T>
void _clear_list(node<T>* &head);

//_item at this position
template <typename T>
T& _at(node<T>* head, int pos);

//Last node in the list, never use this function.
template <typename T>
node<T>* _last_node(node<T>* head);

// Definition

// TODO

#endif // LINKED_LIST_FUNCTIONS_H
```


## Stack

```c++
#ifndef MYSTACK_H
#define MYSTACK_H

#include <iostream>
#include <iomanip>

#include "../linked_list_functions/linked_list_functions.h"

using namespace std;

template <typename T>
class Stack
{
public:
  class Iterator
  {
  public:
    //Give access to list to access _ptr
    friend class Stack;

    //Default CTOR
    Iterator(){ }
    //Point Iterator to where p is pointing to
    Iterator(node<T>* p){ }

    //Casting operator: true if _ptr not NULL
    //This turned out to be a pain!
    operator bool() { }
    
    //dereference operator
    T& operator *(){ }               
    //member access operator
    T* operator ->(){ }
    //true if _ptr is NULL
    bool is_null(){ }   

    //true if left != right
    friend bool operator !=(const Iterator &left, const Iterator &right){ }
    //true if left == right
    friend bool operator ==(const Iterator &left, const Iterator &right){ }

    //member operator:  ++it; or ++it = new_value
    Iterator& operator ++(){ }
    //friend operator: it++
    friend Iterator operator ++(Iterator &it, int unused){ }
    
  private:
    node<T>* _ptr; //pointer being encapsulated
  };

  //constructor: CTOR
  Stack();

  //BIG 3:
  Stack(const Stack<T>& copyMe);
  ~Stack();
  Stack<T>& operator =(const Stack<T>& RHS);

  //Operations:
  void push(T item);
  void pop();

  //Accessors:
  Iterator begin() const;            //Iterator to the head node
  Iterator end() const;              //Iterator to NULL

  //Checkers:
  int size() const;
  bool empty();
  T top();

  template<typename U>
  friend ostream& operator <<(ostream& outs, const Stack<U>& printMe);

private:
  node<T>* _top;
  int _size;
};

//Definition

//TODO

#endif // MYSTACK_H
```


## Queue

```c++
#ifndef MYQUEUE_H
#define MYQUEUE_H

#include <iostream>
#include <iomanip>

#include "../linked_list_functions/linked_list_functions.h"

using namespace std;

template <typename T>
class Queue
{
public:
  class Iterator
  {
  public:
    //Give access to list to access _ptr
    friend class Queue;

    //Default CTOR
    Iterator(){ }
    //Point Iterator to where p is pointing to
    Iterator(node<T>* p){ }

    //Casting operator: true if _ptr not NULL
    //This turned out to be a pain!
    operator bool() { }

    //dereference operator
    T& operator *(){ }  
    //member access operator
    T* operator ->(){ }
    //true if _ptr is NULL
    bool is_null(){ }   

    //true if left != right
    friend bool operator !=(const Iterator &left, const Iterator &right){ }
    //true if left == right
    friend bool operator ==(const Iterator &left, const Iterator &right){ }

    //member operator:  ++it; or ++it = new_value
    Iterator& operator ++(){ }                 
    //friend operator: it++
    friend Iterator operator ++(Iterator &it, int unused){ }

  private:
    node<T>* _ptr; //pointer being encapsulated
  };

  //constructor: CTOR
  Queue();

  //BIG 3:
  Queue(const Queue<T>& copyMe);
  ~Queue();
  Queue<T>& operator =(const Queue<T>& RHS);

  //Operations:
  void push(T item);                  //Enqueue
  void pop();                         //Dequeue

  //Accessors:
  Iterator begin() const;             //Iterator to the head node
  Iterator end() const;               //Iterator to NULL

  //Checkers:
  int size() const;
  bool empty();
  T front();
  T back();

  template<typename U>
  friend ostream& operator <<(ostream& outs, const Queue<U>& printMe);
  
private:
  node<T>* _front;
  node<T>* _rear;
  int _size;
};


//Definition

//TODO

#endif //MYQUEUE_H
```