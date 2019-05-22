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

	unsigned set_type();
	void get_type(unsigned);
	void get_title();

	virtual void print() = 0;
	virtual void print(std::ofstream&) = 0;
};

#endif 