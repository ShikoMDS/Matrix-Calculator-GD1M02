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

	matrixA.resize(4, 4);
	matrixB.resize(4, 4);

	// Read matrix A
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			inputFile >> matrixA[i][j];
		}
	}

	// Read matrix B
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
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

	// determinant
	std::cout << "\n|A|: " << matrixA.determinant();
	std::cout << "\n|B|: " << matrixB.determinant();

	// transpose
	std::cout << "\n\nTranspose of A:\n";
	matrixA.transpose().display();
	std::cout << "\n\nTranspose of B:\n";
	matrixB.transpose().display();
	
	// inverse
	std::cout << "\nInverse of A:\n";
	matrixA.inverse().display();
	std::cout << "\nInverse of B:\n";
	matrixB.inverse().display();
	
	// scalar maultiplication
	std::cout << "\nA * Scalar:\n";
	matrixA.scalarMultiply(scalar).display();
	std::cout << "\nB * Scalar:\n";
	matrixB.scalarMultiply(scalar).display();

	// addition
	std::cout << "\nA + B:\n";
	matrixA.matrixAddition(matrixB).display();
	
	// subtraction
	std::cout << "\nA - B: \n";
	matrixA.matrixSubtraction(matrixB).display();
	
	// matrix multiplication
	std::cout << "\nA * B:\n";
	matrixA.matrixMultiplication(matrixB).display();
	std::cout << "\nB * A:\n";
	matrixB.matrixMultiplication(matrixA).display();
	
	// identity matrix
	std::cout << "\nIdentity Matrix:\n";
	matrixA.identityMatrix().display();
}
