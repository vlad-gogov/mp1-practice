#ifndef _VECTOR_H_
#define _VECTOR_H_
#include <iostream>

struct Vector
{
    int size;
    double* elements;
    Vector();
    int getsize();
    void PrintVector();
    void Input();
    Vector(const Vector& tmp);
    Vector(int _size);
    Vector(int _size, double* array);
    double Len();
    Vector operator+(const Vector & x);
    const Vector& operator=(const Vector & x);
    Vector operator-(const Vector & x);
    double operator*(const Vector & x);
    Vector operator+(double a);
    Vector operator*(double a);
    Vector operator-(double a);
    Vector operator/(double a);
    Vector operator++();
    Vector operator--();
    Vector operator++(int);
    Vector operator--(int);
    Vector operator+();
    Vector operator-();
    Vector operator+=(const Vector & x);
    Vector operator-=(const Vector & x);
    double operator*=(const Vector & x);
    bool operator==(const Vector & x);
    double Angle(Vector & x);
    friend std::ostream& operator << (std::ostream &s, const Vector & x);
    friend std::istream& operator >> (std::istream &s, Vector & x);
    double& operator[](int index);
    const double& operator[](int index) const;
    ~Vector();
};

class DifferentSizes {};

class Sizes {};

class LensZero {};

class VectorBadIndexException {};

class VectorElemException
{
public:
    int info;
    VectorElemException(int _info)
    {
        info = _info;
    }
};


#endif