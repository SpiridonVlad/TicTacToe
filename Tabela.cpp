#include "Tabela.h"

Tabela::Tabela()
{
	vector<string> Aux;
	for(int i=0;i<3;i++)
	Aux.push_back("-");
	for (int i = 0; i < 3; i++)
		Tabla.push_back(Aux);
	
	int index = 1;
	Afisare.resize(3);
	
	for (int i = 0; i < 3; i++) {
		Afisare[i].resize(3);
		for (int j = 0; j < 3; j++) {
			Afisare[i][j] = index;
			index++;
		}
	}
}

Tabela::~Tabela()
{
	Tabla.clear();
	Jucatori.clear();
}

void Tabela::Print(vector<vector<string>> Tabla)
{
	Culoare C;
	C.SchimbaCuloareAlb();
	bool ok = false;
	system("cls");
	cout << " --- --- --- " << endl;
	for (int i = 0; i < 3; i++) {
		(Tabla[i][0] != "-") ? ok = 1  : ok = 0;
		if (ok == 1)
		{
			C.SchimbaCuloareVerde();
			cout << "| " << Tabla[i][0];
			C.SchimbaCuloareAlb();
		}
		else
			cout << "| " << Afisare[i][0];
		(Tabla[i][1] != "-") ? ok = 1 : ok = 0; 
		if (ok == 1)
		{
			C.SchimbaCuloareVerde();
			cout << " | " << Tabla[i][1];
			C.SchimbaCuloareAlb();
		}
		else
			cout << " | " << Afisare[i][1];
		(Tabla[i][2] != "-") ? ok = 1 : ok = 0;
		if (ok == 1)
		{
			C.SchimbaCuloareVerde();
			cout << " | " << Tabla[i][2];
			C.SchimbaCuloareAlb();
		}
		else
			cout << " | " << Afisare[i][2];
		cout<< " |" << endl;
	}
	cout << " --- --- --- " << endl;
}

bool Tabela::Add(Jucator Bolfa)
{
	int pozitie;
	poz_ocup pozitie_ocupata;
	try {
		pozitie = 0;
		cout << "(" << Bolfa.GetName() << ")";
		pozitie=Place(pozitie, Bolfa);
		for(int i = 0 ; i < 3 ; i++)
			for (int j = 0; j < 3; j++) {
				if (Afisare[i][j] == pozitie) {
					if (Tabla[i][j]!="-")
						throw pozitie_ocupata;
					else {
						Tabla[i][j] = Bolfa.GetPiesa();
						return true;
					}
				}
			}
		return false;
	}
	catch (exception& e)
	{
		cout << "Aveti grija la pozitie! (" <<e.what()<<")"<< endl;
		return false;
	}
}

void Tabela::Erase(int pozitie)
{
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++) 
			if (Afisare[i][j] == pozitie) {
				Tabla[i][j] = "-";
				return;
			}
}

bool Tabela::Winner(Jucator& Bolfa, Jucator& Mario,int& miscari)
{
	Sleep(200);
	vector<bool> ok;
	ok.push_back(false);
	ok.push_back(false);
	int count = 0;
//------------------------------------------------------------------------------------------
	for (int k = 0; k < 2; k++) {
		for (int i = 0; i < 3; i++)
		{
			count = 0;
			for (int j = 0; j < 3; j++)
			{
				//cout << Tabla[i][j] << endl;
				if (Tabla[i][j] == Jucatori[k]->GetPiesa()) {
					count++;
				}
			}
			//cout << count << endl;
			if (count == 3)
				ok[k] = true;
		}
	}
//------------------------------------------------------------------------------------------
	if(ok[0]==false && ok[1]==false)
	for (int k = 0; k < 2; k++)
		for (int i = 0; i < 3; i++) {
			count = 0;
			for (int j = 0; j < 3; j++)
			{
				if (Tabla[j][i] == Jucatori[k]->GetPiesa()) {
					count++;
				}
				if (count == 3) {
					ok[k] = true;
				}
			}
		}
//------------------------------------------------------------------------------------------
	if (ok[0] == false && ok[1] == false)
		for (int k = 0; k < 2; k++) {
			count = 0;
			for (int i = 0; i < 3; i++)
			{
				if (Tabla[i][i] == Jucatori[k]->GetPiesa()) {
					count++;
				}
				if (count == 3) {
					ok[k] = true;
				}
			}
		}
//------------------------------------------------------------------------------------------
	int index = 0;
	if (ok[0] == false && ok[1] == false)
		for (int k = 0; k < 2; k++) {
			count = 0;
			index = 0;
			for (int j = 2; j >= 0; j--)
			{
				if (Tabla[index][j] == Jucatori[k]->GetPiesa()) {
					count++;
				}
				if (count == 3) {
					ok[k] = true;
				}
				index++;
			}
		}
//------------------------------------------------------------------------------------------
	if (ok[0] == true)
		{
		system("cls");
		string playerName = Bolfa.GetName();
		std::cout << "============================================" << std::endl;
		std::cout << "|               REZULTATUL                 |" << std::endl;
		std::cout << "|                                          |" << std::endl;
		std::cout << "'                                          '" << std::endl;
		std::cout << "            (" << playerName << ") A Castigat      " << std::endl;
		std::cout << ".                                          ." << std::endl;
		std::cout << "|                                          |" << std::endl;
		std::cout << "============================================" << std::endl;
				Bolfa.operator++();
				Sleep(1000);
				return true;
			
		}
	if (ok[1])
		{
		system("cls");
		string playerName = Mario.GetName();
		std::cout << "============================================" << std::endl;
		std::cout << "|               REZULTATUL                 |" << std::endl;
		std::cout << "|                                          |" << std::endl;
		std::cout << "'                                          '" << std::endl;
		std::cout << "           (" << playerName << ") A Castigat      " << std::endl;
		std::cout << ".                                          ." << std::endl;
		std::cout << "|                                          |" << std::endl;
		std::cout << "============================================" << std::endl;
					Mario.operator++();
					Sleep(1000);
					return true;
		}
	if (ok[0] == false && ok[1] == false && miscari == 9)
		{
		system("cls");
		std::string BolfaName = Bolfa.GetName();
		std::string MarioName = Mario.GetName();
		std::cout << "============================================" << std::endl;
		std::cout << "|               REZULTATUL                 |" << std::endl;
		std::cout << "|                                          |" << std::endl;
		std::cout << "'                                          '" << std::endl;
		std::cout << "        (" << BolfaName << ") -> REMIZA <- (" << MarioName << ")   " << std::endl;
		std::cout << ".                                          ." << std::endl;
		std::cout << "|                                          |" << std::endl;
		std::cout << "============================================" << std::endl;
		Sleep(1000);
			return false;
		}
	return false;
}

void Tabela::Player(Jucator* Bolfa)
{
	Jucatori.push_back(Bolfa);
}

vector<vector<string>> Tabela::GetTable()
{
	return Tabla;
}

int Tabela::Place(int pozitie, Jucator Bolfa)
{
	pozitie = 1;
	bool ok = false;
	string caracter;
	vector<vector<string>> Copie = Tabla;
	while (true) {
		if (GetAsyncKeyState(VK_UP) & 0x8000) {
			if (pozitie < 4)
				pozitie += 6;
			else
				pozitie -= 3;
			for (int i = 0; i < 3; i++)
				for (int j = 0; j < 3; j++)
					if (Afisare[i][j] == pozitie) {
						caracter = Copie[i][j];
						Copie[i][j] = Bolfa.GetPiesa();
						Print(Copie);
						Copie[i][j] = caracter;
					}
			Sleep(100);
		}

		if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
			if (pozitie > 6)
				pozitie -= 6;
			else
				pozitie += 3;
			for (int i = 0; i < 3; i++)
				for (int j = 0; j < 3; j++)
					if (Afisare[i][j] == pozitie) {
						caracter = Copie[i][j];
						Copie[i][j] = Bolfa.GetPiesa();
						Print(Copie);
						Copie[i][j] = caracter;
					}
			Sleep(100);
		}
		if (GetAsyncKeyState(VK_RETURN) & 0x8000) {
			ok = true;
			if (ok == true)
				return pozitie;
		}

		if (GetAsyncKeyState(VK_LEFT) & 0x8000) {
			pozitie--;
			if (pozitie < 1)
				pozitie = 9;
			for (int i = 0; i < 3; i++)
				for (int j = 0; j < 3; j++)
					if (Afisare[i][j] == pozitie) {
						caracter = Copie[i][j];
						Copie[i][j] = Bolfa.GetPiesa();
						Print(Copie);
						Copie[i][j] = caracter;
					}
			Sleep(100);
		}

		if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
			pozitie++;
			if (pozitie > 9)
				pozitie = 1;
			for (int i = 0; i < 3; i++)
				for (int j = 0; j < 3; j++)
					if (Afisare[i][j] == pozitie) {
						caracter = Copie[i][j];
						Copie[i][j] = Bolfa.GetPiesa();
						Print(Copie);
						Copie[i][j] = caracter;
					}
			Sleep(100);
		}
	}
}
