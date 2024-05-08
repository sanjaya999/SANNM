#include <stdio.h>

int main() {
  // Define the number of data points
  int n = 5;

  // Define the x and y data points
  float x[n] = {1, 2, 3, 4, 5};
  float y[n] = {1, 4, 9, 16, 25};

  // Calculate the derivative using backward difference formula
  float derivative = (y[n - 1] - y[n - 2]) / (x[n - 1] - x[n - 2]);
  for (int i = n - 2; i >= 1; i--) {
    derivative = (y[i] - y[i - 1]) / (x[i] - x[i - 1]);
  }

  // Print the derivative
  printf("The derivative of the function at x = %f is: %f\n", x[1], derivative);

  return 0;
}

