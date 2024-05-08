//WAP to implement Newton’s forward difference formula.
#include <stdio.h>

double newton_forward(double x[], double y[], int n, double x0) {
    double h = x[1] - x[0];
    double u = (x0 - x[0]) / h;
    double y0 = y[0];
    double p = 1;
    int i, j;
    for (i = 1; i < n; i++) {
        p = p * (u - i + 1) / i;
        double sum = 0;
        for (j = 0; j <= i; j++) {
            sum += y[j] * p;
        }
        y0 += sum;
    }
    return y0;
}

int main() {
    double x[] = {0, 1, 2, 3};
    double y[] = {11, 12, 13, 14};
    int n = sizeof(x) / sizeof(x[0]);
    double x0 = 0.5;
    double y0 = newton_forward(x, y, n, x0);
    printf("f(%f) = %f\n", x0, y0);
    return 0;
}
