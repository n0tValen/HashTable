#include <iostream>
#include "Hash.h"
#include "Card.h"

const int CapacidadInicial = 5;  //<<-- por la cantidad de las Cards que tenemos

using namespace KanbanBoardCard::Card;
using namespace std;
using namespace KanbanBoardHashTable;

struct KanbanBoardHashTable::HashTable {
	Item* valores; //cada item es una Card* 

	int capacidad;
	int cantItems;
};

KanbanBoardHashTable::HashTable* KanbanBoardHashTable::Create() {
	HashTable* newHashtable = new HashTable;
	newHashtable->cantItems = 0;
	newHashtable->capacidad = CapacidadInicial;
	newHashtable->keys = new int[CapacidadInicial];
	newHashtable->
}
