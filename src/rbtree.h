#ifndef _RBTREE_H_
#define _RBTREE_H_

#include <stddef.h>

typedef enum { RBTREE_RED, RBTREE_BLACK } color_t;

typedef int key_t;

typedef struct node_t {
  color_t color;
  key_t key;
  struct node_t* parent, * left, * right;
} node_t;

typedef struct {
  node_t* root;
  node_t* nil;  // for sentinel
} rbtree;

rbtree* new_rbtree(void);
void delete_rbtree(rbtree*);

node_t* rbtree_insert(rbtree*, const key_t);
node_t* rbtree_find(const rbtree*, const key_t);
node_t* rbtree_min(const rbtree*);
node_t* rbtree_max(const rbtree*);
int rbtree_erase(rbtree*, node_t*);

int rbtree_to_array(const rbtree*, key_t*, const size_t);

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

#define RED 0
#define BLACK 1

#endif  // _RBTREE_H_
