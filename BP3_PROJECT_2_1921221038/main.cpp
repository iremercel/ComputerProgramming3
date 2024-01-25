#include "SquareMatrix.hpp"
#include "IdentityMatrix.hpp"
#include "TriangularMatrix.hpp"

int	main(void)
{
	Complex complex1, complex2; //İki adet Complex tipinde karmaşık sayı oluşturuluyor.
     
	complex1.setRe(2); //complex1 karmaşık sayısının gerçel ve sanal kısımları belirleniyor.
	complex1.setIm(3);
	std::cout << complex1 << std::endl; 

	complex2.setRe(4);
	complex2.setIm(5);
	std::cout << complex2 << std::endl; 

	Complex complex3 = complex1 + complex2; //complex1 ve complex2 karmaşık sayıları toplanarak complex3 oluşturuluyor.
	std::cout << complex3 << std::endl;

	complex3 -= complex1; //complex1 karmaşık sayısı complex3'ten çıkartılıyor.
	std::cout << complex3 << std::endl;

	complex3 *= complex1; //complex3 karmaşık sayısı complex1 ile çarpılıyor.
	std::cout << complex3 << std::endl;

	complex3 /= complex1; //complex3 karmaşık sayısı complex1'e bölünüyor.
	std::cout << complex3 << std::endl;

	std::cout << (complex2 == complex3) << std::endl; //complex2 ve complex3 karmaşık sayıları karşılaştırılıp sonuç ekrana yazdırılıyor.

	Complex complex5(complex3); //karmaşık sayısının kopyası olan complex5 oluşturuluyor.
	std::cout << complex5 << " copied from " << complex3 << std::endl;

	Vector vector1(2); //Boyutu 2 olan bir vektör oluşturuluyor.
	vector1.setElement(0, complex1); //Vektörün elemanlarına complex1 ve complex2 karmaşık sayıları atanıyor.
	vector1.setElement(1, complex2);

	Vector vector2(2); //Boyutu 2 olan bir başka vektör oluşturuluyor.
	vector2.setElement(0, complex1);
	vector2.setElement(1, complex1);

	Vector vector3 = vector1 + vector2; //Vektörün elemanlarına complex1 karmaşık sayısı atanıyor.
	std::cout << vector3 << std::endl;

	vector3 -= vector2;
	std::cout << vector3 << std::endl;

	Complex complex4 = vector1 * vector2;
	std::cout << complex4 << std::endl;

	Matrix matrix1(2, 2); //2x2 boyutlu bir matris oluşturuluyor.
	matrix1.setElement(0, 0, complex1);
	matrix1.setElement(0, 1, complex2);
	matrix1.setElement(1, 0, complex3);
	matrix1.setElement(1, 1, complex4);
	std::cout << matrix1 << std::endl;

	SquareMatrix matrix2(2); //2x2 boyutlu bir kare matris oluşturuluyor.
	matrix2.setElement(0, 0, complex4);
	matrix2.setElement(0, 1, complex3);
	matrix2.setElement(1, 0, complex2);
	matrix2.setElement(1, 1, complex1);

	Matrix matrix3 = matrix1 + matrix1;
	matrix3.print();

	Matrix matrix4(matrix2);
	matrix4.print();
	std::cout << "copied from " << std::endl;
	matrix2.print();

	IdentityMatrix identityMatrix1(3);
	identityMatrix1.print();

	Complex det = matrix1.determinant();
	std::cout << det << std::endl;

	TriangularMatrix triangularMatrix1(3, UPPER);
	triangularMatrix1.print();
}
//g++ main.cpp Imaginary.cpp Complex.cpp Vector.cpp Matrix.cpp SquareMatrix.cpp IdentityMatrix.cpp TriangularMatrix.cpp LinearAlgebraObject.cpp