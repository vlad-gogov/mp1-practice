#ifndef _MATRIX_H_
#define _MATRIX_H_
#include <iostream>
#include <ctime>
#include <cstdlib>

class Matrix
{
    int rows;
    int cols;
    double* arr;
public:
    Matrix();
    Matrix(const Matrix&);
    Matrix(int, int);
    Matrix(double*, int, int);
    ~Matrix();
    Matrix operator+(const Matrix&);
    Matrix operator+(double);
    Matrix operator-(const Matrix&);
    Matrix operator-(double);
    Matrix operator*(const Matrix&);
    Matrix operator*(double);
    const Matrix operator=(const Matrix&);
    const double* operator[](int) const;
    double* operator[](int);
    void Output();
    void Input();
	void GenerationArr();
};

class DifferentSizes {};
class MatrixZero {};
class NoElements {};


#endif
