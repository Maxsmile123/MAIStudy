#include<stdio.h>
 
 
int main(void)
{
    int tests, size, i, j, k, mark, first, second, sum, max_size;
    long long max, min;
    scanf("%d%d", &tests, &max_size);
    int matrix[max_size][max_size];
    for (i = 0; i < tests; i++) {
        scanf("%d", &size);
        mark = 0;
        max = -9223372036854775807 - 1;
        min = 9223372036854775807;
        sum = 0;
        first = second = 0;
        for (j = 0; j < size * size; j++) {
            if (j % size == 0 && j != 0) {
                mark++;
            }
            scanf("%d", &matrix[mark][j % size]);
        }
        if (size == 1) {
            printf("%d\n", matrix[0][0]);
            continue;
        }
        for (j = 0; j < size; j++) {
            for (k = 0; k < size; k++) {
                sum += matrix[k][j];
            } if (sum > max) {
                max = sum;
                first = j;
            } if (sum < min) {
                min = sum;
                second = j;
            }
            sum = 0;
        }
        if (first != second && max != min) {
            for (j = 0; j < size; j++) {
                matrix[j][first] = matrix[j][first] ^ matrix[j][second];
                matrix[j][second] = matrix[j][second] ^ matrix[j][first];
                matrix[j][first] = matrix[j][first] ^ matrix[j][second];
            }
        }
        for (j = 0; j < size; j++) {
            for (k = 0; k < size; k++) {
                printf("%d%c", matrix[j][k], ' ');
            }
            printf("\n");
        }
    }
    return 0;
} 
