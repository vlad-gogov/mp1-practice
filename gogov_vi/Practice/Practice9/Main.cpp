#include <iostream>
#include <clocale>
#include "headers/ToDoList.h"

int main()
{
	setlocale(LC_ALL, "Russian");
	ToDoList to_do_list;
	unsigned day, month, year, count_tasks = to_do_list.read_tasks();
	std::cout << "Введите дату через пробелы (Формат ДД ММ ГГГГ): ";
vvod:
	std::cin >> day >> month >> year;
	date D;
	try
	{
		D = date(day, month, year);
	}
	catch (bad_date e)
	{
		std::cout << e.what() << " Повторите попытку. ";
		goto vvod;
	}

	to_do_list.print_tasks(D, count_tasks);
}
