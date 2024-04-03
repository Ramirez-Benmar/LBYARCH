// Ramirez, Benmar | Andres, Nathan | XX22

#include <stdio.h>  
#include <stdlib.h>  
#include <io.h>  // Include the input/output library
#include <time.h>  // Include the time library
#include <math.h>  // Include the math library

extern double getDPx64(size_t SizeN, double* AsmDP, double* VectorA, double* VectorB);  // Declare an external function that calculates the dot product using x64 assembly

void getDP(size_t SizeN, double* Ans, double* VectorA, double* VectorB) {  // Define a function that calculates the dot product
    *Ans = 0.0;  // Initialize the answer to 0
    for (size_t i = 0; i < SizeN; i++) {  // Loop through each element in the vectors
        *Ans += VectorA[i] * VectorB[i];  // Add the product of the corresponding elements of VectorA and VectorB to the answer tama ba exp ko pre
    }
}

double* initializeVector(size_t SizeN, double value) {  // Define a function that initializes a vector with a given value
    double* Vector = (double*)calloc(SizeN, sizeof(double));  // Allocate memory for the vector
    if (Vector == NULL) {  // If memory allocation failed
        printf("Memory allocation failed\n");  // Print an error message
        exit(1);  // Exit the program
    }
    for (size_t i = 0; i < SizeN; ++i) {  // Loop through each element in the vector
        Vector[i] = value;  // Set the element to the given value
    }
    return Vector;  // Return the vector
}

double measureTime(size_t SizeN, double* DP, double* VectorA, double* VectorB, void (*func)(size_t, double*, double*, double*)) {  // Define a function that measures the time taken by a function
    clock_t Start, End;  // Declare variables to hold the start and end times
    double LoopTime, Avg;  // Declare variables to hold the loop time and average time

    func(SizeN, DP, VectorA, VectorB);  // Call the function once to warm up the cache
    Start = clock();  // Get the current time
    for (int i = 0; i < 30; i++) {  // Loop 30 times
        func(SizeN, DP, VectorA, VectorB);  // Call the function
    }
    End = clock();  // Get the current time
    LoopTime = ((double)End - Start) * 1e3 / CLOCKS_PER_SEC;  // Calculate the total time taken by the loop
    Avg = LoopTime / 30;  // Calculate the average time taken by the function

    return Avg;  // Return the average time
}

int main() {  
    for (int Exp = 20; Exp < 29; Exp++) {  // Loop from 20 to 28
        const size_t SizeN = (size_t)1 << Exp;  // Calculate the size of the arrays
        printf("Array size = %zu or 2^%d\n", SizeN, Exp);  // Print the size of the arrays

        double* CDP = (double*)calloc(SizeN, sizeof(double));  // Allocate memory for the C dot product
        double* AsmDP = (double*)calloc(SizeN, sizeof(double));  // Allocate memory for the assembly dot product
        double* VectorA = initializeVector(SizeN, 0.1);  // Initialize VectorA with 0.1
        double* VectorB = initializeVector(SizeN, 0.1);  // Initialize VectorB with 0.1

        if (CDP != NULL && AsmDP != NULL) {  // If memory allocation was successful
            double CAvg = measureTime(SizeN, CDP, VectorA, VectorB, getDP);  // Measure the time taken by the C function
            double AsmAvg = measureTime(SizeN, AsmDP, VectorA, VectorB, getDPx64);  // Measure the time taken by the assembly function

            printf("The C DP function takes %lf millisecond/s on average, DP = %.2lf \n", CAvg, *CDP);  // Print the average time taken by the C function and the dot product
            printf("The Asm DP function takes %lf millisecon/s on average, DP = %.2lf \n\n", AsmAvg, *AsmDP);  // Print the average time taken by the assembly function and the dot product
            printf("__________________________________________________________________________________________\n");  // Print a separator
        }
        else {  // If memory allocation failed
            printf("Memory allocation failed\n"); 
        }

        free(CDP);  // Free the memory allocated for the C dot product
        free(AsmDP);  // Free the memory allocated for the assembly dot product
        free(VectorA);  // Free the memory allocated for VectorA
        free(VectorB);  // Free the memory allocated for VectorB
    }

    return 0;
}