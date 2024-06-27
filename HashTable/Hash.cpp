#include <iostream>
#include "Hash.h"
//incluir la libreria de "Card.h"

const int CapacidadInicial = 5;  //<<-- por la cantidad de las Cards que tenemos

//using namespace KanbanBoard::Card;
using namespace std;

using namespace KanbanBoardHashTable;

struct KanbanBoardHashTable::HashTable {
	//string* keys;
	//void* *Card;

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
