#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

/* TODO
* 1) Ввод данных в вектор из файла done
* 2) Печать матрицы - в виде схемы и в обычном матричном виде done
* 3) Написать функицю из 9 вара и вывести результат
*/

void print_menu() 
{
	printf("1) Print matrix\n");
	printf("2) Complete the task\n'q' for exit");
}

void vectorFill(Vector** CIP, Vector** PI, Vector** YE, FILE* file)
{
	int m, n, num;
	file = fopen("matrix.txt", "r");
	if (!file) {
		int count = 0; // number of num != 0
		fscanf(file, "%d%d", &m, &n);
		if (*CIP) free(*CIP);
		if (*PI) free(*PI);
		if (*YE) free(*YE);
		vectorCreate(*CIP, 1);
		vectorCreate(*PI, 1);
		vectorCreate(*YE, 1);
		for (int i = 1; i <= m; i++) {
			vectorPushBack(*CIP, count);
			for (int j = 1; j <= n; j++) {
				fscanf(file, "%d", &num);
				if (!num) {
					vectorPushBack(*PI, j);
					vectorPushBack(*YE, num);
					count++;
				}
			}
		}
	}
	fclose(file);
}

void matrixPrint(FILE *file) 
{
	int m, n, num;
	file = fopen("matrix.txt", "r");
	if (!file) {
		fscanf(file, "%d%d", &m, &n);
		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= n; j++) {
				fscanf(file, "%d", &num);
				printf("%d", num);
			}
			printf("\n");
		}
	}
}

int main(void)
{
	char c;
	int m, n, num;
	FILE *file;
	Vector *CIP = NULL, *PI = NULL, *YE = NULL;

	while ((c = getchar()) != EOF) 
	{
		print_menu();
		if (c == '\n')
			continue;
		switch (c) 
		{
		case '1':
			file = fopen("matrix.txt", "r");
			if (!file) {
				vectorFill(&CIP, &PI, &YE, file);
				matrixPrint(file);
				printf("CIP: ");
				vectorPrint(CIP, vectorSize(CIP));
				printf("PI: ");
				vectorPrint(PI, vectorSize(PI));
				printf("YE: ");
				vectorPrint(YE, vectorSize(YE));
			} else printf("File isn't exist!\n");
			fclose(file);
			break;
		case '2':
			file = fopen("matrix.txt", "r");
			if (!file) {
				fscanf(file, "%d%d", &m, &n);
				vectorFill(&CIP, &PI, &YE, file);
			}
			fclose(file);
			int count[n];
			for (int i = 0; i < n; i++)
				count[i] = 0;
			for (int i = 0; i < vectorSize(PI); i++)
				count[PI->_data[i]]++;
			int max, max_i = 0;
			for (int i = 0; i < n; i++)
				if (count[i] > max) {
					max = count[i];
					max_i = i;
				}
			printf("Column with the maximum number of elements: %d\n", max_i);
			int result = 1;
			for (int i = 0; i < vectorSize(PI); i++)
				if (PI->_data[i] == i) result *= YE->_data[i];
			printf("The product of the elements of this column: %d", result);
			break;
		case 'q':
			free(CIP);
			free(PI);
			free(YE);
			return 0;
		}
	}

}