#include "LinearAlgebraObject.hpp"

LinearAlgebraObject::LinearAlgebraObject() {}

LinearAlgebraObject::~LinearAlgebraObject() {}

void LinearAlgebraObject::print() const {}
// Matrisin içeriğini ekrana yazdırmak için kullanılacak bir fonksiyon.
void LinearAlgebraObject::operator+(const LinearAlgebraObject &rhs) const
{
	(void)rhs;
}

void LinearAlgebraObject::operator-(const LinearAlgebraObject &rhs) const
{
	(void)rhs;
}

void LinearAlgebraObject::operator*(const LinearAlgebraObject &rhs) const
{
	(void)rhs;
}

void LinearAlgebraObject::operator+=(const LinearAlgebraObject &rhs)
{
	(void)rhs;
}

void LinearAlgebraObject::operator-=(const LinearAlgebraObject &rhs)
{
	(void)rhs;
}

void LinearAlgebraObject::operator*=(const LinearAlgebraObject &rhs)
{
	(void)rhs;
}

void LinearAlgebraObject::operator==(const LinearAlgebraObject &rhs) const
{
	(void)rhs;
}