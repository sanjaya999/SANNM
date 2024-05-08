//Write a program to calculate the derivative using central difference formula.

#include <stdio.h>

int main() {
  // Define the number of data points
  int n = 5;

  // Define the x and y data points
  float x[n] = {1, 2, 3, 4, 5};
  float y[n] = {1, 4, 9, 16, 25};

  // Calculate the derivative using central difference formula
  float derivative = (y[2] - y[1]) / (x[2] - x[1]);
  for (int i = 3; i < n - 1; i++) {
    derivative += (y[i + 1] - y[i - 1]) / (2 * (x[i + 1] - x[i - 1]));
  }

  // Print the derivative
  printf("The derivative of the function at x = 2 is: %f\n", derivative);

  return 0;
}

