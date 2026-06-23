/**
 * @file    t04.c
 * @brief   Theme 4, Task 4 -- Basic array operations
 *
 * Compute the mean m and variance d for a given array X(n)
 * of observations.
 * d = (1/n) * sum((x_i - m)^2)
 */
#include <stdio.h>

#define MAXN 100

int main(void)
{
    double x[MAXN];
    int n;

    printf("Enter number of elements n: ");
    scanf("%d", &n);
    printf("Enter array elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%lf", &x[i]);

    double sum = 0;
    for (int i = 0; i < n; i++) sum += x[i];
    double m = sum / n;

    double dsum = 0;
    for (int i = 0; i < n; i++) dsum += (x[i]-m)*(x[i]-m);
    double d = dsum / n;

    printf("Mean m = %.4f\n", m);
    printf("Variance d = %.4f\n", d);
    return 0;
}
