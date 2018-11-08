#ifndef RB_TREE_H_INCLUDED
#define RB_TREE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>


typedef enum {RED, BLACK} Color;

typedef struct Node{
    int          key;
    Color        color;
    struct Node *left;
    struct Node *right;
    struct Node *parent;
} Node;

Node* new_node(int key);
Node* tree_insert(Node** T, int key);
void left_rotate(Node** T, Node* x);
void right_rotate(Node** T, Node* x);
void flip_color(Node** T, Node* x);

void rbInsert(Node **T, Node *z);

/*@*/void test(Node* t, int a);/*@*/

#endif // RB_TREE_H_INCLUDED
