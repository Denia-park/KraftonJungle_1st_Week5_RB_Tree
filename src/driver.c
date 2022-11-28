#include "myHeader.h"
#include <assert.h>
#include <stdio.h>

int main(int argc, char* argv[]) {
    const int MAX_VALUE = 10000;
    const int MIN_VALUE = -9999;

    printf("\n");
    printf("Test Start \n");
    printf("\n");

    rbtree* p_rbt = new_rbtree();
    assert(p_rbt != NULL);
    assert(p_rbt->nil != NULL);
    assert(p_rbt->root == p_rbt->nil);

    rbtree_insert(p_rbt, 20);
    rbtree_insert(p_rbt, 10);
    rbtree_insert(p_rbt, 50);
    rbtree_insert(p_rbt, 30);
    rbtree_insert(p_rbt, 80);
    rbtree_insert(p_rbt, 40);
    rbtree_insert(p_rbt, 35);
    rbtree_insert(p_rbt, 25);
    rbtree_insert(p_rbt, MAX_VALUE);
    rbtree_insert(p_rbt, MIN_VALUE);

    print_tree_inorder(p_rbt);

    printf("\n");
    printf("Find value Test\n");

    findTest(p_rbt, 20);
    findTest(p_rbt, 15);

    printf("\n");
    printf("Find max , value Test\n");

    find_max_test(p_rbt, MAX_VALUE);
    find_min_test(p_rbt, MIN_VALUE);

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