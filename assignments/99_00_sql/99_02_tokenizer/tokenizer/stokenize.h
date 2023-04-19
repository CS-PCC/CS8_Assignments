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
  STokenizer(const char str[]);
  bool done();            //true: there are no more tokens
  bool more();            //true: there are more tokens
  // extract one token (very similar to the way cin >> works)
  friend STokenizer& operator >> (STokenizer& s, SToken& t);
  // set a new string as the input string
  void set_string(const char str[]);

  // =====================================
  // TODO: Add more methods here if needed
  // =====================================
  
private:
  // create table for all the tokens we will recognize (e.g. doubles, words, etc.)
  void make_table(int _table[][MAX_COLUMNS]);
  // extract the longest string that match one of the acceptable token types
  bool get_token(int start_state, SToken& token);
  // return the type of the token
  STRING_TOKEN_TYPES token_type(int state) const;
  char _buffer[MAX_BUFFER];       //input string
  int _pos;                       //current position in the string
  static int _table[MAX_ROWS][MAX_COLUMNS];

  // =====================================
  // TODO: Add more methods here if needed
  // =====================================
  
};

#endif // STOKENIZE_H