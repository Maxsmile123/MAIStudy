#ifndef _TREE_H_
#define _TREE_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int data;
    struct Tree *left;
    struct Tree *right;
    struct Tree* parent;
} Tree;

Tree *tree_create(int value);
Tree *tree_add_element(Tree *parent, int value);
Tree *delete_element(Tree *parent, int value);
void tree_print(Tree *t, int n);
int is_AVL(Tree *t);
Tree* minimum(Tree *t);
Tree* maximum(Tree *t);
Tree* search_in_tree(Tree *t, int value);


#endif //_TREE_H_
