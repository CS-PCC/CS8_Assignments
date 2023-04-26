#include "utilities.h"

bool file_exists(const char filename[])
{
  const bool debug = false;
  fstream ff;
  // Open the file
  ff.open(filename, std::fstream::in | std::fstream::binary );
  if (ff.fail()) {
    if (debug) cout << "FAILED: file_exists(): File does NOT exist: " << filename << endl;
    return false;
  }
  if (debug) cout << "file_exists(): File DOES exist: " << filename << endl;
  // Close the file
  ff.close();
  return true;
}

void open_fileRW(fstream& f, const char filename[])
{
  const bool debug = false;
  // Opening a nonexistent file for in|out|app causes a fail()
  // so, if the file does not exist, create it by opening it for output
  if (!file_exists(filename)) {
    // Create the file
    f.open(filename, std::fstream::out | std::fstream::binary);
    if (f.fail()) {
      cout << "FAILED: open_fileRW(): File does NOT exist: " << filename << endl;
    }
    else{
      if (debug) cout << "open_fileRW(): File created successfully: " << filename << endl;
    }
  }
  else {
    // Open the file
    f.open(filename, std::fstream::in | std::fstream::out| std::fstream::binary);
    if (f.fail()) {
      cout << "FAILED: open_fileRW(): File does NOT exist: " << filename << endl;
    }
  }
  // Keep opening the file for writing
}

void open_fileW(fstream& f, const char filename[])
{
  // Open the file
  f.open (filename, std::fstream::out | std::fstream::binary );
  if (f.fail()) {
    cout << "FAILED: open_fileW(): File does NOT exist: " << filename << endl;
  }
  // Keep opening the file for writing
}
