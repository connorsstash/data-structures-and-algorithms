/***********************************************************************
 * Progammer: Connor Pekovic
 * Z-ID: z1761994
 * TA:  Saurabh Chitre.
 * Section: 3
 * Date Due: March 5th, 2018
 *
 * Purpose:  This program implements a class using STL (Standard
 *      Template library) stacks, assignment 4.
 *
 * Usage:  g++ -Wall assignment5.cc –o assignment5.exe
 *         “./assignment5.exe &> assignment5.out
 ***********************************************************************/

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include "assignment5.h"
using namespace std;

const int MAX_SIZE = 40;
const int MAX_COUNT = 40;
const int WIDTH = 5;
const int ROW_SIZE = 8;

int mcount = 0;
int rcount = 0;

void display(int d) {
	if (mcount < MAX_COUNT) {
		cout << setw(WIDTH) << d;
		mcount++;
		rcount++;
		if (rcount == ROW_SIZE) {
			cout << endl;
			rcount = 0;
		}
	}
}

#define BINTREE_MAIN
#ifdef BINTREE_MAIN
int main() {
	vector<int> v(MAX_SIZE);
	for (int i = 1; i<MAX_SIZE; i++)
		v[i] = i;
	random_shuffle(v.begin(), v.end());

	binTree bt;
	vector<int>::iterator it;
	for (it = v.begin(); it != v.end(); it++)
		bt.insert(*it);


	cout << "Height: " << bt.height() << endl;
	cout << "Size: " << bt.size() << endl;
	cout << "In order traverse (displaying first " << MAX_COUNT << " numbers): " << endl;
	mcount = rcount = 0;
	bt.inorder(display);
	cout << "\n\nPre order traverse (displaying first " << MAX_COUNT << " numbers): " << endl;
	mcount = rcount = 0;
	bt.preorder(display);
	cout << "\n\nPost order traverse (displaying first " << MAX_COUNT << " numbers): " << endl;
	mcount = rcount = 0;
	bt.postorder(display);


	cout << endl;
	return 0;
}
#endif

