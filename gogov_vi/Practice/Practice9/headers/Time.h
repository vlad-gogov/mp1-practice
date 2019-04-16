#ifndef _TIME_H_
#define _TIME_H_
#include <iostream>
#include <fstream>

class time
{
	unsigned hour, min;
public:
	time();
	time(const time&);
	time(unsigned, unsigned);
	~time();

	time set_hour(unsigned);
	time set_min(unsigned);

	unsigned get_hour();
	unsigned get_min();

	bool operator==(const time&) const;
	bool operator!=(const time&) const;
	bool operator>(const time&) const;
	bool operator>=(const time&) const;
	bool operator<(const time&) const;
	bool operator<=(const time&) const;

	time operator+(const time&);
	time operator-(const time&);
	const time operator=(const time&);

	friend std::ostream& operator<<(std::ostream&, const time&);
	friend std::ofstream& operator<<(std::ofstream&, const time&);
};

class bad_time : std::exception
{
	const std::string what_str = "Некоректное время.";
public:
	const char* what() const;
};

#endif 