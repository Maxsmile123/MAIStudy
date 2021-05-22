#include <stdio.h>
#include <ctype.h>
#include "tree.h"



// создание дерева
tnode *tree_create(Item a)
{
    tnode *q = (tnode*)malloc(sizeof(tnode));
    q->data = a;
    q->childs = NULL;
    q->next = NULL;
    return q;
}

// удаление дерева
void tree_destroy(tnode* a)
{
    if(a == NULL)
        return;
    if(a->data)
        free(a->data);
    tree_destroy(a->childs);
    tree_destroy(a->next);
    free(a);
}

// добавление ребенка к дереву
void tree_add(tnode* a,Item b)
{
    if(b == NULL)
        return;
    if(a->childs)
    {
        tnode *new1 = tree_create(b);
        new1->next = a->childs;
        a->childs = new1;
    }
    else
        a->childs=tree_create(b);
}

// добавление ребенка у дереву (когда много детей)
void tree_add_node(tnode* a,tnode* b)
{
    if(b == NULL)
        return;
    if(a->childs)
    {
        b->next = a->childs;
        a->childs = b;
    }
    else
        a->childs = b;
}

// поиск по значению в дереве
tnode *tree_find(tnode* a,Item b)
{
    if(a == NULL)
        return NULL;
    if(a->data == b)
        return a;
    tnode *chld1 = tree_find(a->childs,b);
    if(chld1)
        return chld1;
    tnode *nxt1 = tree_find(a->next,b);
    if(nxt1)
        return nxt1;
    return NULL;
}

// поиск родителя дерева
tnode *tree_parent_find(tnode* a,tnode* b)
{
    if(a == NULL)
        return NULL;
    if(a->childs == b || a->next == b)
        return a;
    tnode *chld1 = tree_parent_find(a->childs,b);
    if(chld1 != NULL)
        return chld1;
    tnode *nxt1 = tree_parent_find(a->next,b);
    if(nxt1 != NULL)
        return nxt1;
    return NULL;
}

// удаление ячейки из дерева
void tree_delete(tnode* a,tnode* b)
{
    tnode *par1 = tree_parent_find(a,b);
    if(par1->childs == b)
        par1->childs = b->next;
    else
        par1->next = b->next;
    tree_destroy(b->childs);
    free(b);
}

// вспомогательная рекурсивная функция распечатки
void tree_print_int(tnode* a,int b)
{
    if(a == NULL)
        return;
    for(int i = 0; i < b; i++)
        printf("\t");
    printf("%s\n",a->data);
    tree_print_int(a->childs, b + 1);
    tree_print_int(a->next, b);
}

// распечатка дерева
void tree_print(tnode* a)
{
    tree_print_int(a,0);
}

int is_operator(char c)
{
    if(c == '*' || c == '+' || c == '-') return 1;
    else return 0;
}

/* подсчет количества элементов на уровне level */
int var32(tnode *cur, tnode *parent, int level, int i)
{
    if(cur == NULL)
       return 0;
    else if(i == level && parent && is_operator(parent->data[0]) && (isdigit(cur->data[0]) || isalpha(cur->data[0])) )
       return 1;
    else {
        if(!cur->childs) return 0;
        return var32(cur->childs, cur, level, i+1) + var32(cur->childs->next, cur, level, i+1);
    }
}
