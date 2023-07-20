#pragma once
#include"Common.h"
class Culoare
{
public:
	void SchimbaCuloareVerde()
	{
		std::cout << "\033[32m";
	}
	void SchimbaCuloareRosu()
	{
		std::cout << "\033[31m";
	}
	void SchimbaCuloareAlbastru()
	{
		std::cout << "\033[34m";
	}
	void SchimbaCuloareAlb()
	{
		std::cout << "\033[0m";
	}
};

