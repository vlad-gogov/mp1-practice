#include "../headers/Date.h"

date::date()
{
	d = 1U;
	m = 1U;
	y = 1970U;
}

date::date(const date& x)
{
	d = x.d;
	m = x.m;
	y = x.y;
}

date::date(unsigned _d, unsigned _m, unsigned _y)
{
	if ((_d < 0) || (_d > 31))
	{
		throw bad_date_day();
	}
	if ((_m < 0) || (_m > 12))
	{
		throw bad_date_month();
	}
	if (_y < 0)
	{
		throw bad_date_year();
	}
	if (((_y % 400) == 0) || ((_y % 100 != 0) && (_y % 4 == 0)))
	{
		if ((_m == 2) && (_d >= 29))
			throw bad_date_day();
	}
	if ((_m == 4) || (_m == 6) || (_m == 8) || (_m == 10))
	{
		if (_d > 30)
			throw bad_date_day();
	}
	d = _d;
	m = _m;
	y = _y;
}

date::~date()
{
	d = m = y = 0U;
}

unsigned date::get_days()
{
	return d;
}

unsigned date::get_month()
{
	return m;
}

unsigned date::get_year()
{
	return y;
}

const date date::operator=(const date& x)
{
	d = x.d;
	m = x.m;
	y = x.y;
	return *this;
}

std::ostream& operator<<(std::ostream& s , const date& x)
{
	if (x.d < 10)
		s << "0" << x.d << ".";
	else
		s << x.d << ".";
	if (x.m < 10)
		s << "0" << x.m << ".";
	else
		s << x.m << ".";
	s << x.y;
	return s;
}


bool date::operator==(const date& x) const
{
	if ((d == x.d) && (m == x.m) && (y == x.y))
		return true;
	return false;
}

bool date::operator!=(const date& x) const
{
	if ((d != x.d) || (m != x.m) || (y != x.y))
		return true;
	return false;
}

bool date::operator>(const date& x) const
{
	if (*this == x)
		return false;
	if (y != x.y)
		return y > x.y;
	if (m != x.m)
		return m > x.m;
	if (d != x.d)
		return d > x.d;
	return false;
}

bool date::operator>=(const date& x) const
{
	return (*this == x) || (*this < x);
}

bool date::operator<(const date& x) const
{
	if (*this == x)
		return false;
	if (y != x.y)
		return y < x.y;
	if (m != x.m)
		return m < x.m;
	if (d != x.d)
		return d < x.d;
	return false;
}

bool date::operator<=(const date& x) const
{
	return (*this == x) || (*this > x);
}

// 0 - Неверная дата при вводе
// 1 - Неверная дата при считывании из файла


const char* bad_date_day::what() const
{
	return what_str.c_str();
}

const char* bad_date_month::what() const
{
	return what_str.c_str();
}

const char* bad_date_year::what() const
{
	return what_str.c_str();
}

const char* bad_date_input::what() const
{
	return what_str.c_str();
}
