#include <stdlib.h>

int swap(int x, int y) {
    int temp = y;
    y = x;
    x = temp;

    return 0;
}

int main (int argc, char ** argv) {
    int a;
    a = 4;

    int* pA = NULL; //create a datatype that holds the memory location of an int
                    // and set it to 0
    
    pA = &a; // set pA to the address of a
    *pA = 44; // change what is in the address of a to 44 (change a to 44)

    int b = 100;
    int err = swap(&a, &b);

    return 0;
}