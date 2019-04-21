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

class bad_date : std::exception 
{
	const std::string what_str = "";
public:
	const char* what(char) const;
};

#endif 