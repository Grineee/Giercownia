#include "funkcje_swap.h"

void swap_tab(int* tab_a, int* tab_b, int ilosc_elementow_do_zamiany)
{
	int temp = 0;
	for (int i = 0; i < ilosc_elementow_do_zamiany; i++)
	{
		temp = tab_a[i];
		tab_a[i] = tab_b[i];
		tab_b[i] = temp;
	}
}

void swap_tab_wsk(int* tab_a, int* tab_b, int ilosc_elementow_do_zamiany)
{
	int temp = 0;
	for (int i = 0; i < ilosc_elementow_do_zamiany; i++)
	{
		temp = *(tab_a + i);
		*(tab_a + i) = *(tab_b + i);
		*(tab_b + i) = temp;
	}

}
