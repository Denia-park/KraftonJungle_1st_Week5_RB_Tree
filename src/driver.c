#include "rbtree.h"
#include <assert.h>
#include <stdio.h>

int main(int argc, char* argv[]) {
    rbtree* p_rbt = new_rbtree();
    assert(p_rbt != NULL);

    printf("Test Complete\n");
}