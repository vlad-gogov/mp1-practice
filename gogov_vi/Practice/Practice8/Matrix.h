#ifndef _MATRIX_H_
#define _MATRIX_H_
#include <iostream>

class Matrix
{
    int rows;
    int cols;
    double* arr;
public:
    Matrix();
    Matrix(const Matrix&);
    Matrix(int, int); // Уточнить
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
    const double* operator[](double) const;
    void Output();
    void Input();
};

class DifferentSizes {};
class MatrixZero {};

#endif
