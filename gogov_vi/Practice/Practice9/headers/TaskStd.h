#ifndef _TASKSTD_H_
#define _TASKSTD_H_

class taskstd : public task
{
public:
	time start;
	time end;
	taskstd();
	taskstd(const taskstd&);
	~taskstd();

	virtual void print();
	void print(std::ofstream&);
};

#endif 