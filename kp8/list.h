#ifndef LIST.H
#define LIST.H

typedef char item;

typedef struct{
    item data;
    list_node *next;
} list_node;

typedef struct{
    list_node *head;
} list;

list* listCreate(); // Done
void listPrint(list *lst); // Done
void listInsert(list *lst, item data);
void listRemove(list *lst, item data);
int listLen(list *lst);
void listReverse(list_node *lstFromHead, list_node *lstFromTail, int i, list *lst);

#endif
