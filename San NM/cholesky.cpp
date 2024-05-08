//Write a Program to implement Cholesky Method.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 12

void cholesky(int n, double a[][N], double l[][N]) {
    int i, j, k;

    for (i = 0; i < n; i++) {
        for (j = 0; j <= i; j++) {
            double sum = 0.0;

            if (j == i) {
                for (k = 0; k < j; k++) {
                    sum += pow(l[j][k], 2);
                }
                l[j][j] = sqrt(a[j][j] - sum);
            } else {
                for (k = 0; k < j; k++) {
                    sum += l[i][k] * l[j][k];
                }
                l[i][j] = (a[i][j] - sum) / l[j][j];
            }
        }
    }
}

int main() {
    int n, i, j;
    double a[N][N], l[N][N];

    printf("Enter the order of matrix: ");
    scanf("%d", &n);

    printf("Enter the elements of matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%lf", &a[i][j]);
        }
    }

    cholesky(n, a, l);

    printf("The lower triangular matrix L is:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (i >= j) {
                printf("%lf ", l[i][j]);
            } else {
                printf("0.000000 ");
            }
        }
        printf("\n");
    }

    return 0;
}
