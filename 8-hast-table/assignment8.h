/*
 * Programmer: 	Connor Pekovic - Northern Illinois University
 * Z-ID: 		z1761994
 * TA:  		Saurabh Chitre.
 * Section: 	3
 * Date Due: 	April 18th, 2018
 *
 * Purpose:	This is a C++ program that has functions to create, search,
 *				print, and manage an item inventory using a hash table using
 *				the linear probing technique.  Each item has a key field and
 *				a description field implemented in a structure, and all the
 *				methods are defined in the class HT (Hash Table).
 *
 * unix usage:  g++ -Wall assignment8.cc –o assignment8.exe
 *	   	   		./assignment8.exe &> assignment8.out
 *
 * FileName:  	assignment8.cc
 ***********************************************************************/

#ifndef ASSIGNMENT8_H
#define ASSIGNMENT8_H
#include <vector>
#include <string>

struct Entry { 
    std::string key;
    std::string description;
    
    Entry() { key = "---"; }
};

class HT {
    private:
        std::vector<Entry>* hTable; // used to store the entries of the item inventory
        int table_size;
        int item_count;
        int hashing(const std::string&);
    public:
        HT(int size);
        ~HT();
        bool insert(const Entry&);
        int search(const std::string&);
        bool remove(const std::string&);
        void print();
};

#endif
