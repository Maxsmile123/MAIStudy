#ifndef FUNC_H
#define FUNC_H

#include "table.h"

int binSearch(const row *arr, const int size, const long int key); // Бинарный поиск в таблице по ключу
void sort(row *arr, const int size); // Сортировка методом пузырька
void scramble(row *arr, const int size); // Перемешивание данных в таблице
void reverse(row *arr, const int size); // Реверс данных в таблице
int randomAB(const int a, const int b); 
int isSorted(const row *arr, const int size); // Проверка на отсортированность таблицы


#endif
