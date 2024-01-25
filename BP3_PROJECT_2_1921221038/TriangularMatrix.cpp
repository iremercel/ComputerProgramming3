#include "TriangularMatrix.hpp"

TriangularMatrix::TriangularMatrix(int len, bool l)	: Matrix(len, len)
{  //Constructor: TriangularMatrix sınıfının constructor'ıdır. 
//Parametre olarak matrisin boyutunu (len) ve matrisin üst veya alt üçgenini temsil eden bir bayrak (l) alır.
	Complex complex1(1, 0), complex2(0, 0);

	for (int i = 0; i < len; i++) //Ardından, iç içe iki döngü kullanarak üçgensel matrisin elemanlarını oluşturur.
	{
		for (int j = 0; j < len; j++)
		{
			if ((i <= j && l == UPPER) || (i >= j && l == LOWER)) //Eğer (i <= j && l == UPPER) ise
			// (yani üst üçgen ve bayrak l UPPER ise), elemanı 1 olarak ayarlar.
				this->setElement(i, j, complex1);
			else //Eğer (i >= j && l == LOWER) ise (yani alt üçgen ve bayrak l LOWER ise), elemanı 1 olarak ayarlar.
				this->setElement(i, j, complex2);
		}
	}
}

TriangularMatrix::~TriangularMatrix() {}