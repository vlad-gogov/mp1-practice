#include "../headers/ToDoList.h"

short ToDoList::read_tasks()
{
	std::ifstream open_file;
	open_file.open("ToDoList.txt");
	std::string str;
	size_t pos = 0;

	// Кол-во задач
	getline(open_file, str);
	size_t digits = str.find_first_of("1234567890+-");
	count_tasks = atoi(str.c_str() + digits);
	
	// Массив указателей
	List = new task*[count_tasks];

	short _type = -1;
	for (unsigned i = 0U; i < count_tasks; i++)
	{
		getline(open_file, str);

		if (str.empty())
		{
			std::cout << "Количество задач не совпадает с введенным числом в файле." << std::endl;
			count_tasks = 0;
			return 1;
		}

		// Считывание типа задачи
		str = str.substr(str.find_first_not_of(' '));
		_type = (short)std::stoul(str);

		str = str.substr(str.find_first_of(' '));
		str = str.substr(str.find_first_not_of(' '));

		// Считывание даты
		unsigned fields[3];
		for (int i = 0; i < 3; i++) 
		{
			pos = str.find_first_not_of("1234567890");
			fields[i] = (unsigned)std::stoul(str.substr(0, pos));
			str = str.substr(pos + 1);
		}
		
		
		str = str.substr(str.find_first_of(' '));
		str = str.substr(str.find_first_not_of(' '));

		date Date;
		try
		{
			Date = date(fields[0], fields[1], fields[2]);
		}
		catch (bad_date_input & e)
		{
			std::cout << e.what() << std::endl << "Исправьте в файле строку " << i + 2 << ".";
			return -1;
		}

		if (_type == 1)
		{
			task* a = new taskday;
			a->start_day = Date;
			a->description = str;
			List[i] = a;
		}

		if(_type == 0)
		{
			task* b = new taskstd;
			b->start_day = Date;
			unsigned start_time[2];
			unsigned end_time[2];

			// Время начала
			for (int i = 0; i < 2; i++)
			{
				pos = str.find_first_not_of("1234567890");
				start_time[i] = (unsigned)std::stoul(str.substr(0, pos));
				str = str.substr(pos + 1);
			}

			str = str.substr(str.find_first_of(' '));
			str = str.substr(str.find_first_not_of(' '));

			// Время конца
			for (int i = 0; i < 2; i++)
			{
				pos = str.find_first_not_of("1234567890");
				end_time[i] = (unsigned)std::stoul(str.substr(0, pos));
				str = str.substr(pos + 1);
			}

			// Описание
			str = str.substr(str.find_first_not_of(' '));
			b->description = str;

			time _start;
			time _end;
			try
			{
				_start = time(start_time[0], start_time[1]);
				_end = time(end_time[0], end_time[1]);
			}
			catch (bad_time_hour& e)
			{
				std::cout << e.what()  << " Исправьте в файле строку " << i + 2 << '.';
				return -1;
			}
			catch (bad_time_min& e)
			{
				std::cout << e.what() << " Исправьте в файле строку " << i + 2 << '.';
				return -1;
			}
			if (_start > _end)
			{
				std::cout << "Время начала больше времени конца. Строчка:" << i + 2 << std::endl << '.';
				return -1;
			}
			b->set_start(_start);
			b->set_end(_end);
			List[i] = b;
		}
	}
	open_file.close();
	return 0;
}

void ToDoList::print_tasks(date& D)
{
	int k = 0;
	for (unsigned i = 0U; i < count_tasks; i++)
	{
		if (List[i]->start_day == D)
			List[i]->print();
		else
			k++;
	}
	if (k == count_tasks)
		std::cout << "Дел на эту дату нет. Отдыхайте)))";
}

void ToDoList::print_all_tasks()
{
	std::cout << std::endl << "Полный список дел: " << std::endl;
	for (unsigned i = 0U; i < count_tasks; i++)
		List[i]->print();
}