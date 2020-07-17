#pragma once
#include "Plansza.hpp"
class Gracz {
public:
	char znak;
	std::string nazwa = "nieznane";
	int punkty;
	Gracz(char xlubo);
	bool wykonaj_ruch(Plansza *p);
};
Gracz::Gracz(char xlubo) {
	znak = xlubo;
	punkty = 0;
}
