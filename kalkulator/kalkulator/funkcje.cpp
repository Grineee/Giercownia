#include "funkcje.h"
#include <stdio.h>


int add(int a, int b)
{
	return a + b;
}
int substract(int a, int b)
{
	return a - b;
}
int multiplie(int a, int b)
{
	return a * b;
}
float divide(int a, int b)
{
	return a / b;
}
void pobierz_liczby(int* a, int* b)
{
	printf_s("\nPodaj pierwsza liczbe: ");
	scanf_s("%d", *a);
	printf_s("\nPodaj druga liczbe: ");
	scanf_s("%d", *b);
	printf_s("\n");
}