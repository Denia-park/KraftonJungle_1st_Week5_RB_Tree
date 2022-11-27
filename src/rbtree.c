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
    p_newNode->left = NULL;
    p_newNode->right = NULL;
    p_newNode->parent = NULL;

    return p_newNode;
}

node_t* rbtree_insert(rbtree* t, const key_t key) {
    node_t* parent = NULL;
    node_t* curNode = t->root;

    while (curNode != NULL) {
        parent = curNode;

        if (key < curNode->key) {
            curNode = curNode->left;
        }
        else {
            curNode = curNode->right;
        }
    }

    node_t* p_newNode = makeNewNode(key);
    p_newNode->parent = parent;

    if (parent == NULL) {
        t->root = p_newNode;
    }
    else {
        if (key < parent->key) {
            parent->left = p_newNode;
        }
        else {
            parent->right = p_newNode;
        }
    }

    // TODO : Make FIXUP Function
    // tree_insert_fixup(tree, ptr)

    return t->root;
}

node_t* rbtree_find(const rbtree* t, const key_t key) {
    // TODO: implement find
    return t->root;
}

node_t* rbtree_min(const rbtree* t) {
    // TODO: implement find
    return t->root;
}

node_t* rbtree_max(const rbtree* t) {
    // TODO: implement find
    return t->root;
}

int rbtree_erase(rbtree* t, node_t* p) {
    // TODO: implement erase
    return 0;
}

int rbtree_to_array(const rbtree* t, key_t* arr, const size_t n) {
    // TODO: implement to_array
    return 0;
}

void print_node_inorder(node_t* curNode) {
    if (curNode == NULL) {
        return;
    }

    print_node_inorder(curNode->left);
    printf("%d ", curNode->key);
    print_node_inorder(curNode->right);
}

void print_tree_inorder(rbtree* t) {
    print_node_inorder(t->root);
}