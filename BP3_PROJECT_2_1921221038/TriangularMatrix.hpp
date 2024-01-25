#include "Matrix.hpp"

#define UPPER 1
#define LOWER 0

#pragma once

class TriangularMatrix	: public Matrix
{
	private	:

	public	:
	TriangularMatrix(int len, bool l);
	~TriangularMatrix();
};