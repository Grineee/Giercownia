#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "menu.h"
#include "funkcje.h"

void usage(const char* program_name)
{
    printf_s("\nSposob uzycia: %s <liczba> <dzialanie(add/sub/mul/div)> <liczba>\n", program_name);
    printf_s("Lub\n %s \"menu\" \n", program_name);
    exit(1);
}

int main(int argc, char const* argv[])
{
    int a = 0, b = 0;
    if (argc < 2) usage(argv[0]);
    else if (argc == 2 && argv[1] != "menu") usage(argv[0]);
    else if (argc == 2 && argv[1] == "menu")
    {
        char wybor = '0';
        printf_s("\nWitaj w kalkulatorze.\n");
        while (wybor != 'k')
        {
            menu();
            wybor = _getch();
            switch (wybor)
            {
            case '1':
                pobierz_liczby(&a, &b);
                printf("\nSuma tych liczb wynosi %d.\n", add(a, b));
                break;
            case '2':
                pobierz_liczby(&a, &b);
                printf("\nRoznica tych liczb wynosi %d.\n", substract(a, b));
                break;
            case '3':
                pobierz_liczby(&a, &b);
                printf("\nIloczyn tych liczb wynosi %d.\n", multiplie(a, b));
                break;
            case '4':
                pobierz_liczby(&a, &b);
                printf("\nIloraz tych liczb wynosi %f.\n", divide(a, b));
                break;
            case 'k':
                break;
            default:
                printf_s("\nZly wybor!\n");
            }
        }
        return 0;

    }
    else if (argc == 4)
    {
        char dzialanie = *argv[2];
        printf("jestem tu");
        switch (dzialanie)
        {
        case 'add':
            printf("\nSuma tych liczb wynosi %d.\n", add(atoi(argv[1]), atoi(argv[3])));
            break;
        case 'sub':
            printf("\nSuma tych liczb wynosi %d.\n", substract(atoi(argv[1]), atoi(argv[3])));
            break;
        case 'mul':
            printf("\nSuma tych liczb wynosi %d.\n", multiplie(atoi(argv[1]), atoi(argv[3])));
            break;
        case 'div':
            printf("\nSuma tych liczb wynosi %f.\n", divide(atoi(argv[1]), atoi(argv[3])));
            break;
        }
        /*if (dzialanie == "add") printf("\nSuma tych liczb wynosi %f.\n", add(atof(argv[1]), atof(argv[3])));
        if (dzialanie == 'sub') printf("\nSuma tych liczb wynosi %f.\n", substract(atof(argv[1]), atof(argv[3])));
        if (dzialanie == 'mul') printf("\nSuma tych liczb wynosi %f.\n", multiplie(atof(argv[1]), atof(argv[3])));
        if (dzialanie == 'div') printf("\nSuma tych liczb wynosi %f.\n", divide(atof(argv[1]), atof(argv[3])));
        else printf_s("Ups... cos poszlo nie tak, sprawdz poprawnosc wpisanych parametrow");*/
        return 0;
    }
    else usage(argv[0]);
}