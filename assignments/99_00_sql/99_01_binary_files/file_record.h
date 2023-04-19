#ifndef FILE_RECORD_H
#define FILE_RECORD_H

#include <iostream>  // cout, endl
#include <iomanip>   // setw, right
#include <fstream>   // fstream
#include <cstring>   // strncpy
#include <vector>    // vector

using namespace std;

class FileRecord
{
public:
  // When construct a FileRecord, it's either empty or it contains a word
  FileRecord() {
    recno = -1;
    // _records[0] => [ | '\0' | G | a | r | b | a | g | e | ]
  }
  
  FileRecord(string s);

  FileRecord(char str[]);

  FileRecord(vector<string> v);
  
  // Returns the record number
  long write(fstream& outs);
  // Returns the number of bytes read = MAX, or zero if read passed the end of file
  long read(fstream& ins, long recno);
  // Returns the record
  vector<char*> get_records() { return _records; }

  // Overload the << operator to print a FileRecord
  friend ostream& operator << (ostream& outs, const FileRecord& r) {
    for (char* _record : r._records) {
      outs << setw(MAX/4) << right << _record;
    }
    return outs;
  }

  // =====================================
  // TODO: Add more methods here if needed
  // =====================================

private:
  // The maximum size of the record
  static const int MAX = 100;
  // The record number
  int recno;
  // The record vector
  vector<char*> _records;

  // =====================================
  // TODO: Add more methods here if needed
  // =====================================
  
};

#endif