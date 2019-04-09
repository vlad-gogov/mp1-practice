#include "Matrix.h"

Matrix::Matrix()
{
    rows = 0;
    cols = 0;
    arr = NULL;
	srand((unsigned int)time(0));
}

Matrix::Matrix(const Matrix& x)
{
    rows = x.rows;
    cols = x.cols;
    arr = new double[rows * cols];
    for (int i = 0; i < (x.rows * x.cols); i++)
        arr[i] = x.arr[i];
	srand((unsigned int)time(0));
}

Matrix::Matrix(int _rows, int _cols)
{
    rows = _rows;
    cols = _cols;
    arr = new double[rows * cols];
    for (int i = 0; i < (_rows * _cols); i++)
        arr[i] = 0;
	srand((unsigned int)time(0));
}

Matrix::Matrix(double* _arr, int _rows, int _cols)
{
    rows = _rows;
    cols = _cols;
    arr = new double[rows * cols];
    for (int i = 0; i < (_rows * _cols); i++)
        arr[i] = _arr[i];
	srand((unsigned int)time(0));
}

Matrix::~Matrix()
{
    rows = 0;
    cols = 0;
    delete[] arr;
}

Matrix Matrix::operator+(const Matrix& x)
{
    if ((rows != x.rows) || (cols != x.cols))
        throw DifferentSizes();
    Matrix result(rows, cols);
    for (int i = 0; i < (rows * cols); i++)
        result.arr[i] = arr[i] + x.arr[i];
    return result;
}

Matrix Matrix::operator+(double x)
{
    if ((rows == 0) || (cols == 0))
        throw MatrixZero();
    Matrix result(rows, cols);
    for (int i = 0; i < (rows * cols); i++)
            result.arr[i] = arr[i] + x;
    return result;
}

Matrix Matrix::operator-(const Matrix& x)
{
    if ((rows != x.rows) || (cols != x.cols))
        throw DifferentSizes();
    Matrix result(rows, cols);
    for (int i = 0; i < (rows * cols); i++)
        result.arr[i] = arr[i] - x.arr[i];
    return result;
}

Matrix Matrix::operator-(double x)
{
    if ((rows == 0) || (cols == 0))
        throw MatrixZero();
    Matrix result(rows, cols);
    for (int i = 0; i < (rows * cols); i++)
        result.arr[i] = arr[i] - x;
    return result;
}

Matrix Matrix::operator*(const Matrix& x)
{
    if ((rows != x.cols) || (cols != x.rows))
        throw DifferentSizes();
    Matrix result(rows, x.cols);
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            for (int k = 0; k < result.cols; k++)
                result.arr[i * cols + j] += arr[i * result.cols + k] * x.arr[k * x.cols + j];
    return result;
}

Matrix Matrix::operator*(double x)
{
    if ((rows == 0) || (cols == 0))
        throw MatrixZero();
    Matrix result(rows, cols);
    for (int i = 0; i < (rows * cols); i++)
        result.arr[i] = arr[i] * x;
    return result;
}

const Matrix Matrix::operator=(const Matrix& x)
{
    if ((rows == x.rows) && (cols == x.cols) && (arr == x.arr))
        return *this;
    if ((rows != x.rows) || (cols != x.cols))
        delete[] arr;
    rows = x.rows;
    cols = x.cols;
    arr = new double[x.rows * x.cols];
    for (int i = 0; i < (rows * cols); i++)
        arr[i] = x.arr[i];
    return *this;
}

void Matrix::Output()
{
    std::cout << "\n";
    for (int i = 0; i < rows; i++)
    {
        std::cout << "| ";
        for (int j = 0; j < cols; j++)
            std::cout << arr[i * cols + j] << " ";
        std::cout << "| \n";
    }
    std::cout << "\n";
}

void Matrix::Input()
{
    std::cout << "Введите элементы матрицы (через пробел): ";
    for (int i = 0; i < (rows * cols); i++)
    {
        std::cin >> arr[i];
    }
}

const double* Matrix::operator[](int x) const
{
    if (x >= (rows * cols))
        throw NoElements();
    return arr + x * cols + 1;
}

double* Matrix::operator[](int x)
{
    if (x >= (rows * cols))
        throw NoElements();
    return arr + x * cols + 1;
}

void Matrix::GenerationArr() 
{
	double lb = 1.0, rb = 10.0;
	for (int i = 0; i < (rows * cols); i++)
	{
		arr[i] = lb + ((double)rand() / RAND_MAX) * (rb - lb);
	}
};
