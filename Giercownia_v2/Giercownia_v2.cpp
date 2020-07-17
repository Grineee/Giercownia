#include "Kolko_i_krzyzyk.hpp"
void drukuj_menu() {
	std::cout << "Wybierz co chcesz robic :)" << std::endl;
	std::cout << "1. Zagraj w kolko i krzyzyk (2 graczy)" << std::endl;
	std::cout << "2. ----------------------" << std::endl;
	std::cout << "k. Zakoncz program" << std::endl;
}

int main()
{
	std::cout << "Witaj w giercowni!" << std::endl;
	char choice = '0';
	while (choice != 'k')
	{
		Kolko_i_krzyzyk k1 = Kolko_i_krzyzyk();
		system("cls");
		std::cout << "Witaj w giercowni!" << std::endl;
		drukuj_menu();
		choice = _getch();
		switch (choice)
		{
		case '1':
			k1.uruchom_gre();
			delete[] &k1;
			break;
		case 'k':
			std::cout << "Wpadnij jeszcze kiedys :)" << std::endl;
			break;
		default:
			std::cout << "BLEDNY WYBOR!" << std::endl;
		}
	}
	return 0;
}