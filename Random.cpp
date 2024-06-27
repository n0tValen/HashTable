#include "Random.h"
#include <cstdlib>
#include <ctime>

bool semillaRandomInicializada = false;

void VerificarSemillaInicializada();

int* UndavRandom::CrearRandoms(int cantidadRandoms) {
	VerificarSemillaInicializada();
	int* randoms = new int[cantidadRandoms];
	for (int i = 0;i < cantidadRandoms;++i) {
		randoms[i] = rand();
	}

	return randoms;
}

int UndavRandom::ObtenerNumeroRandom(unsigned int minimoValor, int maximoValor) {
	VerificarSemillaInicializada();
	int random = rand() % maximoValor;
	if (random < minimoValor)
		random += minimoValor;

	return random;
}

void VerificarSemillaInicializada() {
	
	if (!semillaRandomInicializada) {
		srand(time(NULL));
		semillaRandomInicializada = true;
	}
}