/***********************************************************************
 * Progammer: Connor Pekovic
 * Z-ID: z1761994
 * TA:  Saurabh Chitre.
 * Section: 3
 * Date Due: March 22nd, 2018
 *
 * Filename: assignment6.cc
 *
 * Purpose:  This file contains the methods for the BST class methods that
 *	was declared in assignment6.h
 ***********************************************************************/

#include <iostream>       //  The
#include "assignment5.h"  //     given
#include "assignment6.h"  //	      information
using namespace std;      //  "Nessesary Headders"


/********************************************************************
 name: insert

 Use:  Inserts a value into the tree.

 Parameter: 1. A pointer reference to the root node of the tree.
            2. An int  to insert in the tree.

 Returns: void
********************************************************************/
void BST::insert(Node*& n, int x)
{
    if(n == NULL)
    {
        n = new Node(x);
    }
    else if(x < n->value)
    {
        insert(n->lChild, x);
    }
    else if(x > n->value)
    {
        insert(n->rChild, x);
    }
}

/********************************************************************
 Function Name: search

 Use:	Searches the binary tree for an int, then returns true if the int
	is found, and flase if the value is not found.

 Parameters:  1. Pointer reference to the current node
              2. The int to be serched for

 Returns: bool
********************************************************************/
bool BST::search(Node*& n, int x)
{
    if(n == NULL)
    {
        return false;
    }
    else if(n->value == x)   // if it is the node, done, true.
    {
        return true;
    }
    else if(n->value > x) // If the search val is greater than the node val,
    {
        return (search(n->lChild, x)); // try again in left subtree.
    }
    else if(n->value < x) // If the search val is greater than the node val,
    {
        return(search(n->rChild, x)); // try again in right subtree.
    }
    else
    {
        return false;  // value not found.
    }
}


/********************************************************************
 function name: remove

 Use:  This deletes a value from the BST.
       Their's 3 possible cases in node removal.
         1. The node to be removed is a leaf.
         2. The node only has one child.
         3. The node has two children.

 Parameters: 1.  A pointer to a node.
             2.  The int to be removed.

 Returns:  boolean value.
********************************************************************/
bool BST::remove(Node*& n, int x)
{
    Node* pred = n; // Being used to find the immediate predecessor.

    if(n == NULL)// The node dosn't even exhist.
    {
        return false;
    }
    if(n->value > x)
    {
        return remove(n->lChild, x);
    }
    if(n->value < x)
    {
        return remove(n->rChild, x);
    }
    if(n->lChild != NULL && n->rChild != NULL) // Case 3
    {/*Find the immideate predecessor by going to the left child then
	all the way to the right-most child.*/
        pred = n->lChild;
        while( pred->rChild != NULL )
	{
            pred = pred->rChild;
	}
        n->value = pred->value;
        return remove(n->lChild, pred->value);
    }
    if(n->rChild == NULL)//Case n is a leaf, case 1
    {
        n = n->lChild;
    }
    else if(n->lChild == NULL)
    {
        n = n->rChild;
    }
    else// Case 2, n has one child.
    {				      // find immediate predecessor like above.
        pred = n->lChild;             // one to the left.

        while( pred->rChild != NULL )
	{
            pred = pred->rChild;      // and all the way to the right.
	}
        pred->rChild = n->rChild;
        pred = n;
        n = n->lChild;
        delete pred;
    }
    return true;
}
/********************************************************************
 Function Name: leaf_Node

 Use: This function is used to find the the leaf node the the BST.

 Parameter: A pointer to a node.

 Returns:  bool
*******************************************************************/
bool leaf_Node(Node *root)
{
    if(root == NULL)
    {
        return false;
    }
    else if(root->lChild == NULL && root->rChild == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/********************************************************************
 Function Name: sumLeftLeaves

 Use: Calculate the sum of all the left leaf node in the tree.

 Parameters: 1. A Pointer reference to root node.

 Returns: Int - the sum of all the left sub-trees nodes.
********************************************************************/
int BST::sumLeftLeaves(Node*& n)
{
    int sum = 0;
    if(n != NULL)
    {
        if(leaf_Node(n->lChild))
	{
            sum += n->lChild->value;
	}
        else
	{
            sum += sumLeftLeaves(n->lChild);
	}
        sum += sumLeftLeaves(n->rChild);
    }
    return sum;
}


/*
 * Below, all the methods are private methods that call their
 * public versions.  In the main, call the things in the brackets.
 */

/********************************************************************
Name:	   insert
Parameter: int of number to be inserted
Returns:   void
********************************************************************/

void BST::insert(int x)
{
    insert(root, x);
}

/********************************************************************
Name:      search
Parameter: int of number to be searched.
Returns:   bool
********************************************************************/
bool BST::search(int x)
{
    return search(root, x);
}

/********************************************************************
Name:      remove
Parameter: int of number to be removed
Returns:   bool
********************************************************************/
bool BST::remove(int x)
{
    return remove(root, x);
}

/********************************************************************
Name:      sumLeftLeaves
Parameter: none
Returns:   int vale with the sum of the values in the left sub-tree.
********************************************************************/
int BST::sumLeftLeaves()
{
    return sumLeftLeaves(root);
}

