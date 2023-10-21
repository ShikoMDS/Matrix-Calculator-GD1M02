#pragma once

#include <istream>
#include <vector>

class Matrix
{
public:
	Matrix();
	Matrix(int Rows, int Cols);

	void resize(int Rows, int Cols);
	void display() const;

	[[nodiscard]] double determinant() const;
	[[nodiscard]] Matrix transpose() const;
	[[nodiscard]] Matrix inverse() const;
	[[nodiscard]] Matrix scalarMultiply(double Scalar) const;
	[[nodiscard]] Matrix matrixAddition(const Matrix& Other) const;
	[[nodiscard]] Matrix matrixSubtraction(const Matrix& Other) const;
	[[nodiscard]] Matrix matrixMultiplication(const Matrix& Other) const;
	[[nodiscard]] Matrix identityMatrix() const;

	// Add operator[] for accessing rows
	std::vector<double>& operator[](const int Index);
	const std::vector<double>& operator[](const int Index) const;


private:
	std::vector<std::vector<double>> Data;
};
