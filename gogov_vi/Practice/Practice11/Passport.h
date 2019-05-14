#ifndef _PASSPORT_
#define _PASSPORT_
#include <iostream>
#include <string>
#include "Date.h"
#include "Adress.h"

class passport
{
		std::string serial;
		std::string number;
	public:
		std::string issued;
		date issued_in;
		date birth_day;
		adress Adress;
};

#endif