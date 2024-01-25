#include "Complex.hpp"
#include "Vector.hpp"
#include "LinearAlgebraObject.hpp"
#pragma once

class Matrix	: public LinearAlgebraObject
{
	protected	:
    	size_t row;
    	size_t col;
    	std::vector<std::vector<Complex> > elements;

	public		:
    	Matrix(size_t numRows, size_t numCols);
		Matrix(const Matrix &src);
    	~Matrix();
    	size_t getRows(void) const;
    	size_t getCols(void) const;
    	void setElement(size_t rowIndex, size_t colIndex, const Complex &value);
    	const Complex &getElement(size_t rowIndex, size_t colIndex) const;
		Matrix transpose(void) const;
		Complex determinant() const;
		Matrix minorMatrix(size_t removedRow, size_t removedCol) const;
		void operator=(const Matrix &src);
		Matrix operator+(const Matrix &rhs) const;
		Matrix operator-(const Matrix &rhs) const;
		Matrix operator*(const Matrix &rhs) const;
		Matrix &operator+=(const Matrix &rhs);
		Matrix &operator-=(const Matrix &rhs);
		Matrix &operator*=(const Matrix &rhs);
		bool operator==(const Matrix &rhs) const;
		void print(void) const;
    	friend std::ostream &operator<<(std::ostream &os, const Matrix &matrix);
};