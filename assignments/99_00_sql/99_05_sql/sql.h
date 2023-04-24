#ifndef SQL_H
#define SQL_H

#include <iostream> // cout, endl
#include <fstream>  // ifstream
#include <cassert>  // assert

#include "../../includes/parser/parser.h"
#include "../../includes/table/table.h"
#include "../../includes/map/mmap.h"

using namespace std;

class SQL
{
public:
  // Constructor
  SQL();
  // Process commands from a file
  SQL(char*& file);
  // Process a command and return the result table
  Table command(const string& cstr);
  // Get all selected record numbers
  vector<long> select_recnos() { return _table.select_recnos(); }
  // Print command
  void print_lookup() { _command.print_lookup(); }
  //======================================
  // TODO: add more methods here as needed
  //======================================
private:
  Table _table;
  Parser _parser;
  MMap<string, string> _command;
  //======================================
  // TODO: add more methods here as needed
  //======================================
};

#endif // SQL_H