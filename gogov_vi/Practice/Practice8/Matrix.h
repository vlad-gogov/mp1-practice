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
    const Matrix& operator=(const Matrix&);
    const double* operator[](int) const;
	friend std::ostream& operator << (std::ostream& s, const Matrix& x);
    void GenerationArr() const;
};

class DifferentSizes : std::exception
{
    const std::string what_str = "Неверная размерность.\n";
public:
    const char* what() const;
};

class MatrixZero : std::exception
{
    const std::string what_str = "Матрица имеет размеры 0x0.\n";
public:
    const char* what() const;
};

class NoElements : std::exception
{
    const std::string what_str = "Элемент не найден.\n";
public:
    const char* what() const;
};


#endif
