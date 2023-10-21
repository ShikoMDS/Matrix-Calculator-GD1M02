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
	std::cout << "Resizing matrix to " << Rows << "x" << Cols << std::endl;

	if (Rows <= 0 || Cols <= 0)
	{
		std::cerr << "Error: Attempting to resize matrix to non-positive dimensions." << std::endl;
		exit(1);
	}

	Data.resize(Rows, std::vector<double>(Cols, 0));
}

void Matrix::display() const
{
	std::cout << "Matrix dimensions in display: " << Data.size() << "x" << (Data.empty() ? 0 : Data[0].size()) <<
		std::endl;

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
	const int Rows = Data.size();
	const int Cols = Data[0].size();

	if (Rows != Cols)
	{
		std::cerr << "Determinant is undefined for non-square matrices." << std::endl;
		exit(1);
	}

	if (Rows == 1)
	{
		return Data[0][0];
	}

	if (Rows == 2)
	{
		return Data[0][0] * Data[1][1] - Data[0][1] * Data[1][0];
	}

	double Det = 0;
	for (int J = 0; J < Cols; ++J)
	{
		Matrix Submatrix(Rows - 1, Cols - 1);
		for (int I = 1; I < Rows; ++I)
		{
			for (int K = 0, L = 0; K < Cols; ++K)
			{
				if (K != J)
				{
					Submatrix[I - 1][L++] = Data[I][K];
				}
			}
		}
		Det += pow(-1, J) * Data[0][J] * Submatrix.determinant();
	}

	return Det;
}

Matrix Matrix::transpose() const
{
	const int Rows = Data.size();
	const int Cols = Data[0].size();

	Matrix Result(Cols, Rows);

	for (int I = 0; I < Rows; ++I)
	{
		for (int J = 0; J < Cols; ++J)
		{
			Result[J][I] = Data[I][J];
		}
	}

	return Result;
}

Matrix Matrix::inverse() const
{
	const int Rows = Data.size();
	const int Cols = Data[0].size();

	if (Rows != Cols)
	{
		std::cerr << "Inverse is undefined for non-square matrices." << std::endl;
		exit(1);
	}

	const double Det = determinant();

	if (Det == 0)
	{
		std::cerr << "Matrix is singular. Cannot find the inverse." << std::endl;
		exit(1);
	}

	Matrix InverseMatrix(Rows, Cols);

	for (int I = 0; I < Rows; ++I)
	{
		for (int J = 0; J < Cols; ++J)
		{
			// Calculate the cofactor of element (i, j)
			Matrix Submatrix(Rows - 1, Cols - 1);
			for (int M = 0, P = 0; M < Rows; ++M)
			{
				for (int N = 0, Q = 0; N < Cols; ++N)
				{
					if (M != I && N != J)
					{
						Submatrix[P][Q++] = Data[M][N];
					}
				}
				if (M != I)
				{
					++P;
				}
			}

			// Calculate the sign for the cofactor
			const double Sign = (I + J) % 2 == 0 ? 1.0 : -1.0;

			// Calculate the determinant of the cofactor matrix
			const double CofactorDet = Submatrix.determinant();

			// Calculate the (i, j)-th entry of the adjugate matrix
			InverseMatrix[J][I] = Sign * CofactorDet / Det;
		}
	}

	return InverseMatrix;
}

Matrix Matrix::scalarMultiply(const double Scalar) const
{
	const int Rows = Data.size();
	const int Cols = Data[0].size();

	Matrix Result(Rows, Cols);

	for (int I = 0; I < Rows; ++I)
	{
		for (int J = 0; J < Cols; ++J)
		{
			Result[I][J] = Data[I][J] * Scalar;
		}
	}

	return Result;
}


Matrix Matrix::matrixAddition(const Matrix& Other) const
{
	const int Rows = Data.size();
	const int Cols = Data[0].size();

	if (Rows != Other.Data.size() || Cols != Other.Data[0].size())
	{
		std::cerr << "Matrix addition is undefined for matrices of different sizes." << std::endl;
		exit(1);
	}

	Matrix Result(Rows, Cols);

	for (int I = 0; I < Rows; ++I)
	{
		for (int J = 0; J < Cols; ++J)
		{
			Result[I][J] = Data[I][J] + Other.Data[I][J];
		}
	}

	return Result;
}

Matrix Matrix::matrixSubtraction(const Matrix& Other) const
{
	const int Rows = Data.size();
	const int Cols = Data[0].size();

	if (Rows != Other.Data.size() || Cols != Other.Data[0].size())
	{
		std::cerr << "Matrix subtraction is undefined for matrices of different sizes." << std::endl;
		exit(1);
	}

	Matrix Result(Rows, Cols);

	for (int I = 0; I < Rows; ++I)
	{
		for (int J = 0; J < Cols; ++J)
		{
			Result[I][J] = Data[I][J] - Other.Data[I][J];
		}
	}

	return Result;
}

Matrix Matrix::matrixMultiplication(const Matrix& Other) const
{
	const int RowsA = Data.size();
	const int ColsA = Data[0].size();
	const int RowsB = Other.Data.size();
	const int ColsB = Other.Data[0].size();

	if (ColsA != RowsB)
	{
		std::cerr <<
			"Matrix multiplication is undefined. Number of columns in matrix A must be equal to the number of rows in matrix B."
			<< std::endl;
		exit(1);
	}

	Matrix Result(RowsA, ColsB);

	for (int I = 0; I < RowsA; ++I)
	{
		for (int J = 0; J < ColsB; ++J)
		{
			for (int K = 0; K < ColsA; ++K)
			{
				Result[I][J] += Data[I][K] * Other.Data[K][J];
			}
		}
	}

	return Result;
}

Matrix Matrix::identityMatrix() const
{
	const int Rows = Data.size();
	const int Cols = Data[0].size();

	if (Rows != Cols)
	{
		std::cerr << "Identity matrix is undefined for non-square matrices." << std::endl;
		exit(1);
	}

	Matrix Result(Rows, Cols);

	for (int I = 0; I < Rows; ++I)
	{
		for (int J = 0; J < Cols; ++J)
		{
			Result[I][J] = (I == J) ? 1.0 : 0.0;
		}
	}

	return Result;
}

std::vector<double>& Matrix::operator[](const int Index) {
	return Data[Index];
}

const std::vector<double>& Matrix::operator[](const int Index) const {
	return Data[Index];
}