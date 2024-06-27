#pragma once
#include "Card.h"

using KanbanBoardCard::Card;

typedef Card* Item;
typedef KanbanBoardCard::GetId(item)* keys;

namespace KanbanBoardHashTable {
	struct  HashTable;

	HashTable* Create();

	void Add(HashTable* diccionario, int clave, void* valor);

	void* GetItems(HashTable* diccionario, int clave);


	bool Contiene(const HashTable* diccionario, int clave);
	int GetCount(const HashTable* diccionario);

	namespace Iterador {
		struct IteradorHashTable;
		IteradorHashTable* Comienzo(HashTable* diccionario);
		int ObtenerClave(IteradorHashTable* iterador);
		void* ObtenerValor(IteradorHashTable* iterador);
		bool EsFin(IteradorHashTable* iterador);
	}

	void Destroy(HashTable* diccionario);
}
