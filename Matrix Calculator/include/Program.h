#pragma once

#include "Matrix.h"
#include <fstream>
#include <iostream>

class Program
{
public:
	Program();
	void run();

private:
	Matrix MatrixA;
	Matrix MatrixB;
	double Scalar;

	void loadMatricesAndScalar(const std::string& Filename);
	void readMatrix(std::ifstream& File, std::vector<std::vector<int>>& Matrix);
	void displayMatrix(const std::vector<std::vector<int>>& Matrix);
	void displayMatrices() const;
	void performOperations() const;
};
