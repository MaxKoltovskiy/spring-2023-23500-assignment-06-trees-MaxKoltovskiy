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

    std::cout<< "There are "<< tree -> count_leaves() << " leaves in this tree\n";
    std::cout<< "The sum at level 2 of this tree is "<< tree->level_sum(2)<< "\n";

    return 0;
}