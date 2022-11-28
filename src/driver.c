#include "rbtree.h"
#include <assert.h>
#include <stdio.h>

int main(int argc, char* argv[]) {
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
    printf("Test Complete\n");
}