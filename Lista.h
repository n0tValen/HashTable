namespace UndavLista {
	struct Lista;

	typedef void (*TipoFuncionMap)(void* item);

	Lista* CrearListaVacia();

	// Consulta
	bool EstaVacia(const Lista* lista);
	int ContarItems(const Lista* lista);

	// Agregado
	void AgregarAlComienzo(Lista* lista, void* item);
	void AgregarAlFinal(Lista* lista, void* item);
	void AgregarRango(Lista* lista, Lista* items);
	void AgregarRango(Lista* lista, void** items, int cantidadItems);
	
	// Quitar
	void Vaciar(Lista* lista);
	void QuitarPrimero(Lista* lista);
	void QuitarUltimo(Lista* lista);
	// Quitar un item intermedio

	namespace UndavIteradorLista {
		struct IteradorLista;
		IteradorLista* Comienzo(Lista* lista);
		bool Fin(IteradorLista* iterador);
		void* ObtenerItem(IteradorLista* iterador);
		void Siguiente(IteradorLista* iterador);
		void Destruir(IteradorLista* iterador);
	}

	void Reversa(Lista* lista);

	void Map(Lista* lista, TipoFuncionMap funcionAplicacion);

	void Destuir(Lista* lista);
}