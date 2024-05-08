//WAP to implement synthetic division.
#include <stdio.h>

void synthetic_division(int dividend[], int divisor, int n) {
    int i, remainder = 0;
    for (i = 0; i < n; i++) {
        int temp = dividend[i] + remainder;
        dividend[i] = temp / divisor;
        remainder = temp % divisor * 10;
    }
    printf("Quotient: ");
    for (i = 0; i < n - 1; i++) {
        printf("%dx^%d + ", dividend[i], n - i - 1);
    }
    printf("%d\n", dividend[n - 1]);
    printf("Remainder: %d\n", remainder / 10);
}

int main() {
    int dividend[] = {10, 9, 8, 7};
    int divisor = 2;
    int n = sizeof(dividend) / sizeof(dividend[0]);
    synthetic_division(dividend, divisor, n);
    return 0;
}
