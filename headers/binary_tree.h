#include "arena.h"

#ifndef _BINARY_TREE_
#define _BINARY_TREE_


// TODO: make this into a binary tree
struct Node_t;
typedef struct Node_t Node_t;

struct Node_t {
    Node_t* parent_np;
    Node_t* left_child_np;
    Node_t* right_child_np;

    int value;
};

// * Declarations
Node_t n_createNode(Arena_t* arena_p, int val);
Node_t* np_createNode(Arena_t* arena_p, int val);
void v_assignLeftChild(Node_t* parent_np, Node_t* left_child_np);
void v_assignRightChild(Node_t* parent_np, Node_t* right_child_np);
void v_assignChildren(Node_t* parent_np, Node_t* left_child_np, Node_t* right_child_np);
void v_printNode(Node_t* node_p);
// TODO: TODOS
void v_printTree_DFS(Node_t* node_p);
void v_printTree_BFS(Node_t* node_p);


// * Definitions

Node_t n_createNode(Arena_t* arena_p, int val) {

    return (Node_t) {
        .value = val,
        .parent_np = NULL,
        .left_child_np = NULL,
        .right_child_np = NULL,
    };

}

Node_t* np_createNode(Arena_t* arena_p, int val) {
    Node_t* new_node_np = (Node_t*)vp_arenaAlloc(arena_p, sizeof(Node_t));
    new_node_np->parent_np      = NULL;
    new_node_np->left_child_np  = NULL;
    new_node_np->right_child_np = NULL;
    new_node_np->value = val;

    v_printNode(new_node_np);

    return new_node_np;
}

void v_assignChildren(Node_t* parent_np, Node_t* left_child_np, Node_t* right_child_np) {
    parent_np->left_child_np = left_child_np;
    parent_np->right_child_np = right_child_np;

    left_child_np->parent_np = parent_np;
    right_child_np->parent_np = parent_np;
}

void v_printNode(Node_t* node_p) {
    printf("Printing Node ... \n");
    printf("%16s: %p\n", STRINGIFY(parent_np), node_p->parent_np);
    printf("%16s: %p\n", "self_np", node_p);
    printf("%16s: %d\n", STRINGIFY(value), node_p->value);
    printf("%16s: %p\n", STRINGIFY(left_child_np), node_p->left_child_np);
    printf("%16s: %p\n", STRINGIFY(right_child_np), node_p->right_child_np);
}

#endif // _BINARY_TREE_
