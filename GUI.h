#pragma once
#include"Common.h"
#include"Game.h"
#include"Culoare.h"

class GUI
{
	Culoare C;
	vector<Jucator*>Jucatorii;
	int pozitie=0;
	bool ok = false;

public:

	void Meniu() {
		string nume="---";
		string piesa="---";
		Jucator Gol1(nume, piesa);
		Jucator Gol2(nume, piesa);
		Jucatorii.push_back(&Gol1);
		Jucatorii.push_back(&Gol2);
		while (true) {
			cout << "        X^0" << endl;
			cout << endl;
			C.SchimbaCuloareAlb();
			cout << " <Player vs Player>";
			C.SchimbaCuloareVerde();
			if (pozitie == 1)
			{
				cout << "<--";
				if(ok==true)
				{
					Pvp();
					cout << "        X^0" << endl; cout << endl;
					cout << " <Player vs Player>";
					C.SchimbaCuloareVerde();
					cout << "<--";
				}
				cout << "<Jucati cu un prieten>" << endl;
			}
			cout << "\n\n";
			C.SchimbaCuloareAlb();
			cout << "<Player vs Computer>";
			C.SchimbaCuloareVerde();
			if (pozitie == 2)
			{
				cout << "<--";
				if (ok == true)
				{
					PvC();
					cout << "        X^0" << endl; cout << endl;
					cout << " <Player vs Player>"; cout << endl << endl;
					cout << "<Player vs Computer>";
					C.SchimbaCuloareVerde();
					cout << "<--";
				}
				cout << "<Jucati impotriva calculatorului>" << endl;
			}
			cout << "\n\n";
			C.SchimbaCuloareAlb();
			cout << "     <Jucatori>";
			C.SchimbaCuloareVerde();
			if (pozitie == 3)
			{
				cout << "<--";
				cout<<"<Alegeti jucatorii si piesele>"<<endl;
				if (ok == true)
				{
					C.SchimbaCuloareAlb();
					Jucatori();
					cout << "        X^0" << endl;
					cout << endl;
					cout << " <Player vs Player>";
					cout << "\n\n";
					cout << "<Player vs Computer> ";
					cout << "\n\n";
					cout << "     <Jucatori>";
				}
			}
			cout << "\n\n";
			C.SchimbaCuloareAlb();
			cout << "       <Scor>";
			C.SchimbaCuloareVerde();
			if (pozitie == 4)
			{
				cout << "<--";
				if(Jucatorii[0]->GetScor()>=0 || Jucatorii[1]->GetScor()>=0)
				{
					cout << endl;
					Scor();
				}
			}
			cout << "\n\n";
			C.SchimbaCuloareAlb();
			cout << "   <Instructiuni>";
			C.SchimbaCuloareVerde();
			if (pozitie == 5)
			{
				cout << "<--";
					Instructiuni();
			}
			cout << "\n\n";
			C.SchimbaCuloareAlb();
			cout << "       <Exit>";
			C.SchimbaCuloareVerde();
			if (pozitie == 6)
			{
				cout << "<--";
				cout << "<Parasiti jocul>" << endl;
				if(ok==true)
					Exit();
			}
			C.SchimbaCuloareAlb();
			Await_Input();
		}
	}

	void Pvp() {
	Game Joc;
	Joc.Joc(Jucatorii[0],Jucatorii[1]);
	system("cls");
	}

	void PvC() {
		Game Joc;
		Joc.Calculator(Jucatorii[0]);
		system("cls");
	}

	void Exit() {
		system("cls");
		exit(0);
	}

	void Scor()
	{
		cout << endl;
			cout << "      <PUNCTAJ>" << endl;
			cout << endl;
			cout << "<Jucatorul 1> (" << Jucatorii[0]->GetName() << ")" << " Are punctajul: (" << Jucatorii[0]->GetScor() << ")" << endl<<endl;
			cout << "<Jucatorul 2> (" << Jucatorii[1]->GetName() << ")" << " Are punctajul: (" << Jucatorii[1]->GetScor() << ")" << endl;
	}

	void Instructiuni() {
		cout << "<Jucati de pe sageti si alegeti jucatorii inainte>" << "\n";
	}

	void Jucatori() {
		system("cls");
		string nume;
		string piesa;
		C.SchimbaCuloareVerde();
		cout << "(";
		C.SchimbaCuloareAlbastru();
		cout << "X";
		C.SchimbaCuloareVerde();
		cout << " SI ";
		C.SchimbaCuloareAlb();
		cout << "0";
		C.SchimbaCuloareVerde();
		cout << ")" << endl;

		cout << "Alegeti jucatorul 1 ";
		C.SchimbaCuloareAlb();
		cout << "(NUME) : "; cin >> nume;
		C.SchimbaCuloareVerde();
		cout << "Alegeti jucatorul 1 ";
		C.SchimbaCuloareAlb();
		cout << "(PIESA) : "; cin >> piesa;

		Jucator* Bolfa = new Jucator(nume, piesa);
		nume.clear();
		piesa.clear();
		system("cls");

		C.SchimbaCuloareVerde();
		cout << "(";
		C.SchimbaCuloareAlbastru();
		cout << "X";
		C.SchimbaCuloareVerde();
		cout << " SI ";
		C.SchimbaCuloareAlb();
		cout << "0";
		C.SchimbaCuloareVerde();
		cout << ")" << endl;
		cout << "Alegeti jucatorul 2 ";
		C.SchimbaCuloareAlb();
		cout << "(NUME) : "; cin >> nume;
		C.SchimbaCuloareVerde();
		cout << "Alegeti jucatorul 2 ";
		C.SchimbaCuloareAlb();
		cout << "(PIESA) : "; cin >> piesa;

		Jucator* Mario = new Jucator(nume, piesa);

		Jucatorii[0]=Bolfa;
		Jucatorii[1]=Mario;
		system("cls");
		Sleep(100);
	}

	void Await_Input() {
		ok = false;
		while (true) {
			if (GetAsyncKeyState(VK_UP) & 0x8000) {
				Sleep(100);
				pozitie--;
				if (pozitie < 0)
					pozitie = 6;
				system("cls");
				return;
			}
			if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
				Sleep(100);
				pozitie++;
				if (pozitie > 6)
					pozitie = 1;
				system("cls");
				return;
			}
			if (GetAsyncKeyState(VK_RETURN) & 0x8000) {
				Sleep(100);
				this->ok = true;
				system("cls");
				return;
			}
		}
	}
};

