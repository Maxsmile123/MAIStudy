#ifndef TABLE_H
#define TABLE_H

#include <stdio.h>

typedef struct _row{
    long int _key;
    char _str[120];
} row;
void printTable(row *arr, const int size); // Печать таблицы
void getRow(FILE *stream, char *str, const int size); // Получить одну строку из файла
void swapRows(row *r1, row *r2); // swap for row


#endif
