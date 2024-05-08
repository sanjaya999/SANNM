#include <stdio.h>
#include <math.h>

double f(double x, double y) {
    return x - pow(y, 2);
}

double dfdx(double x, double y) {
    return 1.0;
}

double dfdy(double x, double y) {
    return -2.0 * y;
}

double d2fdx2(double x, double y) {
    return 0.0;
}

double d2fdy2(double x, double y) {
    return -2.0;
}

double d2fdxdy(double x, double y) {
    return 0.0;
}

int main() {
    double x0, y0, x, y, h, e, error;
    int i = 0;

    printf("Enter the initial value of x: ");
    scanf("%lf", &x0);

    printf("Enter the initial value of y: ");
    scanf("%lf", &y0);

    printf("Enter the step size: ");
    scanf("%lf", &h);

    printf("Enter the tolerable error: ");
    scanf("%lf", &e);

    x = x0;
    y = y0;

    do {
        double y1 = y + h * f(x, y) + pow(h, 2) / 2.0 * (dfdx(x, y) + dfdy(x, y) * f(x, y));
        double y2 = y1 + pow(h, 3) / 6.0 * (d2fdx2(x, y) + 2.0 * d2fdxdy(x, y) * f(x, y) + pow(dfdy(x, y), 2) * f(x, y) + dfdy(x, y) * dfdx(x, y));
        error = fabs(y2 - y1) / 15.0;
        y = y2;
        x += h;
        i++;
    } while (error > e);

    printf("The solution is: %lf\n", y);

    return 0;
}

