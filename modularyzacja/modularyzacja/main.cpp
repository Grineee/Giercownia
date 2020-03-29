#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include "funkcje_swap.h"
#include "menu.h"

#define ROZMIAR_TABLIC 5

using namespace std;

void wyswietl_tablice(int* tab_a, int* tab_b, int rozmiar_tablicy);

void wpisz_do_tablicy(int* tab_a, int* tab_b, int rozmiar_tablicy);

void wypelnij_losowo(int* tab_a, int* tab_b, int rozmiar_tablicy);

int main()
{
    int tab_a[ROZMIAR_TABLIC];
    int tab_b[ROZMIAR_TABLIC];
    char wybor = 0;
    int ile = 1;
    while (wybor != 'k')
    {
        menu();
        wybor = _getch();

        switch (wybor)
        {
        case '1': 
            wpisz_do_tablicy(tab_a, tab_b, ROZMIAR_TABLIC);
            break;
        case '2':
            wypelnij_losowo(tab_a, tab_b, ROZMIAR_TABLIC);
            break;
        case '3': 
            wyswietl_tablice(tab_a, tab_b, ROZMIAR_TABLIC);
            break;
        case '4':
            printf_s("\nIle elementow chcesz zamienic?\n");
            scanf_s("%d", &ile);
            if (ile >= 0 && ile <= ROZMIAR_TABLIC) swap_tab(tab_a, tab_b, ile);
            else printf_s("niestety, taka operacja jest niewykonalna");
            break;
        case '5':
            printf_s("\nIle elementow chcesz zamienic?\n");
            scanf_s("%d", &ile);
            if (ile >= 0 && ile <= ROZMIAR_TABLIC) swap_tab_wsk(tab_a, tab_b, ile);
            else printf_s("niestety, taka operacja jest niewykonalna");
            break;
        case 'k':
            break;
        default: 
            printf_s("\nMusisz wybrac wlasciwa opcje.\n");
            break;
        }
    }

}

void wyswietl_tablice(int* tab_a, int* tab_b, int rozmiar_tablicy)
{
    printf_s("\n");
    printf_s("Tablica A:\n");
    for (int i = 0; i < rozmiar_tablicy; i++)
    {
        printf_s("%d", *(tab_a + i));
        printf_s(" ");
    }
    printf_s("\n");
    printf_s("Tablica B:\n");
    for (int i = 0; i < rozmiar_tablicy; i++)
    {
        printf_s("%d", *(tab_b + i));
        printf_s(" ");
    }
}

void wpisz_do_tablicy(int* tab_a, int* tab_b, int rozmiar_tablicy)
{
    printf_s("\n");
    printf_s("Wprowadz %d liczb do tablicy A:\n", rozmiar_tablicy);
    for (int i = 0; i < rozmiar_tablicy; i++)
    {
        scanf_s("%d", (tab_a + i));
    }
    printf_s("\n");
    printf_s("Wprowadz %d liczb do tablicy B:\n", rozmiar_tablicy);
    for (int i = 0; i < rozmiar_tablicy; i++)
    {
        scanf_s("%d", (tab_b + i));
    }
}

void wypelnij_losowo(int* tab_a, int* tab_b, int rozmiar_tablicy)
{
    srand(time(NULL));
    for (int i = 0; i < ROZMIAR_TABLIC; i++)
    {
        *(tab_a + i) = rand() % 101;
        *(tab_b + i) = rand() % 101;
    }
    printf_s("\nGotowe!\n");
}