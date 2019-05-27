#ifndef _VECTOR_H_
#define _VECTOR_H_
#include <iostream>

struct Vector
{
    int size;
    double* elements;
    Vector();
    int getsize() const;
    void PrintVector() const;
    void Input() const;
    Vector(const Vector& tmp);
    Vector(int _size);
    Vector(int _size, double* array);
    double Len() const;
    Vector operator+(const Vector & x);
    const Vector& operator=(const Vector & x);
    Vector operator-(const Vector & x);
    double operator*(const Vector & x) const;
    Vector operator+(double a);
    Vector operator*(double a);
    Vector operator-(double a);
    Vector operator/(double a);
    Vector& operator++();
    Vector& operator--();
    Vector operator++(int);
    Vector operator--(int);
    Vector operator+();
    Vector operator-();
    Vector operator+=(const Vector & x);
    Vector operator-=(const Vector & x);
    Vector operator*=(double a);
    bool operator==(const Vector & x) const;
    double Angle(const Vector & x) const;
    friend std::ostream& operator << (std::ostream &s, const Vector & x);
    friend std::istream& operator >> (std::istream &s, Vector & x);
    double& operator[](int index);
    const double& operator[](int index) const;
    ~Vector();
};

class DifferentSizes : std::exception
{
    const std::string what_str = "Ошибка размерности.\n";
public:
    const char* what() const;
};

class LensZero : std::exception 
{
    const std::string what_str = "Деление на ноль невозможно.\n";
public:
    const char* what() const;
};

class VectorBadIndexException : std::exception
{
    const std::string what_str = "Неверный индекс.\n";
public:
    const char* what() const;
};


#endif