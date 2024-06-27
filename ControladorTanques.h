#include "TanqueAgua.h"

using UndavTanqueAgua::TanqueAgua;

namespace UndavControladorTanques {
	struct ControladorTanques;

	ControladorTanques* Crear(int cantidadMaxima);

	// Busqueda
	TanqueAgua* ObtenerTanqueAgua(ControladorTanques* controlador, int idTanqueAgua);

	
	int ObtenerNivel(const ControladorTanques* controlador);
	int ObtenerCapacidadDisponible(const ControladorTanques* controlador);
	int ContarTanquesVacios(const ControladorTanques* controlador);
	int ContarTanques(const ControladorTanques* controlador);

	void Llenar(ControladorTanques* controlador);
	void Vaciar(ControladorTanques* controlador);
	
	void Agregar(ControladorTanques* controlador, TanqueAgua* tanque);
	void RemoverTanquesVacios(ControladorTanques* controlador);
	void RemoverTanquesLlenos(ControladorTanques* controlador);

	void Destuir(ControladorTanques* controlador);
}
