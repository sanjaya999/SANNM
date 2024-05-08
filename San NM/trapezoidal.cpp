#include <stdio.h>

int main() {
  // Define the number of data points
  int n = 6;

  // Define the x and y data points
  float x[n] = {0, 1, 2, 3, 4, 5};
  float y[n] = {0, 1, 4, 9, 16, 25}; // Removed extra comma

  // Calculate the area using trapezoidal rule
  float area = 0;
  for (int i = 0; i < n - 1; i++) {
    area += (y[i] + y[i + 1]) * (x[i + 1] - x[i]) / 2;
  }

  // Print the area
  printf("The area under the curve using trapezoidal rule is: %f\n", area);

  return 0;
}

