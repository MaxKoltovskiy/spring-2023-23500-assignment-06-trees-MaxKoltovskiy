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

void BSTree::deletion(int n) {
    Node *walker = root;
    Node *trailer = nullptr;

    while(walker -> getData() != n) {
        trailer = walker;

        if(n > walker -> getData()) {
            walker = walker -> getRight();
        } else {
            walker = walker -> getLeft();
        }
    }

    if(walker -> getLeft() != nullptr && walker -> getRight() != nullptr) {

        Node *rep = walker -> getLeft();

        while(rep ->getRight() != nullptr) {
            rep = rep -> getRight();
        }

        int d = rep -> getData();
        deletion(d);
        walker -> setData(d);
    } else {
        if(trailer == nullptr) {
            delete walker;
            walker = nullptr;
        } else if(trailer->getData() > walker->getData()) {
            if(walker -> getLeft() != nullptr) {
                trailer -> setLeft(walker -> getLeft());
                delete walker;
            } else {
                trailer -> setLeft(walker -> getRight());
                delete walker;
            }
        } else {
            if(walker -> getLeft() != nullptr) {
                trailer -> setRight(walker -> getLeft());
                delete walker;
            } else {
                trailer -> setRight(walker -> getRight());
                delete walker;
            }
        }
    }
}

int BSTree::count_leaves() {
    return count_leaves(root);
}

int BSTree::count_leaves(Node *p) {
    int leaves = 0;
    if(p -> getLeft() == nullptr && p -> getRight() == nullptr) {
        leaves++;
    }

    if(p->getLeft() != nullptr) {
        leaves += count_leaves(p->getLeft());
    }
    if(p->getRight() != nullptr) {
        leaves += count_leaves(p->getRight());
    }

    return leaves;
}

int BSTree::level_sum(int level) { // assuming root is level 1
    return level_sum(level, root, 1);
}

int BSTree::level_sum(int level, Node *p, int curr_lev) {
    int sum = 0;

    if(curr_lev == level) {
        return p->getData();
    }
    
    if(p->getLeft() != nullptr) {
        sum += level_sum(level, p->getLeft(), curr_lev+1);
    }
    if(p->getRight() != nullptr) {
        sum += level_sum(level, p->getRight(), curr_lev+1);
    }

    return sum;

}
Node *BSTree::getRoot() {
    return root;
}