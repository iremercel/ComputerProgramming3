#include "Vector.hpp"

Vector::Vector(size_t size)	: elements(size) {}
// Parametre olarak alınan boyutta bir vektör oluşturan constructor.
Vector::~Vector() {}

size_t Vector::getSize() const
{ // Vektörün boyutunu döndüren bir getter fonksiyonu.
    return elements.size();
}

void Vector::setElement(size_t index, const Complex &value)
{ //Belirtilen konumdaki vektör elemanını belirtilen karmaşık sayı değeri ile ayarlayan bir fonksiyon
    elements[index] = value;
}

const Complex &Vector::getElement(size_t index) const
{
    return elements[index];
}

Vector Vector::operator+(const Vector &rhs) const
{ // İki vektörü toplayan + operatörü. Eğer vektör boyutları eşit değilse, birinci vektörü geri döndürür.
    Vector res(this->getSize());

    if (this->getSize() != rhs.getSize())
		return *this;
    for (size_t i = 0; i < this->getSize(); ++i)
        res.setElement(i, this->getElement(i) + rhs.getElement(i));
    return res;
}

Vector Vector::operator-(const Vector &rhs) const
{ //İki vektörü çıkaran - operatörü. Eğer vektör boyutları eşit değilse, birinci vektörü geri döndürür.
    Vector res(this->getSize());

    if (this->getSize() != rhs.getSize())
		return *this;
    for (size_t i = 0; i < this->getSize(); ++i)
        res.setElement(i, this->getElement(i) - rhs.getElement(i));
    return res;
}

Complex Vector::operator*(const Vector &rhs) const
{
    if (this->getSize() != rhs.getSize())
        return Complex();
    Complex res;
    for (size_t i = 0; i < this->getSize(); ++i)
        res = res + (this->getElement(i) * rhs.getElement(i));
    return res;
}

Vector &Vector::operator+=(const Vector &rhs)
{
    if (this->getSize() != rhs.getSize())
        return *this;
    for (size_t i = 0; i < this->getSize(); ++i)
        this->setElement(i, this->getElement(i) + rhs.getElement(i));
    return *this;
}

Vector &Vector::operator-=(const Vector &rhs)
{
    if (this->getSize() != rhs.getSize())
        return *this;
    for (size_t i = 0; i < this->getSize(); ++i)
        this->setElement(i, this->getElement(i) - rhs.getElement(i));
    return *this;
}

/*Vector &Vector::operator=(const Vector &rhs)
{
    if (this != &rhs)
        this->elements = rhs.elements;
    return *this;
}*/

bool Vector::operator==(const Vector &rhs) const
{
    if (this->getSize() != rhs.getSize())
        return false;
    for (size_t i = 0; i < this->getSize(); ++i)
        if (!(this->getElement(i) == rhs.getElement(i)))
            return false;
    return true;
}

std::ostream &operator<<(std::ostream &os, const Vector &vector)
{
    for (size_t i = 0; i < vector.getSize(); ++i)
        os << vector.getElement(i) << " ";
    return os;
}