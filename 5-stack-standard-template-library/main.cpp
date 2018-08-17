//#ifndef ASSIGNMENT5
//#define ASSIGNMENT5

class binTree;
class BST;
class Node;


class Node {
    
    friend class binTree;
    
public:
    
    int data;

    Node *leftChild;
    Node *rightChild;
    
    
};

class binTree {
    
public:
    binTree();
    virtual void insert( int );
    unsigned height() const;
    unsigned size() const;
    void inorder( void(*)(int) );
    void preorder( void(*)(int) );
    void postorder( void(*)(int) );
    
protected:
    Node* root;
    
private:
    void insert( Node*&, int );
    unsigned height( Node* ) const;
    unsigned size( Node* ) const;
    void inorder( Node*, void(*)(int) );
    void preorder( Node*, void(*)(int) );
    void postorder( Node*, void(*)(int) );
};

//#endif

//****************************************************

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
//#include "assignment5.h"
using namespace std;

const int MAX_SIZE = 40;
const int MAX_COUNT = 40;
const int WIDTH = 5;
const int ROW_SIZE = 8;

int mcount = 0;
int rcount = 0;

void display(int d) {
    if ( mcount < MAX_COUNT ) {
        cout << setw(WIDTH) << d;
        mcount++;
        rcount++;
        if ( rcount == ROW_SIZE ) {
            cout << endl;
            rcount = 0;
        }
    }
}
//Public Methods
binTree::binTree()
{
    root = nullptr;
}

void binTree::insert(int x)
{
    insert(root, x);
}

unsigned binTree::height() const
{
    return height(root);
}

unsigned binTree::size() const
{
    return size(root);
}

void binTree::inorder(void (* p)(int))
{
    inorder(root, p);
}

void binTree::preorder(void (* p)(int))
{
    preorder(root, p);
}

void binTree::postorder(void (* p)(int))
{
    postorder(root, p);
}


//Private Methods
void binTree::insert(Node*& r, int x)
{
    if (r == NULL)
    {
        r = new Node;
        r->data = x;
    }
    else
    {
        int leftHeight = height(r->leftChild);
        int rightHeight = height(r->rightChild);
    
        if ( leftHeight <= rightHeight)
        {
            insert(r->leftChild, x);
        }
        else
        {
            insert(r->rightChild, x);
        }
    }
}

unsigned binTree::height(Node* r) const
{
    if ( r == NULL)
    {
        return 0;
    }
    else
    {
        int leftHeight = height(r->leftChild);
        int rightHeight = height(r->rightChild);
        
        if (leftHeight > rightHeight)
        {
            return 1+leftHeight;
        }
        else
        {
            return 1+rightHeight;
        }
    }

}

unsigned binTree::size(Node* r) const
{
    if ( r != NULL)
    {
        return 1 + size(r->leftChild) + size(r->rightChild);
    }
    else
    {
        return 0;
    }
}

void binTree::inorder(Node* r, void (* p)(int))
{
    if (r != NULL)
    {
        inorder(r->leftChild, p);
        p(r->data);
        inorder(r->rightChild,p);
    }
}

void binTree::preorder(Node* r, void (* p)(int))
{
    if (r != NULL)
    {
        p( r->data);
        preorder(r->leftChild, p);
        preorder(r->rightChild, p);
    }
    
}

void binTree::postorder(Node* r, void (* p)(int))
{
    
    if (r != NULL)
    {
        postorder(r->leftChild, p);
        postorder(r->rightChild,p);
        p(r->data);
    }
    
}


//#define BINTREE_MAIN
//#ifdef BINTREE_MAIN
int main() {
    vector<int> v(MAX_SIZE);
    for (int i=1; i<MAX_SIZE; i++)
        v[i] = i;
    random_shuffle( v.begin(), v.end() );
    
    binTree bt;
    vector<int>::iterator it;
    for (it=v.begin(); it!=v.end(); it++)
        bt.insert( *it );
    
    cout << "Height: " << bt.height() << endl;
    cout << "Size: " << bt.size() << endl;
    cout << "In order traverse (displaying first " << MAX_COUNT << " numbers): " << endl;
    mcount = rcount = 0;
    bt.inorder( display );
    cout << "\n\nPre order traverse (displaying first " << MAX_COUNT << " numbers): " << endl;
    mcount = rcount = 0;
    bt.preorder( display );
    cout << "\n\nPost order traverse (displaying first " << MAX_COUNT << " numbers): " << endl;
    mcount = rcount = 0;
    bt.postorder( display );
    
    cout << endl;
    return 0;
}

//#endif
