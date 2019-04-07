#include "Matrix.h"
#include <iostream>
#include <clocale>

int main()
{
    setlocale(LC_ALL, "Russian");
    int _rows, _cols;
    double x;
    std::cout << "Введите размерность матрицы A (кол-во строк и столбцов через пробел): ";
    std::cin >> _rows >> _cols;
    Matrix a(_rows, _cols);
    a.Input();
    a.Output();
    std::cout << "Введите размерность матрицы B (кол-во строк и столбцов через пробел): ";
    std::cin >> _rows >> _cols;
    Matrix b(_rows, _cols);
    b.Input();
    b.Output();
    Matrix c;
    std::cout << "Введите число: ";
    std::cin >> x;


    std::cout << "Сложение матриц (A + B): ";
    try
    {
        c = a + b;
        c.Output();
    }
    catch (DifferentSizes)
    {
        std::cout << "Неверная размерность.";
    }

    std::cout << "Сложение матрицы с числом (A + " << x <<"): ";
    try
    {
        c = a + x;
        c.Output();
    }
    catch (MatrixZero)
    {
        std::cout << "Матрица имеет размеры 0x0.";
    }

    std::cout << "Умножение матриц (A * B): ";
    try
    {
        c = a * b;
        c.Output();
    }
    catch (DifferentSizes)
    {
        std::cout << "Неверная размерность.";
    }

    std::cout << "Умножение матрицы на число (A * " << x << "): ";
    try
    {
        c = a * x;
        c.Output();
    }
    catch (MatrixZero)
    {
        std::cout << "Матрица имеет размеры 0x0.";
    }

    std::cout << "Разность матриц (A - B): ";
    try
    {
        c = a - b;
        c.Output();
    }
    catch (DifferentSizes)
    {
        std::cout << "Неверная размерность.";
    }

    std::cout << "Разность матрицы и числа (A - " << x << "): ";
    try
    {
        c = a - x;
        c.Output();
    }
    catch (MatrixZero)
    {
        std::cout << "Матрица имеет размеры 0x0.";
    }

}
