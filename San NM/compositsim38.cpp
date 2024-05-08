//Write a program to implement composite Simson’s 3/8 rule.

#include <stdio.h>

int main() {
  // Define the number of data points
  int n = 6;

  // Define the x and y data points
   float x[n] = {0, 1, 2, 3, 4, 5};
  float y[n] = {0, 1, 4, 9, 16, 25};


  // Calculate the area using composite Simpson's 3/8 rule
  float area = 0;
  float h = (x[n - 1] - x[0]) / n;
  for (int i = 0; i < n - 1; i += 3) {
    area += (y[i] + 3 * y[i + 1] + 3 * y[i + 2] + y[i + 3]) * h / 8;
  }

  // Print the area
  printf("The area under the curve using composite Simpson's 3/8 rule is: %f\n", area);

  return 0;
}

