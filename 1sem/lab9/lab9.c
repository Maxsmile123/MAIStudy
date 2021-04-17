#include<stdio.h>
#include<stdlib.h>
 
// Возвращает минимальное число среди двух
int min(int a, int b) 
{
    if (a > b) {
        return b;
    }
    else {
        return a;
    }
}
// Возвращает максимальное число среди двух
int max(int a, int b)
{
    if (a < b) {
        return b;
    }
    else {
        return a;
    }
}
// Проверяет, попадаем ли мы в нужную зону
int check_zone(int x, int y)
{
    if ((x > -10) && (x < 0) && (y > x + 10) && (y < 10 - x)) {
        return 1;
    }
    else {
        return 0;
    }
}
 
int mod(int a, int b)
{
    return (b + a % b) % b;
}
// Возвращает знак числа, либо 0, если это 0
int sign(int a)
{
    if (a > 0) {
        return 1;
    }
    else if (a < 0) {
        return -1;
    }
    else {
        return 0;
    }
}
 
int main(void)
{
    int k, i, j, l, i0, j0, l0;
    scanf("%d%d%d", &i0, &j0, &l0);
    for (k = 0; k < 50 && check_zone(i, j) == 0; ++k) {
        i = max(mod(min(i0 - j0, j0 - l0), 20), mod(min(i0 - l0, j0 - k), 20)) + 10;
        j = sign(i0 - j0) * min(mod(i0, 20), mod(j0, 20)) - mod(max(abs(i0 - l0), abs(k - 20)), 20) + 20;
        l = mod(i0, 10) * mod(j0, 10) + mod(l0, 10);
        i0 = i; j0 = j; l0 = l;
    }
    if (check_zone(i, j)) {
        printf("Yes \n");
    }
    else {
        printf("No \n");
    }
    printf("%d %c %d %c %d %c %d \n", i, ' ', j, ' ', l, ' ', k);
 
    return 0;
}

