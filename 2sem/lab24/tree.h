#ifndef TREE_H
#define TREE_H

#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef char* Item;

typedef struct tnode tnode;

struct tnode {
    Item data;
    tnode *childs;
    tnode *next;
};

tnode *tree_create(Item); 
void tree_destroy(tnode*); 
void tree_add_node(tnode* a,tnode* b); 
void tree_add(tnode*,Item); 
tnode *tree_find(tnode*,Item); 
void tree_delete(tnode*,tnode*); 
void tree_print(tnode*); 
int var32(tnode *cur, tnode *parent, int level, int i);

#endif
