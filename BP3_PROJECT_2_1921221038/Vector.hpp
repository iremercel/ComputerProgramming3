#include "Complex.hpp"
#include <vector>
#pragma once

class Vector
{
private:
    std::vector<Complex> elements;

public:
    ~Vector();
    Vector(size_t size);
    size_t getSize() const;
    void setElement(size_t index, const Complex &value);
    const Complex &getElement(size_t index) const;
	Vector operator+(const Vector &rhs) const;
	Vector operator-(const Vector &rhs) const;
	Complex operator*(const Vector &rhs) const;
	Vector &operator+=(const Vector &rhs);
	Vector &operator-=(const Vector &rhs);
	//Vector &operator=(const Vector &rhs);
	bool operator==(const Vector &rhs) const;
    friend std::ostream &operator<<(std::ostream &os, const Vector &vector);
};