#include "file_record.h"

long FileRecord::write(fstream &outs)
{
  // Take the Record r and write it into file f and return the record number of this Record
  // r.write(f); calls this function

  // Write to the end of the file
  outs.seekg(0, outs.end);
  // Retrieves the current position of the file pointer
  long pos = outs.tellp();
  // Insert the size of record items into file
  outs.write(_records, sizeof(_records));
  // Return the record number
  return pos / sizeof(_records);
}

long FileRecord::read(fstream &ins, long recno)
{
  // Save sixth record in file to Record r and returns the number of bytes read
  // r.read(f, 6); calls this function

  // Calculate the position of the record in the file
  long pos = recno * sizeof(_records);
  // Set the file pointer to the pos starting from the beginning of the file
  ins.seekg(pos, ios_base::beg);
  // Read the record from the file
  ins.read(_records, sizeof(_records));
  // Set the end of cstring with null
  // For example: _records[] => [zero'\0' trash ... trash]
  _records[ins.gcount()] = '\0';
  // Return the number of bytes read
  return ins.gcount();
}