// Name: Zhien Yu
// USC NetID: zhienyu
// CSCI 455 PA5
// Fall 2023

// Table.cpp  Table class implementation


#include "Table.h"

#include <iostream>
#include <string>
#include <cassert>

// for hash function called in private hashCode method defined below
#include <functional>

using namespace std;


// listFuncs.h has the definition of Node and its methods.  -- when
// you complete it it will also have the function prototypes for your
// list functions.  With this #include, you can use Node type (and
// Node*, and ListType), and call those list functions from inside
// your Table methods, below.

#include "listFuncs.h"


//*************************************************************************


Table::Table() {
   // initialize
   data = new ListType[HASH_SIZE]();
   // save the HASH_SIZE
   hashSize = HASH_SIZE;
}


Table::Table(unsigned int hSize) {
   // initialize using the given hash size
   data = new ListType[hSize]();
   // save the given hash size
   hashSize = hSize;
}


int * Table::lookup(const string &key) {
   // find the hash code of the given key
   int code = hashCode(key);
   // return the address of the value 
   return lookUpKey(key, data[code]);   
}


bool Table::remove(const string &key) {
   // find the hash code of the given key
   int code = hashCode(key);
   // return remove result
   return listRemove(data[code], key);  
}


bool Table::insert(const string &key, int value) {
   // find the hash code of the given key
   int code = hashCode(key);
   // return insert result
   return listInsert(data[code], key, value);  
}


int Table::numEntries() const {
   // the number of entries will be stored in the count
   int count = 0;
   for(int i = 0; i < hashSize; i++){
      // adds up all the number of elements for each hashCode.
      count += numNode(data[i]);
      
   }
   
   return count;     
}


void Table::printAll() const {
   // iterate through all the hash code and prints each node
   for(int i = 0; i < hashSize; i++){
      printAllNode(data[i]);
      
   }
   

}


void Table::hashStats(ostream &out) const {
   // store the number of longest chain in the longest
   int longest = 0;
   // store the number of non-empty chain in the nonEmpty
   int nonEmpty = 0;
   for(int i = 0; i < hashSize; i++){
      int numElements = numNode(data[i]);
      // if the chain have more than 0 elements
      if(numElements != 0){
         nonEmpty++;
      }
      // if the chain is longer than current longest one. 
      if(longest < numElements){
         longest = numElements;
         
      }
      
   }
   cout << "number of buckets: " << hashSize << endl;
   cout << "number of entries: " << numEntries() << endl;
   cout << "number of non-empty buckets: " << nonEmpty << endl;
   cout << "longest chain: " << longest << endl;

}


// hash function for a string
// (we defined it for you)
// returns a value in the range [0, hashSize)
unsigned int Table::hashCode(const string &word) const {

   // Note: calls a std library hash function for string (it uses the good hash
   //   algorithm for strings that we discussed in lecture).
   return hash<string>()(word) % hashSize;

}


// add definitions for your private methods here

