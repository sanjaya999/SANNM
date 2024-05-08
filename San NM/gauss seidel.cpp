//Write a Program to implement Gauss Seidal Method.

#include <stdio.h>
#include <math.h>

#define N 6

int main() {
    int n, i, j, k, count = 0;
    double a[N][N], b[N], x[N], y[N], e, sum;

    printf("Enter the order of matrix: ");
    scanf("%d", &n);

    printf("Enter the elements of augmented matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%lf", &a[i][j]);
        }
        scanf("%lf", &b[i]);
    }

    printf("Enter the tolerable error: ");
    scanf("%lf", &e);

    for (i = 0; i < n; i++) {
        x[i] = 0.0;
    }

    do {
        for (i = 0; i < n; i++) {
            sum = 0.0;

            for (j = 0; j < n; j++) {
                if (i != j) {
                    sum += a[i][j] * x[j];
                }
            }

            y[i] = (b[i] - sum) / a[i][i];
            x[i] = y[i];
        }

        count++;

        for (i = 0; i < n; i++) {
            if (fabs(y[i] - x[i]) > e) {
                break;
            }
        }

        if (i == n) {
            break;
        }
    } while (count < 100);

    printf("The solution is:\n");
    for (i = 0; i < n; i++) {
        printf("x%d = %lf\n", i + 1, y[i]);
    }

    return 0;
}
