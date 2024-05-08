//Write a Program to implement matrix inversion with Gauss-Jordan method.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 6

void swap(double *a, double *b) {
    double temp = *a;
    *a = *b;
    *b = temp;
}

void gauss_jordan(int n, double a[][2*N], double b[][N]) {
    int i, j, k;

    for (i = 0; i < n; i++) {
        if (a[i][i] == 0.0) {
            printf("Mathematical Error!");
            exit(0);
        }

        for (j = 0; j < n; j++) {
            if (i != j) {
                double ratio = a[j][i] / a[i][i];
                for (k = 0; k < 2*n; k++) {
                    a[j][k] -= ratio * a[i][k];
                }
            }
        }
    }

    for (i = 0; i < n; i++) {
        double div = a[i][i];
        for (j = 0; j < n; j++) {
            b[i][j] = a[i][j+n] / div;
        }
    }
}

int main() {
    int n, i, j;
    double a[N][2*N], b[N][N];

    printf("Enter the order of matrix: ");
    scanf("%d", &n);

    printf("Enter the elements of matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%lf", &a[i][j]);
        }
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (i == j) {
                a[i][j+n] = 1.0;
            } else {
                a[i][j+n] = 0.0;
            }
        }
    }

    gauss_jordan(n, a, b);

    printf("The inverse of the matrix is:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%lf ", b[i][j]);
        }
        printf("\n");
    }

    return 0;
}
