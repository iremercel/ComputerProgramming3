#include "Complex.hpp"
#pragma once

class LinearAlgebraObject
{
	private	:

	public	:
		LinearAlgebraObject(void);
		virtual ~LinearAlgebraObject(void);
		virtual void print(void) const = 0;
		virtual void operator+(const LinearAlgebraObject &rhs) const;
		virtual void operator-(const LinearAlgebraObject &rhs) const;
		virtual void operator*(const LinearAlgebraObject &rhs) const;
		virtual void operator+=(const LinearAlgebraObject &rhs);
		virtual void operator-=(const LinearAlgebraObject &rhs);
		virtual void operator*=(const LinearAlgebraObject &rhs);
		virtual void operator==(const LinearAlgebraObject &rhs) const;
};

//Bu sınıf, temel bir lineer cebir nesnesini temsil etmek üzere tasarlanmıştır 
//ve soyut operatörleri içerir. Ancak, bu operatörlerin gövdeleri tanımlanmamıştır
// bu nedenle sınıf doğrudan örneklenemez ve bu operatörler türetilen sınıflar tarafından uygulanmalıdır.S