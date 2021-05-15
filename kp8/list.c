#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "iterator.h"


list* listCreate()
{
    list *lst = (list*) malloc(sizeof(list));
    lst->head = (list_node*) malloc(sizeof(list_node));
    lst->head->next = NULL;
    return lst;
}


void listPrint(list *lst)
{
    listIterator *it = iteratorCreate(lst); 
    if(it->node){
        while(it->node)
        {
           printf("%c-->", it->node->data);
           iteratorNext(it);     
        }
    } else printf("The list doesn't exist!\n");
    free(it);
}


void listInsert(list *lst, item data)
{
    listIterator *it = iteratorCreate(lst); 
    if(it->node){
        while(it->node->next) // next item is NULL!
        {
           iteratorNext(it);     
        }
        list_node *tail = (list_node*) malloc(sizeof(list_node));
        tail->next = NULL;
        it->node->data = data;
        it->node->next = tail;
    } else printf("The list doesn't exist!\n");
    free(it);
}


void listRemove(list *lst, item data)
{
    int flag = 0;
    listIterator *it = iteratorCreate(lst);
    list_node *prew;
    if(it->node){ 
        if(it->node->data == data){  // case, then out node is head
            free(it->node);
            it->node = NULL;
        } else {
            while(it->node->next){
                if(it->node->next->data == data) // case, then our node between two elements or is tail
                {
                    prew = it->node;
                    iteratorNext(it);
                    flag = 1;
                    if(it->node->next != NULL){
                        prew->next = it->node->next;
                    }
                    free(it->node);
                    it->node = NULL;
                    break;    
                }
                iteratorNext(it);
            }
        if(!flag) printf("There is no such element\n");
        }
    } else printf("The list doesn't exist!\n");
    free(it);
}

int listLen(list *lst)
{
    int count = 0;
    listIterator *it = iteratorCreate(lst); 
    if(it->node){
        while(it->node)
        {
           count++;
           iteratorNext(it);     
        }
    } else printf("The list doesn't exist!\n");
    free(it);
    return count;
}

void listReverse(list_node *lstFromHead, list_node *lstFromTail, int i, list *lst)
{
    if(i == listLen(lst)/2) return;
    list_node *lstFromHeadNext = lstFromHead->next;
    list_node *lstFromTailPrew;
    listIterator *it = iteratorCreate(lst);
    for(int j = 0; j < listLen(lst) - i; j++){
        iteratorNext(it);
    }
    lstFromTailPrew = it->node;
    if(i == 1){
        lstFromHead->next = NULL;
    } else{
        lstFromTailPrew->next = lstFromHead;
    }
    lstFromTail->next = lstFromHeadNext;
    free(it);
    listReverse(lstFromHeadNext, lstFromTailPrew, ++i, lst);

}
