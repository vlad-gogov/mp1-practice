#include "Vector.h"
#include <iostream>
#define M_PI 3.14159265358979323846

Vector::Vector()
{
    size = 0;
    elements = nullptr;
}

Vector::Vector(const Vector& tmp)
{
    size = tmp.size;
    elements = new double[tmp.size];
    for (int i = 0; i < tmp.size; i++)
        elements[i] = tmp.elements[i];
}

Vector::Vector(int _size)
{
    size = _size;
    elements = new double[size];
    for (int i = 0; i < size; i++)
        elements[i] = 0;
}

Vector::Vector(int _size, double* array)
{
    size = _size;
    elements = new double[size];
    for (int i = 0; i < size; i++)
        elements[i] = array[i];
}

int Vector::getsize()
{
    return size;
}

void Vector::PrintVector()
{
    for (int i = 0; i < size; i++)
        std::cout << elements[i] << " ";
}

Vector::~Vector()
{
    delete[] elements;
    size = 0;
}

void Vector::Input()
{
    if (size)
    {
        for (int i = 0; i < size; i++)
        {
            std::cout << "Введите " << i + 1 << " элемент: ";
            std::cin >> elements[i];
        }
    }
}

Vector& Vector::operator+(const Vector & x)
{
    if ((x.size != size) || (size <= 0) || (x.size <= 0))
    {
        throw DifferentSizes();
    }
    Vector* result = new Vector(size);
    for (int i = 0; i < size; i++)
        result->elements[i] = x.elements[i] + elements[i];
    return *result;
}

Vector& Vector::operator-(const Vector & x)
{
    if ((x.size != size) || (size <= 0) || (x.size <= 0))
    {
        throw DifferentSizes();
    }
    Vector* result = new Vector(x.size);
    for (int i = 0; i < x.size; i++)
        result->elements[i] = elements[i] - x.elements[i];
    return *result;
}

Vector& Vector::operator++()
{
    Vector* result = new Vector(*this);
    for (int i = 0; i < size; i++)
        result->elements[i]++;
    return *result;
}

Vector& Vector::operator--()
{
	if (size <= 0)
	{
		throw DifferentSizes();
	}
    Vector* result = new Vector(*this);
    for (int i = 0; i < size; i++)
        result->elements[i]--;
    return *result;
}

Vector& Vector::operator--(int)
{
	if (size <= 0)
	{
		throw DifferentSizes();
	}
    Vector* result = new Vector(*this);
    for (int i = 0; i < size; i++)
        result->elements[i]--;
    return *result;
}

Vector& Vector::operator++(int)
{
	if (size <= 0)
	{
		throw DifferentSizes();
	}
    Vector* result = new Vector(*this);
    for (int i = 0; i < size; i++)
        result->elements[i]++;
    return *result;
}

Vector& Vector::operator+()
{
	if (size <= 0)
	{
		throw DifferentSizes();
	}
    Vector* result = new Vector(*this);
    return *result;
}

Vector& Vector::operator-()
{
	if (size <= 0)
	{
		throw DifferentSizes();
	}
    Vector* result = new Vector(*this);
    for (int i = 0; i < size; i++)
        result->elements[i] *= -1;
    return *result;
}

double Vector::operator*(const Vector & x)
{
    if ((x.size != size) || (size <= 0) || (x.size <= 0))
    {
        throw DifferentSizes();
    }
    double result = 0;
    for (int i = 0; i < x.size; i++)
        result += x.elements[i] * elements[i];
    return result;
}

Vector& Vector::operator+(double a)
{
	if (size <= 0)
	{
		throw DifferentSizes();
	}
    Vector* result = new Vector(*this);
    for (int i = 0; i < size; i++)
        result->elements[i] += a;
    return *result;
}


Vector& Vector::operator*(double a)
{
	if (size <= 0)
	{
		throw DifferentSizes();
	}
    Vector* result = new Vector(*this);
    for (int i = 0; i < size; i++)
        result->elements[i] *= a;
    return *result;
}

Vector& Vector::operator-(double a)
{
	if (size <= 0)
	{
		throw DifferentSizes();
	}
    Vector* result = new Vector(*this);
    for (int i = 0; i < size; i++)
        result->elements[i] -= a;
    return *result;
}

Vector& Vector::operator/(double a)
{
	if (size <= 0)
	{
		throw DifferentSizes();
	}
    Vector* res = new Vector(*this);
    for (int i = 0; i < size; i++)
        res->elements[i] = res->elements[i] / a;
    return *res;
}

Vector& Vector::operator+=(const Vector & x)
{
	if (size <= 0)
	{
		throw DifferentSizes();
	}
    Vector* res = new Vector(*this);
    for (int i = 0; i < size; i++)
        res->elements[i] = res->elements[i] + x.elements[i];
    return *res;
}

Vector& Vector::operator-=(const Vector & x)
{
	if (size <= 0)
	{
		throw DifferentSizes();
	}
    Vector* res = new Vector(*this);
    for (int i = 0; i < size; i++)
        res->elements[i] = res->elements[i] - x.elements[i];
    return *res;
}

double Vector::operator*=(const Vector & x)
{
    double result = 0;
    result = (*this) * x;
    return result;
}

const Vector& Vector::operator=(const Vector & x)
{
    if ((size == x.size) && (elements == x.elements))
        return *this;
    if (size && elements)
        delete[] elements;
    size = x.size;
    elements = new double[size];
    for (int i = 0; i < size; i++)
        elements[i] = x.elements[i];
    return *this;
}

bool Vector::operator==(const Vector & x)
{
    if (size != x.size)
        return false;
    for (int i = 0; i < size; i++)
        if (elements[i] != elements[i])
            return false;
    return true;
}

std::ostream& operator << (std::ostream & s, const Vector & x)
{
    for (int i = 0; i < x.size; i++)
        s << x.elements[i] << " ";
    s << "\n";
    return s;
}

std::istream& operator >> (std::istream & s, Vector & x)
{
    for (int i = 0; i < x.size; i++)
    {
        std::cout << "Введите " << i + 1 << " элемент: ";
        s >> x.elements[i];
    }
    return s;
}

double Vector::Len()
{
    if (size < 0)
        throw Sizes();
    double result = 0;
    for (int i = 0; i < size; i++)
        result += elements[i] * elements[i];
    return sqrt(result);
}

double Vector::Angle(Vector & x)
{
    double lens = x.Len() * Len();
    double scal = (*this) * x;
    if (!lens)
        throw LensZero();
    double result = (acos(scal / lens)) * 180 / M_PI;
    return result;
}

double& Vector::operator[](int index)
{
    if ((index < size) && (index >= 0))
        return elements[index];
    throw VectorBadIndexException();
}

const double& Vector::operator[](int index) const
{
    if ((index < size) && (index >= 0))
        return elements[index];
    throw VectorBadIndexException();
}