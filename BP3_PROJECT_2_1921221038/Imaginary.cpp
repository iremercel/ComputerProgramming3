#include "Imaginary.hpp"

Imaginary::Imaginary(void) : im(0) {}
//Sanal kısmı 0 olarak ayarlayarak bir Imaginary nesnesi oluşturur.
Imaginary::Imaginary(int _im) : im(_im) {}
// Bir tam sayı alır ve bu değeri kullanarak bir Imaginary nesnesi oluşturur.
Imaginary::Imaginary(double _im) : im(_im) {}

Imaginary::~Imaginary(void) {}

void Imaginary::setIm(const int &imaginary)
{
	this->im = imaginary;
}

const int &Imaginary::getIm(void) const //Bir referans döndürür, böylece dışarıdan Imaginary nesnesinin sanal kısmına erişim yapılabilir.
{
	return (this->im);
}