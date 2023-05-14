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
TEST_CASE("delete"){
    BSTree *b = new BSTree();

    b->insert(1);
    b->insert(3);
    b->insert(7);
    b->insert(4);
    b->insert(2);

    b->deletion(2);
    CHECK(b->getRoot()->getRight()->getLeft() == nullptr);
    
    b->deletion(7);
    CHECK(b->getRoot()->getRight()->getRight()->getData() == 4);

    b->insert(-2);
    b->insert(-1);
    b->insert(0);

    b->deletion(1);
    CHECK(b->getRoot() -> getData() == 0);
    CHECK(b -> getRoot() -> getLeft() -> getRight() -> getRight() == nullptr );

    b->insert(2);

    b->deletion(3);
    CHECK(b->getRoot() -> getRight() -> getData() == 2);
    CHECK(b -> getRoot() -> getRight() -> getLeft() == nullptr);

}
TEST_CASE("Count Leaves"){
    BSTree *b = new BSTree();

    b->insert(5);
    CHECK(b->count_leaves() == 1);

    b->insert(3);
    b->insert(2);
    b->insert(4);
    b->insert(6);
    b->insert(7);

    CHECK(b->count_leaves() == 3);

    BSTree *tree = new BSTree();

}
TEST_CASE("Level Sum"){
    BSTree *b = new BSTree();

    b->insert(5);
    b->insert(3);
    b->insert(2);
    b->insert(4);
    b->insert(7);
    b->insert(6);
    b->insert(8);

    CHECK(b->level_sum(3) == 20);
    CHECK(b->level_sum(2) == 10);
    CHECK(b->level_sum(1) == 5);
}