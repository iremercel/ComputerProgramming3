#include "Imaginary.hpp"
#pragma once
//Bu pragma, başlık dosyasının yalnızca bir kez derleme zamanında dahil edilmesini sağlar. 
class Complex	: public Imaginary //Complex sınıfı, Imaginary sınıfından miras alır. Yani, karmaşık sayı sınıfı, aynı zamanda Imaginary sınıfının özelliklerine ve fonksiyonlarına erişebilir.
{
	private	:
		int	re;
	public	:
		Complex(void);   //Varsayılan constructor: Karmaşık sayıyı varsayılan değerlerle başlatır. Reel kısmı 0 olarak ayarlar.
		Complex(const Complex &source); //Copy constructor: Bir karmaşık sayıyı başka bir karmaşık sayı ile kopyalar.
		Complex(int _re, int _im);
		Complex(double _re, double _im);
		~Complex();
		const int &getRe(void) const;
		void setRe(const int &reel);
		void operator=(const Complex &source);
		Complex operator+(const Complex &rhs) const;
		Complex operator-(const Complex &rhs) const;
		Complex operator*(const Complex &rhs) const;
		Complex operator/(const Complex &rhs) const;
		void operator+=(const Complex &rhs);
		void operator-=(const Complex &rhs);
		void operator*=(const Complex &rhs);
		void operator/=(const Complex &rhs);
		bool operator==(const Complex &rhs) const;
		friend std::ostream &operator<<(std::ostream &os, const Complex &obj);
};