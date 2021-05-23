#include <stdio.h>
#include <stdlib.h>
#include "func.h"

void printMenu()
{
    printf("Menu:\n");
    printf("1) Print the table\n");
    printf("2) Find a table element by key\n");
    printf("3) Sort the table by keys\n");
    printf("4) Shuffle the data in the table\n");
    printf("5) Reverse the data in the table\n");
    printf("6) Finish the program\n");
}

int main(void)
{
    const int N = 50;
	int i, cnt, action;
	long key;
	char ch;
	row arr[N];
	FILE *file = fopen("input.txt", "r");
    if (file == NULL)
        {
            printf("Ошибка при открытии файла\n");
            return 0;
        }
        i = 0;
        while (i < N && fscanf(file, "%ld", &arr[i]._key) == 1)
        {
            fscanf(file, "%c", &ch);
            getRow(file, arr[i]._str, sizeof(arr[i]._str));
            i++;
        }
        fclose(file);
        cnt = i;
        do{
            printMenu();
            scanf("%d", &action);

            switch(action)
            {
                case 1:
                    printTable(arr, cnt);
                    break;
                case 2: 
                    if(!isSorted(arr, cnt)){
                        printf("The table is not sorted\n");
                    } else{
                        printf("Enter the key: ");
                        scanf("%ld", &key);
                        i = binSearch(arr, cnt, key);
                        if(i > -1){
                            printf("Element by this key: %s\n", arr[i]._str);
                        } else printf("There is no element with this key in the table!\n");
                    }
                    break;
                case 3:
                    sort(arr, cnt);
                    break;
                case 4:
                    scramble(arr, cnt);
                    break;
                case 5:
                    reverse(arr, cnt);
                    break;
                case 6:
                    break;
                default:
                    printf("There is no such item in the menu! Try a different value\n");
                    break;
            }

        } while(action != 6);

    return 0;
}
