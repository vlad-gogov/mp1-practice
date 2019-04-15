#ifndef _TASKDAY_H_
#define _TASKDAY_H_

class taskday : public task
{
public:
	taskday();
	taskday(const taskday&);
	~taskday();

	virtual void print();
	void print(std::ofstream&);
};

#endif 