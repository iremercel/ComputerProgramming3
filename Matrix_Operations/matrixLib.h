#include "matrixLib.c"
#include <stdio.h>

float *returnVector(int size);
//Parametre olarak vektörün boyutunu alacak ve geriye dinamik olarak oluşturduğu vektörü döndürecek.

float **returnMatrix(int row, int col);
/*Bu fonksiyon, parametre olarak matrisin boyutlarını satir (row) ve sütun (col) 
değerlerini alacak ve geriye dinamik olarak oluşturulan 2 boyutlu matrisi döndürecektir.*/

void freeMatrix(float **mat, int row);
/*Dinamik olarak oluşturulmuş 2 boyutlu matrisi ve sütun (row) değerini parametre olarak 
alacak ve heap’ten alınan bu alanı sisteme geri iade edecektir.*/

float mean(float *vec, int size);
//Parametre olarak bir boyutlu bir vektör ve boyutunu alacak, geriye bu vektörün ortalamasını geri döndürecektir.

float correlation(float *vec, float *vec2, int size);
/*Parametre olarak 2 adet bir boyutlu vektör ve boyutlarını alacak (boyutları aynı olmalı), 
geriye bu iki vektörün korelasyonunu döndürecek.*/

float covariance(float *vec1, float *vec2, int size);
/*Parametre olarak 2 adet bir boyutlu vektör ve boyutlarını alacak (boyutları aynı olmalı), 
geriye bu iki vektörün kovaryansını döndürecek.*/

float **matrixMultiplication(float **mat1, float **mat2, int row1, int col1, int row2, int col2);
/*Parametre olarak dinamik olarak oluşturulan 2 adet 2 boyutlu matrisi ve boyut değerlerini (row, col) alacak, 
geriye bu iki matrisin çarpımını geri döndürecektir. 
Fonksiyon matris çarpım kuralını kontrol etmelidir. 
Çarpım matrisi, fonksiyon içerisinde dinamik olarak oluşturulmalıdır.*/

float **matrixTranspose(float **mat, int row, int col);
/*Parametre olarak dinamik olarak oluşturulmuş 2 boyutlu matrisi ve boyutlarını alacak, 
geriye bu matrisin transpozunu döndürecektir.*/


float *rowMeans(float **mat, int row, int col);
/*Parametre olarak 2 boyutlu matrisi ve boyutlarını alacak, bu matrisin satırlarının ortalamasını tutan bir vektör döndürecektir. 
Örneğin; 5x3’lük bir matrisin satır ortalamasını tutan vektör 1x3 boyutlu olmalı.*/

float *columnMeans(float **mat, int row, int col);
/*Parametre olarak 2 boyutlu matrisi ve boyutlarını alacak, bu matrisin sütunlarının ortalamasını tutan bir vektör döndürecektir. 
Örneğin; 5x3’lük bir matrisin sütun ortalamasını tutan vektör 5x1 boyutlu olmalıdır.*/

float **covarianceMatrix(float **mat, int row, int col);
/*Parametre olarak matrisi ve boyutlarını alacak, bu matrisin (sütun bazında) varyans kovaryans matrisini döndürecektir. 
Covariance matrix hesabında yazdığınız diğer fonksiyonlar kullanılacaktır. 
İlgili hesaplamaya ek dosyada bulunmaktadır.*/

float determinant(float **mat, int row);
/*Parametre olarak aldığı 2 boyutlu 3x3 boyutlu matrisin determinantını döndürecektir. 
Fonksiyon içerisinde yeni bir matris oluşturulmayacaktır. 
Sütunların eklenmesi “realloc” fonksiyonu ile yapılacaktır. 
İlgili hesaplamaya ek dosyada bulunmaktadır.
İpucu: “+” ve “-” olarak hesaplanacak değerler uygun boyutta bir vektörde tutulabilir*/

void printVector(float *vec, int N);
//Parametre olarak aldığı bir boyutlu vektörü ekrana yazacaktır.

void printMatrix(float **mat, int row, int col);
//Parametre olarak aldığı 2 boyutlu matrisi ekrana matris formunda yazacaktır.*/