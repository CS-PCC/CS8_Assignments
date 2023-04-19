#ifndef TOKENIZER_CONSTANTS_H
#define TOKENIZER_CONSTANTS_H

const int MAX_COLUMNS = 256;
const int MAX_ROWS = 100;
const int MAX_BUFFER = 200;

const char ALFA[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
const char DIGITS[] = "0123456789";
const char OPERATORS[] = "><=!+-%&|";
const char SPACES[] = {' ', '\t', '\n', '\0'};
const char PUNC[] = "?.,:;'`~!";

// token types
enum STRING_TOKEN_TYPES
{
  TOKEN_NUMBER,
  TOKEN_ALPHA,
  TOKEN_SPACE,
  TOKEN_OPERATOR,
  TOKEN_PUNC,
  TOKEN_UNKNOWN = -1
};

// =====================================
// TODO: Add more methods here if needed
// =====================================

#endif // TOKENIZER_CONSTANTS_H