//Create a facotorials program
// 5! = 5 * 4 * 3 * 2 * 1
#include <stdio.h>
#include <math.h>


int factorial(int n) {
    if (n<=1)
        return 1;

    return n * factorial(n-1);
}

int sum (int n) {
    if (n<=1)
        return 1;
    return n + sum(n-1);
}

