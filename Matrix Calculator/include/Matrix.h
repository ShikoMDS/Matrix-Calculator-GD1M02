/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) [Year] Media Design School
File Name : Matrix.h
Description : Declarations for matrix functions
Author : Chris, Shikomisen (Ayoub)
Mail : christopher.houdt@mds.ac.nz, ayoub.ahmad@mds.ac.nz
**************************************************************************/

#pragma once

#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>

class Matrix
{
public:
	Matrix();
	Matrix(int Rows, int Cols);

	~Matrix();

	void resize(int Rows, int Cols);
	void display() const;
	[[nodiscard]] double determinant() const;
	[[nodiscard]] Matrix transpose() const;
	[[nodiscard]] Matrix inverse() const;
	[[nodiscard]] Matrix scalarMultiply(double Scalar) const;
	[[nodiscard]] Matrix matrixAddition(const Matrix& Other) const;
	[[nodiscard]] Matrix matrixSubtraction(const Matrix& Other) const;
	[[nodiscard]] Matrix matrixMultiplication(const Matrix& Other) const;
	[[nodiscard]] Matrix identityMatrix(const Matrix& Other) const;

	// Add operator[] for accessing rows
	const std::vector<double>& operator[](const int Index) const;
	std::vector<double>& operator[](const int Index);

private:
	std::vector<std::vector<double>> Data;
};
