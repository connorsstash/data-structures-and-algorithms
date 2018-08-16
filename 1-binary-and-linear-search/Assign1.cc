/***********************************************************
 CSCI 241 - Assignment 1 - Fall 2018 - Northern Illinois University

 Progammer: Connor Pekovic
 Z-ID: z1761994
 Section: 3?
 TA:  Saurabh Chitre, Bhaskara Reddy Devarapalli, and Jagadeesan Rajendran.
 Date Due: January 29, 2018

 Purpose: This program searchs through a vector using
 binary search and linear search methods in both sorted and unsorted
 vectors of integers.
************************************************************/

#include<algorithm>
#include<numeric>
#include<vector>
#include<iostream>
#include<iomanip>

using namespace std;

const int DATA_SIZE = 200;
const int DATA_RANGE = 200;
const int DATA_SEED = 9;
const int SEARCH_SEED = 17;

/***************************************************************
 linear_search

 Use: Using a for-loop to iterate over the vector inputVector(1)
 to  compare a number 'x'(2) and recording the number of
 comparisons 'compairson'(3) that were done.

 Parameters:
 1. inputVec:    The vector that is being searched.
 2. x:		 Item searched for in the container.
 3. compairsons: The number of compairsons that were made.

 Returns: Suscuess : the position of the matching search value.
 Fail   : returns -1.
***************************************************************/
int linear_search(const vector<int>& inputVec, const int x, int& comparisons)
{
    comparisons = 0; //Initalize compairsons to 0.

    for (size_t pos = 0; pos < inputVec.size(); pos++)
    {
        comparisons++; // Add 1 before the first compairson.

        if (inputVec[pos] == x)
        {
            return pos; // A match would return the index of the matching number.
        }
    }
      return -1;
}

/***************************************************************
 binary_search

 Use: Using a while loop to compair if a middle value of a sorted
 vector, called 'inputVec'(1), is less than or greater than the int
 'x'(2) and recording the number of 'compairsons'(3) that were found.

 Parameters:
 1. inputVec:    The vector that is being searched.
 2. x:           Item searched for in the container.
 3. compairsons: The number of compairsons that were made.

 Returns: Suscuess : the index position for the searched value.
          Fail     : return a -1.
***************************************************************/
int binary_search(const vector<int>& inputVec, const int x, int& comparisons)
{

	int top = inputVec.size() -1;
	int mid;
	int low = 0;

	comparisons = 0; //Initalize compairsons to 0.

    	while (low <= top)
    	  {
          mid = (low + top) / 2;

	    comparisons++;   //'Only equivelance compairsons are counted.'
            if(inputVec[mid] == x)
            {
              return mid;
            }
            else if(x > inputVec[mid])
            {
              low = mid + 1;
            }
            else if(x < inputVec[mid])
            {
              top = mid - 1;
            }
          }

    return -1; // as directed by the prompt

}

/***************************************************************
 print_vec

 Use: This routine displays the contents of the vector 'vec' exactly
 8 numbers on a single line with 4 spaced inbetween.

 Parameter: 'vec' is a vector of that we're printing to standard output.

 Returns: Nothing.
***************************************************************/
void print_vec(const vector<int>& vec)
{

	int NO_ITEMS = 8; //max number of items to be printed on a line.
	int ITEM_W = 4;   //standard width between output.
	int counter = 0;

	vector<int>::const_iterator itr;

	for (itr = vec.begin(); itr != vec.end(); ++itr)
	{
		if ( counter % NO_ITEMS == 0 )
		{
		    cout << endl;
		}

		// Printing the derefrenced iterator.
		cout << setw(ITEM_W) << *itr;

		// For every 8 outputs, we need a new line character
                counter++;

	}

}

void average_comparisons(const vector<int>& inputVec, const vector<int>& searchVec, int (*search)(const vector<int>&, const int, int&) ) {
    int i, comparison = 0, sum = 0, found = 0;
    int res = 0;
    for (i = 0; i < (int)searchVec.size(); i++) {
        res = search( inputVec, searchVec[i], comparison );
        sum += comparison;
        if ( res >= 0 )
           found++;
    }
    cout << found << " numbers are found. The average number of comparisons in each search: " << (double)sum/(double)searchVec.size() << endl << endl;
}

int random_number() {
	return rand() % DATA_RANGE + 1;
}


int main() {

	// -------- create unique random numbers ------------------//
	vector<int> inputVec(DATA_SIZE);
	srand(DATA_SEED);
	generate(inputVec.begin(), inputVec.end(), random_number);
	sort(inputVec.begin(), inputVec.end());
	vector<int>::iterator it = unique(inputVec.begin(), inputVec.end());
	inputVec.resize(it - inputVec.begin());
	random_shuffle(inputVec.begin(), inputVec.end());

	cout << "------ Data source: " << inputVec.size() << " unique random numbers ------" << endl;
	print_vec(inputVec);
	cout << endl;

	// -------- create random numbers to be searched ---------//
	vector<int> searchVec(DATA_SIZE / 2);
	srand(SEARCH_SEED);
	generate(searchVec.begin(), searchVec.end(), random_number);

	cout << "------ " << searchVec.size() << " random numbers to be searched: ------ " << endl;
	print_vec(searchVec);
	cout << endl;

	cout << "Linear search: ";
	average_comparisons(inputVec, searchVec, linear_search);

	cout << "Binary search: ";
	average_comparisons(inputVec, searchVec, binary_search);

	sort(inputVec.begin(), inputVec.end());
	cout << "------- numbers in data source are now sorted ---------" << endl << endl;
	cout << "Linear search: ";
	average_comparisons(inputVec, searchVec, linear_search);
	cout << "Binary search: ";
	average_comparisons(inputVec, searchVec, binary_search);

	return 0;

}


