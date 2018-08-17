/*
 *
 * Progammer: 	Connor Pekovic - Northern Illinois University
 * Z-ID: 	z1761994
 * TA:  	Saurabh Chitre.
 * Section: 	3
 * Date Due: 	April 4th, 2018
 *
 * Purpose:	This C++ program sorts an array based heap using the
 *		famous `heapsort` techquine.  First, this program
 *		builds a heap from a vector with the 'build_heap' method
 *		that loops the 'heapify method. The heapify method uses
 *		the  'compare' method, which is a combination of the
 *		'greater_than' and the 'less_than' functions.  Then, this
 *		program uses 'print_vector' to out the vector the heap would
 *		hyoptheticaly be made out of.
 *
 * unix usage:  g++ -Wall assignment7.cc –o assignment7.exe
 *	   	   ./assignment7.exe &> assignment7.out
 *
 * FileName:  	assignment7.cc
 *
 ***********************************************************************/

#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

const int HEAP_SIZE = 50;


/* Function Name: heapify
 *
 * use:	 	This function down-heaps by swaping the binary node that's in focus
 *		with it's smallest child.  This method identifies ^it's smallest
 *		child by first identifiying it's largest child,
 *		then doing the swap and recurstion with that one.
 *
 * Parameters:  1. My vector representing out heap.
 *              2. My declared size of the heap (50).
 *              3. My root position of the tree given as an int index.
 *              4. My functor pointing to the copar functor(less_than & greater_than).
 *
 * Returns: Nothing
 ***********************************************************************/
void heapify(vector < int >& v, int heap_size, int r, bool(*compar)(int, int))
{
         // The right and left child rules in arrays are applied.
    int leftChild = 2 * r;
    int rightChild = 2 * r + 1;
    int largestChild;

	 // Left child is larger...
    if ((compar(v[leftChild], v[r]) && (leftChild <= heap_size)))
    {
        largestChild = leftChild;
    }
    else
    {   // Root is the largest...
        largestChild = r;
    }
	// Right child is larger...
    if ((compar(v[rightChild], v[largestChild]) && (rightChild <= heap_size - 1)))
    {
        largestChild = rightChild;
    }

	// Downheap: If it's the smallest child...
    if (largestChild != r)
    {
	//...swap the values...
        swap(v[r], v[largestChild]);
	//...and call this function again.
        heapify(v, heap_size, largestChild, compar);
    }

}



/* Function Name: build_heap
 *
 * Uses: 	  Builds a heap with heap_size elements by in the vector
 *		  calling the heapify function a heap_size of times.
 *
 * Parameters:    1. The vector that we want to make into a heap.
 *		  2. The declared size of the heap (50).
 *                3. A functor pointing to the copar functor.
 *
 * Returns: Nothing.
 ************************************************************************/
void build_heap(vector<int>& v, int heap_size, bool(*compar)(int, int))
{
    //Index '0' is ignored:     i > 0;
    for (int i = heap_size / 2; i > 0; i--)
    {
	heapify(v, heap_size, i, compar);
    }
}



/* Function Name: less_than
 *
 * Use:		  In conjunction with greater_than just below, it decides
 *		  if parm 1 is less than or greater than parm 2
 *		  when used in the functor 'compar' in 'heapify' and
 *		  'build_heap' methods above.
 *
 * Parameters:    1. An int.	2. Another int.
 *
 * Returns: True  - if the firest parm is larger than the second parm.
 * 	    False - (otherwise)
 *******************************************************************************/
bool less_than(int e1, int e2)
{
    if (e1 < e2) // LESS THAN operator
    {
	return true;
    }
    else
    {
	return false;
    }
}



/* Function Name: greater_than
 *
 * Use:           In conjunction with less_than just above, it decides
 *                if a parm 1 is less than or greater than parm 2
 *                when used in the functor 'compar' in the 'heapify' and
 *                'build_heap' methods above.
 *
 * Parameters:    1. An int.    2. Another int.
 *
 * Returns: True  - if the firest parm is larger than the second parm.
 *          False - (otherwise)
 *******************************************************************************/
bool greater_than(int e1, int e2)
{
	if (e1 > e2) // GREATER THAN operator
	{
		return true;
	}
	else
	{
		return false;
	}
}



/* Function Name: extract_heap
 *
 * Uses:    To remove an element from a max_heap, we always...
 *	    1) Remove the max/root element.
 *	    2) Use the right-most leaf as the new root.
 *	    3) Down-heap that new root into the correct position
 *		and update the new heap_size with 'heapify'
 *
 * Parameters:    1. A vector that represents the heap.
 *		  2. Int that represent's.
 *		  3. A functor pointing to the coparE functor.
 *
 * Returns: The root at the begining of the method.
 *************************************************************************/
int extract_heap(vector < int >& v, int& heap_size, bool(*compar)(int, int))
{
    int root = v[1];

    if (!v.empty())
    {
	v[1] = v[heap_size];// Using the right-most leaf as the new root.

	heap_size--; //update heap_size.
    }

    // Down_heap that new root to make it a proper max-heap.
    heapify(v, heap_size, 1, compar);

    return root;
}



/* Function Name: heap_sort
 *
 * Uses:   It takes the original vector that represents out heap and makes a new
 *		vector that represents a perfectly sorted heap.
 *
 * Parameters:    1. A vector that represents the heap.
 *                2. Int that represent's the size of the heap.
 *                3. A functor pointing to the copare functor.
 *
 * Returns: Nothing
 *******************************************************************************/
void heap_sort(vector < int >& v, int heap_size, bool(*compar)(int, int))
{
     for (int i = heap_size; i > 1; i--)
    	{
	    v[i] = extract_heap(v, heap_size, compar);
	}

	/* About 'reverse( , )' reverses the order of the elements because we extrated
	the heap the largest element's in the first index, and we want it to be
	the opposite */
	reverse(v.begin()+1, v.end());
}



/* Function Name: print_vector
 *
 * Use:  	This function print's out the vector that we've been using to
 *		represent our heap stright left to right formated ITEMS_PER_LINE
 *		per line and ITEM_WIDTH apart.
 *
 * Parameters:    1. A vector that represents the heap.
 *                2. Pos represent's the desired starting point in the vector.
 *                3. Size represents how many element's the call to print.
 *
 * Returns: Nothing
 *******************************************************************************/
void print_vector(vector<int>& v, int pos, int size)
{
	// Formating.
	const int ITEM_WIDTH = 4;
	const int ITEMS_PER_LINE = 8;
	int counter = 0;

    // For every element in the vector.
    for (int i = pos; i < size + 1; i++)
    {
	if (counter == ITEMS_PER_LINE)
    	{
		cout << endl;  // New line every 8 indexes.
		counter = 0;
	}
	counter++;

	// Output 4(ITEM_WIDTH) spaces and the indexes value.
	cout << setw(ITEM_WIDTH) << v[i];
    }

    cout << endl;
}

int main(int argc, char** argv) {
    // ------- creating input vector --------------
    vector<int> v;
    v.push_back(-1000000);    // first element is fake
    for (int i=1; i<=HEAP_SIZE; i++)
        v.push_back( i );
    random_shuffle( v.begin()+1, v.begin()+HEAP_SIZE+1 );

    cout << "\nCurrent input numbers: " << endl;
    print_vector( v, 1, HEAP_SIZE );

    // ------- testing min heap ------------------
    cout << "\nBuilding a min heap..." << endl;
    build_heap(v, HEAP_SIZE, less_than);
    cout << "Min heap: " << endl;
    print_vector( v, 1, HEAP_SIZE );
    heap_sort( v, HEAP_SIZE, less_than);
    cout << "Heap sort result (in ascending order): " << endl;
    print_vector( v, 1, HEAP_SIZE );

    // ------- testing max heap ------------------
    cout << "\nBuilding a max heap..." << endl;
    build_heap(v, HEAP_SIZE, greater_than);
    cout << "Max heap: " << endl;
    print_vector( v, 1, HEAP_SIZE );
    heap_sort( v, HEAP_SIZE, greater_than);
    cout << "Heap sort result (in descending order): " << endl;
    print_vector( v, 1, HEAP_SIZE );

    return 0;
}
