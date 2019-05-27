#ifndef _TASK_H_
#define _TASK_H_
#include <iostream>
#include <fstream>
#include <string>
#include "Date.h"
#include "Time.h"

class task    
{
public:
    std::string description;
    date start_day;
    task();
    task(task&);
    virtual ~task();

    void get_title() const;

    virtual void print() = 0;
    virtual void print(std::ofstream&) = 0;
};

#endif 