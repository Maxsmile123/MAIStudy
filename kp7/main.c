#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

void print_menu() 
{
	printf("1) Print matrix\n");
	printf("2) Complete the task\n0 for exit\n");
}

void vectorFill(Vector** CIP, Vector** PI, Vector** YE, FILE* file, int m, int n)
{
	int num;
	if (file) {
		int count = 0; // number of num != 0
		if (*CIP) free(*CIP);
		if (*PI) free(*PI);
		if (*YE) free(*YE);
		*CIP = vectorCreate(1);
		*PI = vectorCreate(1);
		*YE = vectorCreate(1);
		for (int i = 1; i <= m; i++) {
			vectorPushBack(*CIP, count);
			for (int j = 1; j <= n; j++) {
				fscanf(file, "%d", &num);
				if (num) {
					vectorPushBack(*PI, j);
					vectorPushBack(*YE, num);
					count++;
				}
			}
		}
	}
	fclose(file);
}

void matrixPrint(Vector *CIP, Vector *PI, Vector *YE, int m, int n) 
{
	int PIi = 0;
	int CIPi = 1;
	if(CIP && PI && YE){
		for(int i = 0; i < vectorSize(CIP); i++){
			for(int j = 1; j <= n; j++){
				if(PI->_data[PIi] == j){ 
					printf("%d ", YE->_data[PIi]);
					PIi++;
				} else printf("0 ");
				if(CIPi < m)
					if(CIP->_data[CIPi] == PIi){
						CIPi++;
						for(int k = 0; k < n - j; k++)
							printf("0 ");
						printf("\n");
						break;
					}
			}
		}
	}
	printf("\n");
}


int main(void)
{
	char c;
	int m, n, num;
	FILE *file;
	Vector *CIP = NULL,*PI = NULL,*YE = NULL;
	Vector *v1 = NULL;
	v1 = vectorCreate(1);
	print_menu();
	while ((c = getchar()) != EOF) 
	{
		if (c == '\n') continue;
		file = fopen("matrix.txt", "r");
		if (file) { 
			fscanf(file, "%d%d", &m, &n);
			vectorFill(&CIP, &PI, &YE, file, m, n);
			switch (c) 
			{
			case '1':
				matrixPrint(CIP, PI, YE, m, n);
				printf("CIP: ");
				vectorPrint(CIP, vectorSize(CIP));
				printf("PI: ");
				vectorPrint(PI, vectorSize(PI));
				printf("YE: ");
				vectorPrint(YE, vectorSize(YE));
				break;
			case '2':
				vectorResize(v1, n + 1);
				for (int i = 0; i < vectorSize(v1); i++)
					v1->_data[i] = 0;
				for (int i = 0; i < vectorSize(PI); i++)
					v1->_data[PI->_data[i]]++;
				int max = 0, max_i1 = 0;
				int max_i2 = 0;
				int flag = 0;
				for (int i = 1; i < vectorSize(v1); i++)
					if (v1->_data[i] > max) {
						max = v1->_data[i];
						max_i1 = i;
						flag = 0;
					} else if(v1->_data[i] == max){
						max_i2 = max_i1;
						max_i1 = i;
						flag = 1;
					}
				if(flag) max_i1 = max_i2;
				printf("Column with the maximum number of elements: %d\n", max_i1);
				int result = 1;
				for (int i = 0; i < vectorSize(PI); i++)
					if (PI->_data[i] == max_i1) result *= YE->_data[i];
				printf("The product of the elements of this column: %d\n", result);
				break;
			case '0':
				vectorDestroy(CIP);
				vectorDestroy(PI);
				vectorDestroy(YE);
				vectorDestroy(v1);
				return 0;
			default:
				printf("There is no such option! I guess you made a mistake : (\nGoodbye!\n");
				return 0;

			}
			print_menu();
		} else printf("File isn't exist!\n");	
	}

}
