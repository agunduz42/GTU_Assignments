#include <stdio.h>
#include "util.h"

void fraction_print(int numerator, int denominator) {
    printf("%d//%d", numerator, denominator);
}

void fraction_add(int n1, int d1, int n2, int d2, int * n3, int * d3) {
    *n3 = n1*d2 + n2*d1;
    *d3 = d1*d2;
    fraction_simplify(n3, d3);
}

void fraction_sub(int n1, int d1, int n2, int d2, int * n3, int * d3) {
    *n3 = n1*d2 - n2*d1;
    *d3 = d1*d2;
    fraction_simplify(n3, d3);
}

void fraction_mul(int n1, int d1, int n2, int d2, int * n3, int * d3) {
    *n3 = n1*n2;
    *d3 = d1*d2;
    fraction_simplify(n3, d3);
}

void fraction_div(int n1, int d1, int n2, int d2, int * n3, int * d3) {
    *n3 = n1*d2;
    *d3 = n2*d1;
    fraction_simplify(n3, d3);
}

int gcd(int a, int b) {
    int i = 2;
    int gcd = 1;
    int sign = 1;

    // if the both numbers are less than 0
    // multiplying with -1
    if(a < 0 && b < 0)
        sign *= -1;
    a = a < 0 ? -a : a;
    b = b < 0 ? -b : b;

    // finding gcd of two integers
    int min = a > b ? b : a;
    while(i <= min) {
        if(a % i == 0 && b % i == 0)
            gcd = i;
        i++;
    }
    return(gcd * sign);
}

void fraction_simplify(int * n, int * d) {
    int divide = gcd(*n, *d);
    *n /=  divide;
    *d /= divide;
}
