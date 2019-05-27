#include "../headers/TaskDay.h"

taskday::taskday() : task()
{
    description = "";
}

taskday::taskday(taskday& x) : task(x)
{
     description = x.description;
}

taskday::~taskday()
{

}

void taskday::print()
{
    std::cout << "|" << description << "| [" << start_day << "]" << std::endl;
}

void taskday::print(std::ofstream& s)
{

}
