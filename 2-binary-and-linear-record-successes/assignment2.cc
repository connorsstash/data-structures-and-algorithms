/***********************************************************
CSCI 241 - Assignment 2 - Fall 2018 - Northern Illinois University

Progammer: Connor Pekovic
Z-ID: z1761994
Section: 3
TA:  Saurabh Chitre
Date Due: Feb 6, 2018

Purpose:	This is a program that searches for numbers in a vector
	and finds how many comparisons it took through binary search and 
	how many compairsons it takes in linear search.
************************************************************/

#include<algorithm>
#include<numeric>
#include<vector>
#include<iostream>
#include<iomanip>
#include<cstdlib> // Random number generation.
#include<iterator> // for back #insert

using namespace std;

const int DATA_SIZE = 100;
const int SEARCH_SIZE = 50;
const int DATA_SEED = 11;
const int SEARCH_SEED = 7;

/***************************************************************
genRndNums

Use: 1. Establigh range for random numbers.    
	 2. Using srand to start the random number generator
	 3. Fill vector with random numbers
Parameters:
1. inputVec:    The vector that is being searched.
2. x:           Item searched for in the container.

Returns: Bool
***************************************************************/
void genRndNums(vector<int>& v, int seed)
{

	int LOW = 1, HIGH = 100;

	// calls srand with the seed value seed
	srand(seed);

	int randomIntegers;

	for (unsigned i = 0; i < v.size(); i++)
	{
		// generates random integers by calling rand()
		randomIntegers = rand() % (HIGH - LOW + 1) + LOW;

		v[i] = randomIntegers;

	}
}



/***************************************************************
linearSearch

Use: Using 'find(begin, end, searchNum)' from #include<algorithm>
   to return a Boolean value weather the searchNum is in the vector. 
   
   If searchNum is not found, find(x, x, x) will return an iterator
   pointing to the .end() of the vector.

Parameters:
1. inputVec:    The vector that is being searched.
2. x:           Item searched for in the container.

Returns: Bool
***************************************************************/
bool linearSearch(const vector<int>& inputVec, int x) 
{

	vector<int>::const_iterator it; //Somehow, const_iterator works but iterator dosn't

	it = find(inputVec.begin(), inputVec.end(), x);

	if (it != inputVec.end())
	{
		return true;
	}
	else
	{
		return false;
	}
}


/***************************************************************
binarySearch

Use: Using the STL binary_search function to search an input 
	vector for a specefic value

Parameters:
1. inputVec:    The vector that is being searched.
2. x:           Item searched for in the container.

Returns: Bool
***************************************************************/
bool binarySearch(const vector<int>& inputVec, int x)
{
	//searches for element and returns true if found
	if (binary_search(inputVec.begin(), inputVec.end(), x))
	{
		return true;
	}

	//did not find element
	else
	{
		return false;
	}
}

/***************************************************************
search

Use: To count how mant times elements of inputVec appear as elements
 of searchVec.  We're going to loop through a loop to do this.  The first
 loop used int so we use random acess for a vector.  The second loop uses an 
 iterator because that's the recommened implimentation. 

Parameters:
1. inputVec :    A vector with items to search for.
2. searchVec:    A vector with items to search aginst.
3. *p       :    A search routine (binary or linear)

Returns: An interger that counts the number of suscuessful searches.
***************************************************************/
int search(const vector<int>& inputVec, const vector<int>& searchVec, bool(*p)(const vector<int>&, int))
{
	
	int counter = 0;

	for ( unsigned i = 0; i != searchVec.size(); i++)
	{
			
		if ( p(inputVec, i) == true )
		{
			counter++;
		}
	}
	return counter;
}

/***************************************************************
sortVector

Use: 
	 Sorts the bector in acending order, which is already the 
	 defualt criteria for the STL function sort(begin, end).

Parameters:
1. inputVec : The vector that is being sorted

Returns: Nothing
***************************************************************/
void sortVector(vector<int>& inputVec) 
{
	
	sort(inputVec.begin(), inputVec.end());
}


/***************************************************************
printStat

Use: Prints the ratio of suscess from the search function.

Parameter: 1. totalSucCnt -> Total number of suscessful compairsons from
					         the search funtion.
		   2. vec_size    -> Size of the test vector.

Returns: Nothing.
***************************************************************/

void printStat(int totalSucCnt, int vec_size) {
	
	double suscuessRatio = ((totalSucCnt * 100.0) *1.0) / vec_size;

	cout << " Suscuessful searches: " << right << fixed << setprecision(2) <<
		 suscuessRatio <<"%" << endl;
	
}


/***************************************************************
print_vec

Use: This routine displays the contents of the vector 'vec' exactly
8 numbers on a single line with 4 spaced inbetween.

Parameter: 'vec' is a vector of that we're printing to standard output.

Returns: Nothing.
***************************************************************/
void print_vec(const vector<int>& vec) {

	int NO_ITEMS = 10, ITEM_W = 6, counter = 0;

	vector<int>::const_iterator itr;

	for (itr = vec.begin(); itr != vec.end(); ++itr)
	{
		// For every 8 outputs, we need a new line character
		if (counter % NO_ITEMS == 0)
		{
			cout << endl;
		}

		cout << setw(ITEM_W) << *itr;

		counter++;
	}
	cout << endl;
}

int main() {
	vector<int> inputVec(DATA_SIZE);
	vector<int> searchVec(SEARCH_SIZE);
	genRndNums(inputVec, DATA_SEED);
	genRndNums(searchVec, SEARCH_SEED);

	cout << "----- Data source: " << inputVec.size() << " randomly generated numbers ------" << endl;
	print_vec(inputVec);
	cout << "----- " << searchVec.size() << " random numbers to be searched -------" << endl;
	print_vec(searchVec);

	cout << "\nConducting linear search on unsorted data source ..." << endl;
	int linear_search_count = search(inputVec, searchVec, linearSearch);
	printStat(linear_search_count, SEARCH_SIZE);

	cout << "\nConducting binary search on unsorted data source ..." << endl;
	int binary_search_count = search(inputVec, searchVec, binarySearch);
	printStat(binary_search_count, SEARCH_SIZE);

	sortVector(inputVec);

	cout << "\nConducting linear search on sorted data source ..." << endl;
	linear_search_count = search(inputVec, searchVec, linearSearch);
	printStat(linear_search_count, SEARCH_SIZE);

	cout << "\nConducting binary search on sorted data source ..." << endl;
	binary_search_count = search(inputVec, searchVec, binarySearch);
	printStat(binary_search_count, SEARCH_SIZE);

	return 0;
}
