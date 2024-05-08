//Write a program to implement Secant Method.
#include <stdio.h>
#include <math.h>

double f(double x) {
    return x * x - 10;
}

double secant(double x0, double x1, double tol) {
    double x2, f0, f1, f2;
    int i = 0;
    do {
        f0 = f(x0);
        f1 = f(x1);
        x2 = x1 - f1 * (x1 - x0) / (f1 - f0);
        f2 = f(x2);
        x0 = x1;
        x1 = x2;
        i++;
    } while (fabs(f2) > tol && i < 100);
    return x2;
}

int main() {
    double x0 = 1, x1 = 2, tol = 0.0001;
    double root = secant(x0, x1,  tol);
    printf("The root is %f\n", root);
    return 0;
}
