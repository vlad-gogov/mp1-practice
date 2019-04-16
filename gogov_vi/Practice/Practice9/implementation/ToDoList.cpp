#include "../headers/ToDoList.h"

unsigned ToDoList::read_tasks()
{
	std::ifstream open_file;
	open_file.open("ToDoList.txt");
	std::string str;

	// Кол-во задач
	getline(open_file, str);
	size_t digits = str.find_first_of("1234567890+-");
	unsigned cout_tasks = atoi(str.c_str() + digits);
	
	// Массив указателей
	List = new task*[cout_tasks];

	char _type = -1;
	for (int i = 0; i < cout_tasks; i++)
	{
		getline(open_file, str);
		_type = (char)stoul(str);
		unsigned long _d = std::stoul(str.substr(2, 2));
		unsigned long _m = std::stoul(str.substr(5, 2));
		unsigned long _y = std::stoul(str.substr(8, 4));
		date tmp(_d, _m, _y);

		if (_type == 1)
		{
			task* a = new taskday;
			a->start_day = tmp;
			a->description = str.substr(13);
			List[i] = a;
		}

		if (_type == 0)
		{
			task* b = new taskstd;
			b->start_day = tmp;
			unsigned long _h_start = std::stoul(str.substr(13, 2));
			unsigned long _m_start = std::stoul(str.substr(16, 2));
			time _start(_h_start, _m_start);
			unsigned long _h_end = std::stoul(str.substr(19, 2));
			unsigned long _m_end = std::stoul(str.substr(22, 2));
			b->description = str.substr(25);
			time _end(_h_end, _m_end);
			b->set_start(_start);
			b->set_end(_end);
			List[i] = b;
		}
	}
	open_file.close();
	return cout_tasks;
}

void ToDoList::print_tasks(date& D, unsigned count)
{
	int k = 0;
	for (int i = 0; i < count; i++)
	{
		if (List[i]->start_day == D)
			List[i]->print();
		else
			k++;
	}
	if (k == count)
		std::cout << "Дел на эту дату нет. Отдыхай)))";
}

void ToDoList::print_all_tasks(unsigned count)
{
	for (int i = 0; i < count; i++)
		List[i]->print();
}