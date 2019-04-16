#ifndef _TASK_H_
#define _TASK_H_
#include <iostream>
#include <fstream>
#include <string>
#include "Date.h"
#include "Time.h"

class task	
{
	char type;
public:
	std::string description;
	date start_day;
	task();
	task(task&);
	virtual ~task();

	virtual time get_start() = 0;
	virtual time get_end() = 0;

	virtual time set_start(time);
	virtual time set_end(time);

	unsigned set_type();
	void get_type(unsigned);
	void get_title();

	virtual void print() = 0;
	virtual void print(std::ofstream&) = 0;
};

#endif 