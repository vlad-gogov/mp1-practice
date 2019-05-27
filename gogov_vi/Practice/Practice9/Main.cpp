#include <iostream>
#include <clocale>
#include "headers/ToDoList.h"

int main()
{
    setlocale(LC_ALL, "Russian");
    ToDoList to_do_list;
    char flag_input_date;
    unsigned day, month, year; 
    // Считывание файла
    if (to_do_list.read_tasks() == 1)
        return -1;
    std::cout << "Введите дату через пробелы (Формат ДД ММ ГГГГ): ";
    date D;
    do {
        flag_input_date = 0;
        std::cin >> day >> month >> year;
        try
        {
            D = date(day, month, year);
        }
        catch (bad_date_day& e)
        {
            std::cout << e.what() << " Повторите попытку. ";
            flag_input_date = 1;
        }
        catch (bad_date_month & e)
        {
            std::cout << e.what() << " Повторите попытку. ";
            flag_input_date = 1;
        }
        catch (bad_date_year & e)
        {
            std::cout << e.what() << " Повторите попытку. ";
            flag_input_date = 1;
        }
    } while (flag_input_date == 1);

    to_do_list.print_tasks(D);

    return 0;
}
