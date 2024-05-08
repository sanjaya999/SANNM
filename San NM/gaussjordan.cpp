//Write a Program to implement Gauss Jordan Method.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 5

void swap(double *a, double *b) {
    double temp = *a;
    *a = *b;
    *b = temp;
}

void gauss_jordan(int n, double a[][N], double b[]) {
    int i, j, k;

    for (i = 0; i < n; i++) {
        if (a[i][i] == 0.0) {
            printf("Mathematical Error!");
            exit(0);
        }

        for (j = 0; j < n; j++) {
            if (i != j) {
                double ratio = a[j][i] / a[i][i];
                for (k = 0; k <= n; k++) {
                    a[j][k] -= ratio * a[i][k];
                }
            }
        }
    }

    for (i = 0; i < n; i++) {
        b[i] = a[i][n] / a[i][i];
    }
}

int main() {
    int n, i, j;
    double a[N][N], b[N];

    printf("Enter the order of matrix: ");
    scanf("%d", &n);

    printf("Enter the elements of augmented matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j <= n; j++) {
            scanf("%lf", &a[i][j]);
        }
    }

    gauss_jordan(n, a, b);

    printf("The solution is:\n");
    for (i = 0; i < n; i++) {
        printf("x%d = %lf\n", i + 1, b[i]);
    }

    return 0;
}
