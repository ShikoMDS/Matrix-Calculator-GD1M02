# Matrix Calculator  
  
Repository created by Chris and Ayoub for GD1M02 Mathematics for Graphical Games Assessment 4 - Final Project.  
  
  
## Table of Contents  
  
- [Description](#Description)  
- [Features](#Features)  
- [Requirements](#Requirements)  
- [Installation](#Installation)  
- [Controls](#Controls)  
- [Disclaimer](#Disclaimer)  
- [Credits](#Credits)  
  
  
## Description  
  
Matrix calculator implemented in C++.  
This program reads from a given text file providing two matrices and a scalar value with spaces in between the matrix values and empty lines to separate the three items.  
A Visual Studio 2022 solution is provided, however "main.cpp" and individual source files "/src/" and include files "/include/" can be accessed individually in their respective folders.  
  
  
## Features  
### Implementations  
The output of the following operations have been implemented.  
- Determinant of matrix A, B  
- Transpose of A, B  
- Inverse of A, B  
- A, B multiplied by a scalar value  
- A + B  
- B - A  
- A * B  
- B * A  
- Generate an identity matrix  
  
  
  
## Requirements  
  
- Visual Studio 2022 (v143)  
- Windows SDK 10.0  
- C++ Language Standard: ISO C++20 Standard (/std:c++20)  
- C Language Standard: ISO C17 (2018) Standard (/std:c17)  
- Windows x64  
  
  
## Installation  
  
Download and extract from the .zip file.  
This calculator can be run by opening the "Matrix Calculator.sln" file and built in Debug or Release mode with x64.  
  
  
## Controls  
  
The program has been designed to be operated with standard keyboard and mouse controls.  
  
  
## Disclaimer  
  
Due to a potential issue with floating point value precision, there has been a smalll inplementation to check for any value less than 1e-10 to be set to 0.  
All code was written by Chris and Ayoub based off our own knowledge from classes with lecturers and self driven research of the C++ coding language.  
This program is complete for submission. All issues have been searched for and fixed. While this program is complete, unknown bugs may still be present.  
.vs/Matrix Calculator/v17/.suo is included for ease of solution loadup purposes since the solution has been manually configured. The solution should start with x64 Release, on main.cpp and Matrix.txt in side by side docks.  
  
  
## Credits  
  
2023  
- Chris  
- Shikomisen (Ayoub)  
  
Media Design School  
GD1M02 - Mathematics for Graphical Games  
Written for Assignment 4  
