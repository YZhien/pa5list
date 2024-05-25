// Name: Zhien Yu
// USC NetID: zhienyu
// CS 455 PA5
// Fall 2023

// pa5list.cpp
// a program to test the linked list code necessary for a hash table chain

// You are not required to submit this program for pa5.

// We gave you this starter file for it so you don't have to figure
// out the #include stuff.  The code that's being tested will be in
// listFuncs.cpp, which uses the header file listFuncs.h

// The pa5 Makefile includes a rule that compiles these two modules
// into one executable.

#include <iostream>
#include <string>
#include <cassert>

using namespace std;

#include "listFuncs.h"


int main() {
   Node* node1 = new Node("lily", 20);
   //printAllNode(node1);
   Node* node2 = NULL;
   //printAllNode(node2);
   listInsert(node2, "Bili", 34);
   //printAllNode(node2);
   listInsert(node2, "Bili", 35);
   listInsert(node2, "Bili", 36);
   //printAllNode(node2);
   listInsert(node2, "nina", 32);
   //printAllNode(node2);
   listInsert(node2, "lina", 52);
   listInsert(node2, "gina", 52);
   //listRemove(node2, "Bili");
   //printAllNode(node2);
   //listRemove(node2, "nina");
   //printAllNode(node2);
   listRemove(node2, "gina");
   //printAllNode(node2);
   
   cout << numNode(node2) << endl;
   listRemove(node2, "gina");
   listRemove(node2, "nina");
   listRemove(node2, "lina");
   listRemove(node2, "Bili");
   listRemove(node2, "Bili");
   printAllNode(node2);
   
   cout << listInsert(node1, "gily", 52) << endl;


   return 0;
}
