#include "Matrix.h"
#include <iostream>
#include <clocale>

int main()
{
    setlocale(LC_ALL, "Russian");
	Matrix a(3, 3), b(3, 3), c(2, 2), d(0, 0), f(0, 0);
	int x = 5;
	a.GenerationArr();
	b.GenerationArr();
	c.GenerationArr();
	std::cout << "Матрица A: ";
    a.Output();
	std::cout << "Матрица B: ";
    b.Output();
	std::cout << "Матрица C: ";
	c.Output();

	std::cout << "\nЭлемент матрица B[2][2]: ";
	try
	{
		std::cout << b[2][2] << "\n";
	}
	catch (NoElements)
	{
		std::cout << "Нет элемента.\n";
	}

	std::cout << "\nЭлемент матрица A[4][4]: ";
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
        d.Output();
    }
    catch (DifferentSizes)
    {
        std::cout << "Неверная размерность.\n";
    }

	std::cout << "Сложение матриц (A + C): ";
	try
	{
		d = a + c;
		d.Output();
	}
	catch (DifferentSizes)
	{
		std::cout << "Неверная размерность.\n";
	}

    std::cout << "Сложение матрицы с числом (A + " << x <<"): ";
    try
    {
        d = a + x;
        d.Output();
    }
    catch (MatrixZero)
    {
        std::cout << "Матрица имеет размеры 0x0.\n";
    }

	std::cout << "Сложение матрицы с числом (F + " << x << "): ";
	try
	{
		d = f + x;
		d.Output();
	}
	catch (MatrixZero)
	{
		std::cout << "Матрица имеет размеры 0x0.\n";
	}

    std::cout << "Умножение матриц (A * B): ";
    try
    {
        d = a * b;
        d.Output();
    }
    catch (DifferentSizes)
    {
        std::cout << "Неверная размерность.\n";
    }

	std::cout << "Умножение матриц (A * C): ";
	try
	{
		d = a * c;
		d.Output();
	}
	catch (DifferentSizes)
	{
		std::cout << "Неверная размерность.\n";
	}

    std::cout << "Умножение матрицы на число (A * " << x << "): ";
    try
    {
        d = a * x;
        d.Output();
    }
    catch (MatrixZero)
    {
        std::cout << "Матрица имеет размеры 0x0.\n";
    }

	std::cout << "Умножение матрицы на число (f * " << x << "): ";
	try
	{
		d = f * x;
		d.Output();
	}
	catch (MatrixZero)
	{
		std::cout << "Матрица имеет размеры 0x0.\n";
	}

    std::cout << "Разность матриц (A - B): ";
    try
    {
        d = a - b;
        d.Output();
    }
    catch (DifferentSizes)
    {
        std::cout << "Неверная размерность.\n";
    }

	std::cout << "Разность матриц (A - C): ";
	try
	{
		d = a - c;
		d.Output();
	}
	catch (DifferentSizes)
	{
		std::cout << "Неверная размерность.\n";
	}

    std::cout << "Разность матрицы и числа (A - " << x << "): ";
    try
    {
        c = a - x;
        c.Output();
    }
    catch (MatrixZero)
    {
        std::cout << "Матрица имеет размеры 0x0.\n";
    }

	std::cout << "Разность матрицы и числа (f - " << x << "): ";
	try
	{
		c = f - x;
		c.Output();
	}
	catch (MatrixZero)
	{
		std::cout << "Матрица имеет размеры 0x0.\n";
	}
}
