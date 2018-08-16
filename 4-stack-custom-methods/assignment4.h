/*********************************************************************
 * Progammer: Connor Pekovic
 * Z-ID: z1761994
 * TA:  Saurabh Chitre.
 * Section: 3
 * Date Due: Feb 22, 2018
 *
 * Purpose: Playing with the stack, just like the old days.  This time,
	using the predefined stack functions.
 *********************************************************************/

#ifndef ASSIGNMNET4_H
#define ASSIGNMENT4_H
#include <stack>

class Queue {
private:
	std::stack<int> s1, s2;
public:
	bool empty() const;
	int size() const;
	int front();
	int back();
	void push(const int& val);
	void pop();
};

#endif
