#include <stdio.h>
#include <list.h>
#include <iterator.h>



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
	list *lst = create();
	char c;
	printf("Welcome to the list processing program!\n");
	print_menu();
	while ((c = getchar()) != EOF) {
		if (c == '\n') continue;
		switch (c) {
		case '1':
			item data;
			printf("Enter the value you want to add:");
			scanf("%c", &data);
			listInsert(lst, data);
			break;
		case '2':
			listPrint(lst);
			break;
		case '3':
			item data;
			printf("Enter the value you want to delete:");
			scanf("%c", &data);
			listRemove(lst, data);
			break;
		case '4':
			listLen(lst);
			break;
		case '5':
			listIterator *it = iteratorCreate(lst); 
			for(int j = 0; j < listLen(lst); j++){ // seatch for tail list_node
        		iteratorNext(it);
    		}
			listReverse(lst->head, it->node, 1, lst);
			free(it);
			break;
		case '0':
			printf("\nHave a nice day!\n");
			return 0;
		default:
			printf("The number you entered isn't in the menu :(\nPlease try again, in case you made a mistake\n");
			break;
		}
		print_menu();
	}
}
