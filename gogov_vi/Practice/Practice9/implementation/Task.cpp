#include "../headers/Task.h"

task::task()
{
	id = 0;
	type = -1;
	title = "0";
}

task::task(const task& x)
{
	id = x.id;
	type = x.type;
	title = x.title;
}

void task::set_title(std::string _title)
{
	title = _title;
}

char task::get_type()
{
	return type;
}

unsigned task::get_id()
{
	return id;
}

void task::get_title()
{
	std::cout << title;
}
