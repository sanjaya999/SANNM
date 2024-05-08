#include <stdio.h>
#include <math.h>

double f(double x, double y) {
    return 2 * x + y;
}

int main() {
    double x0 = 0, y0 = 1, x, y, h, e, error;
    int i = 0;

    // Define the target value of x
    double target_x = 0.4;

    // Set the step size
    h = 0.1;

    // Set the tolerable error
    e = 0.0001;

    x = x0;
    y = y0;

    do {
        double k1 = h * f(x, y);
        double k2 = h * f(x + h / 2.0, y + k1 / 2.0);
        double k3 = h * f(x + h / 2.0, y + k2 / 2.0);
        double k4 = h * f(x + h, y + k3);
        double y1 = y + 1.0 / 6.0 * (k1 + 2.0 * k2 + 2.0 * k3 + k4);
        error = fabs(y1 - y);
        y = y1;
        x += h;
        i++;
    } while (error > e && x < target_x);

    // Print the solution
    printf("The solution at x = %.1lf is: %.6lf\n", x, y);

    return 0;
}

