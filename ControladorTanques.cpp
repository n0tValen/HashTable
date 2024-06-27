#include "ControladorTanques.h"
#include "TanqueAgua.h"
#include "Lista.h"
#include <iostream>

using namespace UndavLista;

struct UndavControladorTanques::ControladorTanques {
	int cantidadMaxima;
	Lista* tanques;
};

void LlenarTanque(void* tanque);
void VaciarTanque(void* tanque);


UndavControladorTanques::ControladorTanques* UndavControladorTanques::Crear(int cantidadMaxima) {
	ControladorTanques* nuevoControlador = new ControladorTanques;
	nuevoControlador->cantidadMaxima = cantidadMaxima;
	nuevoControlador->tanques = CrearListaVacia();

	return nuevoControlador;
}

void UndavControladorTanques::Agregar(ControladorTanques* controlador, TanqueAgua* tanque) {
	if (ContarItems(controlador->tanques) < controlador->cantidadMaxima){
		UndavLista::AgregarAlFinal(controlador->tanques, tanque);
	}
}

int UndavControladorTanques::ObtenerNivel(const ControladorTanques* controlador) {
	int nivelTotal = 0;
	UndavIteradorLista::IteradorLista* iterador = UndavIteradorLista::Comienzo(controlador->tanques);
	while (UndavIteradorLista::Fin(iterador)) {
		TanqueAgua* tanqueAgua = (TanqueAgua*)UndavIteradorLista::ObtenerItem(iterador);
		nivelTotal += UndavTanqueAgua::ObtenerNivel(tanqueAgua);
		UndavIteradorLista::Siguiente(iterador);
	}
	UndavIteradorLista::Destruir(iterador);

	return nivelTotal;
}

// Esta firma es compatible con la requerida en la funcion Map
void LlenarTanque(void* tanque) {
	UndavTanqueAgua::LlenarTanque((UndavTanqueAgua::TanqueAgua*)tanque);
}

// Vaciar 
void VaciarTanque(void* tanque) {
	UndavTanqueAgua::VaciarTanque((UndavTanqueAgua::TanqueAgua*)tanque);
}

void UndavControladorTanques::Llenar(ControladorTanques* controlador) {
	UndavLista::Map(controlador->tanques, LlenarTanque);
}

void UndavControladorTanques::Vaciar(ControladorTanques* controlador) {
	UndavLista::Map(controlador->tanques, VaciarTanque);
}


// Busqueda secuencial O(N)
TanqueAgua* UndavControladorTanques::ObtenerTanqueAgua(ControladorTanques* controlador, int idTanqueAgua) {
	UndavIteradorLista::IteradorLista* iterador = UndavIteradorLista::Comienzo(controlador->tanques);
	bool encontrado = false;
	TanqueAgua* tanqueAguaBuscado = NULL;
	while (!UndavIteradorLista::Fin(iterador) && !encontrado) {
		TanqueAgua* tanqueAgua = (TanqueAgua*)UndavIteradorLista::ObtenerItem(iterador);
		if (UndavTanqueAgua::ObtenerId(tanqueAgua) == idTanqueAgua) {
			tanqueAguaBuscado = tanqueAgua;
			encontrado = true;
		}
		UndavIteradorLista::Siguiente(iterador);
	}
	UndavIteradorLista::Destruir(iterador);

	return tanqueAguaBuscado;
}


// MAP es una funcion de alto orden (esto lo van a ver en la materia que viene en el paradigma de programacion funcional)