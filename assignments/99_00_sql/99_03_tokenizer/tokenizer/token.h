#ifndef TOKENIZER_TOKEN_H
#define TOKENIZER_TOKEN_H

#include <iostream>
#include <string>

#include "constants.h"

using namespace std;

class Token
{
public:
  // Constructors
  Token();
  Token(string str, int type);
  // return the type of the token
  int type() const { return _type; }
  // return the token string
  string token_str() const { return _token; }
  // return the type of the token as a string
  string token_type() const;
  // overload the << operator
  friend ostream& operator <<(ostream& outs, const Token& t) {
    outs << "|" << t.token_str() << '|'; 
    return outs;
  }
private:
  // the token string
  string _token;
  // the type of the token
  int _type;
};

#endif // TOKENIZER_TOKEN_H