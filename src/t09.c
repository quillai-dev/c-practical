/**
 * @file    t09.c
 * @brief   Theme 9, Task 4 -- Linear algebra
 *
 * In matrix A(m,n), a nonzero minor of order k is selected.
 * The minor is specified by a set of row numbers and a set of
 * column numbers (both of cardinality k). Output the value of
 * this minor (recursive expansion along the first row, k<=4).
 */
#include <stdio.h>

#define MAXK 4

double det(double m[MAXK][MAXK], int k)
{
    if (k == 1) return m[0][0];
    if (k == 2) return m[0][0]*m[1][1] - m[0][1]*m[1][0];

    double result = 0;
    double sub[MAXK][MAXK];
    for (int c = 0; c < k; c++) {
        int subi = 0;
        for (int i = 1; i < k; i++) {
            int subj = 0;
            for (int j = 0; j < k; j++) {
                if (j == c) continue;
                sub[subi][subj] = m[i][j];
                subj++;
            }
            subi++;
        }
        double sign = (c % 2 == 0) ? 1.0 : -1.0;
        result += sign * m[0][c] * det(sub, k-1);
    }
    return result;
}

int main(void)
{
    int M, N, k;
    printf("Matrix dimensions M N: ");
    scanf("%d %d", &M, &N);

    double A[20][20];
    printf("Enter matrix A(%dx%d):\n", M, N);
    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
            scanf("%lf", &A[i][j]);

    printf("Minor order k (<=4): ");
    scanf("%d", &k);

    int rows[MAXK], cols[MAXK];
    printf("Enter %d row numbers: ", k);
    for (int i = 0; i < k; i++) scanf("%d", &rows[i]);
    printf("Enter %d column numbers: ", k);
    for (int i = 0; i < k; i++) scanf("%d", &cols[i]);

    double minor[MAXK][MAXK];
    for (int i = 0; i < k; i++)
        for (int j = 0; j < k; j++)
            minor[i][j] = A[rows[i]][cols[j]];

    printf("Minor value: %.4f\n", det(minor, k));
    return 0;
}
