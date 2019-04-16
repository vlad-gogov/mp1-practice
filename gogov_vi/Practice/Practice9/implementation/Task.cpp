#include "../headers/Task.h"

task::task()
{
//	id = 0;
	type = -1;
	description = "";
}

task::task(task& x)
{
	//id = x.id;
	type = x.type;
	description = x.description;
}
/*
void task::set_id(unsigned x)
{
	id = x;
}
*/
unsigned task::set_type()
{
	return type;
}

void task::get_type(unsigned _type)
{
	type = _type;
}

time task::set_start(time x)
{
	return time();
}

time task::set_end(time x)
{
	return time();
}

void task::get_title()
{
	std::cout << description;
}

task::~task()
{

}