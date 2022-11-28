
#ifndef _MY_HEADER_H_
#define _MY_HEADER_H_

#include "rbtree.h"

void print_node_inorder(node_t* curNode);
void print_tree_inorder(rbtree* t);

void tree_insert_fixup(rbtree* t, node_t* p);

node_t* fixupLeftCase(rbtree* t, node_t* z);
node_t* fixupRightCase(rbtree* t, node_t* z);

node_t* fixupLeftCase_1(node_t* targetNode, node_t* uncle);
node_t* fixupLeftCase_2(rbtree* t, node_t* targetNode);
node_t* fixupLeftCase_3(rbtree* t, node_t* targetNode);

node_t* fixupRightCase_1(node_t* targetNode, node_t* uncle);
node_t* fixupRightCase_2(rbtree* t, node_t* targetNode);
node_t* fixupRightCase_3(rbtree* t, node_t* targetNode);

node_t* makeNilNode(node_t* p_parent);
node_t* makeNewNode(const key_t key);

void left_rotate(rbtree* t, node_t* targetNode);
void right_rotate(rbtree* t, node_t* targetNode);

void findTest(rbtree* t, int testValue);
void find_max_test(rbtree* t, int testValue);
void find_min_test(rbtree* t, int testValue);
int isNilNode(const node_t* node);

int isNilNode(const node_t* node);

#define RED 0
#define BLACK 1

#define SUCCESS 1
#define FAIL 0

#define TRUE 1
#define FALSE 0 

#endif  // _MY_HEADER_H_