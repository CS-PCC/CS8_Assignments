#ifndef STRING_TOKEN_H
#define STRING_TOKEN_H

#include <iostream>
#include <string>

#include "constants.h"

using namespace std;

class SToken
{
public:
  // Constructors
  SToken();
  SToken(string str, STRING_TOKEN_TYPES type);
  // return the token string
  string token_str() const { return _token; }
  // return the type of the token as a string
  string token_type() const;
  // overload the << operator
  friend ostream& operator <<(ostream& outs, const SToken& t) {
    outs << "|" << t.token_str() << '|'; 
    return outs;
  }
private:
  // the token string
  string _token;
  // the type of the token
  STRING_TOKEN_TYPES _type;
};

#endif // STRING_TOKEN_H