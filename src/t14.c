/**
 * @file    t14.c
 * @brief   Theme 14, Task 4 -- Plane in 3D space
 *
 * Plane given by Ax+By+Cz+D=0.
 * Find the distance from point (x0,y0,z0) to the plane
 * and the projection of the point onto the plane.
 */
#include <stdio.h>
#include <math.h>

int main(void)
{
    double A,B,C,D, x0,y0,z0;
    printf("Plane coefficients (A B C D): ");
    scanf("%lf %lf %lf %lf", &A,&B,&C,&D);
    printf("Point (x0 y0 z0): ");
    scanf("%lf %lf %lf", &x0,&y0,&z0);

    double norm = sqrt(A*A+B*B+C*C);
    double t = -(A*x0+B*y0+C*z0+D) / (norm*norm);
    double dist = fabs(A*x0+B*y0+C*z0+D) / norm;

    printf("Distance from point to plane: %.4f\n", dist);
    printf("Projection onto plane: (%.4f, %.4f, %.4f)\n",
           x0+A*t, y0+B*t, z0+C*t);
    return 0;
}
