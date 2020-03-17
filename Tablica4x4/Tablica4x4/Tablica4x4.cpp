﻿// PrzykladMenu.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

// tablica4x4_v01_C.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//Under "Project -> Properties -> C/C++ -> Preprocessor -> Preprocessor Definitions" add _CRT_SECURE_NO_WARNINGS

//#include "pch.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

#define L_WIERSZY 4
#define L_KOLUMN  4


void wprowadz_dane(int tab[][L_KOLUMN])
{
	printf_s("wprowadz_dane\n");
	int rozmiar = L_WIERSZY * L_KOLUMN;
	printf_s("Tablica ma rozmiar %d x %d, wprowadz wiec %d liczb.\n", L_WIERSZY, L_KOLUMN, rozmiar);
	for (int wiersze = 0; wiersze < L_WIERSZY; wiersze++)
	{
		for (int kolumny = 0; kolumny < L_KOLUMN; kolumny++)
		{
			scanf_s("%d", &tab[wiersze][kolumny]);
		}
	}
}

void wprowadz_dane_losowo(int tab[][L_KOLUMN])
{
	printf_s("wprowadz_dane_losowo\n");
	srand(time(NULL));
	for (int wiersze = 0; wiersze < L_WIERSZY; wiersze++)
	{
		for (int kolumny = 0; kolumny < L_KOLUMN; kolumny++)
		{
			tab[wiersze][kolumny] = rand() % 101;
		}
	}
}

void wyswietl_dane(int tab[][L_KOLUMN])
{
	int temp = 0;
	for (int wiersze = 0; wiersze < L_WIERSZY; wiersze++)
	{
		for (int kolumny = 0; kolumny < L_KOLUMN; kolumny++)
		{
			printf_s("%4d", tab[wiersze][kolumny]);
		}
		printf_s("\n");
	}
	printf_s("\n");
}

void wyswietl_dane_posortowane(int tab[])
{
	printf_s("wyswietl_dane_posortowane\n");
}

float srednia(int tab[][L_KOLUMN])
{
	printf_s("srednia\n");
	float srednia = 0;
	int suma = 0;
	for (int wiersze = 0; wiersze < L_WIERSZY; wiersze++)
	{
		for (int kolumny = 0; kolumny < L_KOLUMN; kolumny++)
		{
			suma += tab[wiersze][kolumny];
		}
	}
	srednia = suma / (L_KOLUMN * L_WIERSZY);
	return srednia;
}

float mediana(int tab[][L_KOLUMN], int tab_sort[])
{
	printf_s("mediana\n");
	return 0;
}

void zapisz_dane(int tab[][L_KOLUMN])
{
	printf_s("zapisz_dane\n");
}

void wczytaj_dane(int tab[][L_KOLUMN])
{
	printf_s("wczytaj_dane\n");
}

void zamien_min_max(int tab[][L_KOLUMN])
{
	printf_s("zamien_min_max\n");
	int indexyMin[2] = { 0,0 };
	int indexyMax[2] = { 0,0 };
	int temp = tab[0][0], temp2 = tab[0][0];
	for (int wiersze = 0; wiersze < L_WIERSZY; wiersze++)
	{
		for (int kolumny = 0; kolumny < L_KOLUMN; kolumny++)
		{
			if (temp < tab[wiersze][kolumny])
			{
				temp = tab[wiersze][kolumny];
				indexyMax[0] = wiersze;
				indexyMax[1] = kolumny;
			}
			if (temp2 > tab[wiersze][kolumny])
			{
				temp2 = tab[wiersze][kolumny];
				indexyMin[0] = wiersze;
				indexyMin[1] = kolumny;
			}
		}
	}
	temp = tab[indexyMax[0]][indexyMax[1]];
	tab[indexyMax[0]][indexyMax[1]] = tab[indexyMin[0]][indexyMin[1]];
	tab[indexyMin[0]][indexyMin[1]] = temp;
}

void menu(void)
{
	printf_s("\n");
	printf_s("1 - wprowadz dane\n");
	printf_s("2 - wyswietl dane\n");
	printf_s("3 - oblicz srednia i mediane\n");
	printf_s("4 - zamien wartosc minimalna z maksymalna\n");
	printf_s("5 - generuj dane losowo\n");
	printf_s("z - zapisz dane do pliku\n");
	printf_s("w - wczytaj dane z pliku\n");
	printf_s("k - koniec programu\n");
	printf_s("\n");
}

int main()
{
	int tablica[L_WIERSZY][L_KOLUMN] = { 0 };
	int tab_sort_temp[L_WIERSZY * L_KOLUMN] = { 0 };
	char opcja = 0;

	while (opcja != 'k')
	{
		menu();
		opcja = _getch();

		switch (opcja)
		{
		case '1':
			wprowadz_dane(tablica);
			break;

		case '2':
			wyswietl_dane(tablica);
			break;

		case '3':

			printf_s("Srednia wartosci znajdujacych sie w tabeli wynosi: %f\n", srednia(tablica));
			printf_s("Mediana wartosci znajdujacych sie w tabeli wynosi: %f\n", mediana(tablica, tab_sort_temp));
			break;

		case '4':
			zamien_min_max(tablica);
			printf_s("Zamieniono wartosc minimalna z maksymalna.\n");
			break;

		case '5':
			wprowadz_dane_losowo(tablica);
			printf_s("Wygenerowano dane losowo.\n");
			break;

		case 'z':
			zapisz_dane(tablica);
			printf_s("Zapisano dane do pliku.\n");
			break;

		case 'w':
			wczytaj_dane(tablica);
			printf_s("Odczytano dane z pliku.\n");
			break;

		case 'k':
			//zakonczenie programu
			break;

		default:
			printf_s("Wybierz wlasciwa opcje.\n\n");
			break;
		}
	}

	return 0;
}
