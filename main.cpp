#include <iostream>
#include "Diccionario.h"
#include "TanqueAgua.h"
#include "GeneradorTanquesAgua.h"
#include "Sort.h"

using namespace UndavGeneradorTanquesAgua;
using UndavTanqueAgua::TanqueAgua;

typedef TanqueAgua* Item;
typedef Item* Conjunto;

bool SubconjuntoEstaIncluido(Conjunto conjunto, 
	Conjunto SubConjunto, 
	int cardinalidadConjunto, 
	int cardinalidadSubconjunto);

// O(N)
bool Contiene(Conjunto conjunto, Item item, int cardinalidadConjunto);
void MostarConjunto(Conjunto conjunto, int cantidadItems);

int main()
{
	int n = 20;
	int m = 10;
	Conjunto a = UndavGeneradorTanquesAgua::GenerarTanques(n);
	UndavSorting::Mezclar(a, n);
	Conjunto b = UndavGeneradorTanquesAgua::ObtenerSubconjunto(a, m);
	MostarConjunto(a, n);
	std::cout << std::endl;
	MostarConjunto(b, m);
}


// n log(n) * c1 + m log(m) *c1 +
// ---- O(2nlog(n)) + O(n) 
// Complejidad temporal: O(2nlog(n))
// Complejidad espacial: O(1) -> inplace
bool SubconjuntoEstaIncluido(Conjunto conjunto,
	Conjunto subConjunto,
	int cardinalidadConjunto,
	int cardinalidadSubconjunto) {

	if (cardinalidadSubconjunto > cardinalidadConjunto) return false;
	UndavSorting::Ordenar(conjunto, 0, cardinalidadConjunto - 1);
	UndavSorting::Ordenar(subConjunto, 0, cardinalidadSubconjunto - 1);
	// Procesamiento Secuencial teniendo en cuenta que estan ordenados
}

// O(N*N)
bool SubconjuntoEstaIncluido2(Conjunto conjunto,
	Conjunto subConjunto,
	int cardinalidadConjunto,
	int cardinalidadSubconjunto) {

	if (cardinalidadSubconjunto > cardinalidadConjunto) return false;
	bool estaContenido = true;
	for (int i = 0; i < cardinalidadSubconjunto && estaContenido;++i) {
		estaContenido = Contiene(conjunto, subConjunto[i], cardinalidadConjunto);
	}

	return estaContenido;
}


//Diccionario basado en lista  
// ci (n*n + m * n)
// O(N*N)

//Diccionario basado en binary search  
// ci (n log(n) + n log(n))


// Diccionario basado en HashSet
// ci * n + ci * m  O(N)
// Complejidad espacial: O(n)
// 

bool SubconjuntoEstaIncluido3(Conjunto conjunto,
	Conjunto subConjunto,
	int cardinalidadConjunto,
	int cardinalidadSubconjunto) {
	UndavDiccionario::Diccionario* diccionario = UndavDiccionario::Crear();
	
	for (int i = 0; i < cardinalidadConjunto;++i) {
		UndavTanqueAgua::TanqueAgua* valor = conjunto[i];
		int clave = UndavTanqueAgua::ObtenerId(valor);
		UndavDiccionario::Agregar(diccionario, clave, valor);
	}
	
	bool estaIncluido = true;
	for (int i = 0; i < cardinalidadConjunto;++i) {
		UndavTanqueAgua::TanqueAgua* valorABuscar = subConjunto[i];
		int clave = UndavTanqueAgua::ObtenerId(valorABuscar);
		estaIncluido = UndavDiccionario::Contiene(diccionario, clave);
	}

	return estaIncluido;
}


// f(k) --- Busqueda es interna o externa
//      --- Estatico o dinamico
//      --- Utiliza directamente la clave (Actual Key) o realiza una transformacion de la clave

// Un diccionario es una generalizacion de un vector

// v[i] ->>> Aleatorio -----> O(1)
// - el indice
// -
// v[k] ----> Aleatorio -----> O(1)


// Hashing en criollo ---> Es una funcion F(x) -> y,  
// f(k) ->> Una direccion de memoria en donde esta el item buscado

// texto "DASDASDSSEWEQSQWEERFFGR^%^&^$FDXXDEXCVERSXCBTTYNNBFTEWE#@"
// Buscar la letra/caracter que aparece mas veces
//

void MostarConjunto(Conjunto conjunto, int cantidadItems) {
	for (int i = 0; i < cantidadItems;++i) {
		std::cout<<UndavTanqueAgua::ObtenerId(conjunto[i])<<","<<UndavTanqueAgua::ObtenerCapacidad(conjunto[i])<<","<<UndavTanqueAgua::ObtenerNivel(conjunto[i])<<std::endl;
	}
}


bool Contiene(Conjunto conjunto, Item item, int cardinalidadConjunto) {
	return false;
}