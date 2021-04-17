#include<stdio.h>
 
void printOneRound(int max_size, int matrix[max_size][max_size], int size, int mark)
{
    int sizeFori = size;
    size += mark;
    int i;
    for (i = 0; i < sizeFori ; i++) {
        printf("%d%c", matrix[mark][mark + i], ' ');
    }
    for (i = 1; i < sizeFori; i++) {
        printf("%d%c", matrix[mark + i][size - 1], ' ');
    }
    for (i = 1; i < sizeFori ; i++) {
        printf("%d%c", matrix[size - 1][size - 1 - i], ' ');
    }
    if (size > 2) {
        for (i = 1; i < sizeFori - 1; i++) {
            printf("%d%c", matrix[size - 1 - i][mark], ' ');
        }
    }
}
 
int div_up(int x, int y)
{
    return (x + y - 1) / y;
}
 
int main(void)
{
    int tests, max_size, size, i, j, mark;
    scanf("%d%d", &tests, &max_size);
    int matrix[max_size][max_size];
    mark = 0;
    int size1;
    for (i = 0; i < tests; i++) {
        scanf("%d", &size);
        size1 = size;
        for (j = 0; j < size1 * size1; j++) {
            if (j % size == 0 && j != 0) {
                mark++;
            }
            scanf("%d", &matrix[mark][j % size]);
        }
        mark = 0;
        for (j = 0; j < div_up(size1, 2); j++) {
            if (size == 1) {
                printf("%d", matrix[mark][mark]);
                break;
            }
            printOneRound(max_size, matrix, size, mark);
            mark++;
            size -= 2;
        }
        mark = 0;
        printf("\n");
    }
    return 0;
} 
