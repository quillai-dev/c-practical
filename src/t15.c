/**
 * @file    t15.c
 * @brief   Theme 15, Task 4 -- Quadric surfaces
 *
 * Ellipsoid: x^2/a^2 + y^2/b^2 + z^2/c^2 = 1
 * Determine whether a given point lies inside, on the surface,
 * or outside the ellipsoid.
 */
#include <stdio.h>
#include <math.h>

int main(void)
{
    double a, b, c, x, y, z;
    printf("Semi-axes of ellipsoid (a b c): ");
    scanf("%lf %lf %lf", &a, &b, &c);
    printf("Point (x y z): ");
    scanf("%lf %lf %lf", &x, &y, &z);

    double val = (x*x)/(a*a) + (y*y)/(b*b) + (z*z)/(c*c);
    const double EPS = 1e-6;

    if (fabs(val - 1.0) < EPS)
        printf("Point is on the ellipsoid surface (f=%.6f)\n", val);
    else if (val < 1.0)
        printf("Point is inside the ellipsoid (f=%.6f)\n", val);
    else
        printf("Point is outside the ellipsoid (f=%.6f)\n", val);

    return 0;
}
