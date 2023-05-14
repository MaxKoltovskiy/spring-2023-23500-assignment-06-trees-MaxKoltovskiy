#pragma once
#include "Node.h"

class BSTree {
    private: 
        Node *root;
        int rsearch(int value, Node *p);
        void insert(int n, Node *p, Node *trailer);
        void deletion(int n, Node *p);
        int count_leaves(Node *p);
        int level_sum(int level, Node *p, int curr_lev);
    public: 
        BSTree();
        int rsearch(int value);
        void insert(int n);
        void deletion(int n);
        int count_leaves();
        int level_sum(int level);

        Node *getRoot();
};