#include "../headers/Task.h"

task::task()
{
    description = "";
}

task::task(task& x)
{
    description = x.description;
}

void task::get_title() const
{
    std::cout << description;
}

task::~task()
{

}