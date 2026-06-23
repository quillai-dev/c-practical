/**
 * @file    t02.c
 * @brief   Theme 2, Task 4 -- Branching algorithms
 *
 * Quadrilateral ABCD is given by vertex coordinates.
 * Determine its type: rectangle, parallelogram, trapezoid,
 * or arbitrary quadrilateral.
 */
#include <stdio.h>
#include <math.h>

#define EPS 1e-9

typedef struct { double x, y; } P;

double cross(P a, P b, P c) {
    return (b.x-a.x)*(c.y-a.y) - (b.y-a.y)*(c.x-a.x);
}
int parallel(P a, P b, P c, P d) {
    return fabs(cross(a,b,d) - cross(a,b,c)) < EPS;
}

int main(void)
{
    P v[4];
    printf("Enter coordinates A B C D (x y for each):\n");
    for (int i = 0; i < 4; i++)
        scanf("%lf %lf", &v[i].x, &v[i].y);

    int ab_cd = parallel(v[0],v[1],v[2],v[3]);
    int bc_ad = parallel(v[1],v[2],v[3],v[0]);

    if (ab_cd && bc_ad) {
        double dx1 = v[1].x-v[0].x, dy1 = v[1].y-v[0].y;
        double dx2 = v[3].x-v[0].x, dy2 = v[3].y-v[0].y;
        if (fabs(dx1*dx2 + dy1*dy2) < EPS)
            printf("Rectangle\n");
        else
            printf("Parallelogram\n");
    } else if (ab_cd || bc_ad) {
        printf("Trapezoid\n");
    } else {
        printf("Arbitrary quadrilateral\n");
    }
    return 0;
}
