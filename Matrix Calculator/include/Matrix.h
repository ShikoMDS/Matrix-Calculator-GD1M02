#pragma once
#include <vector>
#include <iostream>
#include <cmath>
#include <iomanip>

class Matrix
{
public:
	Matrix();
	Matrix(int rows, int cols);

	void resize(int rows, int cols);
	void display() const;
	double determinant() const;
	Matrix transpose() const;
	Matrix inverse() const;
	Matrix scalarMultiply(double scalar) const;
	Matrix matrixAddition(const Matrix& other) const;
	Matrix matrixSubtraction(const Matrix& other) const;
	Matrix matrixMultiplication(const Matrix& other) const;
	Matrix identityMatrix(Matrix _Matrix) const;

	// Add operator[] for accessing rows
	const std::vector<double>& operator[](int index) const
	{
		return data[index];
	}

	std::vector<double>& operator[](int index)
	{
		return data[index];
	}

private:
	std::vector<std::vector<double>> data;
};
