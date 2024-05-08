//WAP to implement least square approximation.
// Linear least square method.

#include <stdio.h>

void linear_least_square(double *x_data, double *y_data, int n, double *a, double *b) {
  // Calculate the sum of x
  double sum_x = 0;
  for (int i = 0; i < n; i++) {
    sum_x += x_data[i];
  }

  // Calculate the sum of y
  double sum_y = 0;
  for (int i = 0; i < n; i++) {
    sum_y += y_data[i];
  }

  // Calculate the sum of xy
  double sum_xy = 0;
  for (int i = 0; i < n; i++) {
    sum_xy += x_data[i] * y_data[i];
  }

  // Calculate the slope
  *b = (sum_xy - sum_x * sum_y) / (n * sum_x);

  // Calculate the y-intercept
  *a = sum_y - *b * sum_x;
}

int main() {
  // Define the data points
  double x_data[] = {11, 15, 5,4 };
  double y_data[] = {10, 20, 8, 10};
  int n = sizeof(x_data) / sizeof(double);

  // Initialize the coefficients
  double a = 0, b = 0;

  // Calculate the coefficients
  linear_least_square(x_data, y_data, n, &a, &b);

  // Print the coefficients
  printf("The slope is %f\n", b);
  printf("The y-intercept is %f\n", a);

  return 0;
}

