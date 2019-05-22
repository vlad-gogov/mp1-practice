#ifndef _TASKDAY_H_
#define _TASKDAY_H_
#include "Task.h"

class taskday : public task
{
public:
	taskday();
	taskday(taskday&);
	~taskday();

	virtual void print();
	void print(std::ofstream&);
};

#endif 