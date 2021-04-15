#include <stdio.h>
#include "TreeClass.h"


void print_menu() {
	printf("\nSelect the desired action by writing the appropriate number:\n");
	printf("1) Add an item to the tree\n");
	printf("2) Print the tree\n");
	printf("3) Remove an item from the tree\n");
	printf("4) Check if the tree is an AVL tree\n");
	printf("5) Search for the minimum tree element\n");
	printf("6) Search for the maximum tree element\n");
	printf("Enter 0 for exit\n");
}

int main(void) 
{
	Tree *t = NULL;
	int value;
	char c;
	printf("Welcome to the program for processing binary search trees!\n");
	print_menu();
	while ((c = getchar()) != EOF) {
		value = 0;
		if (c == '\n') continue;
		switch (c) {
		case '1':
			printf("\nEnter the value you want to add to the tree:");
			scanf_s("%d", &value);
			t = tree_add_element(t, value);
			break;
		case '2':
			tree_print(t, 1);
			break;
		case '3':
			printf("\nEnter the value you want to delete from the tree: ");
			scanf_s("%d", &value);
			t = delete_element(t, value);
			break;
		case '4':
			if (is_AVL(t)) printf("\nYes, your tree is AVL tree\n");
			else printf("\nNo, your tree doesn't AVL tree :( \n");
			break;
		case '5':
			printf("\nminimum element from your tree is %d\n", minimum(t)->data);
			break;
		case '6':
			printf("\nmaximum element from your tree is %d\n", maximum(t)->data);
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
