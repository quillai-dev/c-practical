/**
 * @file    t07.c
 * @brief   Theme 7, Task 4 -- Arithmetic
 *
 * Array X(n) holds distinct real numbers.
 * Round each value to 3 significant digits.
 */
#include <stdio.h>
#include <math.h>

double round3sig(double x)
{
    if (x == 0) return 0;
    int sign = x < 0 ? -1 : 1;
    x = fabs(x);
    int exp = (int)floor(log10(x));
    double factor = pow(10, 2 - exp);
    double rounded = round(x * factor) / factor;
    return sign * rounded;
}

int main(void)
{
    double x[50];
    int n;

    printf("Enter number of elements n: ");
    scanf("%d", &n);
    printf("Enter array elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%lf", &x[i]);

    printf("Rounded values (3 significant digits):\n");
    for (int i = 0; i < n; i++) {
        double r = round3sig(x[i]);
        printf("  %.6g -> %.6g\n", x[i], r);
    }
    return 0;
}
