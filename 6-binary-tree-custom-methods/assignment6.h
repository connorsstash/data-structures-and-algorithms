/***********************************************************************
 * Progammer: Connor Pekovic
 * Z-ID: z1761994
 * TA:  Saurabh Chitre.
 * Section: 3
 * Date Due: March 22nd, 2018
 *
 * Purpose:  This just hold the declaration of  binary search tree (BST)
 *	class that is defined in assignment6.cc
 *
 * FileName:  assignment6.h
 ***********************************************************************/

#ifndef ASSIGNMENT6
#define ASSIGNMENT6
#include "assignment5.h"

class BST : public binTree {
    public:
        BST() : binTree() {}
        void insert( int );
        bool search( int );
        bool remove( int );
        int sumLeftLeaves();
    private:
        void insert( Node*&, int );
        bool search( Node*&, int );
        bool remove( Node*&, int );
        int sumLeftLeaves(Node*&);
};

#endif


