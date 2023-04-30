#include "gtest/gtest.h"
#include <iostream>
#include <iomanip>

//------------------------------------------------------------------------------
//Files we are testing:
#include "../../includes/map/map.h"
#include "../../includes/map/mmap.h"
#include "../../includes/map/btree_array_functions.h"

//------------------------------------------------------------------------------

using namespace std;

//------------------------------------------------------------------------------
//          COPY BASIC_TEST INTO THIS FILE.
//                    AND THEN,
//         DO NOT EDIT THIS FILE ANY FURTHER
//------------------------------------------------------------------------------

const string LINE = "\n"+string(50,'-')+"\n";
const string DASH = "\n"+string(50,'.')+"\n";

bool test_map(bool debug=false)
{
  // Initialize
  int keys[] = {43, 20, 96, 100, 69};
  string values[] = {"430", "200", "960", "1000", "690"};
  size_t n = sizeof(keys) / sizeof(keys[0]);
  Map<int, string> map;
  Map<int, string>::Iterator it;
  // Add elements to the map
  for (size_t i = 0; i < n; i++) {
    map[keys[i]] = values[i];
  }
  // Print the map
  cout << LINE << endl << map << DASH << endl;
  for (size_t i = 0; i < n; i++) {
    cout << "map[" << keys[i] << "]: " << map[keys[i]] << endl;
  }
  // Test the [] operator
  for (size_t i = 0; i < n; i++) {
    map[keys[i]] = to_string(keys[i]*10+1);
  }
  // Print the map
  cout << LINE << endl << map << DASH << endl;
  for (size_t i = 0; i < n; i++) {
    cout << "map[" << keys[i] << "]: " << map[keys[i]] << endl;
  }
  // Test the insert() function
  cout << LINE << endl;
  cout << "insert() test" << endl;
  cout << LINE << endl;
  // Add elements to the map using insert()
  map.insert(10, "102");
  map.insert(70, "702");
  map.insert(110, "1102");
  // Print the map
  cout << map;

  // Test the erase() function
  cout << LINE << endl;
  cout << "erase() test" << endl;
  cout << LINE << endl;
  // Remove elements from the map using erase()
  map.erase(10);
  map.erase(96);
  cout << map;
  // Test the iterator
  cout << LINE << endl;
  cout << "iterator / range test" << endl;
  cout << LINE << endl;
  // Print the map using an iterator
  for (it = map.begin(); it != map.end(); it++) {
    cout << *it << " | ";
  }
  cout << endl;
  for (it = map.begin(); it != map.end(); ++it) {
    cout << *it << " | ";
  }
  cout << endl;
  cout << DASH << endl;
  cout << "iterator equality test" << endl;
  if (map.find(20) == map.find(20)) {
    cout << "find(20) == find(20)" << endl;
  }
  if (map.find(20) != map.find(43)) {
    cout << "find(20) != find(43)" << endl;
  }
  if (map.find(20) != map.find(42)) {
    cout << "find(20) != find(42)" << endl;
  }
  cout << DASH << endl;
  // Test get()
  cout << "get(): " << endl;
  cout << "key: 20, value: " << map.get(20) << endl;
  map.get(20) = "2500";
  cout << "key: 20, value: " << map.get(20) << endl;
  // Test lower_bound()
  cout << LINE << endl;
  cout << "lower_bound(): greater or equal to" << endl;
  it = map.lower_bound(10);
  cout << "lower_bound(10): " << *it << endl;
  it = map.lower_bound(20);
  cout << "lower_bound(20): " << *it << endl;
  it = map.lower_bound(42);
  cout << "lower_bound(42): " << *it << endl;
  it = map.lower_bound(150);
  if (it != map.end())
    cout << "lower_bound(150): " << *it << endl;
  else
    cout << "lower_bound(150): " <<  "NULL"  << endl;
  // Test upper_bound()
  cout << DASH << endl;
  cout << "upper_bound(): greater than" << endl;
  it = map.upper_bound(10);
  cout << "upper_bound(10): " << *it << endl;
  it = map.upper_bound(20);
  cout << "upper_bound(20): " << *it << endl;
  it = map.upper_bound(42);
  cout << "upper_bound(42): " << *it << endl;
  it = map.upper_bound(150);
  if (it != map.end())
    cout << "upper_bound(150): " << *it << endl;
  else
    cout << "upper_bound(150): " <<  "NULL"  << endl;
  // Test other functions
  cout << LINE << endl;
  cout << "Other functions" << endl;
  cout << LINE << endl;
  cout << "size():            " << map.size() << endl;
  cout << "count():           " << map.count() << endl;
  cout << "empty():           " << boolalpha << map.empty() << endl;
  cout << "map.at(20):        " << map.at(20) << endl;
  cout << "map.get(20):       " << map.get(20) << endl;
  cout << "map.find(43):      " << *map.find(43) << endl;
  cout << "map.contains(45):  " << boolalpha << map.contains(45) << endl;
  cout << "map.contains(100): " << boolalpha << map.contains(100) << endl;
  cout << "map.contains(150): " << boolalpha << map.contains(150) << endl;
  cout << "map.is_valid():    " << map.is_valid() << endl;
  map.clear();
  cout << "map.clear()        " << boolalpha << map.empty() << endl;
  
  cout << LINE << endl;

  return true;
}

bool test_multimap(bool debug=false)
{
  // Initialize
  int keys[] = {43, 20, 96, 100, 69};
  string values[] = {"430", "200", "960", "1000", "690"};
  size_t n = sizeof(keys) / sizeof(keys[0]);
  MMap<int, string> mmap;
  MMap<int, string>::Iterator it;
  // Add elements to the map using the [] operator
  for (size_t i = 0; i < n; i++) {
    mmap[keys[i]] += values[i];
  }
  // Print the map
  cout << LINE << endl << mmap << DASH << endl;
  for (size_t i = 0; i < n; i++) {
    cout << "mmap[" << keys[i] << "]: " << mmap[keys[i]] << endl;
  }
  // Add more elements to the array of same key
  for (size_t i = 0; i < n; i++) {
    mmap[keys[i]] += to_string(keys[i]*10+1);
  }
  for (size_t i = 0; i < n; i++) {
    mmap[keys[i]] += to_string(keys[i]*10+3);
  }
  // Print the map
  cout << LINE << endl << mmap << DASH << endl;
  for (size_t i = 0; i < n; i++) {
    cout << "mmap[" << keys[i] << "]: " << mmap[keys[i]] << endl;
  }
  cout << endl;
  // Test the insert() function
  cout << LINE << endl;
  cout << "insert() test" << endl;
  cout << LINE << endl;
  // Add elements to the map using insert()
  mmap.insert(10, "100");
  mmap.insert(10, "101");
  mmap.insert(70, "700");
  mmap.insert(80, "800");
  // Print the map
  cout << mmap;
  // Test the erase() function
  cout << LINE << endl;
  cout << "erase() test" << endl;
  cout << LINE << endl;
  // Erase elements from the map using erase()
  mmap.erase(10);
  mmap.erase(69);
  // Print the map
  cout << mmap;
  // Test the iterator
  cout << LINE << endl;
  cout << "iterator / range test" << endl;
  cout << LINE << endl;
  // Print the map using the iterator
  for (it = mmap.begin(); it != mmap.end(); it++) {
    cout << *it << " | ";
  }
  cout << endl;
  for (it = mmap.begin(); it != mmap.end(); ++it) {
    cout << *it << " | ";
  }
  cout << endl;
  cout << DASH << endl;
  cout << "iterator equality test" << endl;
  if (mmap.find(20) == mmap.find(20)) {
    cout << "find(20) == find(20)" << endl;
  }
  if (mmap.find(20) != mmap.find(43)) {
    cout << "find(20) != find(43)" << endl;
  }
  if (mmap.find(20) != mmap.find(42)) {
    cout << "find(20) != find(42)" << endl;
  }
  cout << DASH << endl;
  // Test get()
  cout << "get(): " << endl;
  cout << "key: 20, value: " << mmap.get(20) << endl;
  mmap.get(20).push_back("2500");
  cout << "key: 20, value: " << mmap.get(20) << endl;
  // Test lower_bound()
  cout << LINE << endl;
  cout << "lower_bound(): equal or greater than" << endl;
  it = mmap.lower_bound(10);
  cout << "lower_bound(10): " << *it << endl;
  it = mmap.lower_bound(20);
  cout << "lower_bound(20): " << *it << endl;
  it = mmap.lower_bound(42);
  cout << "lower_bound(42): " << *it << endl;
  it = mmap.lower_bound(150);
  if (it != mmap.end())
    cout << "lower_bound(150): " << *it << endl;
  else
    cout << "lower_bound(150): " <<  "NULL"  << endl;
  // Test upper_bound()
  cout << DASH << endl;
  cout << "upper_bound(): greater than" << endl;
  it = mmap.upper_bound(10);
  cout << "upper_bound(10): " << *it << endl;
  it = mmap.upper_bound(20);
  cout << "upper_bound(20): " << *it << endl;
  it = mmap.upper_bound(42);
  cout << "upper_bound(42): " << *it << endl;
  it = mmap.upper_bound(150);
  if (it != mmap.end())
    cout << "upper_bound(150): " << *it << endl;
  else
    cout << "upper_bound(150): " <<  "NULL"  << endl;
  // Test other functions
  cout << LINE << endl;
  cout << "Other functions" << endl;
  cout << LINE << endl;
  cout << "size():             " << mmap.size() << endl;
  cout << "size_list():        " << mmap.size_list() << endl;
  cout << "count():            " << mmap.count() << endl;
  cout << "empty():            " << boolalpha << mmap.empty() << endl;
  cout << "mmap.at(20):        " << mmap.at(20) << endl;
  cout << "mmap.get(20):       " << mmap.get(20) << endl;
  cout << "mmap.find(43):      " << *mmap.find(43) << endl;
  cout << "mmap.contains(45):  " << boolalpha << mmap.contains(45) << endl;
  cout << "mmap.contains(100): " << boolalpha << mmap.contains(100) << endl;
  cout << "mmap.contains(150): " << boolalpha << mmap.contains(150) << endl;
  cout << "mmap.is_valid():    " << mmap.is_valid() << endl;
  mmap.clear();
  cout << "mmap.clear()        " << boolalpha << mmap.empty() << endl;

  cout << LINE << endl;

  return true;
}

//Lord help me! 
const bool debug = false;

TEST(BASIC_TEST, TestMap)
{
  EXPECT_TRUE(test_map(debug));
}

TEST(BASIC_TEST, TestMultiMap)
{
  EXPECT_TRUE(test_multimap(debug));
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  std::cout<<"\n\n----------running basic_test.cpp---------\n\n"<<std::endl;
  return RUN_ALL_TESTS();
}


/*
includes
└── map
    ├── bplustree.h
    ├── btree_array_functions.h
    ├── map.h
    ├── mmap.h
    ├── mpair.h
    └── pair.h

1 directory, 6 files


----------running basic_test.cpp---------


[==========] Running 2 tests from 1 test suite.
[----------] Global test environment set-up.
[----------] 2 tests from BASIC_TEST
[ RUN      ] BASIC_TEST.TestMap

--------------------------------------------------

    ﹇
    100 : 1000
    96 : 960
    ﹈
﹇
96 : 960
    ^
    ﹇
    69 : 690
    43 : 430
    ﹈
43 : 430
﹈
    ^
    ﹇
    20 : 200
    ﹈


..................................................

map[43]: 430
map[20]: 200
map[96]: 960
map[100]: 1000
map[69]: 690

--------------------------------------------------

    ﹇
    100 : 1001
    96 : 961
    ﹈
﹇
96 : 960
    ^
    ﹇
    69 : 691
    43 : 431
    ﹈
43 : 430
﹈
    ^
    ﹇
    20 : 201
    ﹈


..................................................

map[43]: 431
map[20]: 201
map[96]: 961
map[100]: 1001
map[69]: 691

--------------------------------------------------

insert() test

--------------------------------------------------

        ﹇
        110 : 1102
        100 : 1001
        ﹈
    ﹇
    100 : 1001
        ^
        ﹇
        96 : 961
        ﹈
    96 : 960
    ﹈
        ^
        ﹇
        70 : 702
        69 : 691
        ﹈
﹇
69 : 691
﹈
        ^
        ﹇
        43 : 431
        ﹈
    ﹇
    43 : 430
    ﹈
        ^
        ﹇
        20 : 201
        10 : 102
        ﹈


--------------------------------------------------

erase() test

--------------------------------------------------

        ﹇
        110 : 1102
        100 : 1001
        ﹈
    ﹇
    100 : 1001
        ^
        ﹇
        70 : 702
        ﹈
    70 : 702
    ﹈
        ^
        ﹇
        69 : 691
        ﹈
﹇
69 : 691
﹈
        ^
        ﹇
        43 : 431
        ﹈
    ﹇
    43 : 430
    ﹈
        ^
        ﹇
        20 : 201
        ﹈


--------------------------------------------------

iterator / range test

--------------------------------------------------

20 : 201 | 43 : 431 | 69 : 691 | 70 : 702 | 100 : 1001 | 110 : 1102 | 
20 : 201 | 43 : 431 | 69 : 691 | 70 : 702 | 100 : 1001 | 110 : 1102 | 

..................................................

iterator equality test
find(20) == find(20)
find(20) != find(43)
find(20) != find(42)

..................................................

get(): 
key: 20, value: 201
key: 20, value: 201

--------------------------------------------------

lower_bound(): greater or equal to
lower_bound(10): 20 : 201
lower_bound(20): 20 : 201
lower_bound(42): 43 : 431
lower_bound(150): NULL

..................................................

upper_bound(): greater than
upper_bound(10): 20 : 201
upper_bound(20): 43 : 431
upper_bound(42): 43 : 431
upper_bound(150): NULL

--------------------------------------------------

Other functions

--------------------------------------------------

size():            6
count():           10
empty():           false
map.at(20):        201
map.get(20):       201
map.find(43):      43 : 431
map.contains(45):  false
map.contains(100): true
map.contains(150): false
map.is_valid():    true
map.clear()        true

--------------------------------------------------

[       OK ] BASIC_TEST.TestMap (0 ms)
[ RUN      ] BASIC_TEST.TestMultiMap

--------------------------------------------------

    ﹇
    100 : [1000]
    96 : [960]
    ﹈
﹇
96 : [960]
    ^
    ﹇
    69 : [690]
    43 : [430]
    ﹈
43 : [430]
﹈
    ^
    ﹇
    20 : [200]
    ﹈


..................................................

mmap[43]: 430 
mmap[20]: 200 
mmap[96]: 960 
mmap[100]: 1000 
mmap[69]: 690 

--------------------------------------------------

    ﹇
    100 : [1000 1001 1003]
    96 : [960 961 963]
    ﹈
﹇
96 : [960]
    ^
    ﹇
    69 : [690 691 693]
    43 : [430 431 433]
    ﹈
43 : [430]
﹈
    ^
    ﹇
    20 : [200 201 203]
    ﹈


..................................................

mmap[43]: 430 431 433 
mmap[20]: 200 201 203 
mmap[96]: 960 961 963 
mmap[100]: 1000 1001 1003 
mmap[69]: 690 691 693 


--------------------------------------------------

insert() test

--------------------------------------------------

        ﹇
        100 : [1000 1001 1003]
        96 : [960 961 963]
        ﹈
    ﹇
    96 : [960]
        ^
        ﹇
        80 : [800]
        70 : [700]
        ﹈
    70 : [700]
    ﹈
        ^
        ﹇
        69 : [690 691 693]
        ﹈
﹇
69 : [690 691 693]
﹈
        ^
        ﹇
        43 : [430 431 433]
        ﹈
    ﹇
    43 : [430]
    ﹈
        ^
        ﹇
        20 : [200 201 203]
        10 : [100 101]
        ﹈


--------------------------------------------------

erase() test

--------------------------------------------------

        ﹇
        100 : [1000 1001 1003]
        96 : [960 961 963]
        ﹈
    ﹇
    96 : [960]
        ^
        ﹇
        80 : [800]
        ﹈
    80 : [800]
    ﹈
        ^
        ﹇
        70 : [700]
        ﹈
﹇
70 : [700]
﹈
        ^
        ﹇
        43 : [430 431 433]
        ﹈
    ﹇
    43 : [430]
    ﹈
        ^
        ﹇
        20 : [200 201 203]
        ﹈


--------------------------------------------------

iterator / range test

--------------------------------------------------

20 : [200 201 203] | 43 : [430 431 433] | 70 : [700] | 80 : [800] | 96 : [960 961 963] | 100 : [1000 1001 1003] | 
20 : [200 201 203] | 43 : [430 431 433] | 70 : [700] | 80 : [800] | 96 : [960 961 963] | 100 : [1000 1001 1003] | 

..................................................

iterator equality test
find(20) == find(20)
find(20) != find(43)
find(20) != find(42)

..................................................

get(): 
key: 20, value: 200 201 203 
key: 20, value: 200 201 203 2500 

--------------------------------------------------

lower_bound(): equal or greater than
lower_bound(10): 20 : [200 201 203 2500]
lower_bound(20): 20 : [200 201 203 2500]
lower_bound(42): 43 : [430 431 433]
lower_bound(150): NULL

..................................................

upper_bound(): greater than
upper_bound(10): 20 : [200 201 203 2500]
upper_bound(20): 43 : [430 431 433]
upper_bound(42): 43 : [430 431 433]
upper_bound(150): NULL

--------------------------------------------------

Other functions

--------------------------------------------------

size():             6
size_list():        15
count():            10
empty():            false
mmap.at(20):        200 201 203 2500 
mmap.get(20):       200 201 203 2500 
mmap.find(43):      43 : [430 431 433]
mmap.contains(45):  false
mmap.contains(100): true
mmap.contains(150): false
mmap.is_valid():    true
mmap.clear()        true

--------------------------------------------------

[       OK ] BASIC_TEST.TestMultiMap (0 ms)
[----------] 2 tests from BASIC_TEST (1 ms total)

[----------] Global test environment tear-down
[==========] 2 tests from 1 test suite ran. (1 ms total)
[  PASSED  ] 2 tests.
*/