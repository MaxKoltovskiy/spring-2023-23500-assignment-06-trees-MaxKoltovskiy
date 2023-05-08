#include <iostream>
#include "BSTree.h"

int main() {
    BSTree *tree = new BSTree();

    srand(time(nullptr));
    for(int i = 0; i< 10; i++) {
        tree -> insert(rand()%10);
    }


    try{
        std::cout<< tree->rsearch(6)<< " found in tree"<<"\n";
    }catch(int e){
        std::cout<< "6 not found"<< "\n";
    }

    return 0;
}