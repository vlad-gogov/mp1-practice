#include "Matrix.h"
#include <iostream>
#include <clocale>

int main()
{
    setlocale(LC_ALL, "Russian");
    Matrix a(5, 4), b(4, 5), c(2, 2), d(0, 0), f(0, 0), k(5, 4);
    int x = 5;
    a.GenerationArr();
    b.GenerationArr();
    c.GenerationArr();
    std::cout << "Матрица A: ";
    std::cout << a;
    std::cout << "Матрица B: ";
    std::cout << b;
    std::cout << "Матрица C: ";
    std::cout << c;
    std::cout << "Матрица K: ";
    std::cout << c;

    std::cout << "\nЭлемент матрицы B[2][2]: ";
    try
    {
        std::cout << b[2][2] << "\n";
    }
    catch (NoElements)
    {
        std::cout << "Нет элемента.\n";
    }

    std::cout << "\nЭлемент матрицы A[4][4]: ";
    try 
    {
        std::cout << a[3][3] << "\n";
    }
    catch (NoElements)
    {
        std::cout << "Нет элемента.\n\n";
    }

    std::cout << "Сложение матриц (A + B): ";
    try
    {
        d = a + b;
        std::cout << d;
    }
    catch (DifferentSizes& e)
    {
        std::cout << e.what();
    }

    std::cout << "Сложение матриц (A + K): ";
    try
    {
        d = a + k;
        std::cout << d;
    }
    catch (DifferentSizes& e)
    {
        std::cout << e.what();
    }

    std::cout << "Сложение матрицы с числом (A + " << x <<"): ";
    try
    {
        d = a + x;
        std::cout << d;
    }
    catch (MatrixZero& e)
    {
        std::cout << e.what();
    }

    std::cout << "Сложение матрицы с числом (F + " << x << "): ";
    try
    {
        d = f + x;
        std::cout << d;
    }
    catch (MatrixZero& e)
    {
        std::cout << e.what();
    }

    std::cout << "Умножение матриц (A * B): ";
    try
    {
        d = a * b;
        std::cout << d;
    }
    catch (DifferentSizes& e)
    {
        std::cout << e.what();
    }

    std::cout << "Умножение матриц (A * C): ";
    try
    {
        d = a * c;
        std::cout << d;
    }
    catch (DifferentSizes& e)
    {
        std::cout << e.what();
    }

    std::cout << "Умножение матрицы на число (A * " << x << "): ";
    try
    {
        d = a * x;
        std::cout << d;
    }
    catch (MatrixZero& e)
    {
        std::cout << e.what();
    }

    std::cout << "Умножение матрицы на число (f * " << x << "): ";
    try
    {
        d = f * x;
        std::cout << d;
    }
    catch (MatrixZero& e)
    {
        std::cout << e.what();
    }

    std::cout << "Разность матриц (A - B): ";
    try
    {
        d = a - b;
        std::cout << d;
    }
    catch (DifferentSizes& e)
    {
        std::cout << e.what();
    }

    std::cout << "Разность матриц (A - C): ";
    try
    {
        d = a - c;
        std::cout << d;
    }
    catch (DifferentSizes& e)
    {
        std::cout << e.what();
    }

    std::cout << "Разность матрицы и числа (A - " << x << "): ";
    try
    {
        c = a - x;
        std::cout << c;
    }
    catch (MatrixZero& e)
    {
        std::cout << e.what();
    }

    std::cout << "Разность матрицы и числа (f - " << x << "): ";
    try
    {
        c = f - x;
        std::cout << c;
    }
    catch (MatrixZero& e)
    {
        std::cout << e.what();
    }
}
