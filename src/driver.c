#include "myHeader.h"
#include <assert.h>
#include <stdio.h>

const int MAX_VALUE = 10000;
const int MIN_VALUE = -9999;

int main(int argc, char* argv[]) {
    printf("\n");
    printf("Test Start \n");
    printf("\n");

    rbtree* p_rbt = testMakeRbTree();

    testMaxValueInEmptyRbTree(p_rbt);
    testMinValueInEmptyRbTree(p_rbt);

    testInsertValueToRbTree(p_rbt);

    testFindValueInRbTree(p_rbt);

    testFindMaxMinValueInRbTree(p_rbt);

    printf("\n");
    printf("Test Complete\n");
}

void findTest(rbtree* t, int testValue) {
    node_t* p_searchNode = rbtree_find(t, testValue);
    if (p_searchNode != NULL) {
        printf("Find expected : %d , actual : %d \n", testValue, p_searchNode->key);
    }
    else {
        printf("Not Found : %d \n", testValue);
    }
}

void find_max_test(rbtree* t, const int MAX_VALUE) {
    node_t* searchNode = rbtree_max(t);

    assert(searchNode->key == MAX_VALUE);

    printf("MAX_VALUE Found : %d \n", MAX_VALUE);
}

void find_min_test(rbtree* t, const int MIN_VALUE) {
    node_t* searchNode = rbtree_min(t);

    assert(searchNode->key == MIN_VALUE);

    printf("MIN_VALUE Found : %d \n", MIN_VALUE);
}


rbtree* testMakeRbTree() {
    printf("\n");
    printf("Make RBtree Test\n");

    rbtree* p_rbt = new_rbtree();
    assert(p_rbt != NULL);
    assert(p_rbt->nil != NULL);
    assert(p_rbt->root == p_rbt->nil);

    printf("OK\n");

    return p_rbt;
}

void testMaxValueInEmptyRbTree(rbtree* t) {
    printf("\n");
    printf("find Max Value in Empty RBtree Test\n");

    // 아무값도 들어가있지 않은 경우에 테스트
    assert(rbtree_max(t) == t->nil);

    printf("OK\n");
}

void testMinValueInEmptyRbTree(rbtree* t) {
    printf("\n");
    printf("find Min Value in Empty RBtree Test\n");

    // 아무값도 들어가있지 않은 경우에 테스트
    assert(rbtree_min(t) == t->nil);

    printf("OK\n");
}

void testInsertValueToRbTree(rbtree* t) {
    printf("\n");
    printf("RBtree_insert Test\n");
    rbtree_insert(t, 20);
    rbtree_insert(t, 10);
    rbtree_insert(t, 50);
    rbtree_insert(t, 30);
    rbtree_insert(t, 80);
    rbtree_insert(t, 40);
    rbtree_insert(t, 35);
    rbtree_insert(t, 25);
    rbtree_insert(t, MAX_VALUE);
    rbtree_insert(t, MIN_VALUE);

    print_tree_inorder(t);
    printf("OK\n");
}

void testFindValueInRbTree(rbtree* t) {
    printf("\n");
    printf("Find value Test\n");

    findTest(t, 20);
    findTest(t, 15);
    findTest(t, 0);
}

void testFindMaxMinValueInRbTree(rbtree* t) {
    printf("\n");
    printf("Find max/min value Test\n");

    find_max_test(t, MAX_VALUE);
    find_min_test(t, MIN_VALUE);
}