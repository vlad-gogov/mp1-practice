#ifndef _To_Do_List_H_
#define _To_Do_List_H_
#include "Task.h"
#include "TaskDay.h"
#include "TaskStd.h"

class ToDoList 
{
	task** List;
public:
	unsigned read_tasks();
	void print_tasks(date&, unsigned);
	void print_all_tasks(unsigned);
};

#endif