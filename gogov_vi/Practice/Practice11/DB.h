#ifndef _DB_
#define _DB_
#include <iostream>
#include "Date.h"
#include "Passport.h"
#include "Education.h"
#include "Name.h"
#include <string>

class DB 
{
	public:
		name Name;
		passport passport;
		education Enducation;
		std::string specialty;
		std::string department;
		std::string job;
		unsigned salary;
		date start;
		date last;
		
};

#endif