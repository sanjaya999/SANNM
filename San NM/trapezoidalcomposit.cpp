//Write a program to implement composite trapezoidal rule.

#include <stdio.h>

int main() {
  // Define the number of data points
  int n = 6;

  // Define the x and y data points
  float x[n] = {0, 1, 2, 3, 4, 5};
  float y[n] = {0, 1, 4, 9, 16, 25};

  // Calculate the area using composite trapezoidal rule
  float area = 0;
  float h = (x[n - 1] - x[0]) / n;
  for (int i = 0; i < n - 1; i += 2) {
    area += (y[i] + y[i + 1]) * h;
  }

  // Print the area
  printf("The area under the curve using composite trapezoidal rule is: %f\n", area);

  return 0;
}

