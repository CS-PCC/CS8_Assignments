#ifndef STOKENIZE_H
#define STOKENIZE_H

#include <cstring>
#include <cassert>
#include <iostream>

#include "token.h"
#include "constants.h"
#include "state_machine_functions.h"

class STokenizer
{
public:
  // Constructors
  STokenizer();
  STokenizer(char str[]);
  bool done();            //true: there are no more tokens
  bool more();            //true: there are more tokens
  // extract one token (very similar to the way cin >> works)
  friend STokenizer& operator >> (STokenizer& s, SToken& t);
  // set a new string as the input string
  void set_string(char str[]);
private:
  // create table for all the tokens we will recognize (e.g. doubles, words, etc.)
  void make_table(int _table[][MAX_COLUMNS]);
  // print the table, debug use only
  void print_table(int _table[][MAX_COLUMNS]);
  // extract the longest string that match one of the acceptable token types
  bool get_token(int start_state, SToken& token);
  // return the type of the token
  STRING_TOKEN_TYPES token_type(int state) const;
  char _buffer[MAX_BUFFER];       //input string
  int _pos;                       //current position in the string
  static int _table[MAX_ROWS][MAX_COLUMNS];
};

#endif // STOKENIZE_H