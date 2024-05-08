#include <stdio.h>

int main() {
  // Define the number of equations
  int n = 3;

  // Define the augmented matrix
  float A[n][n + 1] = {
    {2, 1, -1, 8},
    {-3, -1, 2, -11},
    {-2, 1, 2, -3}
  };

  // Forward elimination
  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      float m = A[j][i] / A[i][i];
      for (int k = i; k <= n; k++) { // Start from i, not 0, and include n
        A[j][k] -= m * A[i][k];
      }
    }
  }

  // Back substitution
  float x[n];
  for (int i = n - 1; i >= 0; i--) {
    x[i] = A[i][n] / A[i][i];
    for (int j = i + 1; j < n; j++) {
      x[i] -= A[i][j] * x[j] / A[i][i];
    }
  }

  // Print the solution
  for (int i = 0; i < n; i++) {
    printf("x[%d] = %f\n", i, x[i]);
  }

  return 0;
}
