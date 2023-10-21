#include "Matrix.h"
#include <iostream>
#include <cmath>

Matrix::Matrix()
{
	// Default constructor
}

Matrix::Matrix(const int Rows, const int Cols) : Data(Rows, std::vector<double>(Cols, 0))
{
	// Constructor with size
}

void Matrix::resize(const int Rows, const int Cols)
{
	Data.resize(Rows, std::vector<double>(Cols, 0));
}

void Matrix::display() const
{
	for (const auto& Row : Data)
	{
		for (const double Val : Row)
		{
			std::cout << Val << " ";
		}
		std::cout << std::endl;
	}
}

double Matrix::determinant() const
{
	// Implementation for determinant
}

Matrix Matrix::transpose() const
{
	// Implementation for transpose
}

Matrix Matrix::inverse() const
{
	// Implementation for inverse
}

Matrix Matrix::scalarMultiply(double Scalar) const
{
	// Implementation for scalar multiplication
}

Matrix Matrix::matrixAddition(const Matrix& Other) const
{
	// Implementation for matrix addition
}

Matrix Matrix::matrixSubtraction(const Matrix& Other) const
{
	// Implementation for matrix subtraction
}

Matrix Matrix::matrixMultiplication(const Matrix& Other) const
{
	// Implementation for matrix multiplication
}

Matrix Matrix::identityMatrix() const
{
	// Implementation for identity matrix
}
