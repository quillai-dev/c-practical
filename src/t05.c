/**
 * @file    t05.c
 * @brief   Theme 5, Task 4 -- Vectors and matrices
 *
 * A cube consists of N^3 transparent and opaque elementary
 * unit cubes. Build the visibility projection along the Z axis:
 * a projection cell is visible (opaque) if at least one cube
 * in the corresponding column along Z is opaque.
 */
#include <stdio.h>

#define N 3

int main(void)
{
    /* cube[i][j][k]: 1 = opaque, 0 = transparent */
    int cube[N][N][N] = {0};

    printf("Enter cube %dx%dx%d (1=opaque, 0=transparent):\n", N,N,N);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            for (int k = 0; k < N; k++)
                scanf("%d", &cube[i][j][k]);

    /* projection along z-axis: visible if any cube along k is opaque */
    printf("Projection along Z axis:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int vis = 0;
            for (int k = 0; k < N; k++)
                if (cube[i][j][k]) vis = 1;
            printf("%d ", vis);
        }
        printf("\n");
    }

    int total = 0;
    for (int i=0;i<N;i++) for(int j=0;j<N;j++) for(int k=0;k<N;k++)
        total += cube[i][j][k];
    printf("Total opaque cubes: %d of %d\n", total, N*N*N);
    return 0;
}
