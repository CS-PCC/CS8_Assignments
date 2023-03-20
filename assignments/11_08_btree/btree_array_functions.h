#ifndef BTREE_ARRAY_FUNCTIONS_H
#define BTREE_ARRAY_FUNCTIONS_H

#include <iostream>   // Provides std::cout
#include <iomanip>    // Provides std::setw
#include <cassert>    // Provides assert
#include <cstdlib>    // Provides size_t

// Declaration

template <class T>
void swap(T& a, T& b);                                  //swap the two items

template <class T>
T maximal(const T& a, const T& b);                      //return the larger of the two items

template <class T>
std::size_t index_of_maximal(T data[], std::size_t n);  //return index of the largest item in data with length n

template <class T>
std::size_t first_ge(const T data[], std::size_t n, const T& entry); //return the first index such that data[i] is not less than the entry
                                                        //if there is no such index, then return n indicating all of data are less than the entry.

template <class T>
void insert_item(T data[], std::size_t i, std::size_t& n, T entry);  //insert entry at index i in data

template <class T>
void ordered_insert(T data[], std::size_t& n, T entry); //insert entry into the sorted array data with length n

template <class T>
void attach_item(T data[], std::size_t& n, const T& entry);          //append entry to the right of data

template <class T>
void delete_item(T data[], std::size_t i, std::size_t& n, T& entry); //delete item at index i and place it in entry

template <class T>
void detach_item(T data[], std::size_t& n, T& entry);   //remove the last element in data and place it in entry

template <class T>
void merge(T data1[], std::size_t& n1, T data2[], std::size_t& n2);  //append data2 to the right of data1 and set n2 to 0

template <class T>
void split(T data1[], std::size_t& n1, T data2[], std::size_t& n2);  //move n/2 elements from the right of data1 to beginning of data2

template <class T>
void copy_array(T dest[], const T src[], std::size_t& dest_size, std::size_t src_size); //copy all entries from src[] to replace dest[]

template <class T>
bool is_le(const T data[], std::size_t n, const T& item);//return true if item <= all data[i], otherwise return false

template <class T>
bool is_gt(const T data[], std::size_t n, const T& item);//return true if item > all data[i], otherwise return false

template <class T>
void print_array(const T data[], std::size_t n, std::size_t pos = 0);//print array data


// Definition

template <class T>
bool is_le(const T data[], std::size_t n, const T& item) {
  for(std::size_t i = 0; i < n; i++) {
    if (item > data[i]) return false;
  }
  return true;
}

template <class T>
bool is_gt(const T data[], std::size_t n, const T& item)
{
  for(std::size_t i = 0; i < n; i++) {
    if (item <= data[i]) return false;
  }
  return true;
}

// TODO


#endif // BTREE_ARRAY_FUNCTIONS_H