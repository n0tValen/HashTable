// Sinonimos de diccionario: Symbol Table, HashTable, MapSet, HashSet

namespace UndavDiccionario {
	struct Diccionario;

	Diccionario* Crear();


	void Agregar(Diccionario* diccionario, int clave, void* valor);
	
	void* Obtener(Diccionario* diccionario, int clave);


	bool Contiene(const Diccionario* diccionario, int clave);
	int ObtenerCantidadElementos(const Diccionario* diccionario);

	namespace UndavIterador {
		struct IteradorDiccionario;
		IteradorDiccionario* Comienzo(Diccionario* diccionario);
		int ObtenerClave(IteradorDiccionario* iterador);
		void* ObtenerValor(IteradorDiccionario* iterador);
		bool EsFin(IteradorDiccionario* iterador);
	}

	void Destruir(Diccionario* diccionario);
}
