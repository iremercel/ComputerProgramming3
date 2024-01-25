#include <iostream>
#pragma once

class Imaginary
{
	protected	:
		int im;
	public	:
		Imaginary(void);
		Imaginary(int _im);
		Imaginary(double _im);
		~Imaginary(void);
		void setIm(const int &imaginary);
		const int &getIm(void) const;
};
//Bu sınıf, karmaşık sayıların sanal kısmını temsil etmek için kullanılabilir.
// Imaginary sınıfının üyeleri korumalıdır, bu da bu sınıfın alt sınıflar tarafından erişilebileceği, 
//ancak doğrudan dışarıdan erişilemeyeceği anlamına gelir. Sınıfın kullanıcılarına açık olan kısımlar 
//ise public: etiketi altında tanımlanmıştır.