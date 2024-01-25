#include "IdentityMatrix.hpp"
//Constructor, başlangıçta temel sınıf olan Matrix sınıfının constructor'ını çağırır ve matris boyutunu belirler.
IdentityMatrix::IdentityMatrix(size_t len) : Matrix(len, len)
{
	Complex complex1(1, 0), complex2(0, 0);
//Complex sınıfından türetilmiş iki karmaşık sayı oluşturulur.
//complex1 kimlik matrisinin köşegenindeki elemanları temsil eder (1, 0).
//complex2 ise köşegen dışındaki elemanları temsil eder (0, 0).

	for(size_t i = 0; i < len; i++) //Satır
	{
		for(size_t j = 0; j < len; j++) //sütun 
		{
			if (i == j)
				this->setElement(i, j, complex1); //Eğer satır ve sütun numaraları birbirine eşitse (köşegen elemanları), o konuma complex1 (1, 0) atanır.
			else
				this->setElement(i, j, complex2);
		}
	} //Eğer satır ve sütun numaraları birbirine eşit değilse (köşegen dışındaki elemanlar), o konuma complex2 (0, 0) atanır.
}

IdentityMatrix::~IdentityMatrix(){}