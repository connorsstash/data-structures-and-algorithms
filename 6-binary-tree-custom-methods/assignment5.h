/***********************************************************************
 * Progammer: Connor Pekovic
 * Z-ID: z1761994
 * TA:  Saurabh Chitre.
 * Section: 3
 * Date Due: March 22nd, 2018
 *
 * Purpose: This file contains the class declarations for or binTree
 *	class and our nodes.
 *
 * Usage:  make [enter]
 *         ---or---
 *         g++ -Wall assignment5.cc –o assignment5.exe
 *         ./assignment5.exe &> assignment5.out
 ***********************************************************************/

#ifndef ASSIGNMENT5
#define ASSIGNMENT5

/*This is the Node class that holds the values for each node.*/
class Node {
	friend class binTree;
	friend class BST;

public:
	Node(int& x, Node* l = 0, Node* r = 0)
	{ value = x; lChild = l; rChild = r; }

public:
	Node();
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

#endif
