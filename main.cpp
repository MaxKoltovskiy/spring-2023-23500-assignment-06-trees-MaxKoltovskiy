#include <iostream>
#include "BSTree.h"

int main() {
    BSTree *tree = new BSTree();

    srand(time(nullptr));
    for(int i = 0; i< 10; i++) {
        tree -> insert(rand()%10);
    }

    bool six = true;
    try{
        std::cout<< tree->rsearch(6)<< " found in tree"<<"\n";
    }catch(int e){
        std::cout<< "6 not found"<< "\n";
        six = false;
    }

    if(six) {
        tree -> deletion(6);
        try{
            tree -> rsearch(6);
        } catch(int e) {
            std::cout<< "6 no longer in tree\n";
        }
    }

    return 0;
}