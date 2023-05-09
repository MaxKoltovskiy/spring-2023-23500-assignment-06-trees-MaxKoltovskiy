#pragma once
#include "Node.h"

class BSTree {
    private: 
        Node *root;
        int rsearch(int value, Node *p);
        void insert(int n, Node *p, Node *trailer);
        void deletion(int n, Node *p);
    public: 
        BSTree();
        int rsearch(int value);
        void insert(int n);
        void deletion(int n);

        Node *getRoot();
};