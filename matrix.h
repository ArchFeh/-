#include <stdio.h>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

template <class T_Type>
class Matrix
{
	public:
		Matrix(unsigned row,unsigned col);
		Matrix(const Matrix<T_Type>&);
		template<class T>
		Matrix(const Matrix<T>&);
		Matrix(const char*);
		Matrix<T_Type> transpose();
		Matrix<T_Type>& operator=(const Matrix<T_Type>&);
		Matrix<T_Type> operator+(const Matrix<T_Type>&);
		Matrix<T_Type> operator-(const Matrix<T_Type>&);
		Matrix<T_Type> operator*(int);
		Matrix<T_Type> operator*(const Matrix<T_Type>&);
	private:
		unsigned rows;
		unsigned cols;
		<T_Type> mat[rows][cols];
}

template <class T_Type>
Matrix<T_Type>::Matrix(unsigned row,unsigned col)
{
	rows=row;
	cols=col;
	mat.resize(rows*cols)};
}

template <class T_Type>
Matrix<T_Type>::Matrix(const Matrix<T_Type>&mat2)
{
	this.mat=mat2.mat;
}

template <class T_Type>
template <typename T>
Matrix<T_Type>::Matrix(const Matrix<T>& mat2)
{
	this.mat=static_cast<T>mat2;
	this.mat=[1][1];
}

template<class T_Type>
Matrix<T_Type>::Matrix(const char* fileName)
{
}
