#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "iterator.h"



void print_menu() {
	printf("\nSelect the desired action by writing the appropriate number:\n");
	printf("1) Add an item to the list(at the end)\n");
	printf("2) Print the list\n");
	printf("3) Remove an item from the list\n");
	printf("4) Length of the list\n");
	printf("5) Rearrange the list items in reverse order\n");
	printf("Enter 0 for exit\n");
}

int main(void) 
{
	item data;
	char rubish;
	list *lst = listCreate();
	listIterator *it = iteratorCreate(lst); 
	char c;
	printf("Welcome to the list processing program!\n");
	print_menu();
	while ((c = getchar()) != EOF) {
		iteratorSet(lst->head,it);
		if (c == '\n' && c == ' ') continue;
		switch (c) {
		case '1':
			printf("Enter the value you want to add: ");
			rubish = getchar();
			data = getchar();
			listInsert(lst, data);
			break;
		case '2':
			listPrint(lst);
			break;
		case '3':
			printf("Enter the value you want to delete: ");
			rubish = getchar();
			data = getchar();
			listRemove(lst, data);
			break;
		case '4':
			printf("%d", listLen(lst));
			break;
		case '5':
			iteratorSet(lst->head,it);
			for(int j = 0; j < listLen(lst) - 1; j++){ // search for tail list_node
        		iteratorNext(it);
    		}
			listReverse(lst->head, it->node, 1, lst, listLen(lst));
			iteratorSet(lst->head,it);
			for(int j = 0; j < listLen(lst) - 1; j++){ // search for tail list_node
        		iteratorNext(it);
    		}
			list_node *tail = (list_node*) malloc(sizeof(list_node));
        		tail->next = NULL; 
        		tail->data = ' ';  
			it->node->next = tail;
			break;
		case '0':
			printf("\nHave a nice day!\n");
			free(it);
			free(lst);
			return 0;
		default:
			printf("The number you entered isn't in the menu :(\nPlease try again, in case you made a mistake\n");
			break;
		}
		print_menu();
	}
}
