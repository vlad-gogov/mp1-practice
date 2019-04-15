#ifndef _TASK_H_
#define _TASK_H_
#include <iostream>
#include <fstream>
#include <string>
#include "Date.h"
#include "Time.h"

class task	
{
	unsigned id; 
	char type;
public:
	std::string title;
	date Date;
	task();
	task(const task&);
	virtual ~task();

	void set_title(std::string);
	char get_type();
	unsigned get_id();
	void get_title();

	virtual unsigned get_duration() = 0;
	virtual void print() = 0;
	virtual void print(std::ofstream&) = 0;
};

#endif 