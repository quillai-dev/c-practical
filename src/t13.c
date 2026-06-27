/**
 * @file    t13.c
 * @brief   Theme 13, Task 4 -- Graphical solution of equations
 *
 * Solve the 2x2 linear system by Cramer's rule:
 *   a1*x + b1*y = c1
 *   a2*x + b2*y = c2
 */
#include <stdio.h>

int main(void)
{
    double a1,b1,c1,a2,b2,c2;
    printf("Equation 1 (a1 b1 c1): ");
    scanf("%lf %lf %lf", &a1,&b1,&c1);
    printf("Equation 2 (a2 b2 c2): ");
    scanf("%lf %lf %lf", &a2,&b2,&c2);

    double det  = a1*b2 - a2*b1;
    double detX = c1*b2 - c2*b1;
    double detY = a1*c2 - a2*c1;

    if (det != 0) {
        printf("Unique solution: x=%.4f, y=%.4f\n",
               detX/det, detY/det);
    } else if (detX == 0 && detY == 0) {
        printf("Infinitely many solutions (lines coincide)\n");
    } else {
        printf("No solution (lines are parallel)\n");
    }
    return 0;
}
