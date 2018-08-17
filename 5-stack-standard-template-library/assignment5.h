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

#ifndef ASSIGNMENT5
#define ASSIGNMENT5
#include<iostream>
#include<algorithm>
#include<iomanip>

/*This is the Node class that holds the values for each node.*/
class Node {
	friend class binTree;
public:
	Node(); //experimental
	int value;
	Node *lChild;
	Node *rChild;
};

/* This is the bin tree class that holds all the finctions that a node
   can preform */
class binTree {
public:
	binTree();
	virtual void insert(int);
	unsigned height() const;
	unsigned size() const;
	void inorder(void(*)(int));
	void preorder(void(*)(int));
	void postorder(void(*)(int));

protected:
	Node * root;

private:
	void insert(Node*&, int);
	unsigned height(Node*) const;
	unsigned size(Node*) const;
	void inorder(Node*, void(*)(int));
	void preorder(Node*, void(*)(int));
	void postorder(Node*, void(*)(int));
};


Node::Node(){// The output was the same with or without this.
}

/***********************************************************************
* binTree
*
* Use: sets the root to a null pointer.
*
* Parameters: None
*
* Returns: binTree
***********************************************************************/
binTree::binTree()
{
	root = nullptr;
}

/***********************************************************************
* insert
*
* Use: calls the private function of insert and assigns an intiger value
*       to that node.
*
* Parameters: an intiger
*
* Returns: void
***********************************************************************/
void binTree::insert(int x) {
	insert(root, x);
}

/***********************************************************************
* height
*
* Use: calls the private funtion height to determin the height of the BST.
*
* Parameters: None
*
* Returns: unsigned     its a posative initger.
***********************************************************************/
unsigned binTree::height() const {
	return height(root);
}

/***********************************************************************
* size
*
* Use: Calls the private function size
*
* Parameters: None
*
* Returns: an intiger from the function size.
***********************************************************************/
unsigned binTree::size() const {
	return size(root);
}

/***********************************************************************
* inorder
*
* Use: calls the private finction of inrder
*
* Parameters: a finction pointer and an intiger.
*
* Returns:  void
***********************************************************************/
void binTree::inorder(void(* x)(int)) {
	inorder(root, x);
}

/***********************************************************************
* preorder
*
* Use: Calls the private function of the function preorder.
*
* Parameters: A function pointer and an intiger.
*
* Returns: void.
***********************************************************************/
void binTree::preorder(void(* x)(int)) {
	preorder(root, x);
}

/***********************************************************************
* postorder.
*
* Use: Calls the private function of inorder.
*
* Parameters: A function pointer and an intiger.
*
* Returns: void
***********************************************************************/
void binTree::postorder(void(* x)(int)) {
	postorder(root, x);
}

/***********************************************************************
* insert
*
* Use: Inserts a new node into the BTS.
*
* Parameters: A pointer to the node and the intiger that we want to insert.
*
* Returns: void
***********************************************************************/
void binTree::insert(Node*& r, int x)
{
	// If we have to make a while new tree from the root.
	if (r == nullptr)
	{
	    r = new Node;    // new node
	    root = r;
	    r->value = x;
	    root->lChild = nullptr;
	    root->rChild = nullptr;
	}

	/* Ok, from here we got 3 options...
	 * Option A : the insert val is smaller than the current val or...
	 * Option B : the insert val is larger than the current val...
	 * Option C : the insert cal is + to the current val... I still don't
		fully understand what happens when Option C happens.
	 */

	if (size(r->rChild) < size(r->lChild))   // Option A
	{

	    if (r->rChild == nullptr) // If no leaf exhist yet.
            {
                r->rChild = new Node;
                r->rChild->value = x;
                r->rChild->lChild = nullptr;
                r->rChild->rChild = nullptr;
            }
            else
            {
                if ( r->rChild != nullptr ) // If a leaf node exhist
                {
                insert(r->rChild, x);
                }
            }
	}
	else  // Option B
	{
	    if (r->lChild == nullptr) // If no leaf exhist yet.
            {
                r->lChild = new Node;   // Make new leaf and-
                r->lChild->value = x;   // -assign 'x' as the value.
                r->lChild->lChild = nullptr;
                r->lChild->rChild = nullptr;
            }
            else
            {
                if ( r->lChild != nullptr )  // Option A...when a leaf node exhists.
                {
                insert(r->lChild, x);
                }
            }
	}

}

/***********************************************************************
* height
*
* Use: Returns a bool indicating both s1 and s2 are empty.
*
*	- I divide the height in half before returning it because
*	by height returns double of what it shuld have in assignment 5.
*
* Parameters: None
*
* Returns: Bool
***********************************************************************/
unsigned binTree::height(Node* n) const {

	if (n == nullptr)
	{
		return 0;
	}
	else
	{
		auto leftHeight = height(n->lChild);
		auto rightHeight = height(n->rChild);

		//return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;

		if ( rightHeight < leftHeight )
		{
			return leftHeight + 1;
		}
		else
		{
			return rightHeight + 1;
		}
	}
}

/***********************************************************************
* size
*
* Use: Indicated the current size of the binary tree.
*
* Parameters: A pointer to a code, idealy the root node.
*
* Returns: A posative int
***********************************************************************/
unsigned binTree::size(Node* r) const
{
	if (r == nullptr)
	{
		return 0;
	}
	else
	{
		return size(r->lChild) + size(r->rChild) + 1;
	}

}

/***********************************************************************
* inorder
*
* Use: Traverse the B.S.T. and visit the values from least to greatest.
*
* Parameters: A pointer to a node that idealy is the root node and a functor.
*
* Returns: void
***********************************************************************/
void binTree::inorder(Node* r, void(* k)(int)) {
	if (r != NULL)
	{
		inorder(r->lChild, k);

		k(r->value);   // Visit??

		inorder(r->rChild, k);
	}
}

/***********************************************************************
* preorder
*
* Use: Traverses the tree top down, left to right,  Bredths First Search.
*
* Parameters: A pointer to a node that is idealy the root and a fucntor.
*
* Returns: void
***********************************************************************/
void binTree::preorder(Node* r, void(* p)(int)) {
	if (r != NULL)
	{
		p(r->value);   // Visit??

		preorder(r->lChild, p);
		preorder(r->rChild, p);
	}

}

/***********************************************************************
* postorder
*
* Use: Traverses the tree bottom to top, left to right,  Depths First Search.
*
* Parameters: A pointer to a node that is idealy the root and a fucntor.
*
* Returns: void
***********************************************************************/
void binTree::postorder(Node* r, void(* p)(int)) {
	if (r != NULL)
	{
		postorder(r->lChild, p);
		postorder(r->rChild, p);

		p(r->value);  // Visit??
	}
}

#endif
