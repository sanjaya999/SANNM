//Write a program to implement Newton’s divided difference interpolation.

#include <stdio.h>

double newton_divided_difference(double x, double xCord[], double yCord[], int n) {
  // Initialize the result
  double result = yCord[0];

  // Loop through the data points
  for (int i = 1; i < n; i++) {
    // Calculate the divided difference
    double d = yCord[i] - result;

    // Update the result
    result = result + d * (x - xCord[i - 1]);
  }

  // Return the result
  return result;
}

int main() {
  // Define the data points
  double xCord[] = {2, 3, 4, 5};
  double yCord[] = {6, 7, 7, 9};
  int n = sizeof(xCord) / sizeof(double);

  // Calculate the value of the polynomial at x = 2
  double value = newton_divided_difference(2, xCord, yCord, n);

  // Print the value
  printf("The value of the polynomial is %.2f\n", value);

  return 0;
}

