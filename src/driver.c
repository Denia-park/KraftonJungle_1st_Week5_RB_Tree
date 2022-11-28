#include "rbtree.h"
#include <assert.h>
#include <stdio.h>

void findTest(rbtree* t, int testValue);

int main(int argc, char* argv[]) {
    printf("\n");
    printf("Test Start \n");
    printf("\n");

    rbtree* p_rbt = new_rbtree();
    assert(p_rbt != NULL);

    rbtree_insert(p_rbt, 20);
    rbtree_insert(p_rbt, 10);
    rbtree_insert(p_rbt, 50);
    rbtree_insert(p_rbt, 30);
    rbtree_insert(p_rbt, 80);
    rbtree_insert(p_rbt, 40);
    rbtree_insert(p_rbt, 35);
    rbtree_insert(p_rbt, 25);

    print_tree_inorder(p_rbt);

    printf("\n");

    findTest(p_rbt, 20);
    findTest(p_rbt, 15);

    printf("\n");
    printf("Test Complete\n");
}

void findTest(rbtree* t, int testValue) {
    node_t* p_searchNode = rbtree_find(t, testValue);
    if (p_searchNode != NULL) {
        printf("Find expected : %d , actual : %d \n", testValue, p_searchNode->key);
    }
    else {
        assert(p_searchNode == NULL);
        printf("Not Found : %d \n", testValue);
    }
}