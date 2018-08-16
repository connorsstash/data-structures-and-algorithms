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

#include "assignment4.h"
#include <cstdio>
#include <iostream>
#include <iomanip>

using std::cout;
/***********************************************************************
* empty
*
* Use: Returns a true of flase (bool) value if both s1 and s2 are empty.
*
* Parameters: None
*
* Returns: Bool
***********************************************************************/
bool Queue::empty() const
{
	if (s1.empty() && s2.empty())
	{
		return true;
	}
	else
	{
		return false;
	}
}

/***********************************************************************
* size
*
* Use: Returns the count of elements in s1 & s2.
*
* Parameters: None
*
* Returns: int
************************************************************************/
int Queue::size() const
{
	unsigned totalSize = 0;

	totalSize = s1.size();
	totalSize += s2.size();

	return totalSize;
}

/***********************************************************************
* front
*
* Use:  If s2 is empty, move(swap) all elements from s1 to s2. Simply
* return the top element in s2. This returns the oldest element, the top
* of s2.
*
* Parameters: None
*
* Returns: int
************************************************************************/
int Queue::front()
{
	if (s2.empty())
	{
		if (s1.empty())
		{
			cout << "Both stacks are empty";
		}
	}
	s1.swap(s2);
	return s2.top();
}

/***********************************************************************
* back
*
* Use:  Returns the newest element, the top element of s1.
*
* Parameters: None
*
* Returns: int
************************************************************************/
int Queue::back()
{
	return s1.top();
}

/***********************************************************************
* push
*
* Use:  Simply add an element to s1.
*
* Parameters: A constent refrence to a value that's an int.
*
* Returns: int
************************************************************************/
void Queue::push(const int& val)
{
	s1.push(val);
}
void Queue::pop()
{
	if (s2.empty())
	{
		if (s1.empty())
		{
			cout << "Both stacks are empty";
		}
	s1.swap(s2);
	}
	s2.pop();
}
