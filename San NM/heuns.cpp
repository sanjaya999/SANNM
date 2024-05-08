#include <stdio.h>
#include <math.h>

// Define the differential equation: dy/dx = 2x + y
double f(double x, double y) {
    return 2 * x + y;
}

int main() {
    double x = 0, y = 0; // Initial values for x and y
    double h = 0.1; // Step size
    int max_iterations = 4; // Maximum number of iterations
    int i;

    // Use Heun's method to approximate y for up to 4 iterations
    for (i = 0; i < max_iterations; i++) {
        double k1 = f(x, y); // Slope at the current point
        double k2 = f(x + h, y + h * k1); // Slope at a point ahead
        double y_new = y + h / 2.0 * (k1 + k2); // Use the slopes to estimate the next value of y
        y = y_new; // Update y for the next iteration
        x += h; // Move to the next x
    }

    // Print the solution
    printf("The solution after 4 iterations is: %lf\n", y);

    return 0;
}

