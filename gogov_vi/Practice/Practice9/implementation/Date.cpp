#include "../headers/Date.h"

date::date()
{
	d = m = y = 0U;
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
		throw "Invalid date - day";
	}
	if ((_m < 0) || (_m > 12))
	{
		throw "Invalid date - month";
	}
	if (_y < 0)
	{
		throw "Invalid date - year";
	}
	if (((_y % 400) == 0) || ((_y % 100 != 0) && (_y % 4 == 0)))
	{
		if ((_m == 2) && (_d >= 29))
			throw "Invalid date - month #2";
	}
	if ((_m == 4) || (_m == 6) || (_m == 8) || (_m == 10))
	{
		if (_d > 30)
			throw "Invalid date - month";
	}
	d = _d;
	m = _m;
	y = _y;
}

date::~date()
{
	d = m = y = 0U;
}

date date::set_day(unsigned _d)
{
	if ((d < 0) || (d > 32))
	{
		throw "Неверные данные";
	}
	d = _d;
	return *this;
}

date date::set_month(unsigned _m)
{
	if ((m < 0) || (m > 13))
	{
		throw "Неверные данные";
	}
	m = _m;
	return *this;
}

date date::set_year(unsigned _y)
{
	if (_y < 0)
		throw "Неверные данные";
	y = _y;
	return *this;
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
	s << "Дата (ДД.ММ.ГГГГ): " << x.d << x.m << x.y;
	return s;
}

std::ofstream& operator<<(std::ofstream& s, const date& x)
{

}
/*
bool date::operator==(const date& x) const
{
	if ((d == x.d) && (m == x.m) && (y == x.y))
		return 1;
	return 0;
}

bool date::operator!=(const date& x) const
{
	if ((d != x.d) || (m != x.m) || (y != x.y))
		return 1;
	return 0;
}

bool date::operator>(const date& x) const
{
	if (y > x.y)
		return 1;
	if (y < x.y)
		return 0;
	if (m > x.m)
		return 1;
	if (m < x.m)
		return 0;
	if (d > x.d)
		return 1;
	if (d < x.d)
		return 0;
}

bool date::operator>=(const date& x) const
{

}

bool date::operator<(const date& x) const
{

}

bool date::operator<=(const date& x) const
{

}
*/