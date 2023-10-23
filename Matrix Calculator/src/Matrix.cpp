#include "Matrix.h"

Matrix::Matrix()
{
	// Default constructor
}

Matrix::Matrix(const int Rows, const int Cols) : data(Rows, std::vector<double>(Cols, 0))
{
	// Constructor with size
}

void Matrix::resize(const int Rows, const int Cols)
{
	data.resize(Rows, std::vector<double>(Cols, 0));
}

void Matrix::display() const
{
	for (const auto& Row : data)
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
	const double a = data[0][0];
	const double b = data[0][1];
	const double c = data[0][2];
	const double d = data[0][3];
	const double e = data[1][0];
	const double f = data[1][1];
	const double g = data[1][2];
	const double h = data[1][3];
	const double i = data[2][0];
	const double j = data[2][1];
	const double k = data[2][2];
	const double l = data[2][3];
	const double m = data[3][0];
	const double n = data[3][1];
	const double o = data[3][2];
	const double p = data[3][3];
	
	double determinant = (a * f * k * p) + (a * g * l * n) + (a * h * j * o)
		- (a * h * k * n) - (a * g * j * p) - (a * f * l * o)
		- (b * e * k * p) - (c * e * l * n) - (d * e * j * o)
		+ (d * e * k * n) + (c * e * j * p) + (b * e * l * o)
		+ (b * g * i * p) + (c * h * i * n) + (d * f * i * o)
		- (d * g * i * n) - (c * f * i * p) - (b * h * i * o)
		- (b * g * l * m) - (c * h * j * m) - (d * f * k * m)
		+ (d * g * j * m) + (c * f * l * m) + (b * h * k * m);

	return determinant;
}

Matrix Matrix::transpose() const
{
	// Implementation for transpose
	Matrix transpose;
	transpose.resize(4, 4);

	transpose[0][0] = data[0][0];
	transpose[0][1] = data[1][0];
	transpose[0][2] = data[2][0];
	transpose[0][3] = data[3][0];
	transpose[1][0] = data[0][1];
	transpose[1][1] = data[1][1];
	transpose[1][2] = data[2][1];
	transpose[1][3] = data[3][1];
	transpose[2][0] = data[0][2];
	transpose[2][1] = data[1][2];
	transpose[2][2] = data[2][2];
	transpose[2][3] = data[3][2];
	transpose[3][0] = data[0][3];
	transpose[3][1] = data[1][3];
	transpose[3][2] = data[2][3];
	transpose[3][3] = data[3][3];

	return transpose;
}

Matrix Matrix::inverse() const
{
	// Implementation for inverse
	const double a = data[0][0];
	const double b = data[0][1];
	const double c = data[0][2];
	const double d = data[0][3];
	const double e = data[1][0];
	const double f = data[1][1];
	const double g = data[1][2];
	const double h = data[1][3];
	const double i = data[2][0];
	const double j = data[2][1];
	const double k = data[2][2];
	const double l = data[2][3];
	const double m = data[3][0];
	const double n = data[3][1];
	const double o = data[3][2];
	const double p = data[3][3];

	Matrix cofactor;
	cofactor.resize(4, 4);

	cofactor[0][0] = f * ((k * p) - (o * l)) - g * ((j * p) - (n * l)) + h * ((j * o) - (n * k));
	cofactor[0][1] = -(e * ((k * p) - (o * l)) - g * ((i * p) - (m * l)) + h * ((i * o) - (m * k)));
	cofactor[0][2] = e * ((j * p) - (n * l)) - f * ((i * p) - (m * l)) + h * ((i * n) - (m * j));
	cofactor[0][3] = -(e * ((j * o) - (n * k)) - f * ((i * o) - (m * k)) + g * ((i * n) - (m * j)));
	cofactor[1][0] = -(b * ((k * p) - (o * l)) - c * ((j * p) - (n * l)) + d * ((j * o) - (n * k)));
	cofactor[1][1] = a * ((k * p) - (o * l)) - c * ((i * p) - (m * l)) + d * ((i * o) - (m * k));
	cofactor[1][2] = -(a * ((j * p) - (n * l)) - b * ((i * p) - (m * l)) + d * ((i * n) - (m * j)));
	cofactor[1][3] = a * ((j * o) - (n * k)) - b * ((i * o) - (m * k)) + c * ((i * n) - (m * j));
	cofactor[2][0] = b * ((g * p) - (o * h)) - c * ((f * p) - (n * h)) + d * ((f * o) - (n * g));
	cofactor[2][1] = -(a * ((g * p) - (o * h)) - c * ((e * p) - (m * h)) + d * ((e * o) - (m * g)));
	cofactor[2][2] = a * ((f * p) - (n * h)) - b * ((e * p) - (m * h)) + d * ((e * n) - (m * f));
	cofactor[2][3] = -(a * ((f * o) - (n * g)) - b * ((e * o) - (m * g)) + c * ((e * n) - (m * f)));
	cofactor[3][0] = -(b * ((g * l) - (k * h)) - c * ((f * l) - (j * h)) + d * ((f * k) - (j * g)));
	cofactor[3][1] = a * ((g * l) - (k * h)) - c * ((e * l) - (i * h)) + d * ((e * k) - (i * g));
	cofactor[3][2] = -(a * ((f * l) - (j * h)) - b * ((e * l) - (i * h)) + d * ((e * j) - (i * f)));	
	cofactor[3][3] = a * ((f * k) - (j * g)) - b * ((e * k) - (i * g)) + c * ((e * j) - (i * f));

	Matrix inverse;
	inverse.resize(4, 4);
	inverse = cofactor.transpose();

	inverse[0][0] = inverse[0][0] / determinant();
	inverse[0][1] = inverse[0][1] / determinant();
	inverse[0][2] = inverse[0][2] / determinant();
	inverse[0][3] = inverse[0][3] / determinant();
	inverse[1][0] = inverse[1][0] / determinant();
	inverse[1][1] = inverse[1][1] / determinant();
	inverse[1][2] = inverse[1][2] / determinant();
	inverse[1][3] = inverse[1][3] / determinant();
	inverse[2][0] = inverse[2][0] / determinant();
	inverse[2][1] = inverse[2][1] / determinant();
	inverse[2][2] = inverse[2][2] / determinant();
	inverse[2][3] = inverse[2][3] / determinant();
	inverse[3][0] = inverse[3][0] / determinant();
	inverse[3][1] = inverse[3][1] / determinant();
	inverse[3][2] = inverse[3][2] / determinant();
	inverse[3][3] = inverse[3][3] / determinant();

	return inverse;
}

Matrix Matrix::scalarMultiply(double Scalar) const
{
	// Implementation for scalar multiplication
	Matrix resultant;
	resultant.resize(4, 4);

	resultant[0][0] = data[0][0] * Scalar;
	resultant[0][1] = data[0][1] * Scalar;
	resultant[0][2] = data[0][2] * Scalar;
	resultant[0][3] = data[0][3] * Scalar;
	resultant[1][0] = data[1][0] * Scalar;
	resultant[1][1] = data[1][1] * Scalar;
	resultant[1][2] = data[1][2] * Scalar;
	resultant[1][3] = data[1][3] * Scalar;
	resultant[2][0] = data[2][0] * Scalar;
	resultant[2][1] = data[2][1] * Scalar;
	resultant[2][2] = data[2][2] * Scalar;
	resultant[2][3] = data[2][3] * Scalar;
	resultant[3][0] = data[3][0] * Scalar;
	resultant[3][1] = data[3][1] * Scalar;
	resultant[3][2] = data[3][2] * Scalar;
	resultant[3][3] = data[3][3] * Scalar;

	return resultant;
}

Matrix Matrix::matrixAddition(const Matrix& Other) const
{
	// Implementation for matrix addition
	Matrix resultant;
	resultant.resize(4, 4);

	resultant[0][0] = data[0][0] + Other[0][0];
	resultant[0][1] = data[0][1] + Other[0][1];
	resultant[0][2] = data[0][2] + Other[0][2];
	resultant[0][3] = data[0][3] + Other[0][3];
	resultant[1][0] = data[1][0] + Other[1][0];
	resultant[1][1] = data[1][1] + Other[1][1];
	resultant[1][2] = data[1][2] + Other[1][2];
	resultant[1][3] = data[1][3] + Other[1][3];
	resultant[2][0] = data[2][0] + Other[2][0];
	resultant[2][1] = data[2][1] + Other[2][1];
	resultant[2][2] = data[2][2] + Other[2][2];
	resultant[2][3] = data[2][3] + Other[2][3];
	resultant[3][0] = data[3][0] + Other[3][0];
	resultant[3][1] = data[3][1] + Other[3][1];
	resultant[3][2] = data[3][2] + Other[3][2];
	resultant[3][3] = data[3][3] + Other[3][3];

	return resultant;
}

Matrix Matrix::matrixSubtraction(const Matrix& Other) const
{
	// Implementation for matrix subtraction
	Matrix resultant;
	resultant.resize(4, 4);

	resultant[0][0] = data[0][0] - Other[0][0];
	resultant[0][1] = data[0][1] - Other[0][1];
	resultant[0][2] = data[0][2] - Other[0][2];
	resultant[0][3] = data[0][3] - Other[0][3];
	resultant[1][0] = data[1][0] - Other[1][0];
	resultant[1][1] = data[1][1] - Other[1][1];
	resultant[1][2] = data[1][2] - Other[1][2];
	resultant[1][3] = data[1][3] - Other[1][3];
	resultant[2][0] = data[2][0] - Other[2][0];
	resultant[2][1] = data[2][1] - Other[2][1];
	resultant[2][2] = data[2][2] - Other[2][2];
	resultant[2][3] = data[2][3] - Other[2][3];
	resultant[3][0] = data[3][0] - Other[3][0];
	resultant[3][1] = data[3][1] - Other[3][1];
	resultant[3][2] = data[3][2] - Other[3][2];
	resultant[3][3] = data[3][3] - Other[3][3];

	return resultant;
}

Matrix Matrix::matrixMultiplication(const Matrix& Other) const
{
	// Implementation for matrix multiplication
	Matrix resultant;
	resultant.resize(4, 4);

	resultant[0][0] = (data[0][0] * Other[0][0]) + (data[0][1] * Other[1][0]) + (data[0][2] * Other[2][0]) + (data[0][3] * Other[3][0]);
	resultant[0][1] = (data[0][0] * Other[0][1]) + (data[0][1] * Other[1][1]) + (data[0][2] * Other[2][1]) + (data[0][3] * Other[3][1]);
	resultant[0][2] = (data[0][0] * Other[0][2]) + (data[0][1] * Other[1][2]) + (data[0][2] * Other[2][2]) + (data[0][3] * Other[3][2]);
	resultant[0][3] = (data[0][0] * Other[0][3]) + (data[0][1] * Other[1][3]) + (data[0][2] * Other[2][3]) + (data[0][3] * Other[3][3]);
	resultant[1][0] = (data[1][0] * Other[0][0]) + (data[1][1] * Other[1][0]) + (data[1][2] * Other[2][0]) + (data[1][3] * Other[3][0]);
	resultant[1][1] = (data[1][0] * Other[0][1]) + (data[1][1] * Other[1][1]) + (data[1][2] * Other[2][1]) + (data[1][3] * Other[3][1]);
	resultant[1][2] = (data[1][0] * Other[0][2]) + (data[1][1] * Other[1][2]) + (data[1][2] * Other[2][2]) + (data[1][3] * Other[3][2]);
	resultant[1][3] = (data[1][0] * Other[0][3]) + (data[1][1] * Other[1][3]) + (data[1][2] * Other[2][3]) + (data[1][3] * Other[3][3]);
	resultant[2][0] = (data[2][0] * Other[0][0]) + (data[2][1] * Other[1][0]) + (data[2][2] * Other[2][0]) + (data[2][3] * Other[3][0]);
	resultant[2][1] = (data[2][0] * Other[0][1]) + (data[2][1] * Other[1][1]) + (data[2][2] * Other[2][1]) + (data[2][3] * Other[3][1]);
	resultant[2][2] = (data[2][0] * Other[0][2]) + (data[2][1] * Other[1][2]) + (data[2][2] * Other[2][2]) + (data[2][3] * Other[3][2]);
	resultant[2][3] = (data[2][0] * Other[0][3]) + (data[2][1] * Other[1][3]) + (data[2][2] * Other[2][3]) + (data[2][3] * Other[3][3]);
	resultant[3][0] = (data[3][0] * Other[0][0]) + (data[3][1] * Other[1][0]) + (data[3][2] * Other[2][0]) + (data[3][3] * Other[3][0]);
	resultant[3][1] = (data[3][0] * Other[0][1]) + (data[3][1] * Other[1][1]) + (data[3][2] * Other[2][1]) + (data[3][3] * Other[3][1]);
	resultant[3][2] = (data[3][0] * Other[0][2]) + (data[3][1] * Other[1][2]) + (data[3][2] * Other[2][2]) + (data[3][3] * Other[3][2]);
	resultant[3][3] = (data[3][0] * Other[0][3]) + (data[3][1] * Other[1][3]) + (data[3][2] * Other[2][3]) + (data[3][3] * Other[3][3]);

	return resultant;
}

Matrix Matrix::identityMatrix() const
{
	// Implementation for identity matrix
	Matrix identity;
	identity.resize(4, 4);

	identity[0][0] = 1;
	identity[0][1] = 0;
	identity[0][2] = 0;
	identity[0][3] = 0;
	identity[1][0] = 0;
	identity[1][1] = 1;
	identity[1][2] = 0;
	identity[1][3] = 0;
	identity[2][0] = 0;
	identity[2][1] = 0;
	identity[2][2] = 1;
	identity[2][3] = 0;
	identity[3][0] = 0;
	identity[3][1] = 0;
	identity[3][2] = 0;
	identity[3][3] = 1;

	return identity;
}
