#include "Matrix.hpp"
#pragma once

class SquareMatrix	: public Matrix
{
	private	:

	public	:
		SquareMatrix(size_t len);
		~SquareMatrix();
};

//Bu sınıfın amacı, karesel matrisleri temsil etmek ve bu matrisler üzerinde işlemler gerçekleştirmek için Matrix sınıfından türemektir. Ancak, sınıfın kendisi özel bir işlevsellik eklememiş gibi görünmektedir. 
//Gerçek işlemler ve özellikler Matrix sınıfında tanımlanmış olabilir.