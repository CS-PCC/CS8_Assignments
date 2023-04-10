#include <iostream>  // cout, endl
#include <fstream>   // fstream

#include "includes/binary_files/file_record.h"
#include "includes/binary_files/utilities.h"

using namespace std;

// Declarations
void simple_test();
void confuse_me();


int main()
{
  cout << "================================ " << endl;
  cout << "Testing the FileRecord class" << endl;
  cout << "================================ " << endl;

  simple_test();

  cout << "================================ " << endl;
  cout << "Testing the FileRecord class" << endl;
  cout << "================================ " << endl;

  confuse_me();

  cout << "================================ " << endl;

  return 0;
}

// Definitions
void simple_test()
{
  // Open the file
  fstream f;
  // Reset the file: use this for new files
  open_fileW(f, "record_list.bin");
  // Initialize the FileRecord
  FileRecord r;
  // recno is the record number
  int recno = -1;
  // Fill the FileRecord with a string
  r = FileRecord("Joe Zero");
  // Write the FileRecord to the file return the record number
  recno = r.write(f);
  // Print the record number
  cout << "Wrote into record: " << recno << endl;
  
  r = FileRecord("One Arm Jane");
  recno = r.write(f);
  cout << "Wrote into record: " << recno << endl;

  r = FileRecord("Two face Harvey");
  recno = r.write(f);
  cout << "Wrote into record: " << recno << endl;

  r = FileRecord("Three Eyed Raven");
  recno = r.write(f);
  cout << "Wrote into record: " << recno << endl;

  r = FileRecord("Four Eyes, Four Eyes! ");
  recno = r.write(f);
  cout << "Wrote into record: " << recno << endl;

  r = FileRecord("Cinco De Mayo, Bryan! ");
  recno = r.write(f);
  cout << "Wrote into record: " << recno << endl;

  r = FileRecord("The Six Shooter Kid! ");
  recno = r.write(f);
  cout << "Wrote into record: " << recno << endl;

  // Close the file
  f.close();

  // Initialize the FileRecord
  FileRecord r2;
  // Open the file for reading and writing
  open_fileRW(f, "record_list.bin" );
  // Read the third record
  r2.read(f, 3);
  // Print the record
  cout << "Record 3: " << r2 << endl;
  // Read the sixth record
  r2.read(f, 6);
  // Print the record
  cout << "Record 6: " << r2 << endl;

  // Reading passed the end of file:
  long bytes = r2.read(f, 19);
  cout << "Number of bytes read: " << bytes << endl;

  // Close the file
  f.close();
}

void confuse_me()
{
  string list[10] = {"zero",
                      "one",
                      "two",
                      "three",
                      "four",
                      "five",
                      "six",
                      "seven",
                      "eight",
                      "nine"};

  for (int i = 0; i< 10; i++){
    cout << list[i] << endl;
  }

  // Open the file
  fstream f;
  // Reset the file: use this for new files
  open_fileW(f, "record_list.bin");
  // Save list into the file
  for (int i= 0; i<10; i++) {
    FileRecord r(list[i]);
    long recno = r.write(f);
    cout << "[" << list[i] << "] was written into file as record: " << recno << endl;
  }

  // Close the file
  f.close();

  // Initialize the FileRecord
  FileRecord r;
  // Open the file for reading and writing
  open_fileRW(f, "record_list.bin" );
  // Read the third record
  r.read(f, 3);
  // Print the record
  cout << "Record 3: " << r << endl;
  // Read the sixth record
  r.read(f, 6);
  // Print the record
  cout << "Record 6: " << r << endl;

  // Reading passed the end of file
  long bytes = r.read(f, 19);
  cout << "Number of bytes read: " << bytes << endl;

  // Close the file
  f.close();
}


/*
================================ 
Testing the FileRecord class
================================ 
Wrote into record: 0
Wrote into record: 1
Wrote into record: 2
Wrote into record: 3
Wrote into record: 4
Wrote into record: 5
Wrote into record: 6
Record 3: Three Eyed Raven
Record 6: The Six Shooter Kid! 
Number of bytes read: 0
================================ 
Testing the FileRecord class
================================ 
zero
one
two
three
four
five
six
seven
eight
nine
[zero] was written into file as record: 0
[one] was written into file as record: 1
[two] was written into file as record: 2
[three] was written into file as record: 3
[four] was written into file as record: 4
[five] was written into file as record: 5
[six] was written into file as record: 6
[seven] was written into file as record: 7
[eight] was written into file as record: 8
[nine] was written into file as record: 9
Record 3: three
Record 6: six
Number of bytes read: 0
================================
*/