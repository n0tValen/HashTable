#include "Lista.h"
#include <iostream>

struct NodoBinario {
	void* item;
	NodoBinario* siguiente;
};

struct UndavLista::Lista {
	NodoBinario* primero;
	NodoBinario* ultimo;
	int cantidadItems;
};

NodoBinario* CrearUltimoNodo(void* item);


// O(1)
UndavLista::Lista* UndavLista::CrearListaVacia() {
	Lista* nuevaLista = new Lista;
	nuevaLista->primero = NULL;// Asignacion destructiva
	nuevaLista->ultimo = NULL;
	nuevaLista->cantidadItems = 0;
	return nuevaLista;
}

NodoBinario* CrearUltimoNodo(void* item) {
	NodoBinario* nuevoNodo = new NodoBinario;
	nuevoNodo->item = item;
	nuevoNodo->siguiente = NULL;
	return nuevoNodo;
}

bool UndavLista::EstaVacia(const Lista* lista) {
	return lista->cantidadItems == 0;
}

// O(N) -> O(1)
void UndavLista::AgregarAlFinal(Lista* lista, void* item) {
	NodoBinario* nuevoUltimo = CrearUltimoNodo(item);
	if (EstaVacia(lista)) {
		lista->primero = nuevoUltimo;
	}
	else {
		lista->ultimo->siguiente = nuevoUltimo;
	}
	lista->ultimo = nuevoUltimo;
	lista->cantidadItems++;
}

// O(1)
int UndavLista::ContarItems(const Lista* lista) {
	return lista->cantidadItems;
}

void UndavLista::Vaciar(Lista* lista) {
	NodoBinario* iterador = lista->primero;
	NodoBinario* auxiliar;
	while (iterador != NULL) {
		auxiliar = iterador;
		iterador = iterador->siguiente;
		delete auxiliar;
	}

	lista->cantidadItems = 0;
	lista->primero = lista->ultimo = NULL;
}

void UndavLista::Destuir(Lista* lista) {
	Vaciar(lista);
	delete lista;
}

struct UndavLista::UndavIteradorLista::IteradorLista {
	NodoBinario* nodoActual;
};

UndavLista::UndavIteradorLista::IteradorLista* UndavLista::UndavIteradorLista::Comienzo(Lista* lista) {
	IteradorLista* nuevoIterador = new IteradorLista;
	nuevoIterador->nodoActual = lista->primero;

	return nuevoIterador;
}

bool UndavLista::UndavIteradorLista::Fin(IteradorLista* iterador) {
	return iterador->nodoActual == NULL;
}

void* UndavLista::UndavIteradorLista::ObtenerItem(IteradorLista* iterador) {
	return iterador->nodoActual->item;
}

void UndavLista::UndavIteradorLista::Siguiente(IteradorLista* iterador) {
	iterador->nodoActual = iterador->nodoActual->siguiente;
}

void UndavLista::Map(Lista* lista, TipoFuncionMap funcionAplicacion) {
	NodoBinario* iterador = lista->primero;
	while (iterador != NULL) {
		funcionAplicacion(iterador->item);
		iterador = iterador->siguiente;
	}
}

void UndavLista::UndavIteradorLista::Destruir(IteradorLista* iterador){
	delete iterador;
}