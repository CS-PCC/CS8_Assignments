#include "gtest/gtest.h"
#include <cmath>
#include <iostream>
#include <iomanip>
#include <set>
#include <vector>

//------------------------------------------------------------------------------------------
//Files we are testing:
#include "../../includes/node/node.h"
#include "../../includes/linked_list_functions/linked_list_functions.h"
#include "../../includes/stack/MyStack.h"
#include "../../includes/queue/MyQueue.h"
//------------------------------------------------------------------------------------------

using namespace std;

bool test_linked_list_functions(bool debug = false)
{
  node<int>* head = nullptr;
  for (int i = 0; i < 5; i++) {
    _insert_head(head, (i+1) * 10);
  }
  _print_list(head);

  node<int> *inserted;
  node<int> *this_node;
  int n;

  cout << "\n=================== testing insert ===================" << endl;

  n = 30;
  this_node = _search_list(head, n);
  cout << "prev and next: " << endl;
  cout << "found : " << n << ": " << *this_node << endl;
  cout << "before: " << n << ": " << *(this_node->_prev) << endl;
  cout << "after : " << n << ": " << *(this_node->_next) << endl;

  cout << "\ninsert_after(): " << endl;
  inserted = _insert_after(head, this_node, n - 5);
  _print_list(head);
  cout << "inserted: " << *inserted << endl;
  cout << "before  : " << *(inserted->_prev) << endl;
  cout << "after   : " << *(inserted->_next) << endl;

  cout << "\ninsert_before()" << endl;
  inserted = _insert_before(head, this_node, n + 5);
  _print_list(head);
  cout << "inserted: " << *inserted << endl;
  cout << "before  : " << *(inserted->_prev) << endl;
  cout << "after   : " << *(inserted->_next) << endl;
  
  cout << "\n----------------------- \n\n";

  n = 50;
  this_node = _search_list(head, n);
  cout << "prev and next: " << endl;
  cout << "found : " << n << ": " << *this_node << endl;
  cout << "before: " << n << ": ";
  if (this_node->_prev)
    cout << *(this_node->_prev) << endl;
  else
    cout << "|||" << endl;
  cout << "after : " << n << ": " << *(this_node->_next) << endl;

  cout << "\ninsert_after(): " << endl;
  inserted = _insert_after(head, this_node, n - 5);
  _print_list(head);
  cout << "inserted: " << *inserted << endl;
  cout << "before  : ";
  if (inserted->_prev)
    cout << *(inserted->_prev) << endl;
  else
    cout << "|||" << endl;
  cout << "after   : " << *(inserted->_next) << endl;

  cout << "\ninsert_before()" << endl;
  inserted = _insert_before(head, this_node, n + 5);
  _print_list(head);
  cout << "inserted: " << *inserted << endl;
  cout << "before  : ";
  if (inserted->_prev)
    cout << *(inserted->_prev) << endl;
  else
    cout << "|||" << endl;
  cout << "after   : " << *(inserted->_next) << endl;
  
  cout << "\n----------------------- \n\n";

  n = 10;
  this_node = _search_list(head, n);
  cout << "prev and next: " << endl;
  cout << "found : " << n << ": " << *this_node << endl;
  cout << "before: " << n << ": " << *(this_node->_prev) << endl;
  cout << "after : " << n << ": ";
  if (this_node->_next)
    cout << *(this_node->_next) << endl;
  else
    cout << "|||" << endl;

  cout << "\ninsert_after(): " << endl;
  inserted = _insert_after(head, this_node, n - 5);
  _print_list(head);
  cout << "inserted: " << *inserted << endl;
  cout << "before  : " << *(inserted->_prev) << endl;
  cout << "after   : ";
  if (inserted->_next)
    cout << *(inserted->_next) << endl;
  else
    cout << "|||" << endl;

  cout << "\ninsert_before()" << endl;
  inserted = _insert_before(head, this_node, n + 5);
  _print_list(head);
  cout << "inserted: " << *inserted << endl;
  cout << "before  : " << *(inserted->_prev) << endl;
  cout << "after   : ";
  if (inserted->_next)
    cout << *(inserted->_next) << endl;
  else
    cout << "|||" << endl;


  cout << "\n======= testing delete =======================" << endl;

  this_node = _search_list(head, 55); //first element
  cout << "to delete : " << *this_node << endl;
  cout << "deleted   : " << _delete_node(head, this_node) << endl;
  _print_list(head);
  cout << endl;

  this_node = _search_list(head, 30); //middle element
  cout << "to delete : " << *this_node << endl;
  cout << "deleted   : " << _delete_node(head, this_node) << endl;
  _print_list(head);
  cout << endl;

  this_node = _search_list(head, 5); //last element
  cout << "to delete : " << *this_node << endl;
  cout << "deleted   : " << _delete_node(head, this_node) << endl;
  _print_list(head);
  cout << endl;

  cout << "\n----------------------- \n\n";

  return true;
}

bool test_queue(bool debug = false)
{
  Queue<int> q;
  for (int i = 0; i < 10; i++)
  {
    q.push(i * 10);
    cout << "queue: " << q;
  }
  cout << endl << endl;

  for(Queue<int>::Iterator it = q.begin(); it != q.end(); it++)
  {
    cout << "it->>" << *it << endl;
  }
  cout << endl << endl;

  cout << "popping queue: [" << setw(4) << " " << "]: ";
  cout << q;
  for (; !q.empty();)
  {
    cout << "popping queue: [" << setw(4) << q.front() << "]: ";
    q.pop();
    cout << q;
  }
  cout << endl << endl;

  Queue<int>::Iterator it = q.begin();
  cout << "Iterator is_null(): " << boolalpha << it.is_null() << endl;
  
  cout << "\n----------------------- \n\n";
  
  return true;
}

bool test_stack(bool debug = false)
{
  Stack<int> s;
  for (int i = 0; i < 10; i++)
  {
    s.push(i * 10);
    cout << "stack: " << s;
  }
  cout << endl << endl;

  for(Stack<int>::Iterator it = s.begin(); it != s.end(); it++)
  {
    cout << "it->>" << *it << endl;
  }
  cout << endl << endl;

  cout << "popping stack: [" << setw(4) << " " << "]: ";
  cout << s;
  for (; !s.empty();)
  {
    cout << "popping stack: [" << setw(4) << s.top() << "]: ";
    s.pop();
    cout << s;
  }
  cout << endl << endl;

  Stack<int>::Iterator it = s.begin();
  cout << "Iterator is_null(): " << boolalpha << it.is_null() << endl;

  cout << "\n----------------------- \n\n";
  
  return true;
}

//Lord help me! 
bool debug = false;

TEST(TEST_FUNCTIONS, TestLinkedListFunctions)
{
  bool success = test_linked_list_functions(true);
  EXPECT_EQ(success, true);
}

TEST(TEST_FUNCTIONS, TestQueue)
{
  bool success = test_queue(true);
  EXPECT_EQ(success, true);
}

TEST(TEST_FUNCTIONS, TestStack)
{
  bool success = test_stack(true);
  EXPECT_EQ(success, true);
}

int main(int argc, char **argv)
{
  if (argc>1) {
    debug = argv[1][0]=='t';
  }
  ::testing::InitGoogleTest(&argc, argv);
  std::cout<<"\n\n----------running basic_test.cpp---------\n\n"<<std::endl;
  return RUN_ALL_TESTS();
}


/*
includes
├── linked_list_functions
│   └── linked_list_functions.h
├── node
│   └── node.h
├── queue
│   └── queue.h
└── stack
    └── stack.h

4 directories, 4 files

----------running basic_test.cpp---------


[==========] Running 3 tests from 1 test suite.
[----------] Global test environment set-up.
[----------] 3 tests from TEST_FUNCTIONS
[ RUN      ] TEST_FUNCTIONS.TestLinkedListFunctions
Head-><-[50]-><-[40]-><-[30]-><-[20]-><-[10]->|||

=================== testing insert ===================
prev and next: 
found : 30: <-[30]->
before: 30: <-[40]->
after : 30: <-[20]->

insert_after(): 
Head-><-[50]-><-[40]-><-[30]-><-[25]-><-[20]-><-[10]->|||
inserted: <-[25]->
before  : <-[30]->
after   : <-[20]->

insert_before()
Head-><-[50]-><-[40]-><-[35]-><-[30]-><-[25]-><-[20]-><-[10]->|||
inserted: <-[35]->
before  : <-[40]->
after   : <-[30]->

----------------------- 

prev and next: 
found : 50: <-[50]->
before: 50: |||
after : 50: <-[40]->

insert_after(): 
Head-><-[50]-><-[45]-><-[40]-><-[35]-><-[30]-><-[25]-><-[20]-><-[10]->|||
inserted: <-[45]->
before  : <-[50]->
after   : <-[40]->

insert_before()
Head-><-[55]-><-[50]-><-[45]-><-[40]-><-[35]-><-[30]-><-[25]-><-[20]-><-[10]->|||
inserted: <-[55]->
before  : |||
after   : <-[50]->

----------------------- 

prev and next: 
found : 10: <-[10]->
before: 10: <-[20]->
after : 10: |||

insert_after(): 
Head-><-[55]-><-[50]-><-[45]-><-[40]-><-[35]-><-[30]-><-[25]-><-[20]-><-[10]-><-[5]->|||
inserted: <-[5]->
before  : <-[10]->
after   : |||

insert_before()
Head-><-[55]-><-[50]-><-[45]-><-[40]-><-[35]-><-[30]-><-[25]-><-[20]-><-[15]-><-[10]-><-[5]->|||
inserted: <-[15]->
before  : <-[20]->
after   : <-[10]->

======= testing delete =======================
to delete : <-[55]->
deleted   : 55
Head-><-[50]-><-[45]-><-[40]-><-[35]-><-[30]-><-[25]-><-[20]-><-[15]-><-[10]-><-[5]->|||

to delete : <-[30]->
deleted   : 30
Head-><-[50]-><-[45]-><-[40]-><-[35]-><-[25]-><-[20]-><-[15]-><-[10]-><-[5]->|||

to delete : <-[5]->
deleted   : 5
Head-><-[50]-><-[45]-><-[40]-><-[35]-><-[25]-><-[20]-><-[15]-><-[10]->|||


----------------------- 

[       OK ] TEST_FUNCTIONS.TestLinkedListFunctions (1 ms)
[ RUN      ] TEST_FUNCTIONS.TestQueue
queue: Head-><-[0]->|||
queue: Head-><-[0]-><-[10]->|||
queue: Head-><-[0]-><-[10]-><-[20]->|||
queue: Head-><-[0]-><-[10]-><-[20]-><-[30]->|||
queue: Head-><-[0]-><-[10]-><-[20]-><-[30]-><-[40]->|||
queue: Head-><-[0]-><-[10]-><-[20]-><-[30]-><-[40]-><-[50]->|||
queue: Head-><-[0]-><-[10]-><-[20]-><-[30]-><-[40]-><-[50]-><-[60]->|||
queue: Head-><-[0]-><-[10]-><-[20]-><-[30]-><-[40]-><-[50]-><-[60]-><-[70]->|||
queue: Head-><-[0]-><-[10]-><-[20]-><-[30]-><-[40]-><-[50]-><-[60]-><-[70]-><-[80]->|||
queue: Head-><-[0]-><-[10]-><-[20]-><-[30]-><-[40]-><-[50]-><-[60]-><-[70]-><-[80]-><-[90]->|||


it->>0
it->>10
it->>20
it->>30
it->>40
it->>50
it->>60
it->>70
it->>80
it->>90


popping queue: [    ]: Head-><-[0]-><-[10]-><-[20]-><-[30]-><-[40]-><-[50]-><-[60]-><-[70]-><-[80]-><-[90]->|||
popping queue: [   0]: Head-><-[10]-><-[20]-><-[30]-><-[40]-><-[50]-><-[60]-><-[70]-><-[80]-><-[90]->|||
popping queue: [  10]: Head-><-[20]-><-[30]-><-[40]-><-[50]-><-[60]-><-[70]-><-[80]-><-[90]->|||
popping queue: [  20]: Head-><-[30]-><-[40]-><-[50]-><-[60]-><-[70]-><-[80]-><-[90]->|||
popping queue: [  30]: Head-><-[40]-><-[50]-><-[60]-><-[70]-><-[80]-><-[90]->|||
popping queue: [  40]: Head-><-[50]-><-[60]-><-[70]-><-[80]-><-[90]->|||
popping queue: [  50]: Head-><-[60]-><-[70]-><-[80]-><-[90]->|||
popping queue: [  60]: Head-><-[70]-><-[80]-><-[90]->|||
popping queue: [  70]: Head-><-[80]-><-[90]->|||
popping queue: [  80]: Head-><-[90]->|||
popping queue: [  90]: Head->|||


Iterator is_null(): true

----------------------- 

[       OK ] TEST_FUNCTIONS.TestQueue (0 ms)
[ RUN      ] TEST_FUNCTIONS.TestStack
stack: Head-><-[0]->|||
stack: Head-><-[10]-><-[0]->|||
stack: Head-><-[20]-><-[10]-><-[0]->|||
stack: Head-><-[30]-><-[20]-><-[10]-><-[0]->|||
stack: Head-><-[40]-><-[30]-><-[20]-><-[10]-><-[0]->|||
stack: Head-><-[50]-><-[40]-><-[30]-><-[20]-><-[10]-><-[0]->|||
stack: Head-><-[60]-><-[50]-><-[40]-><-[30]-><-[20]-><-[10]-><-[0]->|||
stack: Head-><-[70]-><-[60]-><-[50]-><-[40]-><-[30]-><-[20]-><-[10]-><-[0]->|||
stack: Head-><-[80]-><-[70]-><-[60]-><-[50]-><-[40]-><-[30]-><-[20]-><-[10]-><-[0]->|||
stack: Head-><-[90]-><-[80]-><-[70]-><-[60]-><-[50]-><-[40]-><-[30]-><-[20]-><-[10]-><-[0]->|||


it->>90
it->>80
it->>70
it->>60
it->>50
it->>40
it->>30
it->>20
it->>10
it->>0


popping stack: [    ]: Head-><-[90]-><-[80]-><-[70]-><-[60]-><-[50]-><-[40]-><-[30]-><-[20]-><-[10]-><-[0]->|||
popping stack: [  90]: Head-><-[80]-><-[70]-><-[60]-><-[50]-><-[40]-><-[30]-><-[20]-><-[10]-><-[0]->|||
popping stack: [  80]: Head-><-[70]-><-[60]-><-[50]-><-[40]-><-[30]-><-[20]-><-[10]-><-[0]->|||
popping stack: [  70]: Head-><-[60]-><-[50]-><-[40]-><-[30]-><-[20]-><-[10]-><-[0]->|||
popping stack: [  60]: Head-><-[50]-><-[40]-><-[30]-><-[20]-><-[10]-><-[0]->|||
popping stack: [  50]: Head-><-[40]-><-[30]-><-[20]-><-[10]-><-[0]->|||
popping stack: [  40]: Head-><-[30]-><-[20]-><-[10]-><-[0]->|||
popping stack: [  30]: Head-><-[20]-><-[10]-><-[0]->|||
popping stack: [  20]: Head-><-[10]-><-[0]->|||
popping stack: [  10]: Head-><-[0]->|||
popping stack: [   0]: Head->|||


Iterator is_null(): true

----------------------- 

[       OK ] TEST_FUNCTIONS.TestStack (2 ms)
[----------] 3 tests from TEST_FUNCTIONS (3 ms total)

[----------] Global test environment tear-down
[==========] 3 tests from 1 test suite ran. (3 ms total)
[  PASSED  ] 3 tests.
*/