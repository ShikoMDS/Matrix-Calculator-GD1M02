/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) [Year] Media Design School
File Name : Program.h
Description : Declarations for an instance of a matrix calculator program
Author : Chris, Shikomisen (Ayoub)
Mail : christopher.houdt@mds.ac.nz, ayoub.ahmad@mds.ac.nz
**************************************************************************/

#pragma once

#include <fstream>

#include "Matrix.h"

class Program
{
public:
	Program();
	~Program();

	void run();

private:
	Matrix MatrixA;
	Matrix MatrixB;
	double Scalar{};

	void loadMatricesAndScalar(const std::string& Filename);
	void displayMatrices() const;
	void performOperations() const;
};
