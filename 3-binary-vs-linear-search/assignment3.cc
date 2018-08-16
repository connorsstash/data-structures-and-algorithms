/***********************************************************
CSCI 241 - Assignment 3 - Fall 2018 - Northern Illinois University

Progammer: Connor Pekovic
Z-ID: z1761994
Section: 3
TA:  Saurabh Chitre
Date Due: Feb 12, 2018

Purpose:	This is a program that searches for numbers in a vector
and finds how many comparisons it took through binary search and
how many compairsons it takes in linear search.
************************************************************/
#include<set>
#include<algorithm>
#include<numeric>
#include<vector>
#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<iterator>
#include<math.h>

using std::cin;
using std::cout;
using std::endl;
using std::setw;
using std::set;
using std::string;


using namespace std;

  /***************************************************************
  sieve

  Use:  This routine is the Sieve of Eratosthenes algorithm. It removes
		all nonprime numbers from an integer set. My prime number test
		consist of a nested for-loop, the 1st loop supplies a number
		from the set, and the 2nd loop supplies a number to test aginst.

  Parameter:  1. 's' is a set.
			  2. 'lower' is the user defined lower boundry.
			  3. 'upper' is the user defined lower boundry.

  Returns: Nothing.
  ***************************************************************/

void sieve(set<int>& s, const int lower, const int upper)
{
	//  Fills 's' with values from 'upper' to 'lower'.
	for (int i = lower; i < upper; i++)
	{
		s.insert(i);
	}

	set<int>::iterator setItr;

	for (setItr = s.begin(); setItr != s.end(); ++setItr)
	{

		for (int i = 2; i <= sqrt(upper); ++i) // making sure to erace all $
		{
			for (int j = 2; j <= sqrt(upper); ++j)
			{
				int tester = i * j;

				if (tester == *setItr)
				{
					s.erase(setItr);
				}
			}
		}
	}

}


  /***************************************************************
  print_primes

  Use: This routine displays the contents of the set 's'.  Here, we 
		implement a const_iterator because set's need iterators to
		be traversed and we're not changing the value.

  Parameter: 1. 's' is a set.
		   2. 'lower' is the user defined lower boundry.
		   3. 'upper' is the user defined lower boundry.

  Returns: Nothing.
  ***************************************************************/
void print_primes(const set<int>& s, const int lower, const int upper)
{
	int NO_ITEMS = 6, ITEM_W = 4, counter = 0, countPrimes = 0;

	set<int>::const_iterator setItr;

	/*  Counting the number of prime numbers immediatly before
	    use it. */
	for (setItr = s.begin(); setItr != s.end(); ++setItr)
	{
		countPrimes++;
	}



	cout << "There are " << countPrimes << " prime numbers between "
		<< lower << " and " << upper << ":";

	for (setItr = s.begin(); setItr != s.end(); ++setItr)
	{
		if (counter % NO_ITEMS == 0)
		{
			cout << endl;
		}

		cout << setw(ITEM_W) << *setItr;

		counter++;
	}

	cout << endl;


}


  /***************************************************************
  run_game

  Use:  We use while loops to run the prompts becuase we want the
		menu to run atleast once.  The inner loop will stop if the
		user-input is valid, and the outter do-while loop stops
		when the user want's to exit the program.

		The functions 'seieve' and 'print_primes' are called

  Parameter:	1. 's' is a set.

  Returns: Nothing.
  ***************************************************************/
void run_game(set<int>& s) 
{
	int lower = 0, upper = 0;
	string happy;

	do {
		do {
			// User interface to accept a lower and upper bound for the range
			cout << "Please input lower bound and upper bound and hit enter (e.g. 10 100):" << endl << endl;

			cin >> lower >> upper;

			// Looks for better input if lower is less than a.
			if (lower < 2){
				cout << "Make sure your lower value is greater than 2! Try again please." << endl;
				cout << "Please input lower bound and upper bound and hit enter (e.g. 10 100):" << endl << endl;
				cin >> lower >> upper;
			}

		   } while (lower > upper);//  Makes sure upper is bigger.


		sieve(s, lower, upper);

		print_primes(s, lower, upper);

		cout << "Do you want to contiue or not? Please answer 'yes' or 'no' and hit enter: ";
		cin >> happy;

	} while (happy == "no");
}

int main() 
{
	set<int> s;
	run_game(s);
	return 0;
}
