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
	for (unsigned i = 0U; i < cout_tasks; i++)
	{
		getline(open_file, str);
		_type = (char)stoul(str);
		unsigned long _d = std::stoul(str.substr(2, 2));
		unsigned long _m = std::stoul(str.substr(5, 2));
		unsigned long _y = std::stoul(str.substr(8, 4));
		date tmp;
		try
		{
			tmp = date(_d, _m, _y);;
		}
		catch (bad_date e)
		{
			std::cout << e.what(1) << std::endl << "Исправьте в файле строку " << i + 2 << ".";
			return -1;
		}

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
			unsigned long _h_end = std::stoul(str.substr(19, 2));
			unsigned long _m_end = std::stoul(str.substr(22, 2));
			time _start;
			time _end;
			try
			{
				_start = time(_h_start, _m_start);
				_end = time(_h_end, _m_end);
			}
			catch (bad_time e)
			{
				std::cout << e.what(0) << std::endl << "Исправьте в файле строку " << i + 2 << ".";
				return -1;
			}
			if (_end < _start)
			{
				std::cout << "Время начала задачи больше чем время конца. Строчка " << i + 2 << std::endl;
				return -1;
			}
			b->description = str.substr(25);
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
	for (unsigned i = 0U; i < count; i++)
	{
		if (List[i]->start_day == D)
			List[i]->print();
		else
			k++;
	}
	if (k == count)
		std::cout << "Дел на эту дату нет. Отдыхате)))";
}

void ToDoList::print_all_tasks(unsigned count)
{
	std::cout << std::endl << "Полный список дел: " << std::endl;
	for (unsigned i = 0U; i < count; i++)
		List[i]->print();
}