#include "BSTree.h"

BSTree::BSTree() {
    root = nullptr;
}

int BSTree::rsearch(int value, Node *p) {
    if(p == nullptr) {
        throw 1;
    }

    if(p->getData() > value) {
        return rsearch(value, p->getLeft());

    } else if(p->getData() < value) {
        return rsearch(value, p->getRight());
    } 
    
    return value;
}

int BSTree::rsearch(int value) {
    try {
        return rsearch(value, root);
    } catch(int e) {
        throw 1;
    }
}

void BSTree::insert(int n) {
    Node *new_node = new Node(n);

    if(root==nullptr) {
        root = new_node;
        return;
    }

    insert(n,root, nullptr);
}

void BSTree::insert(int n, Node *p, Node *trailer) {
    Node *current = p;

    if(current != nullptr) {
        trailer = current;

        int val = current->getData();
        if(n == val) {
            //update with stuff
            return;
        } else if(n < val) {
            insert(n, current->getLeft(), trailer);
        } else {
            insert(n, current->getRight(), trailer);
        }
    } else {
        Node *new_node = new Node(n);
        if(n < trailer -> getData()) {
            trailer -> setLeft(new_node);
        } else {
            trailer -> setRight(new_node);
        }
    }
}


Node *BSTree::getRoot() {
    return root;
}