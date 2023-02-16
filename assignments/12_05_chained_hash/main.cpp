#include <iostream>
#include <iomanip>
#include <vector>
#include <unordered_set>

#include "includes/hash/chained_hash.h"
#include "includes/hash/double_hash.h"
#include "includes/hash/hash_record.h"

using namespace std;

static std::string GetHashName(DoubleHash<HashRecord> h) {return string("DoubleHash<HashRecord>");}
static std::string GetHashName(ChainedHash<HashRecord> h) {return string("ChainedHash<HashRecord>");}

int random(int low, int high);
string to_string(const HashRecord& h);
template<typename T>
void test_hash_table_interactive(T hash);
template<typename T>
void test_hash_table_random(T& hash);

int main()
{
  cout << "\n\n\n----------------------\n\n\n";

  const bool RANDOM_CHAINED = true;
  const bool RANDOM_DOUBLE = true;
  const bool INTERACTIVE_DOUBLE = false;
  const bool INTERACTIVE_CHAINED = false;
  
  if (INTERACTIVE_DOUBLE)
  {
    cout << "-------  INTERACTIVE TESTS ---------------------------" << endl;
    DoubleHash<HashRecord> double_hash;
    test_hash_table_interactive(double_hash);
  }

  if (INTERACTIVE_CHAINED)
  {
    cout<<"-------  INTERACTIVE TESTS ---------------------------"<<endl;
    ChainedHash<HashRecord> chained_hash;
    test_hash_table_interactive(chained_hash);
  }

  if (RANDOM_CHAINED)
  {
    //----------- RANDOM TEST ------------------------------
    //. . . . . .  Chained Hash Table . . . . . . . . . . .;
    ChainedHash<HashRecord> c_table;
    test_hash_table_random(c_table);
    // cout << c_table << endl;
  }

  if (RANDOM_DOUBLE)
  {
    //----------- RANDOM TEST ------------------------------
    //. . . . . .  Simple Hash Table . . . . . . . . . . .;
    DoubleHash<HashRecord> h_table;
    test_hash_table_random(h_table);
    // cout << h_table << endl;
  }

  cout << "\n\n\n----------------------\n\n\n";

  return 0;
}

int random(int low, int high)
{
  //call srand in main if you want better random numbers.
  return static_cast<int>(low + (rand() % static_cast<int>((high - low + 1))));
}

//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
//We will need a function like this for any class/struct that will specialize 
//      the AVL class. (for use in the AVL's 
//      pre_order(), in_order(), post_order() functions)
string to_string(const HashRecord& h)
{
  return string(to_string(h.key) + " : " + h.item);
}
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 


// TODO
template<typename T>
void test_hash_table_interactive(T hash);

template<typename T>
void test_hash_table_random(T& hash);
