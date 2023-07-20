#include "Game.h"

void Game::Joc(Jucator* Bolfa, Jucator* Mario)
{
	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof(cfi);
	cfi.nFont = 0;
	cfi.dwFontSize.X = 20;
	cfi.dwFontSize.Y = 20;
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
	X_O(Bolfa, Mario);
}

void Game::Calculator(Jucator* Bolfa)
{
	Tabela Tabla;
	int pozitie;
	Jucator* Robot=new Jucator("Robot", "X");
	Tabla.Player(Bolfa);
	Tabla.Player(Robot);
	int miscari = 0;
	Tabla.Print(Tabla.GetTable());
	while (!Tabla.Winner(*Bolfa, *Robot, miscari) && miscari < 8) {
		while (!Tabla.Add(*Bolfa));
		miscari++;
		Tabla.Print(Tabla.GetTable());
		if (!Tabla.Winner(*Bolfa, *Robot, miscari)) {
			Tabla.Print(Tabla.GetTable());
			while (!Tabla.Add_Robot(*Robot));
			miscari++;
			Tabla.Print(Tabla.GetTable());
			Tabla.Winner(*Bolfa, *Robot, miscari);
		}
		else
			return;
	}
	cout << "{Jocu s-a termiant}" << endl;
}


void Game::X_O(Jucator* Bolfa, Jucator* Mario)
{
	Tabela Tabla;
	int pozitie;
	Tabla.Player(Bolfa);
	Tabla.Player(Mario);
	int miscari = 0;
	Tabla.Print(Tabla.GetTable());
	while (!Tabla.Winner(*Bolfa, *Mario,miscari) && miscari<8) {
		while (!Tabla.Add(*Bolfa));
		miscari++;
		Tabla.Print(Tabla.GetTable());
		if (!Tabla.Winner(*Bolfa, *Mario, miscari)) {
			Tabla.Print(Tabla.GetTable());
			while (!Tabla.Add(*Mario));
			miscari++;
			Tabla.Print(Tabla.GetTable());
			Tabla.Winner(*Bolfa, *Mario, miscari);
		}
		else
			return;
	}
	cout << "{Jocu s-a termiant}"<<endl;
}

