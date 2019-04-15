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

	date set_day(unsigned);
	date set_month(unsigned);
	date set_year(unsigned);

	unsigned get_days();
	unsigned get_month();
	unsigned get_year();

	const date operator=(const date&);
	/*
	bool operator==(const date&) const;
	bool operator!=(const date&) const;
	bool operator>(const date&) const;
	bool operator>=(const date&) const;
	bool operator<(const date&) const;
	bool operator<=(const date&) const;
	*/
	friend std::ostream& operator<<(std::ostream&, const date&);
	friend std::ofstream& operator<<(std::ofstream&, const date&);
};


#endif 