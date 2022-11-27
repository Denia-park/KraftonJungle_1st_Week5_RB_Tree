#include "rbtree.h"
#include <assert.h>
#include <stdio.h>

int main(int argc, char* argv[]) {
    rbtree* p_rbt = new_rbtree();
    assert(p_rbt != NULL);

    rbtree_insert(p_rbt, 1);
    rbtree_insert(p_rbt, 2);
    rbtree_insert(p_rbt, 3);

    printf("Test Complete\n");
}