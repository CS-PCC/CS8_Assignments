#ifndef FTOKENIZE_H
#define FTOKENIZE_H

#include <iostream>
#include <fstream>

#include "constants.h"
#include "token.h"
#include "stokenize.h"

class FTokenizer
{
public:
  // Maximum number of characters in a block
  const int MAX_BLOCK = MAX_BUFFER;
  // Constructor
  FTokenizer(char* fname);
  // Extract one token (very similar to the way cin >> works)
  SToken next_token();
  bool more() { return _more; }        //returns the current value of _more
  int pos() { return _pos; }           //returns the value of _pos
  int block_pos() { return _blockPos; }//returns the value of _blockPos
  friend FTokenizer& operator >> (FTokenizer& f, SToken& t);
private:
  bool get_new_block(); //gets the new block from the file
  std::ifstream _f;     //file being tokenized
  STokenizer _stk;      //STokenizer object to tokenize current block
  int _pos;             //current position in the file
  int _blockPos;        //current position in the current block
  bool _more;           //false if last token of the last block
                        //  has been processed and now we are at
                        //  the end of the last block.
};

#endif //FTOKENIZE_H