#include "Sort.h"
#include "Random.h"

void UndavSorting::Ordenar(Item* items, int indiceComienzo, int indiceFin) {
	for (int i = indiceComienzo + 1; i <= indiceFin; ++i)
	{
		for (int j = i; j > indiceComienzo; --j)
		{
			if (EsMayor(items[j - 1], items[j]))
			{
				Intercambiar(items[j - 1], items[j]);
			}
		}
	}
}

void IntercambiarClavesRandom(int* a, int* b);

void UndavSorting::Mezclar(Item* items, int cantidadItems) {
	int indiceComienzo = 0;
	int indiceFin = cantidadItems - 1;
	int* clavesRandom = UndavRandom::CrearRandoms(cantidadItems);

	for (int i = indiceComienzo + 1; i <= indiceFin; ++i)
	{
		for (int j = i; j > indiceComienzo; --j)
		{
			if (clavesRandom[j - 1] > clavesRandom[j])
			{
				Intercambiar(items[j - 1], items[j]);
				IntercambiarClavesRandom(&clavesRandom[j - 1], &clavesRandom[j]);
			}
		}
	}
}


void IntercambiarClavesRandom(int* a, int* b) {
	int auxiliar = *a;
	*a = *b;
	*b = auxiliar;

}