#include "TanqueAgua.h"

using UndavTanqueAgua::TanqueAgua;

typedef TanqueAgua* Item;
#define Clave(item) (UndavTanqueAgua::ObtenerId(item)) // Definimos que la clave de ordenamiento es el valor de la carta en el truco
#define EsMenor(itemA, itemB) (Clave(itemA)<Clave(itemB))
#define EsMayor(itemA, itemB) (Clave(itemA)>Clave(itemB))
#define Intercambiar(itemA, itemB) {Item aux = itemA; itemA = itemB; itemB = aux;}
#define SiEsMayorIntercambiar(itemA, itemB) {if(!EsMenor(itemA,itemB)) Intercambiar(itemA,itemB)}
#define SiEsMenorIntercambiar(itemA, itemB) {if(EsMenor(itemA,itemB)) Intercambiar(itemA,itemB)}