#include "Complex.hpp"

Complex::Complex(void)	: re(0) {}   

Complex::Complex(const Complex &source) : Imaginary(0) //Copy constructor: Bir karmaşık sayıyı başka
// bir karmaşık sayı ile kopyalar. İmajiner kısmı 0 olarak ayarlar.
{
	*this = source;
}

Complex::Complex(int _re, int _im)	: Imaginary(_im), re(_re) {}
// Parametreli constructor: İki tam sayı parametre alır ve karmaşık sayıyı bu değerlerle başlatır.
Complex::Complex(double _re, double _im)	: Imaginary(_im), re(_re) {}
//Parametreli constructor: İki double parametre alır ve karmaşık sayıyı bu değerlerle başlatır.
Complex::~Complex(void) {}
//Destructor: Bellekten önce karmaşık sayı nesnesini temizler.
const int &Complex::getRe(void) const //Reel kısmı döndüren bir getter fonksiyonu.
{
	return (this->re); 
}

void Complex::setRe(const int &reel) //Reel kısmı ayarlayan bir setter fonksiyonu.
{
	this->re = reel;
}

void Complex::operator=(const Complex &source)  //Atama operatörü: Bir karmaşık sayıyı başka bir karmaşık sayıya atar.
{
	this->setIm(source.getIm());
	this->setRe(source.getRe());
}


Complex Complex::operator+(const Complex &rhs) const //İki karmaşık sayıyı toplar.
{
	Complex res;
	res.setIm(this->im + rhs.getIm());
	res.setRe(this->re + rhs.getRe());
	return res;
}

Complex Complex::operator-(const Complex &rhs) const //İki karmaşık sayıyı çıkarır.
{
	Complex res;
	res.setIm(this->im - rhs.getIm());
	res.setRe(this->re - rhs.getRe());
	return res;
}

Complex Complex::operator*(const Complex &rhs) const  //
{
    Complex res;
    res.setRe((this->re * rhs.getRe()) - (this->im * rhs.getIm()));
    res.setIm((this->re * rhs.getIm()) + (this->im * rhs.getRe()));
    return res;
}

Complex Complex::operator/(const Complex &rhs) const
{
    Complex res;
    int denominator = rhs.getRe() * rhs.getRe() + rhs.getIm() * rhs.getIm();
    res.setRe((this->re * rhs.getRe() + this->im * rhs.getIm()) / denominator);
    res.setIm((this->im * rhs.getRe() - this->re * rhs.getIm()) / denominator);
    return res;
}

void Complex::operator+=(const Complex &rhs) //Bu karmaşık sayıyı başka bir karmaşık sayı ile toplayıp kendine atar.
{
	this->im = this->im + rhs.getIm();
	this->re =this->re + rhs.getRe();
}

void Complex::operator-=(const Complex &rhs) //Çıkarma atama operatörü: Bu karmaşık sayıyı başka bir karmaşık sayıdan çıkarıp kendine atar.
{
	this->im = this->im - rhs.getIm();
	this->re =this->re - rhs.getRe();
}


void Complex::operator*=(const Complex &rhs)
{
	int tmpRe;
	int tmpIm;

	tmpRe = this->re;
	tmpIm = this->im;
    this->re = (tmpRe * rhs.getRe()) - (tmpIm * rhs.getIm());
	this->im = (tmpRe * rhs.getIm()) + (tmpIm * rhs.getRe());
}

void Complex::operator/=(const Complex &rhs)
{
    int denominator = rhs.getRe() * rhs.getRe() + rhs.getIm() * rhs.getIm();
	int tmpRe;
	int tmpIm;

	tmpRe = this->re;
	tmpIm = this->im;
    this->re = (tmpRe * rhs.getRe() + tmpIm * rhs.getIm()) / denominator;
    this->im = (tmpIm * rhs.getRe() - tmpRe * rhs.getIm()) / denominator;
}

bool Complex::operator==(const Complex &rhs) const //İki karmaşık sayının eşit olup olmadığını kontrol eder.
{
	if (this->im == rhs.getIm())
		if (this->re == rhs.getRe())
			return true;
	return false;
}

std::ostream &operator<<(std::ostream &os, const Complex &obj)
{
    os << obj.re << " + " << obj.im << "i";
    return os;
}