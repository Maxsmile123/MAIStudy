#include <math.h>
#include <stdio.h>

int main(void)
{
    int n, k;
    scanf_s("%d %d", &n, &k);
    double e0 = 1.0, d = 1.0 / (double)n;
    while ((1.0 + e0 / 2.0) > 1.0)
    {
        e0 = e0 / 2.0;
    }
    printf("Machine epsilon equals %.8e\n", e0);
    printf("--------------------------------------\n");
    double acc = e0 * pow(10, 16 - k);
    double x = 0.0, ans1, ans2, count, cur, cur0, cur1;

    double e = 2.7182818284;
    for(int i = 0; i <= n; i++)
    {
        ans1 = 0;
        ans2 = (1 + 2 * x * x) * (pow(e, x * x));

        count = 0.0;
        cur = 1.0;
        cur0 = 1.0;
        cur1 = 1.0;
        
        while(fabs(ans1 - ans2) > acc)
        {
            count ++;
            cur0 *= 1 / count;
            cur1 = (2 * count + 1) * pow(x, 2 * count);
            cur = cur0 * cur1;
            ans1 += cur;
        }
        
        printf("%.2f | %.*f | %.*f | %d | %.*f\n", x, k + 1, ans1, k + 1, ans2, (int)count, k + 1, fabs(ans2 - ans1));
        x += d;
    }
    return 0;
}
