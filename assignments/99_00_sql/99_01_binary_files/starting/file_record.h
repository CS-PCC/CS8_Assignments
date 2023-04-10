#ifndef FILE_RECORD_H
#define FILE_RECORD_H

#include <iostream>  // cout, endl
#include <fstream>   // fstream
#include <cstring>   // strncpy

using namespace std;

class FileRecord
{
public:
  // When construct a FileRecord, it's either empty or it contains a word
  FileRecord() {
    _records[0] = '\0';
    recno = -1;
    // _records[] => [ | '\0' | G | a | r | b | a | g | e | ]
  }
  
  FileRecord(string s) {
    // Copy the string into the record cstring
    strncpy(_records, s.c_str(), MAX);
  }

  FileRecord(char str[]) {
    // Copy the string into the record cstring
    strncpy(_records, str, MAX);
  }

  // Returns the record number
  long write(fstream& outs);
  // Returns the number of bytes read = MAX, or zero if read passed the end of file
  long read(fstream& ins, long recno);

  // Overload the << operator to print a FileRecord
  friend ostream& operator << (ostream& outs, const FileRecord& r) {
    outs << r._records;
    return outs;
  }
private:
  // The maximum size of the record
  static const int MAX = 100;
  // The record number
  int recno;
  // The record cstring
  char _records[MAX+1];
};

#endif