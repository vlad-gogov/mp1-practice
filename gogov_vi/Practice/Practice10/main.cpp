#include <iostream>
#include "Container.h"
#include <clocale>

int main()
{
    setlocale(LC_ALL, "Russian");
    Container<double> a;
    double* tmp = new double[10];
    std::cout << "Добавление 10 элементов: ";
    for (int i = 0; i < 10; i++)
    {
        tmp[i] = i;
        a.add_elem(i);
    }
    std::cout << a;
    std::cout << "Копирование из a в b: ";
    Container<double> b(a);
    std::cout << b;
    std::cout << "Добавление 11 элемента: ";
    a.add_elem(1);
    std::cout << a;

    std::cout << "a[5] = ";
    try
    {
        std::cout << a[5] << "\n";
    }
    catch (std::out_of_range e)
    {
        std::cout << e.what();
    }

    std::cout << "a[10] = ";
    try
    {
        std::cout << a[10] << "\n";
    }
    catch (std::out_of_range e)
    {
        std::cout << e.what();
    }

    std::cout << "Изменение a[7] = ";
    try
    {
        a[7] = 5;
        std::cout << a[7] << "\n";
    }
    catch (std::out_of_range e)
    {
        std::cout << e.what();
    }

    std::cout << "Индекс элемента равный 5: ";
    int idx = a.find_elem(5);
    if (idx == -1)
        std::cout << "Элемент не найден." << "\n";
    std::cout << idx << "\n";
    std::cout << "Индекс элемента равный 6: ";
    idx = a.find_elem(6);
    if (idx == -1)
        std::cout << "Элемент не найден." << "\n";
    std::cout << a;
    std::cout << "Удаление элемента равный 5: ";
    try 
    {
        a.delete_elem(5);
    }
    catch (const char* k)
    {
        std::cout << k;
    }
    std::cout << a;
    std::cout << "Удаление элемента равный 7: ";
    try
    {
        a.delete_elem(7);
    }
    catch (const char* k)
    {
        std::cout << k;
    }
    std::cout << a;

    std::cout << "\nМассив указателей. \n";

    Container<double*> c;
    for (int i = 0; i < 10; i++)
        c.add_elem(tmp + i);
    std::cout << c;
    std::cout << "Копирование из c в d: ";
    Container<double*> d(c);
    std::cout << d;
    std::cout << "Добавление 11 элемента: ";
    c.add_elem(tmp + 1);
    std::cout << c;


    std::cout << "a[5] = ";
    try
    {
        std::cout << *(c[5]) << "\n";
    }
    catch (std::out_of_range e)
    {
        std::cout << e.what();
    }

    std::cout << "a[10] = ";
    try
    {
        std::cout << *(c[10]) << "\n";
    }
    catch (std::out_of_range e)
    {
        std::cout << e.what();
    }

    std::cout << "Изменение a[7] = ";
    try
    {
        c[7] = new double(5);
        std::cout << *(c[7]) << "\n";
    }
    catch (std::out_of_range e)
    {
        std::cout << e.what();
    }
    std::cout << "Индекс элемента равный 5: ";
    idx = c.find_elem(tmp + 5);
    if (idx == -1)
        std::cout << "Элемент не найден." << "\n";
    std::cout << idx << "\n";
    std::cout << "Индекс элемента равный 6: ";
    idx = c.find_elem(tmp + 6);
    std::cout << idx << "\n";
    if (idx == -1)
        std::cout << "Элемент не найден." << "\n";
    std::cout << "Удаление элемента равный 5: ";
    try
    {
        c.delete_elem(tmp + 5);
    }
    catch (const char* k)
    {
        std::cout << k;
    }
    std::cout << c;
    std::cout << "Удаление элемента равный 7: ";
    try
    {
        a.delete_elem(7);
    }
    catch (const char* k)
    {
        std::cout << k;
    }
    std::cout << c;
    return 0;
}