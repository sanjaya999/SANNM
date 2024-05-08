//Write a Program to implement Do-Little LU Decomposition.

#include <stdio.h>

int main() {
  // Define the number of equations
  int n = 8;

  // Define the augmented matrix
  float A[n][n + 1] = {
      {5, 6, 12, 10},
      {10, 12, 14, 10},
      {10, 12, 12, 6},
  };

  // Initialize L and U matrices
  float L[n][n];
  float U[n][n];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      L[i][j] = 0;
      U[i][j] = 0;
    }
  }

  // Do-Little LU Decomposition
  for (int i = 0; i < n; i++) {
    L[i][i] = 1;
    for (int j = i + 1; j < n; j++) {
      U[j][i] = A[j][i] / L[i][i];
      for (int k = i + 1; k < n; k++) {
        A[j][k] -= U[j][i] * L[i][k];
      }
    }
  }

  // Print L and U matrices
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      printf("%f ", L[i][j]);
    }
    printf("\n");
  }
  printf("\n");
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      printf("%f ", U[i][j]);
    }
    printf("\n");
  }

  return 0;
}

