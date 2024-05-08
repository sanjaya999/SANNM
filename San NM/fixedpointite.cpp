//WAP to implement fixed point iteration method.
#include <stdio.h>
#include <math.h>

double f(double x) {
    return sin(x) - 4 * x + 1;
}

double g(double x) {
    return (1 + cos(x)) / 4;
}

double fixed_point_iteration(double x0, double (*g)(double), double tol) {
    double x1, g0, g1;
    int i = 0;
    do {
        g0 = g(x0);
        x1 = g0;
        g1 = g(x1);
       
        x0 = x1;
        i++;
    } while (fabs(g1 - g0) > tol && i < 100);
    return x1;
}

int main() {
    double x0 = 1, tol = 0.0001;
    double root = fixed_point_iteration(x0, g, tol);
    printf("The root is %f\n", root);
    return 0;
}
