#include <stdio.h>

int main() {
  // Define the number of data points
  int n = 5;

  // Define the x and y data points
  float x[n] = {4, 8, 9, 10, 11};
  float y[n] = {4, 6, 8, 10, 12};

  // Calculate the derivative using forward difference formula
  float derivative = (y[1] - y[0]) / (x[1] - x[0]);
  for (int i = 2; i < n; i++) {
    derivative += (y[i] - y[i - 1]) / (x[i] - x[i - 1]);
  }

  // Print the derivative
  printf("The derivative of the function at x = %f is: %f\n", x[0], derivative);

  return 0;
}

