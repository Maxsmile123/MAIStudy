#ifndef LIST_H 
#define LIST_H


typedef char item;
typedef struct _list_node list_node;

typedef struct _list_node{
    item data;
    list_node *next;
} list_node;

typedef struct{
    list_node *head;
} list;

list* listCreate(); // Done
void listPrint(list *l); // Done
void listInsert(list *lst, item data);
void listRemove(list *lst, item data);
int listLen(list *lst);
void listReverse(list_node *lstFromHead, list_node *lstFromTail, int i, list *lst, int len);

#endif
