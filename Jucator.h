#pragma once
#include"Common.h"
using namespace std;
class Jucator
{
	string name;
	int scor;
	string piesa;
public:
	Jucator(string name,string piesa);
	int GetScor();
	string GetName();
	string GetPiesa();
	void operator++();
};

