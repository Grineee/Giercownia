#pragma once
#include "Gracz.hpp"
#include "Gracz.hpp"
class Kolko_i_krzyzyk {
private:
	Plansza p1 = Plansza();
	Gracz g1 = Gracz('O');
	Gracz g2 = Gracz('X');
	int rundy = 0;
public:
	Kolko_i_krzyzyk();
	void drukuj_wyniki();
	void uruchom_gre();
	void menu_kolko_krzyzyk();
	void instrukcja_gry_kolko_krzyzyk();
	void start_rundy();
	bool ruch_gracza(Gracz);
};

Kolko_i_krzyzyk::Kolko_i_krzyzyk() {
	std::cout << "Rozpoczeto nowa gre!" << std::endl;
	std::cout << "POWODZENIA!" << std::endl;
}

void Kolko_i_krzyzyk::drukuj_wyniki() {
	system("cls");
	if (g1.punkty >= g2.punkty) std::cout << "\n\tTABLICA WYNIKOW\nlp.\tNazwa\tWynik\n1.\t" << g1.nazwa << "\t" << g1.punkty << "\n" << "2.\t" << g2.nazwa << "\t" << g2.punkty << std::endl;
	else std::cout << "\n\tTABLICA WYNIKOW\nlp.\tNazwa\tWynik\n1.\t" << g2.nazwa << "\t" << g2.punkty << "\n" << "2.\t" << g1.nazwa << "\t" << g1.punkty << std::endl;
	std::cout << "Nacisnij dowolny klawisz aby powrocic do menu gry...";
	_getch();
}
void Kolko_i_krzyzyk::uruchom_gre() {
	system("cls");
	std::cout << "Podaj imiona graczy:" << std::endl;
	std::cout << "Gracz 1: ";
	std::cin >> g1.nazwa;
	std::cout << std::endl << "Gracz 2: ";
	std::cin >> g2.nazwa;
	char wybor = '0';
	while (wybor != 'j') {
		system("cls");
		menu_kolko_krzyzyk();
		wybor = _getch();
		switch (wybor)
		{
		case '1':
			rundy++;
			start_rundy();
			break;
		case '2':
			instrukcja_gry_kolko_krzyzyk();
			break;
		case '3':
			drukuj_wyniki();
			break;
		case 'j':
			std::cout << "Koniec gry w kolko i krzyzyk!" << std::endl;
			break;
		default:
			std::cout << "BLEDNY WYBOR!" << std::endl;
		}
	}
}
void Kolko_i_krzyzyk::menu_kolko_krzyzyk() {
	system("cls");
	std::cout << "\tMenu:" << std::endl;
	std::cout << "1. Rozpocznij runde" << std::endl;
	std::cout << "2. Instrukcja gry" << std::endl;
	std::cout << "3. Tablica punktow" << std::endl;
	std::cout << "j. Zakoncz gre" << std::endl;
}
void Kolko_i_krzyzyk::instrukcja_gry_kolko_krzyzyk() {
	system("cls");
	std::cout << "\tINSTRUKCJA:" << std::endl;
	std::cout << "Kazdy z graczy naprzemian wpisuje\nswoj znak na plansze poprzez wpisanie\ndwoch liczb oddzielonych spacja, ktore oznaczaja\nkolejno wiersz i kolumne miejsca w ktore\ndany gracz chce wpisac swoj znak.\n\nPo wybraniu zakonczenia gry wszystkie dane\nzostaja wyczyszczone (imie i punkty).\n\n";
	std::cout << "Nacisnij dowolny klawisz aby powrocic do menu gry...";
	_getch();
}
void Kolko_i_krzyzyk::start_rundy() {
	p1.plansza[0][0] = ' ';
	p1.plansza[0][1] = ' ';
	p1.plansza[0][2] = ' ';
	p1.plansza[1][0] = ' ';
	p1.plansza[1][1] = ' ';
	p1.plansza[1][2] = ' ';
	p1.plansza[2][0] = ' ';
	p1.plansza[2][1] = ' ';
	p1.plansza[2][2] = ' ';
	Gracz* ostatni_ruch = &g1;
	int ruch = 0;
	while (!(p1.czy_wygrana()) && ruch < 9)
	{
		p1.drukuj();
		if ((this->rundy % 2 == 1 && ruch % 2 == 1) || (this->rundy % 2 == 0 && ruch % 2 == 0))
		{
			ostatni_ruch = &g1;
			ruch++;
			while (!(ruch_gracza(g1)));
		}
		else
		{
			ostatni_ruch = &g2;
			ruch++;
			while (!(ruch_gracza(g2)));
		}
	}
	if (ruch != 9) {
		std::cout << "Gratulacje! Wygrywa " << ostatni_ruch->nazwa << "!" << std::endl << "Nacisnij dowolny klawisz, aby wrocic do menu..." << std::endl;
		ostatni_ruch->punkty++;
	}else {
		std::cout << "Remis! Kazdy z graczy otrzymuje punkt! :)";
		g1.punkty++;
		g2.punkty++;
	}
	_getch();
}
bool Kolko_i_krzyzyk::ruch_gracza(Gracz x) {
	int a, b;
	std::cout << "Kolej gracza " << x.nazwa << std::endl << "Gdzie chcesz wstawic " << x.znak << "?" << std::endl;
	std::cin >> a >> b;
	if (p1.wprowadz(x.znak, a, b)) return true;
	else return false;
}