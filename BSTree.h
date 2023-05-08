#pragma once
#include "Node.h"

class BSTree {
    private: 
        Node *root;
        int rsearch(int value, Node *p);
        void insert(int n, Node *p, Node *trailer);
    public: 
        BSTree();
        int rsearch(int value);
        void insert(int n);

        Node *getRoot();
};