#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "BSTree.h"

TEST_CASE("insert") {
    BSTree *b = new BSTree();

    b->insert(2);
    CHECK(b->getRoot()->getData() == 2);

    b->insert(0);
    CHECK(b->getRoot()->getLeft()->getData() == 0);
    
    b->insert(1);
    CHECK(b->getRoot()->getLeft()->getRight()->getData() == 1);
    
    b->insert(4);
    CHECK(b->getRoot()->getRight()->getData() == 4);
}
TEST_CASE("rsearch"){
    BSTree *b = new BSTree();

    try{
        b->rsearch(2);
    }
    catch(int e){
        CHECK(e == 1);
    }

    b->insert(1);
    b->insert(3);
    b->insert(7);
    b->insert(4);
    b->insert(2);

    try{
        b->rsearch(5);
    }
    catch(int e){
        CHECK(e == 1);
    }

    CHECK(b->rsearch(2) == 2);
}