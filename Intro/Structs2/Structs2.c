//return the sum of two complex numbers using structs in C

#include <stdio.h> // Include the standard input/output library for functions like printf.

typedef struct _complexNum { // Define a structure for complex numbers.
    double a; // Real part of the complex number.
    double b; // Imaginary part of the complex number.
} ComplexNum; // Alias for the struct as "ComplexNum."

ComplexNum addComplex(ComplexNum num1, ComplexNum num2) { // Function to add two complex numbers.
    ComplexNum result; // Declare a variable to store the result.
    result.a = num1.a + num2.a; // Add the real parts of num1 and num2.
    result.b = num1.b + num2.b; // Add the imaginary parts of num1 and num2.
    return result; // Return the sum as a new ComplexNum struct.
}

int main() { // Main function where the program starts execution.
    ComplexNum num1, num2, sum; // Declare variables to store complex numbers and their sum.
    
    // Initialize the first complex number (num1).
    num1.a = 3.0; // Set the real part to 3.0.
    num1.b = 4.0; // Set the imaginary part to 4.0.
    
    // Initialize the second complex number (num2).
    num2.a = 1.5; // Set the real part to 1.5.
    num2.b = 2.5; // Set the imaginary part to 2.5.
    
    // Calculate the sum of the two complex numbers using the addComplex function.
    sum = addComplex(num1, num2);
    
    // Print the result as "Sum: realPart + imaginaryParti".
    printf("Sum: %.2lf + %.2lfi\n", sum.a, sum.b);
    
    return 0; // Indicate successful program execution.
}
