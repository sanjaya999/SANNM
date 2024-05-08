//WAP to implement Newton’s backward difference formula.
#include <stdio.h>

double newton_backward(double x[], double y[], int n, double x0) {
    double h = x[1] - x[0];
    double u = (x0 - x[n - 1]) / h;
    double y0 = y[n - 1];
    double p = 1;
    int i, j;
    for (i = 1; i < n; i++) {
        p = p * (u + i - 1) / i;
        double sum = 0;
        for (j = n - 1; j >= n - i - 1; j--) {
            sum += y[j] * p;
        }
        y0 += sum;
    }
    return y0;
}

int main() {
    double x[] = {4, 3, 2, 1};
    double y[] = {10, 15, 22, 11};
    int n = sizeof(x) / sizeof(x[0]);
    double x0 = 3.5;
    double y0 = newton_backward(x, y, n, x0);
    printf("f(%f) = %f\n", x0, y0);
    return 0;
}
