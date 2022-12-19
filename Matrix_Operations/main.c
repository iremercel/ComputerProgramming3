#include <stdio.h>
#include <stdlib.h>
#include "matrixLib.h"

int seed;

int main(int arg)
{
    seed = arg;
    float *vector = returnVector(5);
    float **matrix = returnMatrix(3, 3);
    printVector(vector, 5);
    printMatrix(matrix, 3, 3);

    printf("%.2f\n", determinant(matrix,3));

    printf("%.2f\n", mean(vector, 5));
    printf("%.2f\n", correlation(vector, vector, 5));
    printf("%.2f\n", covariance(vector, vector, 5));
}