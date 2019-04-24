#ifndef _To_Do_List_H_
#define _To_Do_List_H_
#include "Task.h"
#include "TaskDay.h"
#include "TaskStd.h"

class ToDoList 
{
	task** List;
	unsigned count_tasks;
public:
	short read_tasks();
	void print_tasks(date&);
	void print_all_tasks();
};

#endif