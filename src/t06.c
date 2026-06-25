/**
 * @file    t06.c
 * @brief   Theme 6, Task 4 -- Linear search
 *
 * Given n linear functions y = k1*x+b1, ..., kn*x+bn.
 * Find the minimum value of the "upper envelope" of these
 * functions, i.e. f(x) = max(ki*x+bi) at a given point x.
 */
#include <stdio.h>

#define MAXN 50

int main(void)
{
    double k[MAXN], b[MAXN];
    int n;
    double x;

    printf("Enter number of functions n: ");
    scanf("%d", &n);
    printf("Enter coefficients k_i b_i for each function:\n");
    for (int i = 0; i < n; i++)
        scanf("%lf %lf", &k[i], &b[i]);

    printf("Enter value of x: ");
    scanf("%lf", &x);

    double maxv = k[0]*x + b[0];
    int idx = 0;
    for (int i = 1; i < n; i++) {
        double v = k[i]*x + b[i];
        if (v > maxv) { maxv = v; idx = i; }
    }

    printf("Upper envelope at x=%.2f: f(x)=%.4f (function %d)\n",
           x, maxv, idx+1);
    return 0;
}
