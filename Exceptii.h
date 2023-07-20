#pragma once
#include"Common.h"
class poz_ocup :public exception
{
public:
	const char* what() const throw()
	{
		return "Pozitie ocupata";
	}
};

class poz_inc :public exception
{
public:
	const char* what() const throw()
	{
		return "Pozitie gresita";
	}
};

