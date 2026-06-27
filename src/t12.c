/**
 * @file    t12.c
 * @brief   Theme 12, Task 4 -- Conics (second-order curves)
 *
 * A rectangle is specified by center (cx,cy), width w,
 * height h, and rotation angle theta (degrees).
 * Find the coordinates of its four vertices.
 */
#include <stdio.h>
#include <math.h>

int main(void)
{
    double cx, cy, w, h, theta;
    printf("Rectangle center (cx cy): ");
    scanf("%lf %lf", &cx, &cy);
    printf("Width and height (w h): ");
    scanf("%lf %lf", &w, &h);
    printf("Rotation angle (degrees): ");
    scanf("%lf", &theta);

    double rad = theta * M_PI / 180.0;
    double dx[4] = {-w/2,  w/2,  w/2, -w/2};
    double dy[4] = {-h/2, -h/2,  h/2,  h/2};

    printf("Rectangle vertices:\n");
    for (int i = 0; i < 4; i++) {
        double rx = dx[i]*cos(rad) - dy[i]*sin(rad);
        double ry = dx[i]*sin(rad) + dy[i]*cos(rad);
        printf("  (%.4f, %.4f)\n", cx+rx, cy+ry);
    }
    return 0;
}
