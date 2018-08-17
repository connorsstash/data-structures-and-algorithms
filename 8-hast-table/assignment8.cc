/*
 *
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
 * unix usage:  1.	make
 *	   	   		2.	./assignment8.exe assignment8input.txt
 *
 * FileName:  	assignment8.cc
 *
 ***********************************************************************/
#include "assignment8.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

/******************************************************************************
Name : Entry::get_entry

Uses : This function takes a line of input from the input fule and breaks it up into
		the 'key' and the 'description'.  The original input is formated like 
		'item key:item description', where the 'item key' are only the second and third
		characters in the input string.
		
Parameters : The line input to read from.

Returns : Returns a new entry structure.
*******************************************************************************/
Entry* get_entry(const string& line)
{
	// Holds the new key and description fields.
	Entry* NewEnteryLine = new Entry;

	// The key is index 2 and 3 on the line.
	NewEnteryLine->key = line.substr(2, 3); 
	
	// The description starts at line 6 until the end of the line.
	NewEnteryLine->description = line.substr(6, line.length() - 6);
	
	return NewEnteryLine;
}

/*******************************************************************************
 * name: Entry::get_key
 *
 * Uses : Returns just the key in the string.
 * 
 * Parameters : The line input to read from.
 *		
 * Returns : Just the key.
 *******************************************************************************/
string get_key(const string& line)
{
	string key = line.substr(2, 3);
	return key;
}

/*******************************************************************************
 * Name: HT::HT
 *
 * Uses : Default constructor for the hash table, which is a vector of entry
 *		structures, is created according to the predefined size of the parameter.
 *		
 * Parameters : Predefined parameter making the hash table's size 11.
 *
 * Returns : Nothing.
*******************************************************************************/
HT::HT(int s = 11)
{
	hTable = new vector<Entry>(s); //11
	
	table_size = s;
	//item_count = 0;
}

/*******************************************************************************
 * Name			: HT::~HT()
 * Use			: Destructor for Hash Table deallocates memory used by the hash table.
 * Parameters 	: Nothing.
 * Returns 		: Nothing.
*******************************************************************************/
HT::~HT()
{
	delete hTable;
}


/*******************************************************************************
 * Name			: int HT::search
 * Use			: This function loops through the hash table once to look for a
 *					value with the key that was passed in the parameter.   If the
 *					key is found, the key's index on the hash table the key is is
 *					returned.
 * Parameters 	: The key.
 * Returns 		: On Success: The index of the key on the hash table.
 *				  On Failure : -1
 ******************************************************************************/
int HT::search (const string& key)
{
	int keyIndex = hashing(key);
	
	for(int i = 0; i < table_size; i++)
	{
		if ((*hTable)[keyIndex].key == key)
		{
			return keyIndex;
		}
		keyIndex = (keyIndex + 1) % table_size;
	}
	return -1;
}


/*******************************************************************************
 * Name			: HT::insert
 * Use			: 1. First, this function takes the parameter an Entry struct
						and takes the key and sees if the key is already in the
						table.  If so, then their's no need to re insert.
				  2. The hash value is computed for the key of e.
				  3. If the hash table position is still the defualt values, that 
						means it's empty and we can go ahead and insert the Entry
						into that position. 
				  4. If the hash table id full, a position is found by linear probing.
				  
 * Parameters 	: an Entry structure.
 * Returns 		: Type Bool
				  On Success: 1  || true
				  On Failure: 0  || false
*******************************************************************************/
bool HT::insert(const Entry& e)
{
	int keyIndex = hashing(e.key);

	string sKey = e.key;
	
	//If the key already exist, no need too reinsert a new one.
	if (search(sKey) != -1)
	{
		cerr << "Unable to insert - identical key found" << endl;
		return false;
	}
	
	//If the table is fill, then we cannot insert a new one.
	else if (item_count == table_size)
	{
		cerr << "Unable to insert - the table is full." << endl;
		return false;
	}

	else
	{
		int i;
		for (i = 0; i < table_size; i++) 
		{
				/* The hash table is computed for Entry 'e'.,  if the hash value is
				empty (still the default value), then the item is inserted in that
				position. */
			if ((*hTable)[keyIndex].key == "---" || (*hTable)[keyIndex].key == "+++")
			{
				/* The item is inserted into that position and the item count in
					incremented by 1. */
				(*hTable)[keyIndex] = e;
				item_count++;

				return true;
			}
			
			//  Linear Probing
			keyIndex = keyIndex + 1 % table_size;
		}
	}
	return false;
}



/*******************************************************************************
 * Name			: HT::remove
 * Use			: Removes an item with a cretin key value.
 * Parameters 	: A string that holds the key.
 * Returns 		: Type Bool
 *					1. Returns true if the key has been removed from the table.
 *					2. Returns false if the key is not found.
 *					
 *	Option.  Can replace +++ with --- and then in the insert function, we can just
 *				look for +++'s.
 ******************************************************************************/
bool HT::remove(const string& s)
{
	//  If the item is not found, then we can exit the program.
	if (search(s) == -1)
	{
		return false;
	}
	else
	{
		// Find the key's index.
		int keyIndex = search(s);

		// Fill that key's location with the +++ which symbolizes an empty field.
		(*hTable)[keyIndex].key = "+++";
		
		// One less item to account for.
		item_count--;
		
		return true;
	}
}



/*******************************************************************************
 * Name			: HT::print
 * Use			: Prints the index value, the key, and the description.
 * Parameters 	: None.
 * Returns 		: Void.
*******************************************************************************/
void HT::print ()
{
	cout << endl << "----Hash Table-----" << endl;

	for (int i = 0; i < table_size; i++) {
		if ((*hTable)[i].key != "---" && (*hTable)[i].key != "+++") {
			cout << right << setw(2) << i << ": ";
			cout << (*hTable)[i].key << " ";
			cout << (*hTable)[i].description << endl;
		}
	}
	cout << "---------------------------" << endl << endl;
}




// key is in form of letter-letter-digit
// compute sum <-- ascii(pos1)+ascii(pos2)+ascii(pos3)
// compute sum%htable_size
int HT::hashing(const string& key) {
   return ((int)key[0] + (int)key[1] + (int)key[2])%table_size;
}

int main(int argc, char** argv ) {
    if ( argc < 2 ) {
        cerr << "argument: file-name\n";
        return 1;
    }

    HT ht;
    ifstream infile(argv[1], ios::in);
    string line;
    infile >> line;    
    while ( !infile.eof() ) {
        if ( line[0] == 'A' ) { 
            Entry* e = get_entry( line );
            ht.insert( *e );
            delete e;
        }
        else {
            string key = get_key(line);
            if ( line[0] == 'D' ) {
                cout << "Removing " << key << "...\n";
                bool removed = ht.remove( key );
                if ( removed )
                    cout << key << " is removed successfully...\n\n";
                else
                    cout << key << " does not exist, no key is removed...\n\n";
            }
            else if ( line[0] == 'S' ) {
                int found = ht.search( key );
                if ( found < 0 ) 
                    cout << key << " does not exit in the hash table ..." << endl << endl;
                else
                   cout << key << " is found at table position " << found << endl << endl;
            }
            else if ( line[0] == 'P' ) {
                cout << "\nDisplaying the table: " << endl;
                ht.print();
            }
            else
                cerr << "wrong input: " << line << endl;
        }
        infile >> line;
 
    }

    infile.close();
    return 0;
}