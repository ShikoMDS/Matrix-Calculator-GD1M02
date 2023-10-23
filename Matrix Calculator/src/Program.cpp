/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) [Year] Media Design School
File Name : Program.cpp
Description : Implementations for a matrix calculator program
Author : Chris, Shikomisen (Ayoub)
Mail : christopher.houdt@mds.ac.nz, ayoub.ahmad@mds.ac.nz
**************************************************************************/

#include "Program.h"

Program::Program() : Scalar(0.0) {}

Program::~Program() = default;

void Program::run()
{
	loadMatricesAndScalar("Matrix.txt");
	displayMatrices();
	performOperations();
}

void Program::loadMatricesAndScalar(const std::string& Filename)
{
	std::ifstream InputFile(Filename);
	if (!InputFile)
	{
		std::cerr << "Error opening file." << std::endl;
		exit(1);
	}

	MatrixA.resize(4, 4);
	MatrixB.resize(4, 4);

	// Read matrix A
	for (int I = 0; I < 4; ++I)
	{
		for (int J = 0; J < 4; ++J)
		{
			InputFile >> MatrixA[I][J];
		}
	}

	// Read matrix B
	for (int I = 0; I < 4; ++I)
	{
		for (int j = 0; j < 4; ++j)
		{
			InputFile >> MatrixB[I][j];
		}
	}

	// Read scalar
	InputFile >> Scalar;

	// Close the file
	InputFile.close();
}

void Program::displayMatrices() const
{
	// Call the display function both matrices and the scalar as read
	std::cout << "Matrix A:" << std::endl;
	MatrixA.display();

	std::cout << "\nMatrix B:" << std::endl;
	MatrixB.display();

	std::cout << "\nScalar: " << Scalar << std::endl;
}

void Program::performOperations() const
{
	// Matrix operations using the Matrix class

	// Determinant
	std::cout << "\n|A|: " << MatrixA.determinant();
	std::cout << "\n|B|: " << MatrixB.determinant();

	// Transpose
	std::cout << "\n\nTranspose of A:\n";
	MatrixA.transpose().display();
	std::cout << "\n\nTranspose of B:\n";
	MatrixB.transpose().display();
	
	// Inverse
	std::cout << "\nInverse of A:\n";
	MatrixA.inverse().display();
	std::cout << "\nInverse of B:\n";
	MatrixB.inverse().display();
	
	// Scalar multiplication
	std::cout << "\nA * Scalar:\n";
	MatrixA.scalarMultiply(Scalar).display();
	std::cout << "\nB * Scalar:\n";
	MatrixB.scalarMultiply(Scalar).display();

	// Addition
	std::cout << "\nA + B:\n";
	MatrixA.matrixAddition(MatrixB).display();
	
	// Subtraction
	std::cout << "\nA - B: \n";
	MatrixA.matrixSubtraction(MatrixB).display();
	
	// Matrix multiplication
	std::cout << "\nA * B:\n";
	MatrixA.matrixMultiplication(MatrixB).display();
	std::cout << "\nB * A:\n";
	MatrixB.matrixMultiplication(MatrixA).display();
	
	// Identity matrix
	std::cout << "\nIdentity Matrix:\n";
	MatrixA.identityMatrix(MatrixA).display();
}
