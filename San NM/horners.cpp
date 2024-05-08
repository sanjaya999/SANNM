//WAP to implement Horner’s method.
#include <stdio.h>

int horner(int coefficients[], int degree, int x) {
    int result = coefficients[0];
    for (int i = 1; i <= degree; i++) {
        result = result * x + coefficients[i];
    }
    return result;
}

int main() {
    int coefficients[] = {5, 4, 2, 1};  // Coefficients of the polynomial: 5x^3 - 4x^2 + 2x - 1
    int degree = sizeof(coefficients) / sizeof(coefficients[0]) - 2;
    int x = 5;  // Value of x for evaluation

    int evaluatedValue = horner(coefficients, degree, x);
    printf("The result of evaluating the polynomial at x = %d is %d\n", x, evaluatedValue);

    return 0;
}

