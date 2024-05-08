//WAP to implement Newton Raphson method.
#include <stdio.h>
#include <math.h>

double f(double x) {
    return x * x - 4;
}


double newton_raphson(double x0,   double tol) {
    double x1, f0, f1, df0;
    int i = 0;
    do {
      
        f0 = x0 * x0 - 4;
        df0 = 2 * x0;
        
      
        x1 = x0 - f0 / df0;
        
       
        f1 = x1 * x1 - 4;
        
     
        x0 = x1;
        
        i++;
    } while (fabs(x1 - x0) > tol && i < 100);
    return x1;
}
int main() {
    double x0 = 1, tol = 0.0001;
    double root = newton_raphson(x0, tol);
    printf("The root is %f\n", root);
    return 0;
}
