#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double bisect(double foo(double x), double a, double b, double tol);
double test_foo(double x);
int sign(double x);

int main(int argc, char **argv) {
    if (argc != 4) {
        printf("Incorrect number of arguments (received %d, should be %d)\n", argc-1, 3);
        exit(EXIT_SUCCESS);
    }
    double a = atof(argv[1]);
    double b = atof(argv[2]);
    double tol = atof(argv[3]);
    printf("Root found by bisect method: %f\n", bisect(test_foo, a, b, tol));
}

double bisect(double foo(double x), double a, double b, double tol) {
    double f_a = foo(a);
    double f_b = foo(b);
    double f_mid;
    double ab_mid;
    
    printf("args to bisect: a: %f b: %f, tol: %f\n", a, b, tol);
    if (f_a * sign(f_b) >= 0) {
        printf("Bisect error, same sign for f(a) and f(b)\n");
        exit(EXIT_SUCCESS);
    }

    while ((b - a) / 2 > tol) {
        ab_mid = (a + b) / 2;
        f_mid = foo(ab_mid);
        if (f_mid == 0) {
            break;
        }
        if (sign(f_mid) * sign(f_a) < 0) {
            b = ab_mid;
            f_b = f_mid;
        } else {
            a = ab_mid;
            f_a = f_mid;
        }
    }
    return (a + b) / 2;
}

double test_foo(double x) {
    return pow(x, 3) + x - 1;
}

int sign(double x) {
    if (x > 0) {
        return 1;
    } else if (x == 0) {
        return 0;
    } else if (x < 0) {
        return -1;
    }
    printf("Received invalid value to sign\n");
    exit(EXIT_SUCCESS);
}
