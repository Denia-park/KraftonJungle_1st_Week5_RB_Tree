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

    while (searchNode != NULL) {
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
    print_node_inorder(t->root);
}

void tree_insert_fixup(rbtree* t, node_t* p) {

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
