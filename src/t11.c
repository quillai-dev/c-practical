/**
 * @file    t11.c
 * @brief   Theme 11, Task 4 -- Analytic geometry
 *
 * Find the angle between two intersecting lines given by general
 * equations a1*x+b1*y+c1=0 and a2*x+b2*y+c2=0.
 */
#include <stdio.h>
#include <math.h>

int main(void)
{
    double a1,b1,c1,a2,b2,c2;
    printf("Line 1 (a1 b1 c1): ");
    scanf("%lf %lf %lf", &a1,&b1,&c1);
    printf("Line 2 (a2 b2 c2): ");
    scanf("%lf %lf %lf", &a2,&b2,&c2);

    double dot = a1*a2 + b1*b2;
    double n1 = sqrt(a1*a1+b1*b1);
    double n2 = sqrt(a2*a2+b2*b2);

    double cosA = dot / (n1*n2);
    if (cosA > 1) cosA = 1;
    if (cosA < -1) cosA = -1;

    double angleRad = acos(fabs(cosA));
    double angleDeg = angleRad * 180.0 / M_PI;

    int deg = (int)angleDeg;
    int min = (int)round((angleDeg - deg) * 60);

    printf("Angle between lines: %.6f rad = %d deg %d min\n",
           angleRad, deg, min);
    return 0;
}
