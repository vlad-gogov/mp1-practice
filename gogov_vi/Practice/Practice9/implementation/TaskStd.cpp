#include "../headers/TaskStd.h"

taskstd::taskstd()
{
	get_type(0);
	description = "";
}

taskstd::taskstd(taskstd& x)
{
	get_type(x.set_type());
	description = x.description;
}

taskstd::~taskstd()
{

}

time taskstd::get_start()
{
	return start;
}

time taskstd::set_start(time x)
{
	start = x;
	return x;
}

time taskstd::get_end()
{
	return end;
}

time taskstd::set_end(time x)
{
	end = x;
	return x;
}

void taskstd::print()
{
	std::cout << "|" << description << "| [" << start_day << "] {Время начало: " << start << " Время конца: " << end << " Продолжительность: " << end - start << "}" << std::endl;
}

void taskstd::print(std::ofstream& s)
{

}