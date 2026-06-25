/**
 * @file    t08.c
 * @brief   Theme 8, Task 4 -- Geometry and set theory
 *
 * From a numeric set of cardinality n, select all subsets
 * whose element sum lies within [a, b].
 */
#include <stdio.h>

int main(void)
{
    int x[20], n;
    double a, b;

    printf("Enter set cardinality n: ");
    scanf("%d", &n);
    printf("Enter set elements:\n");
    for (int i = 0; i < n; i++) scanf("%d", &x[i]);

    printf("Enter bounds a b: ");
    scanf("%lf %lf", &a, &b);

    long long total = 1LL << n;
    int found = 0;

    printf("Subsets with sum in [%.1f, %.1f]:\n", a, b);
    for (long long mask = 0; mask < total; mask++) {
        int sum = 0;
        for (int i = 0; i < n; i++)
            if (mask & (1LL << i)) sum += x[i];

        if (sum >= a && sum <= b) {
            found++;
            printf("  {");
            int first = 1;
            for (int i = 0; i < n; i++) {
                if (mask & (1LL << i)) {
                    if (!first) printf(",");
                    printf("%d", x[i]);
                    first = 0;
                }
            }
            printf("}  sum=%d\n", sum);
        }
    }
    printf("Subsets found: %d\n", found);
    return 0;
}
