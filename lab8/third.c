#include<stdio.h>
int main(void)
{
    int a = 0, i = 0, b = 0;
    long int sum = 0;
    scanf("%d", &b);
    for (i = 0; i < b; i++) {
        scanf("%d", &a);
        if (a >= 10) {
            sum = sum + a;
        }
    }
    printf("%ld\n",
 sum);
    return 0;
}
