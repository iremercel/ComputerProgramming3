#include <stdio.h>
#include <math.h>

extern int seed;

float *returnVector(int size)
{
    srand(seed);
    float *vector = malloc(size * sizeof(float));
    for (int i = 0; i < size; i++)
        vector[i] = (rand() % 10) + 1;
    return vector;
}

float **returnMatrix(int row, int col)
{
    srand(seed);
    float **matrix = (float **)malloc(row * sizeof(float *));
    for (int i = 0; i < row; i++)
        matrix[i] = (float *)malloc(col * sizeof(float));

    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            matrix[i][j] = (rand() % 10) + 1;

    return matrix;
}

void freeMatrix(float **mat, int row)
{
    free(mat[row]);
}

float mean(float *vec, int size)
{
    float sum = 0;
    for (int i = 0; i < size; i++)
        sum = vec[i] + sum;
    return sum / size;
}

float variance(float *vec, int size)
{
    float meanVec = mean(vec, size);
    float diff = 0;
    for (int i = 0; i < size; i++)
        diff += (vec[i] - meanVec) * (vec[i] - meanVec);
    return diff / size;
}

double standardDeviation(float *vec, int size)
{
    return sqrt(variance(vec, size));
}

float covariance(float *vec1, float *vec2, int size)
{
    float sum = 0;
    float mean_arr1 = mean(vec1, size);
    float mean_arr2 = mean(vec2, size);
    for (int i = 0; i < size; i++)
        sum = sum + (vec1[i] - mean_arr1) * (vec2[i] - mean_arr2);
    return sum / (size - 1);
}

float correlation(float *vec1, float *vec2, int size)
{
    float vec1StandardDeviation = standardDeviation(vec1, size);
    float vec2StandardDeviation = standardDeviation(vec2, size);
    float correlation = covariance(vec1, vec2, size) / (vec1StandardDeviation * vec2StandardDeviation);
    return correlation;
}

float **matrixMultiplication(float **mat1, float **mat2, int row1, int col1, int row2, int col2)
{
    if (col1 != row2)
        return NULL;

    float **matrixMult = returnMatrix(row1, col2);
    float sum;
    for (int i = 0; i < row1; i++)
    {
        for (int j = 0; j < col2; j++)
        {
            for (int k = 0; k < row2; k++)
            {
                sum += mat1[i][k] * mat2[k][j]; // Matris çarpma işleminin algoritması
            }
            matrixMult[i][j] = sum; // Çıkan sonuc dizinin elemanı olarak yazılır
            sum = 0;                // Toplam tekrar kullanılacağı için 0 a eşitlenir.
        }
    }
    return matrixMult;
}

float **matrixTranspose(float **mat, int row, int col)
{
    float **matrixTrans = returnMatrix(col, row);
    // computing the transpose
    for (int i = 0; i < row; ++i)
        for (int j = 0; j < col; ++j)
        {
            matrixTrans[j][i] = mat[i][j];
        }
    return matrixTrans;
}

float *rowMeans(float **mat, int row, int col)
{
    float *vectorRowMeans = returnVector(row);
    for (int i = 0; i < row; i++)
        vectorRowMeans[i] = mean(mat[i], col);
    return vectorRowMeans;
}

float *columnMeans(float **mat, int row, int col)
{
    float *vectorColMeans = returnVector(col);
    for (int i = 0; i < col; i++)
        vectorColMeans[i] = mean(mat[i], col);
    return vectorColMeans;
}
float **covarianceMatrix(float **mat, int row, int col)
{
    float **colMat = matrixTranspose(mat, row, col);
    float **covarianceMat = returnMatrix(col, col);
    int boolean = 1;
    for (int i = 0; i < col; ++i)
        for (int j = 0; j < col; ++j)
        {
            if (boolean == 1)
            {
                covarianceMat[i][j] = variance(colMat[j], col);
                boolean = 0;
            }
            else
            {
                covarianceMat[i][j] = covariance(colMat[j], colMat[col - 1], col);
                boolean = 1;
            }
        }
    for (int i = 0; i < row; i++)
        freeMatrix(colMat, i);
    return covarianceMat;
}
float determinant(float **mat, int row)
{
    for (int i = 0; i < row; i++)
        mat[i] = (float *)realloc(mat[i], (5 * sizeof(float)));

    for (int i = 0; i < row; i++)
        for (int j = 3; j <= 4; j++)
        {
            mat[i][j] = mat[i][j - 3];
        }

    float *plus = returnVector(3);
    float *minus = returnVector(3);

    for (int i = 0; i < row; i++)
    {
        plus[i] = 1;
        minus[i] = 1;
    }

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < row; j++)
        {
            plus[i] = plus[i] * mat[j][j + i];
            minus[i] = minus[i] * mat[2 - j][j + i];
        }
    }

    float pluses = 0;
    float minuses = 0;

    for (int i = 0; i < row; i++)
    {
        pluses = pluses + plus[i];
        minuses = minuses + minus[i];
    }
    free(plus);
    free(minus);
    return pluses - minuses;
}

void printVector(float *vec, int N)
{
    for (int i = 0; i < N; i++)
        printf("%.2f\t", vec[i]);
    printf("\n");
}

void printMatrix(float **mat, int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        printVector(mat[i], col);
    }
}
