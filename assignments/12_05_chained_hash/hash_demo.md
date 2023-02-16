# Hash Table Demonstration Program

This document is asking you to make demonstration of double and chain hash.


## Application

We will write an application that will demonstrate the functionality of these two classes:
1. double_hash
2. chained_hash

The application has two parts:
1. random test
2. interactive test

The `main` function may run a random test on `double_hash`, or `chained_hash` objects. Or allow the user to interact with either of the two objects.

To accomplish this, you need to implement two templated functions that take a generic hash table as argument. These functions will be called with an `double_hash` or `chained_hash` objects.

```cpp
template<typename T>
void test_hash_table_interactive(T hash);
template<typename T>
void test_hash_table_random(T& hash);
```

## Output

### Random Test

Your random test function will take a templed hash object (chained or double).

Set your table size back to 811.

Allocate an array of appropriate size and append random records to it. We want to know what keys have been inserted so we can search for existing keys AND nonexistent keys.

obviously, for double_hash test, you need a number below 811, say 500.

Insert these random records into the hash object

Then take half this amount (how_many/2) and pick random cells in the array and search for them in the object. Count the number of found records and the number of not_found records. For this test, the number of not_found records must be zero.

Then, generate the same number of keys making sure they are not in the array and search for these keys. The number of found records must be zero. 

Report the result of your test

Sample Run:

Here I am running both chained_hash and open_hash random tests:

```
********************************************************************************
                 R A N D O M   H A S H   T E S T: ChainedHash<HashRecord>
********************************************************************************
---- [1250] keys inserted.
---- size of hash: 1250


- - - - - - - - - Remove existing keys ----------------
Remove existing keys: 1250 keys to be removed:
EXISTING KEYS REMOVAL: VERIFIED. EXISTING KEYS EXAMINED: 1250


- - - - - - - - - Search for existing keys ----------------
Search for existing keys: 1250 keys to be tested:
EXISTING KEYS LOOKUP: VERIFIED. EXISTING KEYS EXAMINED: 1250


- - - - - - - - - Search for non-existing keys ----------------
Search for nonexistent keys: 1250 keys to be tested:
NONEXISTENT KEYS LOOKUP: VERIFIED. NONEXISTENT KEYS EXAMINED: 1250

------------------ END RANDOM TEST ----------------------


********************************************************************************
                 R A N D O M   H A S H   T E S T: DoubleHash<HashRecord>
********************************************************************************
---- [250] keys inserted.
---- size of hash: 250


- - - - - - - - - Remove existing keys ----------------
Remove existing keys: 250 keys to be removed:
EXISTING KEYS REMOVAL: VERIFIED. EXISTING KEYS EXAMINED: 250


- - - - - - - - - Search for existing keys ----------------
Search for existing keys: 250 keys to be tested:
EXISTING KEYS LOOKUP: VERIFIED. EXISTING KEYS EXAMINED: 250


- - - - - - - - - Search for non-existing keys ----------------
Search for nonexistent keys: 250 keys to be tested:
NONEXISTENT KEYS LOOKUP: VERIFIED. NONEXISTENT KEYS EXAMINED: 250

------------------ END RANDOM TEST ----------------------
```


### Interactive Test

When running this, an unreasonably small table would be more suitable (I used 17) since we require all the data in the tables to be displayed.

User will be presented with this menu:

```
[S]ize() [I]nsert [R]andom [D]elete [F]ind value [?]exists?   e[X]it  :
```

The user can insert a pair of numbers (key, value), delete a given key, find or test the existence of a key, get a report of how many keys are in the table or the most useful of all, insert a random record in the table. (the random record will obviously not work with a record of keys and strings)

NOTE: If the user attempts to delete a nonexistent key, the test function will report that the delete has failed. (the Remove function should return false if the removal has failed)

Once the user has made a choice, you will respond accordingly and will use the hash object's insertion operator to print the entire table with useful information:


#### Sample Interactive Run: double_hash

```
-------  INTERACTIVE TESTS ---------------------------
Table of {int:double}
/*
 * After each operation, tell the user what you did:
 * e.g: 9272:2231 has been INSERTED.
 */

[S]ize() [I]nsert [R]andom [D]elete [F]ind value [?]exists?   e[X]it  :r
9272:2231 has been INSERTED.
[000]  
[001]  
[002]  
[003]  
[004]  
[005]  
[006]  
[007] 9272:2231(007) 
[008]  
[009]  
[010]  
[011]  
[012]  
[013]  
[014]  
[015]  
[016]  


[S]ize() [I]nsert [R]andom [D]elete [F]ind value [?]exists?   e[X]it  :r
7733:1077 has been INSERTED.
[000]  
[001]  
[002]  
[003]  
[004]  
[005]  
[006]  
[007] 9272:2231(007) 
[008]  
[009]  
[010]  
[011]  
[012]  
[013]  
[014]  
[015] 7733:1077(015) 
[016]  


[S]ize() [I]nsert [R]andom [D]elete [F]ind value [?]exists?   e[X]it  :r
4755:4919 has been INSERTED.
[000]  
[001]  
[002]  
[003]  
[004]  
[005]  
[006]  
[007] 9272:2231(007) 
[008]  
[009]  
[010]  
[011]  
[012] 4755:4919(012) 
[013]  
[014]  
[015] 7733:1077(015) 
[016]  

/*
 * Collisions:
 * when there is a collision, put a star next to the record:
 *     the hash code for the key does not match the index
 *     at which it is stored.
 */
[S]ize() [I]nsert [R]andom [D]elete [F]ind value [?]exists?   e[X]it  :r
4908:7544 has been INSERTED.
[000]  
[001]  
[002]  
[003]  
[004]  
[005]  
[006]  
[007] 9272:2231(007) 
[008]  
[009]  
[010]  
[011]  
[012] 4755:4919(012) 
[013] 4908:7544(012) *
[014]  
[015] 7733:1077(015) 
[016]  


[S]ize() [I]nsert [R]andom [D]elete [F]ind value [?]exists?   e[X]it  :r
9135:1852 has been INSERTED.
[000]  
[001]  
[002]  
[003]  
[004]  
[005]  
[006] 9135:1852(006) 
[007] 9272:2231(007) 
[008]  
[009]  
[010]  
[011]  
[012] 4755:4919(012) 
[013] 4908:7544(012) *
[014]  
[015] 7733:1077(015) 
[016]  


[S]ize() [I]nsert [R]andom [D]elete [F]ind value [?]exists?   e[X]it  :r
1408:4397 has been INSERTED.
[000]  
[001]  
[002]  
[003]  
[004]  
[005]  
[006] 9135:1852(006) 
[007] 9272:2231(007) 
[008]  
[009]  
[010]  
[011]  
[012] 4755:4919(012) 
[013] 4908:7544(012) *
[014] 1408:4397(014) 
[015] 7733:1077(015) 
[016]  


[S]ize() [I]nsert [R]andom [D]elete [F]ind value [?]exists?   e[X]it  :r
8592:6345 has been INSERTED.
[000]  
[001]  
[002]  
[003]  
[004]  
[005]  
[006] 9135:1852(006) 
[007] 9272:2231(007) 
[008] 8592:6345(007) *
[009]  
[010]  
[011]  
[012] 4755:4919(012) 
[013] 4908:7544(012) *
[014] 1408:4397(014) 
[015] 7733:1077(015) 
[016]  


[S]ize() [I]nsert [R]andom [D]elete [F]ind value [?]exists?   e[X]it  :r
9453:8696 has been INSERTED.
[000]  
[001] 9453:8696(001) 
[002]  
[003]  
[004]  
[005]  
[006] 9135:1852(006) 
[007] 9272:2231(007) 
[008] 8592:6345(007) *
[009]  
[010]  
[011]  
[012] 4755:4919(012) 
[013] 4908:7544(012) *
[014] 1408:4397(014) 
[015] 7733:1077(015) 
[016]  


[S]ize() [I]nsert [R]andom [D]elete [F]ind value [?]exists?   e[X]it  :i 7 42
>>7:2 has been INSERTED.
[000]  
[001] 9453:8696(001) 
[002]  
[003]  
[004]  
[005]  
[006] 9135:1852(006) 
[007] 9272:2231(007) 
[008] 8592:6345(007) *
[009] 0007:0002(007) *
[010]  
[011]  
[012] 4755:4919(012) 
[013] 4908:7544(012) *
[014] 1408:4397(014) 
[015] 7733:1077(015) 
[016]  


[S]ize() [I]nsert [R]andom [D]elete [F]ind value [?]exists?   e[X]it  :d 9135
>>9135 was REMOVED.
[000]  
[001] 9453:8696(001) 
[002]  
[003]  
[004]  
[005]  
[006] - - - - - - 
[007] 9272:2231(007) 
[008] 8592:6345(007) *
[009] 0007:0002(007) *
[010]  
[011]  
[012] 4755:4919(012) 
[013] 4908:7544(012) *
[014] 1408:4397(014) 
[015] 7733:1077(015) 
[016]  

/*
 * if a cell is PREVIOUSLY_USED, mark it with a line of dashes
 */
[S]ize() [I]nsert [R]andom [D]elete [F]ind value [?]exists?   e[X]it  :d 9272   
>>9272 was REMOVED.
[000]  
[001] 9453:8696(001) 
[002]  
[003]  
[004]  
[005]  
[006] - - - - - - 
[007] - - - - - - 
[008] 8592:6345(007) *
[009] 0007:0002(007) *
[010]  
[011]  
[012] 4755:4919(012) 
[013] 4908:7544(012) *
[014] 1408:4397(014) 
[015] 7733:1077(015) 
[016]  


[S]ize() [I]nsert [R]andom [D]elete [F]ind value [?]exists?   e[X]it  :f 9272
>>9272 NOT FOUND
[000]  
[001] 9453:8696(001) 
[002]  
[003]  
[004]  
[005]  
[006] - - - - - - 
[007] - - - - - - 
[008] 8592:6345(007) *
[009] 0007:0002(007) *
[010]  
[011]  
[012] 4755:4919(012) 
[013] 4908:7544(012) *
[014] 1408:4397(014) 
[015] 7733:1077(015) 
[016]  


[S]ize() [I]nsert [R]andom [D]elete [F]ind value [?]exists?   e[X]it  :f 7
>>7:2
[000]  
[001] 9453:8696(001) 
[002]  
[003]  
[004]  
[005]  
[006] - - - - - - 
[007] - - - - - - 
[008] 8592:6345(007) *
[009] 0007:0002(007) *
[010]  
[011]  
[012] 4755:4919(012) 
[013] 4908:7544(012) *
[014] 1408:4397(014) 
[015] 7733:1077(015) 
[016]  


[S]ize() [I]nsert [R]andom [D]elete [F]ind value [?]exists?   e[X]it  :f 4755
>>4755:4919
[000]  
[001] 9453:8696(001) 
[002]  
[003]  
[004]  
[005]  
[006] - - - - - - 
[007] - - - - - - 
[008] 8592:6345(007) *
[009] 0007:0002(007) *
[010]  
[011]  
[012] 4755:4919(012) 
[013] 4908:7544(012) *
[014] 1408:4397(014) 
[015] 7733:1077(015) 
[016]  


[S]ize() [I]nsert [R]andom [D]elete [F]ind value [?]exists?   e[X]it  :? 1408
>>1408 EXISTS.
[000]  
[001] 9453:8696(001) 
[002]  
[003]  
[004]  
[005]  
[006] - - - - - - 
[007] - - - - - - 
[008] 8592:6345(007) *
[009] 0007:0002(007) *
[010]  
[011]  
[012] 4755:4919(012) 
[013] 4908:7544(012) *
[014] 1408:4397(014) 
[015] 7733:1077(015) 
[016]  


[S]ize() [I]nsert [R]andom [D]elete [F]ind value [?]exists?   e[X]it  :d 1408
>>1408 was REMOVED.
[000]  
[001] 9453:8696(001) 
[002]  
[003]  
[004]  
[005]  
[006] - - - - - - 
[007] - - - - - - 
[008] 8592:6345(007) *
[009] 0007:0002(007) *
[010]  
[011]  
[012] 4755:4919(012) 
[013] 4908:7544(012) *
[014] - - - - - - 
[015] 7733:1077(015) 
[016]  


[S]ize() [I]nsert [R]andom [D]elete [F]ind value [?]exists?   e[X]it  :r
7201:8569 has been INSERTED.
[000]  
[001] 9453:8696(001) 
[002]  
[003]  
[004]  
[005]  
[006] - - - - - - 
[007] - - - - - - 
[008] 8592:6345(007) *
[009] 0007:0002(007) *
[010] 7201:8569(010) 
[011]  
[012] 4755:4919(012) 
[013] 4908:7544(012) *
[014] - - - - - - 
[015] 7733:1077(015) 
[016]  


[S]ize() [I]nsert [R]andom [D]elete [F]ind value [?]exists?   e[X]it  :r
8342:2211 has been INSERTED.
[000]  
[001] 9453:8696(001) 
[002]  
[003]  
[004]  
[005]  
[006] - - - - - - 
[007] - - - - - - 
[008] 8592:6345(007) *
[009] 0007:0002(007) *
[010] 7201:8569(010) 
[011]  
[012] 4755:4919(012) 
[013] 4908:7544(012) *
[014] 8342:2211(012) *
[015] 7733:1077(015) 
[016]  


[S]ize() [I]nsert [R]andom [D]elete [F]ind value [?]exists?   e[X]it  :r
6095:1343 has been INSERTED.
[000]  
[001] 9453:8696(001) 
[002]  
[003]  
[004]  
[005]  
[006] - - - - - - 
[007] - - - - - - 
[008] 8592:6345(007) *
[009] 0007:0002(007) *
[010] 7201:8569(010) 
[011] 6095:1343(009) *
[012] 4755:4919(012) 
[013] 4908:7544(012) *
[014] 8342:2211(012) *
[015] 7733:1077(015) 
[016]  


[S]ize() [I]nsert [R]andom [D]elete [F]ind value [?]exists?   e[X]it  :r
8912:12 has been INSERTED.
[000]  
[001] 9453:8696(001) 
[002]  
[003]  
[004] 8912:0012(004) 
[005]  
[006] - - - - - - 
[007] - - - - - - 
[008] 8592:6345(007) *
[009] 0007:0002(007) *
[010] 7201:8569(010) 
[011] 6095:1343(009) *
[012] 4755:4919(012) 
[013] 4908:7544(012) *
[014] 8342:2211(012) *
[015] 7733:1077(015) 
[016]  


[S]ize() [I]nsert [R]andom [D]elete [F]ind value [?]exists?   e[X]it  :r
877:6201 has been INSERTED.
[000]  
[001] 9453:8696(001) 
[002]  
[003]  
[004] 8912:0012(004) 
[005]  
[006] - - - - - - 
[007] - - - - - - 
[008] 8592:6345(007) *
[009] 0007:0002(007) *
[010] 7201:8569(010) 
[011] 6095:1343(009) *
[012] 4755:4919(012) 
[013] 4908:7544(012) *
[014] 8342:2211(012) *
[015] 7733:1077(015) 
[016] 0877:6201(010) *

/*
 * Primary Clustering: Note how the two numbers with hash of 7
 *            caused the number with hash of 9 to be misplaced. In 
 *            larger scale projects, this is a real problem.
 */
[S]ize() [I]nsert [R]andom [D]elete [F]ind value [?]exists?   e[X]it  :r
4706:7240 has been INSERTED.
[000] 4706:7240(014) *
[001] 9453:8696(001) 
[002]  
[003]  
[004] 8912:0012(004) 
[005]  
[006] - - - - - - 
[007] - - - - - - 
[008] 8592:6345(007) *
[009] 0007:0002(007) *
[010] 7201:8569(010) 
[011] 6095:1343(009) *
[012] 4755:4919(012) 
[013] 4908:7544(012) *
[014] 8342:2211(012) *
[015] 7733:1077(015) 
[016] 0877:6201(010) *


[S]ize() [I]nsert [R]andom [D]elete [F]ind value [?]exists?   e[X]it  :r
6479:762 has been INSERTED.
[000] 4706:7240(014) *
[001] 9453:8696(001) 
[002] 6479:0762(002) 
[003]  
[004] 8912:0012(004) 
[005]  
[006] - - - - - - 
[007] - - - - - - 
[008] 8592:6345(007) *
[009] 0007:0002(007) *
[010] 7201:8569(010) 
[011] 6095:1343(009) *
[012] 4755:4919(012) 
[013] 4908:7544(012) *
[014] 8342:2211(012) *
[015] 7733:1077(015) 
[016] 0877:6201(010) *


[S]ize() [I]nsert [R]andom [D]elete [F]ind value [?]exists?   e[X]it  :r
4968:2387 has been INSERTED.
[000] 4706:7240(014) *
[001] 9453:8696(001) 
[002] 6479:0762(002) 
[003]  
[004] 8912:0012(004) 
[005] 4968:2387(004) *
[006] - - - - - - 
[007] - - - - - - 
[008] 8592:6345(007) *
[009] 0007:0002(007) *
[010] 7201:8569(010) 
[011] 6095:1343(009) *
[012] 4755:4919(012) 
[013] 4908:7544(012) *
[014] 8342:2211(012) *
[015] 7733:1077(015) 
[016] 0877:6201(010) *


[S]ize() [I]nsert [R]andom [D]elete [F]ind value [?]exists?   e[X]it  :r
7427:6289 has been INSERTED.
[000] 4706:7240(014) *
[001] 9453:8696(001) 
[002] 6479:0762(002) 
[003] 7427:6289(015) *
[004] 8912:0012(004) 
[005] 4968:2387(004) *
[006] - - - - - - 
[007] - - - - - - 
[008] 8592:6345(007) *
[009] 0007:0002(007) *
[010] 7201:8569(010) 
[011] 6095:1343(009) *
[012] 4755:4919(012) 
[013] 4908:7544(012) *
[014] 8342:2211(012) *
[015] 7733:1077(015) 
[016] 0877:6201(010) *


[S]ize() [I]nsert [R]andom [D]elete [F]ind value [?]exists?   e[X]it  :x
D O N E .




---------------------------------
Press <RETURN> to close this window...
```

#### Sample Interactive Run: chained_hash

This method will avoid the problem of Primary Clustering: 

```
-------  INTERACTIVE TESTS ---------------------------
Table of {int:double}
[000] |||
[001] |||
[002] |||
[003] |||
[004] |||
[005] |||
[006] |||
[007] |||
[008] |||
[009] |||
[010] |||
[011] |||
[012] |||
[013] |||
[014] |||
[015] |||
[016] |||


[S]ize() [I]nsert [R]andom [D]elete [F]ind value [?]exists?   e[X]it  :rrrrrrrrr
8448:9784 has been INSERTED.
[000] |||
[001] |||
[002] |||
[003] |||
[004] |||
[005] |||
[006] |||
[007] |||
[008] |||
[009] |||
[010] |||
[011] |||
[012] |||
[013] |||
[014] |||
[015] |||
[016] [8448:9784]-> |||


[S]ize() [I]nsert [R]andom [D]elete [F]ind value [?]exists?   e[X]it  :1607:9530 has been INSERTED.
[000] |||
[001] |||
[002] |||
[003] |||
[004] |||
[005] |||
[006] |||
[007] |||
[008] |||
[009] [1607:9530]-> |||
[010] |||
[011] |||
[012] |||
[013] |||
[014] |||
[015] |||
[016] [8448:9784]-> |||


[S]ize() [I]nsert [R]andom [D]elete [F]ind value [?]exists?   e[X]it  :2369:2904 has been INSERTED.
[000] |||
[001] |||
[002] |||
[003] |||
[004] |||
[005] |||
[006] [2369:2904]-> |||
[007] |||
[008] |||
[009] [1607:9530]-> |||
[010] |||
[011] |||
[012] |||
[013] |||
[014] |||
[015] |||
[016] [8448:9784]-> |||


[S]ize() [I]nsert [R]andom [D]elete [F]ind value [?]exists?   e[X]it  :270:2516 has been INSERTED.
[000] |||
[001] |||
[002] |||
[003] |||
[004] |||
[005] |||
[006] [2369:2904]-> |||
[007] |||
[008] |||
[009] [1607:9530]-> |||
[010] |||
[011] |||
[012] |||
[013] |||
[014] |||
[015] [270:2516]-> |||
[016] [8448:9784]-> |||


[S]ize() [I]nsert [R]andom [D]elete [F]ind value [?]exists?   e[X]it  :7913:6780 has been INSERTED.
[000] |||
[001] |||
[002] |||
[003] |||
[004] |||
[005] |||
[006] [2369:2904]-> |||
[007] |||
[008] [7913:6780]-> |||
[009] [1607:9530]-> |||
[010] |||
[011] |||
[012] |||
[013] |||
[014] |||
[015] [270:2516]-> |||
[016] [8448:9784]-> |||


[S]ize() [I]nsert [R]andom [D]elete [F]ind value [?]exists?   e[X]it  :3556:2761 has been INSERTED.
[000] |||
[001] |||
[002] |||
[003] [3556:2761]-> |||
[004] |||
[005] |||
[006] [2369:2904]-> |||
[007] |||
[008] [7913:6780]-> |||
[009] [1607:9530]-> |||
[010] |||
[011] |||
[012] |||
[013] |||
[014] |||
[015] [270:2516]-> |||
[016] [8448:9784]-> |||


[S]ize() [I]nsert [R]andom [D]elete [F]ind value [?]exists?   e[X]it  :3061:1864 has been INSERTED.
[000] |||
[001] [3061:1864]-> |||
[002] |||
[003] [3556:2761]-> |||
[004] |||
[005] |||
[006] [2369:2904]-> |||
[007] |||
[008] [7913:6780]-> |||
[009] [1607:9530]-> |||
[010] |||
[011] |||
[012] |||
[013] |||
[014] |||
[015] [270:2516]-> |||
[016] [8448:9784]-> |||


[S]ize() [I]nsert [R]andom [D]elete [F]ind value [?]exists?   e[X]it  :3980:9301 has been INSERTED.
[000] |||
[001] [3061:1864]-> |||
[002] [3980:9301]-> |||
[003] [3556:2761]-> |||
[004] |||
[005] |||
[006] [2369:2904]-> |||
[007] |||
[008] [7913:6780]-> |||
[009] [1607:9530]-> |||
[010] |||
[011] |||
[012] |||
[013] |||
[014] |||
[015] [270:2516]-> |||
[016] [8448:9784]-> |||


[S]ize() [I]nsert [R]andom [D]elete [F]ind value [?]exists?   e[X]it  :5449:3694 has been INSERTED.
[000] |||
[001] [3061:1864]-> |||
[002] [3980:9301]-> |||
[003] [3556:2761]-> |||
[004] |||
[005] |||
[006] [2369:2904]-> |||
[007] |||
[008] [7913:6780]-> |||
[009] [5449:3694]-> [1607:9530]-> |||
[010] |||
[011] |||
[012] |||
[013] |||
[014] |||
[015] [270:2516]-> |||
[016] [8448:9784]-> |||


[S]ize() [I]nsert [R]andom [D]elete [F]ind value [?]exists?   e[X]it  :r
2502:3474 has been INSERTED.
[000] |||
[001] [3061:1864]-> |||
[002] [3980:9301]-> |||
[003] [2502:3474]-> [3556:2761]-> |||
[004] |||
[005] |||
[006] [2369:2904]-> |||
[007] |||
[008] [7913:6780]-> |||
[009] [5449:3694]-> [1607:9530]-> |||
[010] |||
[011] |||
[012] |||
[013] |||
[014] |||
[015] [270:2516]-> |||
[016] [8448:9784]-> |||


[S]ize() [I]nsert [R]andom [D]elete [F]ind value [?]exists?   e[X]it  :r
7864:3177 has been INSERTED.
[000] |||
[001] [3061:1864]-> |||
[002] [3980:9301]-> |||
[003] [2502:3474]-> [3556:2761]-> |||
[004] |||
[005] |||
[006] [2369:2904]-> |||
[007] |||
[008] [7913:6780]-> |||
[009] [5449:3694]-> [1607:9530]-> |||
[010] [7864:3177]-> |||
[011] |||
[012] |||
[013] |||
[014] |||
[015] [270:2516]-> |||
[016] [8448:9784]-> |||


[S]ize() [I]nsert [R]andom [D]elete [F]ind value [?]exists?   e[X]it  :rr
4868:1768 has been INSERTED.
[000] |||
[001] [3061:1864]-> |||
[002] [3980:9301]-> |||
[003] [2502:3474]-> [3556:2761]-> |||
[004] |||
[005] |||
[006] [4868:1768]-> [2369:2904]-> |||
[007] |||
[008] [7913:6780]-> |||
[009] [5449:3694]-> [1607:9530]-> |||
[010] [7864:3177]-> |||
[011] |||
[012] |||
[013] |||
[014] |||
[015] [270:2516]-> |||
[016] [8448:9784]-> |||


[S]ize() [I]nsert [R]andom [D]elete [F]ind value [?]exists?   e[X]it  :5013:779 has been INSERTED.
[000] |||
[001] [3061:1864]-> |||
[002] [3980:9301]-> |||
[003] [2502:3474]-> [3556:2761]-> |||
[004] |||
[005] |||
[006] [4868:1768]-> [2369:2904]-> |||
[007] |||
[008] [7913:6780]-> |||
[009] [5449:3694]-> [1607:9530]-> |||
[010] [7864:3177]-> |||
[011] |||
[012] |||
[013] |||
[014] |||
[015] [5013:779]-> [270:2516]-> |||
[016] [8448:9784]-> |||


[S]ize() [I]nsert [R]andom [D]elete [F]ind value [?]exists?   e[X]it  :d 270
>>270 was REMOVED.
[000] |||
[001] [3061:1864]-> |||
[002] [3980:9301]-> |||
[003] [2502:3474]-> [3556:2761]-> |||
[004] |||
[005] |||
[006] [4868:1768]-> [2369:2904]-> |||
[007] |||
[008] [7913:6780]-> |||
[009] [5449:3694]-> [1607:9530]-> |||
[010] [7864:3177]-> |||
[011] |||
[012] |||
[013] |||
[014] |||
[015] [5013:779]-> |||
[016] [8448:9784]-> |||


[S]ize() [I]nsert [R]andom [D]elete [F]ind value [?]exists?   e[X]it  :f 1607
>>1607:9530
[000] |||
[001] [3061:1864]-> |||
[002] [3980:9301]-> |||
[003] [2502:3474]-> [3556:2761]-> |||
[004] |||
[005] |||
[006] [4868:1768]-> [2369:2904]-> |||
[007] |||
[008] [7913:6780]-> |||
[009] [5449:3694]-> [1607:9530]-> |||
[010] [7864:3177]-> |||
[011] |||
[012] |||
[013] |||
[014] |||
[015] [5013:779]-> |||
[016] [8448:9784]-> |||


[S]ize() [I]nsert [R]andom [D]elete [F]ind value [?]exists?   e[X]it  :?8448
>>8448 EXISTS.
[000] |||
[001] [3061:1864]-> |||
[002] [3980:9301]-> |||
[003] [2502:3474]-> [3556:2761]-> |||
[004] |||
[005] |||
[006] [4868:1768]-> [2369:2904]-> |||
[007] |||
[008] [7913:6780]-> |||
[009] [5449:3694]-> [1607:9530]-> |||
[010] [7864:3177]-> |||
[011] |||
[012] |||
[013] |||
[014] |||
[015] [5013:779]-> |||
[016] [8448:9784]-> |||


[S]ize() [I]nsert [R]andom [D]elete [F]ind value [?]exists?   e[X]it  :?42
>>42 DOES NOT EXIST.
[000] |||
[001] [3061:1864]-> |||
[002] [3980:9301]-> |||
[003] [2502:3474]-> [3556:2761]-> |||
[004] |||
[005] |||
[006] [4868:1768]-> [2369:2904]-> |||
[007] |||
[008] [7913:6780]-> |||
[009] [5449:3694]-> [1607:9530]-> |||
[010] [7864:3177]-> |||
[011] |||
[012] |||
[013] |||
[014] |||
[015] [5013:779]-> |||
[016] [8448:9784]-> |||


[S]ize() [I]nsert [R]andom [D]elete [F]ind value [?]exists?   e[X]it  :x
D O N E .



---------------------------------
Press <RETURN> to close this window...
```