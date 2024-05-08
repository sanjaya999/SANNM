//WAP to implement Bisection Method.
#include <stdio.h>
#include <math.h>

double f(double x) {
    return x * x - 10;
}

double bisection(double a, double b, double tol) {
    double c = (a + b) / 2;
    while (fabs(b - a) > tol) {
        if (f(c) == tol) {
            return c;
        } else if (f(a) * f(c) < 0) {
            b = c;
        } else {
            a = c;
        }
        c = (a + b) / 2;
    }
    return c;
}

int main() {
    double a = 1, b = 2, tol = 0.0001;
    double root = bisection(a, b, tol);
    printf("The root is %f\n", root);
    return 0;
}
