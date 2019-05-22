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

void task::get_title()
{
	std::cout << description;
}

task::~task()
{

}