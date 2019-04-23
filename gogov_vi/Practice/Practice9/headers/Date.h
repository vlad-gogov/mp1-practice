#ifndef _DATE_H_
#define _DATE_H_
#include <iostream>
#include <fstream>

class date
{
	unsigned d, m, y;
public:
	date();
	date(const date&);
	date(unsigned, unsigned, unsigned);
	~date();

	unsigned get_days();
	unsigned get_month();
	unsigned get_year();

	const date operator=(const date&);

	bool operator==(const date&) const;
	bool operator!=(const date&) const;
	bool operator>(const date&) const;
	bool operator>=(const date&) const;
	bool operator<(const date&) const;
	bool operator<=(const date&) const;

	friend std::ostream& operator<<(std::ostream&, const date&);
};

class bad_date_day : std::exception
{
	const std::string what_str = "Некорректное число.";
public:
	const char* what() const;
};

class bad_date_month : std::exception
{
	const std::string what_str = "Некорректный месяц.";
public:
	const char* what() const;
};

class bad_date_year : std::exception
{
	const std::string what_str = "Некорректный год.";
public:
	const char* what() const;
};

class bad_date_input : std::exception 
{
	const std::string what_str = "Некорректная дата при вводе.";
public:
	const char* what() const;
};

#endif 