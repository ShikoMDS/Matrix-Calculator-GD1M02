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
	Matrix matrixA;
	Matrix matrixB;
	double scalar;

	void loadMatricesAndScalar(const std::string& filename);
	void displayMatrices();
	void performOperations();
};
