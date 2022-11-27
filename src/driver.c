#include "rbtree.h"
#include <assert.h>
#include <stdio.h>

int main(int argc, char* argv[]) {
    rbtree* p_rbt = new_rbtree();
    assert(p_rbt != NULL);

    rbtree_insert(p_rbt, 4);
    rbtree_insert(p_rbt, 7);
    rbtree_insert(p_rbt, 1);
    rbtree_insert(p_rbt, 2);
    rbtree_insert(p_rbt, 3);

    print_tree_inorder(p_rbt);

    printf("\n");
    printf("Test Complete\n");
}