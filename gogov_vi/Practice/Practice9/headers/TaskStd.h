#ifndef _TASKSTD_H_
#define _TASKSTD_H_
#include "Task.h"

class taskstd : public task
{
public:
    time start;
    time end;
    taskstd();
    taskstd(const date,const time, const time);
    taskstd(taskstd&);
    ~taskstd();

    time set_start(time);
    time set_end(time);

    virtual void print(); 
    void print(std::ofstream&);
};

#endif 