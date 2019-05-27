#include "../headers/TaskStd.h"

taskstd::taskstd() : task()
{
    description = "";
}

taskstd::taskstd(taskstd& x) : task(x)
{
    description = x.description;
}

taskstd::taskstd(const date day, const time start, const time end) : task(), start(start), end(end)
{
    start_day = day;
}

taskstd::~taskstd()
{

}

time taskstd::set_start(time x)
{
    start = x;
    return x;
}

time taskstd::set_end(time x)
{
    end = x;
    return x;
}

void taskstd::print()
{
    std::cout << "|" << description << "| [" << start_day << "] {Время начала: " << start << " Время конца: " << end << " Продолжительность: " << end - start << "}" << std::endl;
}

void taskstd::print(std::ofstream& s)
{

}