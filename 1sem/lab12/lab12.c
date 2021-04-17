#include <stdio.h>
#include <stdlib.h>
 
int digits(int number) // Возвращает кол-во цифр в числе
{
    if (number == 0) {
        return 1;
    }
    int power = 0;
    while (number > 0) {
        number /= 10;
        power++;
    }
    return power;
}
 
int fpeek(void) // Для проверки, что символ != EOF
{
    int c;
    c = fgetc(stdin);
    ungetc(c, stdin);
    return c;
}
 
int pows(int number, int power) // Точный аналог функции pow
{
    int returnNumber = 1;
    for (int i = 0; i < power; i++) {
        returnNumber *= number;
    }
    return returnNumber;
}
 
void binary(int digit) // Распечатка цифры в двоичной системе счисления
{
    switch (digit) {
        case 0:
            printf("%d%d%d%d", 0, 0, 0, 0);
            break;
        case 1:
            printf("%d%d%d%d", 0, 0, 0, 1);
            break;
        case 2:
            printf("%d%d%d%d", 0, 0, 1, 0);
            break;
        case 3:
            printf("%d%d%d%d", 0, 0, 1, 1);
            break;
        case 4:
            printf("%d%d%d%d", 0, 1, 0, 0);
            break;
        case 5:
            printf("%d%d%d%d", 0, 1, 0, 1);
            break;
        case 6:
            printf("%d%d%d%d", 0, 1, 1, 0);
            break;
        case 7:
            printf("%d%d%d%d", 0, 1, 1, 1);
            break;
        case 8:
            printf("%d%d%d%d", 1, 0, 0, 0);
            break;
        case 9:
            printf("%d%d%d%d", 1, 0, 0, 1);
            break;
    }
}

int main(void)
{
    long long border = -1 * pows(2, 31); // INT_MIN
    int number = 0;
    int powerOfTen = 0;
    while (fpeek() != EOF) {
        if (scanf("%d", &number) == -1) {
            break;
        }
        if (number == border) { // Костыль для обработки INT_MIN
            printf("-0010000101000111010010000011011001001000\n");
        } else {
            if (number < 0) { // Для отрицательных чисел
                printf("%c", '-');
            }
            powerOfTen = digits(abs(number));
            while (powerOfTen > 0) {
                binary(abs(number) / (pows(10, powerOfTen - 1)));
                number %= pows(10, powerOfTen - 1);
                powerOfTen--;
            }
            printf("\n");
        }
    }
    return 0;
}
