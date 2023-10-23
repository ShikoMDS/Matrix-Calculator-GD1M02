/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) [Year] Media Design School
File Name : Matrix.cpp
Description : Implementations for matrix calculation functions
Author : Chris, Shikomisen (Ayoub)
Mail : christopher.houdt@mds.ac.nz, ayoub.ahmad@mds.ac.nz
**************************************************************************/

#include "Matrix.h"

Matrix::Matrix() = default;

Matrix::Matrix(const int Rows, const int Cols) : Data(Rows, std::vector<double>(Cols, 0)) {}

Matrix::~Matrix() = default;

void Matrix::resize(const int Rows, const int Cols)
{
	Data.resize(Rows, std::vector<double>(Cols, 0));
}

void Matrix::display() const
{
	for (const auto& Row : Data)
	{
		for (const double Val : Row)
		{
			std::cout << std::setprecision(2) << Val << "	";
		}
		std::cout << std::endl;
	}
}

double Matrix::determinant() const
{
	// Implementation for determinant
	const double A = Data[0][0];
	const double B = Data[0][1];
	const double C = Data[0][2];
	const double D = Data[0][3];
	const double E = Data[1][0];
	const double F = Data[1][1];
	const double G = Data[1][2];
	const double H = Data[1][3];
	const double I = Data[2][0];
	const double J = Data[2][1];
	const double K = Data[2][2];
	const double L = Data[2][3];
	const double M = Data[3][0];
	const double N = Data[3][1];
	const double O = Data[3][2];
	const double P = Data[3][3];

	const double Determinant = (A * F * K * P) + (A * G * L * N) + (A * H * J * O)
		- (A * H * K * N) - (A * G * J * P) - (A * F * L * O)
		- (B * E * K * P) - (C * E * L * N) - (D * E * J * O)
		+ (D * E * K * N) + (C * E * J * P) + (B * E * L * O)
		+ (B * G * I * P) + (C * H * I * N) + (D * F * I * O)
		- (D * G * I * N) - (C * F * I * P) - (B * H * I * O)
		- (B * G * L * M) - (C * H * J * M) - (D * F * K * M)
		+ (D * G * J * M) + (C * F * L * M) + (B * H * K * M);

	return Determinant;
}

Matrix Matrix::transpose() const
{
	// Implementation for transpose
	Matrix Transpose;
	Transpose.resize(4, 4);

	Transpose[0][0] = Data[0][0];
	Transpose[0][1] = Data[1][0];
	Transpose[0][2] = Data[2][0];
	Transpose[0][3] = Data[3][0];
	Transpose[1][0] = Data[0][1];
	Transpose[1][1] = Data[1][1];
	Transpose[1][2] = Data[2][1];
	Transpose[1][3] = Data[3][1];
	Transpose[2][0] = Data[0][2];
	Transpose[2][1] = Data[1][2];
	Transpose[2][2] = Data[2][2];
	Transpose[2][3] = Data[3][2];
	Transpose[3][0] = Data[0][3];
	Transpose[3][1] = Data[1][3];
	Transpose[3][2] = Data[2][3];
	Transpose[3][3] = Data[3][3];

	return Transpose;
}

Matrix Matrix::inverse() const
{
	// Implementation for inverse
	const double A = Data[0][0];
	const double B = Data[0][1];
	const double C = Data[0][2];
	const double D = Data[0][3];
	const double E = Data[1][0];
	const double F = Data[1][1];
	const double G = Data[1][2];
	const double H = Data[1][3];
	const double I = Data[2][0];
	const double J = Data[2][1];
	const double K = Data[2][2];
	const double L = Data[2][3];
	const double M = Data[3][0];
	const double N = Data[3][1];
	const double O = Data[3][2];
	const double P = Data[3][3];

	Matrix Cofactor;
	Cofactor.resize(4, 4);

	Cofactor[0][0] = F * ((K * P) - (O * L)) - G * ((J * P) - (N * L)) + H * ((J * O) - (N * K));
	Cofactor[0][1] = -(E * ((K * P) - (O * L)) - G * ((I * P) - (M * L)) + H * ((I * O) - (M * K)));
	Cofactor[0][2] = E * ((J * P) - (N * L)) - F * ((I * P) - (M * L)) + H * ((I * N) - (M * J));
	Cofactor[0][3] = -(E * ((J * O) - (N * K)) - F * ((I * O) - (M * K)) + G * ((I * N) - (M * J)));
	Cofactor[1][0] = -(B * ((K * P) - (O * L)) - C * ((J * P) - (N * L)) + D * ((J * O) - (N * K)));
	Cofactor[1][1] = A * ((K * P) - (O * L)) - C * ((I * P) - (M * L)) + D * ((I * O) - (M * K));
	Cofactor[1][2] = -(A * ((J * P) - (N * L)) - B * ((I * P) - (M * L)) + D * ((I * N) - (M * J)));
	Cofactor[1][3] = A * ((J * O) - (N * K)) - B * ((I * O) - (M * K)) + C * ((I * N) - (M * J));
	Cofactor[2][0] = B * ((G * P) - (O * H)) - C * ((F * P) - (N * H)) + D * ((F * O) - (N * G));
	Cofactor[2][1] = -(A * ((G * P) - (O * H)) - C * ((E * P) - (M * H)) + D * ((E * O) - (M * G)));
	Cofactor[2][2] = A * ((F * P) - (N * H)) - B * ((E * P) - (M * H)) + D * ((E * N) - (M * F));
	Cofactor[2][3] = -(A * ((F * O) - (N * G)) - B * ((E * O) - (M * G)) + C * ((E * N) - (M * F)));
	Cofactor[3][0] = -(B * ((G * L) - (K * H)) - C * ((F * L) - (J * H)) + D * ((F * K) - (J * G)));
	Cofactor[3][1] = A * ((G * L) - (K * H)) - C * ((E * L) - (I * H)) + D * ((E * K) - (I * G));
	Cofactor[3][2] = -(A * ((F * L) - (J * H)) - B * ((E * L) - (I * H)) + D * ((E * J) - (I * F)));	
	Cofactor[3][3] = A * ((F * K) - (J * G)) - B * ((E * K) - (I * G)) + C * ((E * J) - (I * F));

	Matrix Inverse;
	Inverse.resize(4, 4);
	Inverse = Cofactor.transpose();

	Inverse[0][0] = Inverse[0][0] / determinant();
	Inverse[0][1] = Inverse[0][1] / determinant();
	Inverse[0][2] = Inverse[0][2] / determinant();
	Inverse[0][3] = Inverse[0][3] / determinant();
	Inverse[1][0] = Inverse[1][0] / determinant();
	Inverse[1][1] = Inverse[1][1] / determinant();
	Inverse[1][2] = Inverse[1][2] / determinant();
	Inverse[1][3] = Inverse[1][3] / determinant();
	Inverse[2][0] = Inverse[2][0] / determinant();
	Inverse[2][1] = Inverse[2][1] / determinant();
	Inverse[2][2] = Inverse[2][2] / determinant();
	Inverse[2][3] = Inverse[2][3] / determinant();
	Inverse[3][0] = Inverse[3][0] / determinant();
	Inverse[3][1] = Inverse[3][1] / determinant();
	Inverse[3][2] = Inverse[3][2] / determinant();
	Inverse[3][3] = Inverse[3][3] / determinant();

	return Inverse;
}

Matrix Matrix::scalarMultiply(const double Scalar) const
{
	// Implementation for scalar multiplication
	Matrix Resultant;
	Resultant.resize(4, 4);

	Resultant[0][0] = Data[0][0] * Scalar;
	Resultant[0][1] = Data[0][1] * Scalar;
	Resultant[0][2] = Data[0][2] * Scalar;
	Resultant[0][3] = Data[0][3] * Scalar;
	Resultant[1][0] = Data[1][0] * Scalar;
	Resultant[1][1] = Data[1][1] * Scalar;
	Resultant[1][2] = Data[1][2] * Scalar;
	Resultant[1][3] = Data[1][3] * Scalar;
	Resultant[2][0] = Data[2][0] * Scalar;
	Resultant[2][1] = Data[2][1] * Scalar;
	Resultant[2][2] = Data[2][2] * Scalar;
	Resultant[2][3] = Data[2][3] * Scalar;
	Resultant[3][0] = Data[3][0] * Scalar;
	Resultant[3][1] = Data[3][1] * Scalar;
	Resultant[3][2] = Data[3][2] * Scalar;
	Resultant[3][3] = Data[3][3] * Scalar;

	return Resultant;
}

Matrix Matrix::matrixAddition(const Matrix& Other) const
{
	// Implementation for matrix addition
	Matrix Resultant;
	Resultant.resize(4, 4);

	Resultant[0][0] = Data[0][0] + Other[0][0];
	Resultant[0][1] = Data[0][1] + Other[0][1];
	Resultant[0][2] = Data[0][2] + Other[0][2];
	Resultant[0][3] = Data[0][3] + Other[0][3];
	Resultant[1][0] = Data[1][0] + Other[1][0];
	Resultant[1][1] = Data[1][1] + Other[1][1];
	Resultant[1][2] = Data[1][2] + Other[1][2];
	Resultant[1][3] = Data[1][3] + Other[1][3];
	Resultant[2][0] = Data[2][0] + Other[2][0];
	Resultant[2][1] = Data[2][1] + Other[2][1];
	Resultant[2][2] = Data[2][2] + Other[2][2];
	Resultant[2][3] = Data[2][3] + Other[2][3];
	Resultant[3][0] = Data[3][0] + Other[3][0];
	Resultant[3][1] = Data[3][1] + Other[3][1];
	Resultant[3][2] = Data[3][2] + Other[3][2];
	Resultant[3][3] = Data[3][3] + Other[3][3];

	return Resultant;
}

Matrix Matrix::matrixSubtraction(const Matrix& Other) const
{
	// Implementation for matrix subtraction
	Matrix Resultant;
	Resultant.resize(4, 4);

	Resultant[0][0] = Data[0][0] - Other[0][0];
	Resultant[0][1] = Data[0][1] - Other[0][1];
	Resultant[0][2] = Data[0][2] - Other[0][2];
	Resultant[0][3] = Data[0][3] - Other[0][3];
	Resultant[1][0] = Data[1][0] - Other[1][0];
	Resultant[1][1] = Data[1][1] - Other[1][1];
	Resultant[1][2] = Data[1][2] - Other[1][2];
	Resultant[1][3] = Data[1][3] - Other[1][3];
	Resultant[2][0] = Data[2][0] - Other[2][0];
	Resultant[2][1] = Data[2][1] - Other[2][1];
	Resultant[2][2] = Data[2][2] - Other[2][2];
	Resultant[2][3] = Data[2][3] - Other[2][3];
	Resultant[3][0] = Data[3][0] - Other[3][0];
	Resultant[3][1] = Data[3][1] - Other[3][1];
	Resultant[3][2] = Data[3][2] - Other[3][2];
	Resultant[3][3] = Data[3][3] - Other[3][3];

	return Resultant;
}

Matrix Matrix::matrixMultiplication(const Matrix& Other) const
{
	// Implementation for matrix multiplication
	Matrix Resultant;
	Resultant.resize(4, 4);

	Resultant[0][0] = (Data[0][0] * Other[0][0]) + (Data[0][1] * Other[1][0]) + (Data[0][2] * Other[2][0]) + (Data[0][3] * Other[3][0]);
	Resultant[0][1] = (Data[0][0] * Other[0][1]) + (Data[0][1] * Other[1][1]) + (Data[0][2] * Other[2][1]) + (Data[0][3] * Other[3][1]);
	Resultant[0][2] = (Data[0][0] * Other[0][2]) + (Data[0][1] * Other[1][2]) + (Data[0][2] * Other[2][2]) + (Data[0][3] * Other[3][2]);
	Resultant[0][3] = (Data[0][0] * Other[0][3]) + (Data[0][1] * Other[1][3]) + (Data[0][2] * Other[2][3]) + (Data[0][3] * Other[3][3]);
	Resultant[1][0] = (Data[1][0] * Other[0][0]) + (Data[1][1] * Other[1][0]) + (Data[1][2] * Other[2][0]) + (Data[1][3] * Other[3][0]);
	Resultant[1][1] = (Data[1][0] * Other[0][1]) + (Data[1][1] * Other[1][1]) + (Data[1][2] * Other[2][1]) + (Data[1][3] * Other[3][1]);
	Resultant[1][2] = (Data[1][0] * Other[0][2]) + (Data[1][1] * Other[1][2]) + (Data[1][2] * Other[2][2]) + (Data[1][3] * Other[3][2]);
	Resultant[1][3] = (Data[1][0] * Other[0][3]) + (Data[1][1] * Other[1][3]) + (Data[1][2] * Other[2][3]) + (Data[1][3] * Other[3][3]);
	Resultant[2][0] = (Data[2][0] * Other[0][0]) + (Data[2][1] * Other[1][0]) + (Data[2][2] * Other[2][0]) + (Data[2][3] * Other[3][0]);
	Resultant[2][1] = (Data[2][0] * Other[0][1]) + (Data[2][1] * Other[1][1]) + (Data[2][2] * Other[2][1]) + (Data[2][3] * Other[3][1]);
	Resultant[2][2] = (Data[2][0] * Other[0][2]) + (Data[2][1] * Other[1][2]) + (Data[2][2] * Other[2][2]) + (Data[2][3] * Other[3][2]);
	Resultant[2][3] = (Data[2][0] * Other[0][3]) + (Data[2][1] * Other[1][3]) + (Data[2][2] * Other[2][3]) + (Data[2][3] * Other[3][3]);
	Resultant[3][0] = (Data[3][0] * Other[0][0]) + (Data[3][1] * Other[1][0]) + (Data[3][2] * Other[2][0]) + (Data[3][3] * Other[3][0]);
	Resultant[3][1] = (Data[3][0] * Other[0][1]) + (Data[3][1] * Other[1][1]) + (Data[3][2] * Other[2][1]) + (Data[3][3] * Other[3][1]);
	Resultant[3][2] = (Data[3][0] * Other[0][2]) + (Data[3][1] * Other[1][2]) + (Data[3][2] * Other[2][2]) + (Data[3][3] * Other[3][2]);
	Resultant[3][3] = (Data[3][0] * Other[0][3]) + (Data[3][1] * Other[1][3]) + (Data[3][2] * Other[2][3]) + (Data[3][3] * Other[3][3]);

	return Resultant;
}

Matrix Matrix::identityMatrix(const Matrix& Other) const
{
	// Implementation for identity matrix
	Matrix Identity;
	Identity.resize(4, 4);

	Identity = Other.matrixMultiplication(Other.inverse());

	// Set very small values to zero (8.9e-16 is basically 0, whatever. n.b. Chris please remove my dumb comment when you see this c;)
	// Basically, floating point precision issues I can't be bothered dealing with!!!
	for (int I = 0; I < 4; ++I)
	{
		for (int J = 0; J < 4; ++J)
		{
			if (std::abs(Identity[I][J]) < 1e-10)
			{
				Identity[I][J] = 0.0;
			}
		}
	}

	return Identity;
}

const std::vector<double>& Matrix::operator[](const int Index) const
{
	return Data[Index];
}

std::vector<double>& Matrix::operator[](const int Index)
{
	return Data[Index];
}
