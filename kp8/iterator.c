
#include <stdlib.h>
#include "iterator.h"

listIterator *iteratorCreate(list *lst)
{
    listIterator *it = (listIterator*) malloc(sizeof(listIterator));
    it->node = lst->head;
    return it;
}
void iteratorNext(listIterator *it)
{
    if (it->node == NULL)
    {
        printf("You have met a barrier element! The list is finished\n");
    } else { 
        it->node = it->node->next;
    }
}

list_node* iteratorGet(listIterator *it)
{
    return it->node;
}

void iteratorSet(list_node* lst, listIterator* it)
{
    it->node = lst;
}
