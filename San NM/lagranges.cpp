//WAP to implement Lagrange’s interpolation.
#include <stdio.h>

double lagrange(double x, double xCor[], double yCor[], int n) {
  // Initialize the result
  double result = 0;

  // Loop through the data points
  for (int i = 0; i < n; i++) {
    // Calculate the Lagrange polynomial
    double p = 1;
    for (int j = 0; j < n; j++) {
      if (i != j) {
        p *= (x - xCor[j]) / (xCor[i] - xCor[j]);
      }
    }

    // Add the polynomial to the result
    result += p * yCor[i];
  }

  // Return the result
  return result;
}

int main() {
  // Define the data points
  double xCor[] = {1, 2, 3, 4};
  double yCor[] = {6, 7, 8,9 };
  int n = sizeof(xCor) / sizeof(double);

  // Calculate the value of the polynomial at x = 2
  double value = lagrange(2, xCor, yCor, n);

  // Print the value
  printf("The value of the polynomial is %.2f\n", value);

  return 0;
}

