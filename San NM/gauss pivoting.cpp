//Write a Program to implement Gauss Elimination with pivoting.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 10

void swap(double *a, double *b) {
    double temp = *a;
    *a = *b;
    *b = temp;
}

void gauss_elimination(int n, double a[][N], double b[]) {
    int i, j, k, max_row;
    double c, max_val;

    for (i = 0; i < n; i++) {
        max_row = i;
        max_val = fabs(a[i][i]);

        for (j = i + 1; j < n; j++) {
            if (fabs(a[j][i]) > max_val) {
                max_row = j;
                max_val = fabs(a[j][i]);
            }
        }

        if (max_row != i) {
            for (j = i; j < n; j++) {
                swap(&a[i][j], &a[max_row][j]);
            }
            swap(&b[i], &b[max_row]);
        }

        for (j = i + 1; j < n; j++) {
            c = a[j][i] / a[i][i];
            for (k = i; k < n; k++) {
                a[j][k] -= c * a[i][k];
            }
            b[j] -= c * b[i];
        }
    }

    for (i = n - 1; i >= 0; i--) {
        for (j = i + 1; j < n; j++) {
            b[i] -= a[i][j] * b[j];
        }
        b[i] /= a[i][i];
    }
}

int main() {
    int n, i, j;
    double a[N][N], b[N];

    printf("Enter the order of matrix: ");
    scanf("%d", &n);

    printf("Enter the elements of augmented matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%lf", &a[i][j]);
        }
        scanf("%lf", &b[i]);
    }

    gauss_elimination(n, a, b);

    printf("The solution is:\n");
    for (i = 0; i < n; i++) {
        printf("x%d = %lf\n", i + 1, b[i]);
    }

    return 0;
}
