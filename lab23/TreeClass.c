#include <stdio.h>
#include <stdlib.h>

#include "TreeClass.h"



Tree *root_create(int value) // Done
{
    Tree* tree = (Tree*)malloc(sizeof(Tree));
    tree->data = value;
    tree->left = NULL;
    tree->right = NULL;
    tree->parent = NULL;
    return tree;
}

Tree *tree_add_element(Tree *root, int value) // Done
{ 
    if (root == NULL) {
        printf("Done!\n\n");
        return root_create(value);
    }

    Tree *NewTree = (Tree*)malloc(sizeof(Tree));
    NewTree->data = value;
    Tree *tree1 = root;
    Tree *tree2 = NULL;

    while (tree1 != NULL) {
        tree2 = tree1;
        if (value < tree1->data)
            tree1 = tree1->left;
        else
            tree1 = tree1->right;
    }
    NewTree->parent = tree2;
    NewTree->left = NULL;
    NewTree->right = NULL;
    if (value < tree2->data) {
        tree2->left = NewTree;
    } else {
        tree2->right = NewTree;
    }
    printf("Done!\n\n");
    return root;
}

void tree_print(Tree *root, int n) // Done
{
    if (root != NULL) {
        tree_print(root->right, n + 1);
        for (int i = 0; i < n; i++) printf("\t");
        printf("%d\n", root->data);
        tree_print(root->left, n + 1);
    }
}

Tree *delete_element(Tree *root, int value) // Done
{ 
    Tree *tree1 = NULL, *tree2 = NULL, *tree3 = root;

    if (tree3 == NULL) {
        printf("Delete error! Your tree doesn't exist!");
        return NULL;
    }
    tree1 = search_in_tree(tree3, value);
    if (tree1 == NULL) {
        printf("Your element already doesn't exist!");
    }
    // Первый случай. Элемент == лист
    if (tree1->left == NULL && tree1->right == NULL) {
        tree2 = tree1->parent;
        if (tree2->left == tree1) {
            tree2->left = NULL;
        } else {
            tree2->right = NULL; 
        }
        free(tree1);
    }
    // Второй случай. У элемента есть одно поддерево
    else if (tree1->left != NULL && tree1->right == NULL) {
        tree2 = tree1->parent;
        if (tree2->left == tree1) {
            tree2->left = tree1->left;
        }
        else {
            tree2->right = tree1->left;
        }
        free(tree1);
    } else if (tree1->left == NULL && tree1->right != NULL) {
        tree2 = tree1->parent;
        if (tree2->left == tree1) {
            tree2->left = tree1->right;
        }
        else {
            tree2->right = tree1->right;
        }
        free(tree1);
    }
    // 3 случай. Имеются оба поддеререва
    else if (tree1->left != NULL && tree1->right != NULL) {
        tree2 = minimum(tree1->right);
        tree1->data = tree2->data;
        if (tree2->parent->left == tree2) {
            free(tree2);
            tree2->parent->left = NULL;
        }
        if (tree2->parent->right == tree2) {
            free(tree2);
            tree2->parent->right = NULL;
        }
    return root;
}

Tree *search_in_tree(Tree *root, int value) // Done
{
    if (root == NULL) {
        printf("Search error! Value doesn't exist!");
        return NULL;
    }
    if (root->data == value) {
        return root;
    }
    if (value > root->data) {
        return search_in_tree(root->right,value);
    } else {
        return search_in_tree(root->left, value);
    }
}

Tree *minimum(Tree *t) 
{
    if (t->left == NULL) {
        return t;
    }
    return minimum(t->left);
}

Tree *maximum(Tree *t) {
    if (t->right == NULL) {
        return t;
    }
    return maximum(t->right);
}

int is_AVL(Tree *t) 
{

}