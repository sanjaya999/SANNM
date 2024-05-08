#include <stdio.h>
#include <math.h>

// Define the differential equation: dy/dx = x + y
double f(double x, double y) {
    return x + y;
}

// Function to solve the boundary value problem using the shooting method
double solve(double x0, double y0, double xf, double yf, double h) {
    double x = x0;
    double y = y0;
    double dydx_guess = (yf - y0) / (xf - x0); // Initial guess for dy/dx

    while (x < xf) {
        // Use Euler's method to integrate the differential equation
        y += h * (f(x, y) + f(x + h, y + h * dydx_guess)) / 2.0;
        x += h;
    }

    return y;
}

int main() {
    double x0 = 0, y0 = 0; // Initial conditions: y(0) = 0
    double xf = 1, yf = 2; // Final conditions: y(1) = 2
    double h = 0.1; // Step size

    // Solve the boundary value problem
    double y = solve(x0, y0, xf, yf, h);

    // Print the solution
    printf("The solution at x = %.1lf is: %.6lf\n", xf, y);

    return 0;
}

