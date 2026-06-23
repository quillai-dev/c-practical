/**
 * @file    t01.c
 * @brief   Theme 1, Task 4 -- Linear algorithms
 *
 * Given start and end moments of a time interval in hours,
 * minutes and seconds (within one day). Find the duration
 * of this interval in the same units.
 */
#include <stdio.h>

int main(void)
{
    int h1, m1, s1, h2, m2, s2;

    printf("Start (hh mm ss): ");
    scanf("%d %d %d", &h1, &m1, &s1);
    printf("End   (hh mm ss): ");
    scanf("%d %d %d", &h2, &m2, &s2);

    int t1 = h1*3600 + m1*60 + s1;
    int t2 = h2*3600 + m2*60 + s2;
    int dt = t2 - t1;
    if (dt < 0) dt += 86400;

    int dh = dt / 3600;
    int dm = (dt % 3600) / 60;
    int ds = dt % 60;

    printf("Duration: %02d h %02d min %02d s\n", dh, dm, ds);
    return 0;
}
