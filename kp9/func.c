#include <time.h>
#include <stdlib.h>
#include "table.h"

int binSearch(const row *arr, const int size, const long int key)
{
    int start = 0, end = size - 1, mid;

	if (size <= 0)
		return -1;

	while (start < end)
	{
		mid = start + (end - start) / 2;

		if (arr[mid]._key == key)
			return mid;
		else if (arr[mid]._key < key)
			start = mid + 1;
		else
			end = mid;
	}

	if (arr[end]._key == key)
		return end;

	return -1;
}

void sort(row *arr, const int size)
{
    for(int j = 1; j < size - 1; j++)
        for(int i = 0; i < size - j; i++)
            if(arr[i]._key > arr[i+1]._key){
                swapRows(&arr[i], &arr[i+1]);
            }
}

int randomAB(const int a, const int b)
{
    return a + rand() % (b - a + 1);
}

void scramble(row *arr, const int size)
{
	int i, j, k;

	srand((unsigned int)time(0));

	for (k = 0; k < size; k++)
	{
		i = randomAB(0, size - 1);
		j = randomAB(0, size - 1);

		swapRows(&arr[i], &arr[j]);
	}
} 

void reverse(row *arr, const int size)
{
    int i, j;
	for (i = 0, j = size - 1; i < j; i++, j--)
		swapRows(&arr[i], &arr[j]);
}

int isSorted(const row *arr, const int size)
{
	for (int i = 0; i < size - 1; i++)
		if (arr[i]._key > arr[i + 1]._key)
			return 0;

	return 1;
}
