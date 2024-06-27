#include "GeneradorTanquesAgua.h"
#include "TanqueAgua.h"
#include "Random.h"

using UndavTanqueAgua::TanqueAgua;


TanqueAgua** UndavGeneradorTanquesAgua::GenerarTanques(int cantidadTanques) {
	TanqueAgua** tanques = new TanqueAgua * [cantidadTanques];
	for (int i = 0; i < cantidadTanques;++i) {
		int capacidad = UndavRandom::ObtenerNumeroRandom(100);
		int nivel = UndavRandom::ObtenerNumeroRandom(0, capacidad);
		tanques[i] = UndavTanqueAgua::CrearTanqueAgua(capacidad, nivel);
	}

	return tanques;
}

TanqueAgua** UndavGeneradorTanquesAgua::ObtenerSubconjunto(TanqueAgua** items, int cantidadSubConjunto) {
	TanqueAgua** subConjunto = new TanqueAgua * [cantidadSubConjunto];
	for (int i = 0; i < cantidadSubConjunto;++i) {
		subConjunto[i] = items[i];
	}

	return subConjunto;
}
