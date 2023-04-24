#ifndef TABLE_H
#define TABLE_H

#include <iostream> // cout, endl
#include <iomanip>  // setw
#include <fstream>  // fstream
#include <string>   // string
#include <cassert>  // assert
#include <vector>   // vector
#include <cstring>  // strcmp

#include "../binary_files/file_record.h"
#include "../binary_files/utilities.h"

#include "../linked_list/queue/MyQueue.h"

#include "../map/map.h"
#include "../map/mmap.h"

#include "../rpn/rpn.h"
#include "../shunting_yard/shunting_yard.h"

#include "../token/leftparen.h"
#include "../token/logical.h"
#include "../token/universal.h"
#include "../token/relational.h"
#include "../token/rightparen.h"
#include "../token/tokenstr.h"

//======================================
// TODO: include more lib here as needed
//======================================

class Table
{
public:
  // TYPEDEFS
  typedef vector<string> vector_str;
  typedef vector<long> vector_long;
  typedef Map<string, long> map_sl;
  typedef Map<string, string> map_ss;
  typedef MMap<string, long> mmap_sl;
  typedef MMap<string, string> mmap_ss;
  // CONSTRUCTORS
  Table(const string& title = string(), const vector<string>& fields = vector<string>());
  // SQL: CREATE TABLE
  string create_table(const string& title, const vector<string>& fields);
  // SQL: INSERT INTO
  string insert_into(const vector<char*>& record);
  string insert_into(const vector<string>& row); 
  // SQL: SELECT
  Table select(const vector<string>& fields, const string& lhs, const string& op, const string& rhs);
  Table select(const vector<string>& fields, const vector<string>& expression = vector<string>());
  Table select(const vector<string>& fields, const Queue<Token*>& expression);
  // Get all selected record numbers
  vector<long> select_recnos() const { return _selected; }
  // Print table
  friend ostream& operator << (ostream& outs, const Table& t);
  // Get the title of the table
  string title() const { return _title; }
  // Get the fields of the table
  vector<string> get_fields();
  // Get the number of records in the table
  long record_count() const;
  //======================================
  // TODO: add more methods here as needed
  //======================================
private:
  // title of the table
  string _title;
  // fields of the table
  vector<string> _fields;
  // number of records in the table
  long _n_records;
  // selected records' numbers
  vector<long> _selected;
  //===========================================
  // TODO: add more data members here as needed
  //===========================================
};

#endif // TABLE_H