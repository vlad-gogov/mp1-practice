#include <iostream>
#include <clocale>
#include "headers/ToDoList.h"

void main()
{
	setlocale(LC_ALL, "Russian");
	ToDoList to_do_list;
	char flag_input_date;
	unsigned day, month, year; 
	// Считывание файла
	unsigned count_tasks = to_do_list.read_tasks();
	if (count_tasks == -1)
		return;
	std::cout << "Введите дату через пробелы (Формат ДД ММ ГГГГ): ";
	date D;
	do {
		flag_input_date = 0;
		std::cin >> day >> month >> year;
		try
		{
			D = date(day, month, year);
		}
		catch (bad_date e)
		{
			std::cout << e.what(0) << " Повторите попытку. ";
			flag_input_date = 1;
		}
	} while (flag_input_date == 1);

	to_do_list.print_tasks(D, count_tasks);
}
