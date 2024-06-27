#include "Diccionario.h"
#include <iostream>

const int CapacidadInicial = 10;

struct UndavDiccionario::Diccionario {
	int* claves;
	void* *valores;

	int capacidad;
	int cantidadElementos;
};

UndavDiccionario::Diccionario* UndavDiccionario::Crear() {
	Diccionario* nuevoDiccionario = new Diccionario;
	nuevoDiccionario->cantidadElementos = 0;
	nuevoDiccionario->capacidad = CapacidadInicial;
	nuevoDiccionario->claves = new int[CapacidadInicial];
	nuevoDiccionario->valores = new void* [CapacidadInicial];

	return nuevoDiccionario;
}

// Precondicion:
// - @claves esta ordenado (ascendentemente)
// - @indiceComienzo e @indiceFin es un rango valido
int ObtenerIndiceBuscado(int* claves, int clave, int indiceComienzo, int indiceFin) {
	while (indiceComienzo<indiceFin) {
		int indiceMitad = ((indiceFin - indiceComienzo) / 2) + indiceComienzo;
		if (claves[indiceMitad] == clave) {
			return indiceMitad;
		}
		else if(claves[indiceMitad]>clave) {
			indiceFin = indiceMitad-1;
		}
		else {
			indiceComienzo = indiceMitad+1;
		}
	}

	return -1;
}

// Postcondicion: Si existe devuelve la posicion donde esta. Si no existe devuelve la posicion donde deberia estar
int ObtenerRanking(int* claves, int clave, int indiceComienzo, int indiceFin) {
	while (indiceComienzo < indiceFin) {
		int indiceMitad = ((indiceFin - indiceComienzo) / 2) + indiceComienzo;
		if (claves[indiceMitad] == clave) {
			return indiceMitad;
		}
		else if (claves[indiceMitad] > clave) {
			indiceFin = indiceMitad - 1;
		}
		else {
			indiceComienzo = indiceMitad + 1;
		}
	}

	return indiceComienzo;
}

// Implementacion en lista O(N)
// Implementacion en vector (Binary Search) O(Log(N))
void* UndavDiccionario::Obtener(Diccionario* diccionario, int clave) {
	int indiceBuscado = ObtenerRanking(diccionario->claves, clave, 0, diccionario->cantidadElementos - 1);
	if (diccionario->claves[indiceBuscado] == clave) {
		return diccionario->valores[indiceBuscado];
	}
	else {
		return NULL;
	}
}


// Implementacion en lista O(N)
// Implementacion en vector (Binary Search) O(Log(N)) depende si se redimensiona o no

void UndavDiccionario::Agregar(Diccionario* diccionario, int clave, void* valor) {
	int indiceBuscado = ObtenerRanking(diccionario->claves, clave, 0, diccionario->cantidadElementos - 1);
	if (diccionario->claves[indiceBuscado] == clave) {
		diccionario->valores[indiceBuscado]= valor;
	}
	else {
		//Correr a la derecha el vector
		diccionario->valores[indiceBuscado] = valor;
		diccionario->claves[indiceBuscado] = clave;
	}
}




bool UndavDiccionario::Contiene(const Diccionario* diccionario, int clave) {
	return false;
}

int UndavDiccionario::ObtenerCantidadElementos(const Diccionario* diccionario) {
	return 0;
}

void UndavDiccionario::Destruir(Diccionario* diccionario);