#ifndef _TASKSTD_H_
#define _TASKSTD_H_
#include "Task.h"

class taskstd : public task
{
public:
	time start;
	time end;
	taskstd();
	taskstd(taskstd&);
	~taskstd();

	time get_start();
	time get_end();
	time set_start(time);
	time set_end(time);

	virtual void print();
	void print(std::ofstream&);
};

#endif 