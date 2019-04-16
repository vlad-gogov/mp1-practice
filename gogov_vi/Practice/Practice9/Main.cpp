#include <iostream>
#include <clocale>
#include "headers/ToDoList.h"

int main()
{
	setlocale(LC_ALL, "Russian");
	ToDoList to_do_list;
	unsigned day, month, year, count_tasks = to_do_list.read_tasks();
	std::cout << "Введите дату через пробелы (Формат ДД ММ ГГГГ): ";
	std::cin >> day >> month >> year;
	date D(day, month, year);
	to_do_list.print_tasks(D, count_tasks);
	std::cout << std::endl << "Полный список дел: " << std::endl;
	to_do_list.print_all_tasks(count_tasks);
}
