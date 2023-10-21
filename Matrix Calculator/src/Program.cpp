#include "Program.h"

#include <sstream>
#include <string>

Program::Program(): Scalar(0)
{
	// Default constructor
}

void Program::run()
{
	loadMatricesAndScalar("Matrix.txt");
	displayMatrices();
	performOperations();
}

void Program::loadMatricesAndScalar(const std::string& Filename)
{
	if (std::ifstream File(Filename); File.is_open()) {
		std::vector<std::vector<int>> Matrix1, Matrix2;
		int Scalar;

		// Read the first matrix
		readMatrix(File, Matrix1);

		// Read the second matrix
		readMatrix(File, Matrix2);

		// Read the scalar
		File >> Scalar;

		// Close the file
		File.close();

		// Display the loaded data (for testing purposes)
		displayMatrix(Matrix1);
		displayMatrix(Matrix2);
		std::cout << "Scalar: " << Scalar << std::endl;
	}
	else {
		std::cerr << "Unable to open file: " << Filename << std::endl;
	}
}

void Program::readMatrix(std::ifstream& File, std::vector<std::vector<int>>& Matrix) {
	std::string Line;
	while (std::getline(File, Line) && !Line.empty()) {
		std::vector<int> Row;
		std::istringstream Iss(Line);

		char C;
		while (Iss >> C) {
			if (C != '\'' && C != '\"') {
				Row.push_back(C - '0');
			}
		}

		Matrix.push_back(Row);
	}
}

void Program::displayMatrix(const std::vector<std::vector<int>>& Matrix) {
	for (const auto& Row : Matrix) {
		for (const int Value : Row) {
			std::cout << Value << ' ';
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void Program::displayMatrices() const
{
	std::cout << "Matrix A:" << std::endl;
	MatrixA.display();

	std::cout << "\nMatrix B:" << std::endl;
	MatrixB.display();

	std::cout << "\nScalar: " << Scalar << std::endl;
}

void Program::performOperations() const
{
	// Matrix operations using the Matrix class
	// You can call Matrix member functions here
	const Matrix ResultInverse = MatrixA.inverse();
	const Matrix ResultTranspose = MatrixA.transpose();
	const Matrix ResultScalarMultiply = MatrixA.scalarMultiply(Scalar);
	const Matrix ResultAddition = MatrixA.matrixAddition(MatrixB);
	const Matrix ResultSubtraction = MatrixA.matrixSubtraction(MatrixB);
	const Matrix ResultMultiplicationAB = MatrixA.matrixMultiplication(MatrixB);
	const Matrix ResultMultiplicationBA = MatrixB.matrixMultiplication(MatrixA);
	const Matrix ResultIdentity = MatrixA.identityMatrix();

	// Note: You might want to display or use the results as needed
	// For example:
	std::cout << "\nResult of Inverse of A:" << std::endl;
	ResultInverse.display();

	std::cout << "\nResult of Transpose of A:" << std::endl;
	ResultTranspose.display();

	std::cout << "\nResult of Scalar Multiplication of A by " << Scalar << ":" << std::endl;
	ResultScalarMultiply.display();

	std::cout << "\nResult of Addition of A and B:" << std::endl;
	ResultAddition.display();

	std::cout << "\nResult of Subtraction of A and B:" << std::endl;
	ResultSubtraction.display();

	std::cout << "\nResult of Multiplication of A and B:" << std::endl;
	ResultMultiplicationAB.display();

	std::cout << "\nResult of Multiplication of B and A:" << std::endl;
	ResultMultiplicationBA.display();

	std::cout << "\nResult of Identity Matrix of A:" << std::endl;
	ResultIdentity.display();
}
