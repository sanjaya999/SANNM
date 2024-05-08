#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NX 4 // Number of grid points in the x-direction (4 for 5×5 cm grid)
#define NY 4 // Number of grid points in the y-direction (4 for 5×5 cm grid)
#define MAX_ITER 10000 // Maximum number of iterations
#define TOL 1e-6 // Tolerance for convergence

// Function to initialize the grid and boundary conditions
void initialize(double grid[NX][NY]) {
    int i, j;

    // Initialize the grid with zeros
    for (i = 0; i < NX; i++) { 
        for (j = 0; j < NY; j++) {
            grid[i][j] = 0.0;
        }
    }

    // Set boundary conditions
    for (i = 0; i < NX; i++) {
        grid[i][0] = 0.0;   // Bottom boundary (y = 0)
        grid[i][NY - 1] = 100.0; // Top boundary (y = 1)
    }
    for (j = 0; j < NY; j++) {
        grid[0][j] = 0.0;   // Left boundary (x = 0)
        grid[NX - 1][j] = 100.0; // Right boundary (x = 1)
    }
}

// Function to solve the Laplace equation using the Gauss-Seidel method
void solvePDE(double grid[NX][NY]) {
    int i, j, iter;
    double error;

    // Perform iterations until convergence or maximum iterations reached
    for (iter = 0; iter < MAX_ITER; iter++) {
        error = 0.0;

        // Update the grid using the Gauss-Seidel method
        for (i = 1; i < NX - 1; i++) {
            for (j = 1; j < NY - 1; j++) {
                double oldValue = grid[i][j];
                grid[i][j] = (grid[i - 1][j] + grid[i + 1][j] + grid[i][j - 1] + grid[i][j + 1]) / 4.0;
                error += fabs(grid[i][j] - oldValue);
            }
        }

        // Check for convergence
        if (error < TOL) {
            printf("Converged after %d iterations\n", iter + 1);
            return;
        }
    }

    printf("Maximum number of iterations reached\n");
}

// Function to print the grid values
void printGrid(double grid[NX][NY]) {
    int i, j;

    for (j = NY - 1; j >= 0; j--) {
        for (i = 0; i < NX; i++) {
            printf("%.2f ", grid[i][j]);
        }
        printf("\n");
    }
}

int main() {
    double grid[NX][NY];

    // Initialize the grid and boundary conditions
    initialize(grid);

    // Solve the Laplace equation
    solvePDE(grid);

    // Print the final grid values
    printf("Final grid:\n");
    printGrid(grid);

    return 0;
}
