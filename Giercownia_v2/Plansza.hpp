#pragma once
#include <iostream>
#include <conio.h>

class Plansza {
public:
	char plansza[3][3];
	void drukuj();
	bool czy_wygrana();
	bool wprowadz(char, int, int);
};

void Plansza::drukuj() {
	system("cls");
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (i == 0) {
				if (j == 0) std::cout << "  ";
				else std::cout << "  " << j << "  ";
			}
			else if (j == 0) std::cout << i << " ";
			else {
				std::cout << "  " << plansza[i - 1][j - 1];
				if (j != 3) {
					if (j == 1) std::cout << " |";
					else std::cout << "  |";
				}
				else std::cout << "  ";
			}
		}
		if (i == 1 || i == 2) {
			std::cout << std::endl << "  ";
			for (int j = 0; j < 3; j++) {
				if (j != 2)
				{
					if (j == 1)std::cout << "_____|";
					else std::cout << "____|";
				}
				else std::cout << "_____";
			}
		}
		if (i == 3) {
			std::cout << std::endl << "      |     |";
		}
		std::cout << std::endl;
	}
}

bool Plansza::czy_wygrana() {
	if (plansza[0][0] == plansza[0][1] && plansza[0][1] == plansza[0][2] && plansza[0][2] == 'X') return true;
	else if (plansza[0][0] == plansza[0][1] && plansza[0][1] == plansza[0][2] && plansza[0][2] == 'O') return true;

	else if (plansza[1][0] == plansza[1][1] && plansza[1][1] == plansza[1][2] && plansza[1][2] == 'X') return true;
	else if (plansza[1][0] == plansza[1][1] && plansza[1][1] == plansza[1][2] && plansza[1][2] == 'O') return true;

	else if (plansza[2][0] == plansza[2][1] && plansza[2][1] == plansza[2][2] && plansza[2][2] == 'X') return true;
	else if (plansza[2][0] == plansza[2][1] && plansza[2][1] == plansza[2][2] && plansza[2][2] == 'O') return true;

	else if (plansza[0][0] == plansza[1][0] && plansza[2][0] == plansza[2][0] && plansza[2][0] == 'X') return true;
	else if (plansza[0][0] == plansza[1][0] && plansza[2][0] == plansza[2][0] && plansza[2][0] == 'O') return true;

	else if (plansza[0][1] == plansza[1][1] && plansza[1][1] == plansza[2][1] && plansza[2][1] == 'X') return true;
	else if (plansza[0][1] == plansza[1][1] && plansza[1][1] == plansza[2][1] && plansza[2][1] == 'O') return true;

	else if (plansza[0][2] == plansza[1][2] && plansza[1][2] == plansza[2][2] && plansza[2][2] == 'X') return true;
	else if (plansza[0][2] == plansza[1][2] && plansza[1][2] == plansza[2][2] && plansza[2][2] == 'O') return true;

	else if (plansza[0][0] == plansza[1][1] && plansza[1][1] == plansza[2][2] && plansza[2][2] == 'X') return true;
	else if (plansza[0][0] == plansza[1][1] && plansza[1][1] == plansza[2][2] && plansza[2][2] == 'O') return true;

	else if (plansza[0][2] == plansza[1][1] && plansza[1][1] == plansza[2][0] && plansza[2][0] == 'X') return true;
	else if (plansza[0][2] == plansza[1][1] && plansza[1][1] == plansza[2][0] && plansza[2][0] == 'O') return true;

	else return false;
}

bool Plansza::wprowadz(char znak, int x, int y) {
	if (x != 1 && x != 2 && x != 3 && y != 1 && y != 2 && y != 3) {
		std::cout << "Blad! Wprowadzono nieprawidlowe dane!" << std::endl;
		return false;
	}
	else if (plansza[x-1][y-1] != ' ') {
		std::cout << "Blad! To miejsce jest juz zajete!" << std::endl;
		return false;
	}
	else {
		plansza[x-1][y-1] = znak;
		return true;
	}
}