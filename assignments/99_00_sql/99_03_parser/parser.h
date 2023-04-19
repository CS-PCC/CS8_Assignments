#ifndef PARSE_H
#define PARSE_H

#include <iostream>
#include <iomanip>
#include <cassert>
#include <string>

#include "../linked_list/queue/MyQueue.h"
#include "../map/map.h"
#include "../map/mmap.h"
#include "../tokenizer/stokenize.h"

class Parser
{
public:
  // Constructors
  Parser();
  Parser(const char*& cstr);
  Parser(const string& str);
  // save string to private member
  void set_string(const char*& cstr);
  void set_string(const string& str);
  // parse string to map
  MMap<string, string> parse_tree();

  // =====================================
  // TODO: Add more methods here if needed
  // =====================================

private:
  // command string
  string _str;

  // =====================================
  // TODO: Add more methods here if needed
  // =====================================
  
};

#endif // PARSE_H