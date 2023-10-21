#include "Program.h"

Program::Program()
{
	// Default constructor
}

void Program::run()
{
	loadMatricesAndScalar("Matrix.txt");
	displayMatrices();
	performOperations();
}

void Program::loadMatricesAndScalar(const std::string& filename)
{
	std::ifstream inputFile(filename);
	if (!inputFile)
	{
		std::cerr << "Error opening file." << std::endl;
		exit(1);
	}

	int size;
	inputFile >> size;

	matrixA.resize(size, size);
	matrixB.resize(size, size);

	// Read matrix A
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			inputFile >> matrixA[i][j];
		}
	}

	// Read matrix B
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			inputFile >> matrixB[i][j];
		}
	}

	// Read scalar
	inputFile >> scalar;

	// Close the file
	inputFile.close();
}

void Program::displayMatrices()
{
	std::cout << "Matrix A:" << std::endl;
	matrixA.display();

	std::cout << "\nMatrix B:" << std::endl;
	matrixB.display();

	std::cout << "\nScalar: " << scalar << std::endl;
}

void Program::performOperations()
{
	// Matrix operations using the Matrix class
	// You can call Matrix member functions here
	// For example:
	// matrixA.inverse();
	// matrixA.transpose();
	// matrixA.scalarMultiply(scalar);
	// matrixA.matrixAddition(matrixB);
	// matrixA.matrixSubtraction(matrixB);
	// matrixA.matrixMultiplication(matrixB);
	// matrixB.matrixMultiplication(matrixA);
	// matrixA.identityMatrix();
}
