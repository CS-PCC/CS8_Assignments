# Binary Files


- Accept [99_01_binary_files](https://classroom.github.com/a/a3aDR4_-)
- Get [basic_test.cpp](basic_test.cpp)

---

A binary file is a file whose content is in a binary format consisting of a series of sequential bytes, each of which is eight bits in length. The content must be interpreted by a program or a hardware processor that understands in advance exactly how that content is formatted and how to read the data.

```
01001000 01100101 01101100 01101100 01101111 00101100 00100000 01010111 01101111 01110010 01101100 01100100 00100001
```

In this example, each letter and punctuation mark is represented by an 8-bit ASCII code. For example, the letter "H" is represented by the binary value 01001000, "e" is represented by 01100101, and so on. When these binary values are interpreted as text using an ASCII table, they spell out the familiar phrase "Hello, World!".

Note that while this binary file contains text, it is not a plain text file. A plain text file would simply contain the characters "Hello, World!" as human-readable text, whereas this binary file represents the same text as a sequence of binary digits.

## Task

You can start to read [example code](starting/) to save string as `FileRecord` into `bin` file, then implement [FileRecord](file_record.h) class to save vector of string into `bin` file with [utilities](utilities.h).

## Libraries

The following fstream methods maybe used.

- [cstring:strncpy ( char * destination, const char * source, size_t num )](https://cplusplus.com/reference/cstring/strncpy/): Copies the first num characters of source to destination.
- [std::ostream::write (const char* s, streamsize n)](https://cplusplus.com/reference/ostream/ostream/write/): Inserts the first n characters of the array pointed by s into the stream.
- [std::ostream::seekp](https://cplusplus.com/reference/ostream/ostream/seekp/): Sets the position where the next character is to be inserted into the output stream.
- [std::ostream::tellp](https://cplusplus.com/reference/ostream/ostream/tellp/): Returns the position of the current character in the output stream.
- [std::istream::read (char* s, streamsize n)](https://cplusplus.com/reference/istream/istream/read/): Extracts n characters from the stream and stores them in the array pointed to by s.
- [std::istream::gcount](https://cplusplus.com/reference/istream/istream/gcount/): Returns the number of characters extracted by the last unformatted input operation performed on the object.
- [std::ostream::put (char c)](https://cplusplus.com/reference/ostream/ostream/put/): Inserts character c into the stream.
- [std::istream::get](https://cplusplus.com/reference/istream/istream/get/): Extracts characters from the stream, as unformatted input.
