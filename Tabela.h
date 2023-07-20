#pragma once
#include"Exceptii.h"
#include"Jucator.h"
#include"Common.h"
#include"Culoare.h"

class Tabela
{
	vector<vector<string>>Tabla;
	vector<vector<int>> Afisare;
	vector<Jucator*>Jucatori;
public:
	Tabela();
	~Tabela();
	void Print(vector<vector<string>> Tabla);
	bool Add(Jucator Bolfa);
	void Erase(int pozitie);
	bool Winner(Jucator& Bofla, Jucator& Mario,int& miscari);
	void Player(Jucator* Bolfa);
	vector<vector<string>> GetTable();
	int Place(int pozitie, Jucator Bolfa);
};

