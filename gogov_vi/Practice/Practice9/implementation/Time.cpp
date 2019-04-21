﻿#include "../headers/Time.h"

time::time()
{
	hour = min = 0U;
}

time::~time()
{
	hour = min = 0U;
}

time::time(const time& x)
{
	hour = x.hour;
	min = x.min;
}

time::time(unsigned _hour, unsigned _min)
{
	if ((_hour < 0) || (_hour > 24))
		throw bad_time();
	if ((_min < 0) || (_min > 60))
		throw bad_time();
	hour = _hour;
	min = _min;
}

time time::operator+(const time& x)
{
	unsigned _hour_to_min1 = 0, _hour_to_min2 = 0;
	time rez;
	_hour_to_min1 = hour * 60 + min;
	_hour_to_min2 = x.hour * 60 + x.min;
	rez.hour = (_hour_to_min1 + _hour_to_min2) / 60;
	rez.min = _hour_to_min1 + _hour_to_min2 - rez.hour * 60;
	if (rez.hour > 24)
	{
		rez.hour -= 24;
		//Date ++
	}
	return rez;
}

time time::operator-(const time& x)
{
	unsigned _hour_to_min1 = 0, _hour_to_min2 = 0;
	time rez;
	_hour_to_min1 = hour * 60 + min;
	_hour_to_min2 = x.hour * 60 + x.min;
	if (_hour_to_min1 < _hour_to_min2)
		throw "Не могу из меньшего вычесть большее";
	rez.hour = (_hour_to_min1 - _hour_to_min2) / 60;
	rez.min = _hour_to_min1 - _hour_to_min2 - rez.hour * 60;
	return rez;
}

const time time::operator=(const time& x)
{
	hour = x.hour;
	min = x.min;
	return *this;
}

std::ostream& operator << (std::ostream& s, const time& x)
{
	if (x.hour < 10)
		s << "0" << x.hour << ":";
	else
		s << x.hour << ":";
	if (x.min < 10)
		s << "0" << x.min;
	else
		s << x.min;
	return s;
}

time time::set_hour(unsigned _hour)
{
	if ((_hour < 0) || (_hour > 12))
		throw bad_time();
	hour = _hour;
	return *this;
}

time time::set_min(unsigned _min)
{
	if ((_min < 0) || (_min > 60))
		throw bad_time();
	min = _min;
	return *this;
}

unsigned time::get_hour()
{
	return hour;
}

unsigned time::get_min()
{
	return min;
}

bool time::operator==(const time& x) const
{
	if ((hour == x.hour) && (min == x.min))
		return true;
	return false;
}

bool time::operator!=(const time& x) const
{
	if ((hour != x.hour) || (min != x.min))
		return true;
	return false;
}

bool time::operator>(const time& x) const
{
	if ((hour * 60 + min) > (x.hour * 60 + x.min))
		return true;
	return false;
}

bool time::operator>=(const time& x) const
{
	if ((hour * 60 + min) >= (x.hour * 60 + x.min))
		return true;
	return false;
}

bool time::operator<(const time& x) const
{
	if ((hour * 60 + min) < (x.hour * 60 + x.min))
		return true;
	return false;
}

bool time::operator<=(const time& x) const
{
	if ((hour * 60 + min) <= (x.hour * 60 + x.min))
		return true;
	return false;
}

const char* bad_time::what(char message) const
{
	if(message == 0)
		return "Неккоректное время.";
}