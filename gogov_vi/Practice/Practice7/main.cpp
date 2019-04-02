#include "Vector.h"
#include <iostream>
#include <clocale>

int main()
{
    int size;
	setlocale(LC_ALL, "Russian");
    std::cout << "Введите размерность первого вектора: ";
    std::cin >> size;
    Vector c;
    Vector a(size);
    std::cin >> a;
    std::cout << "Введите размерность второго вектора: ";
    std::cin >> size;
    Vector b(size);
    std::cin >> b;
    std::cout << "Вектор a: " << a;
    std::cout << "Вектор b: " << b << "\n";
    std::cout << "Длина 1 вектора: " << a.Len() << "\n";
    std::cout << "Длина 2 вектора: " << b.Len() << "\n";

    std::cout << "Умнож на -1 (a * (-1)) : ";
    try
    {
        c = a * (-1);
        std::cout << c;
    }
    catch (DifferentSizes)
    {
        std::cout << "Ошибка размерности.\n";
    }

    std::cout << "Сумма с 1 (a + 1) : ";
    try
    {
        c = a + 1;
        std::cout << c;
    }
    catch (DifferentSizes)
    {
        std::cout << "Ошибка размерности.\n";
    }

    std::cout << "Разность с 1 (a - 1) : ";
    try
    {
        c = a - 1;
        std::cout << c;
    }
    catch (DifferentSizes)
    {
        std::cout << "Ошибка размерности.\n";
    }

    std::cout << "Сумма (a + b) : ";
    try
    {
        c = a + b;
        std::cout << c;
    }
    catch (DifferentSizes)
    {
        std::cout << "Ошибка размерности.\n";
    }

    std::cout << "Разность (a - b) : ";
    try
    {
        c = a - b;
        std::cout << c;
    }
    catch (DifferentSizes)
    {
        std::cout << "Ошибка размерности.\n";
    }

    std::cout << "Скалярное произведение (a * b) : ";
    try
    {
        double scal = 0.F;
        scal = a * b;
        std::cout << scal << "\n";
    }
    catch (DifferentSizes)
    {
        std::cout << "Ошибка размерности.\n";
    }

    std::cout << "Угол в радианах (a ^ b) : ";
    try
    {
        double ang = 0.F;
        ang = a.Angle(b);
        std::cout << ang << " градусов\n";
    }
    catch (DifferentSizes)
    {
        std::cout << "Ошибка размерности.\n";
    }
    catch (LensZero)
    {
        std::cout << "Деление на ноль невозможно.\n";
    }
}
