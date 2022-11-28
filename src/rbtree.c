#include "rbtree.h"

#include <stdlib.h>
#include <stdio.h>

rbtree* new_rbtree(void) {
    rbtree* p = (rbtree*) calloc(1, sizeof(rbtree));

    p->root = NULL;

    return p;
}

void delete_rbtree(rbtree* t) {
    // TODO: reclaim the tree nodes's memory
    free(t);
}

node_t* rbtree_insert(rbtree* t, const key_t key) {
    node_t* searchNodeParent = NULL;
    node_t* searchNode = t->root;

    while (searchNode != NULL && searchNode->key != NULL) {
        searchNodeParent = searchNode;

        if (key < searchNode->key) {
            searchNode = searchNode->left;
        }
        else {
            searchNode = searchNode->right;
        }
    }

    node_t* p_newInsertNode = makeNewNode(key);
    p_newInsertNode->parent = searchNodeParent;

    if (searchNodeParent == NULL) {
        t->root = p_newInsertNode;
    }
    else {
        if (key < searchNodeParent->key) {
            searchNodeParent->left = p_newInsertNode;
        }
        else {
            searchNodeParent->right = p_newInsertNode;
        }
    }

    tree_insert_fixup(t, p_newInsertNode);

    return t->root;
}

node_t* rbtree_find(const rbtree* t, const key_t key) {
    node_t* searchNode = t->root;

    while (searchNode != NULL && searchNode->key != key) {
        if (key < searchNode->key) {
            searchNode = searchNode->left;
        }
        else {
            searchNode = searchNode->right;
        }
    }

    return searchNode;
}

node_t* rbtree_min(const rbtree* t) {
    node_t* searchNode = t->root;
    while (searchNode != NULL && searchNode->left->key != NULL) {
        searchNode = searchNode->left;
    }

    return searchNode;
}

node_t* rbtree_max(const rbtree* t) {
    node_t* searchNode = t->root;
    while (searchNode != NULL && searchNode->right->key != NULL) {
        searchNode = searchNode->right;
    }

    return searchNode;
}

int rbtree_erase(rbtree* t, node_t* p) {
    // TODO: implement erase
    return 0;
}

int rbtree_to_array(const rbtree* t, key_t* arr, const size_t n) {
    // TODO: implement to_array
    return 0;
}

node_t* makeNilNode(node_t* p_parent) {
    node_t* p_newNilNode = (node_t*) calloc(1, sizeof(node_t));
    p_newNilNode->key = NULL;
    p_newNilNode->color = RBTREE_BLACK;
    p_newNilNode->left = NULL;
    p_newNilNode->right = NULL;
    p_newNilNode->parent = p_parent;

    return p_newNilNode;
}

node_t* makeNewNode(const key_t key) {
    node_t* p_newNode = (node_t*) calloc(1, sizeof(node_t));
    p_newNode->key = key;
    p_newNode->color = RBTREE_RED;
    p_newNode->left = makeNilNode(p_newNode);
    p_newNode->right = makeNilNode(p_newNode);
    p_newNode->parent = NULL;

    return p_newNode;
}

void print_node_inorder(node_t* curNode) {
    if (curNode == NULL) {
        return;
    }

    print_node_inorder(curNode->left);
    if (curNode->key != NULL) {
        printf("%d %c // ", curNode->key, curNode->color == RED ? 'R' : 'B');
    }
    print_node_inorder(curNode->right);
}

void print_tree_inorder(rbtree* t) {
    printf("RootValue : %d \n", t->root->key);
    print_node_inorder(t->root);
    printf("\n");
}

void tree_insert_fixup(rbtree* t, node_t* targetNode) {
    while (targetNode->parent != NULL && targetNode->parent->color == RBTREE_RED) {
        if (targetNode->parent->parent->left == targetNode->parent) {
            targetNode = fixupLeftCase(t, targetNode);
        }
        else {
            targetNode = fixupRightCase(t, targetNode);
        }
    }

    t->root->color = RBTREE_BLACK;
}

node_t* fixupLeftCase(rbtree* t, node_t* targetNode) {
    node_t* uncle = targetNode->parent->parent->right;

    if (uncle->color == RBTREE_RED) {
        targetNode = fixupLeftCase_1(targetNode, uncle);
    }
    else {
        if (targetNode->parent->right == targetNode) {
            targetNode = fixupLeftCase_2(t, targetNode);
        }

        targetNode = fixupLeftCase_3(t, targetNode);
    }

    return targetNode;
}

node_t* fixupLeftCase_1(node_t* targetNode, node_t* uncle) {
    targetNode->parent->color = RBTREE_BLACK;
    uncle->color = RBTREE_BLACK;

    targetNode->parent->parent->color = RBTREE_RED;
    targetNode = targetNode->parent->parent;

    return targetNode;
}

node_t* fixupLeftCase_2(rbtree* t, node_t* targetNode) {
    targetNode = targetNode->parent;
    left_rotate(t, targetNode);

    return targetNode;
}

node_t* fixupLeftCase_3(rbtree* t, node_t* targetNode) {
    targetNode->parent->color = RBTREE_BLACK;
    targetNode->parent->parent->color = RBTREE_RED;

    right_rotate(t, targetNode->parent->parent);

    return targetNode;
}

node_t* fixupRightCase(rbtree* t, node_t* targetNode) {
    node_t* uncle = targetNode->parent->parent->left;

    if (uncle->color == RBTREE_RED) {
        targetNode = fixupRightCase_1(targetNode, uncle);
    }
    else {
        if (targetNode->parent->left == targetNode) {
            targetNode = fixupRightCase_2(t, targetNode);
        }

        targetNode = fixupRightCase_3(t, targetNode);
    }

    return targetNode;
}

node_t* fixupRightCase_1(node_t* targetNode, node_t* uncle) {
    targetNode->parent->color = RBTREE_BLACK;
    uncle->color = RBTREE_BLACK;

    targetNode->parent->parent->color = RBTREE_RED;
    targetNode = targetNode->parent->parent;

    return targetNode;
}

node_t* fixupRightCase_2(rbtree* t, node_t* targetNode) {
    targetNode = targetNode->parent;
    right_rotate(t, targetNode);

    return targetNode;
}

node_t* fixupRightCase_3(rbtree* t, node_t* targetNode) {
    targetNode->parent->color = RBTREE_BLACK;
    targetNode->parent->parent->color = RBTREE_RED;

    left_rotate(t, targetNode->parent->parent);

    return targetNode;
}

void left_rotate(rbtree* t, node_t* targetNode) {
    node_t* toRootNode = targetNode->right;
    targetNode->right = toRootNode->left;
    toRootNode->left->parent = targetNode;
    toRootNode->parent = targetNode->parent;

    if (targetNode->parent == NULL) {
        t->root = toRootNode;
    }
    else if (targetNode->parent->left == targetNode) {
        targetNode->parent->left = toRootNode;
    }
    else {
        targetNode->parent->right = toRootNode;
    }

    toRootNode->left = targetNode;

    targetNode->parent = toRootNode;
}

void right_rotate(rbtree* t, node_t* targetNode) {
    node_t* toRootNode = targetNode->left;
    targetNode->left = toRootNode->right;
    toRootNode->right->parent = targetNode;
    toRootNode->parent = targetNode->parent;

    if (targetNode->parent == NULL) {
        t->root = toRootNode;
    }
    else if (targetNode->parent->right == targetNode) {
        targetNode->parent->right = toRootNode;
    }
    else {
        targetNode->parent->left = toRootNode;
    }

    toRootNode->right = targetNode;

    targetNode->parent = toRootNode;
}
