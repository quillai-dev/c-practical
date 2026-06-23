/**
 * @file    t03.c
 * @brief   Theme 3, Task 4 -- Iterative algorithms
 *
 * Rectangle on the plane: x=[x1,x2], y=[y1,y2].
 * Rectangle dimensions are entered sequentially; while reading,
 * compute the area of their intersection.
 */
#include <stdio.h>

int main(void)
{
    double cx1, cy1, cx2, cy2;
    double x1, y1, x2, y2;
    int n;

    printf("Enter number of rectangles: ");
    scanf("%d", &n);

    printf("First rectangle (x1 y1 x2 y2): ");
    scanf("%lf %lf %lf %lf", &cx1, &cy1, &cx2, &cy2);

    for (int i = 1; i < n; i++) {
        printf("Rectangle %d (x1 y1 x2 y2): ", i+1);
        scanf("%lf %lf %lf %lf", &x1, &y1, &x2, &y2);

        double lx = cx1 > x1 ? cx1 : x1;
        double ly = cy1 > y1 ? cy1 : y1;
        double rx = cx2 < x2 ? cx2 : x2;
        double ry = cy2 < y2 ? cy2 : y2;

        if (rx > lx && ry > ly) {
            cx1 = lx; cy1 = ly; cx2 = rx; cy2 = ry;
            printf("  Intersection: [%.2f,%.2f]x[%.2f,%.2f]\n",
                   cx1, cx2, cy1, cy2);
        } else {
            printf("  Intersection is empty\n");
            cx1=cx2=cy1=cy2=0;
        }
    }

    double area = (cx2-cx1) * (cy2-cy1);
    if (area < 0) area = 0;
    printf("Total intersection area: %.4f\n", area);
    return 0;
}
