#include <iostream>
#include "TanqueAgua.h"

using namespace UndavTanqueAgua;
using namespace std;

struct UndavTanqueAgua::TanqueAgua {
    int nivel;
    int capacidad;
    int id;
};

int id = 100;

TanqueAgua* UndavTanqueAgua::CrearTanqueAguaVacio(int capacidad) {
    TanqueAgua* nuevoTanque = NULL;
    if (capacidad > 0) {
        nuevoTanque = new TanqueAgua;
        nuevoTanque->capacidad = capacidad;
        nuevoTanque->nivel = 0;
        nuevoTanque->id = id++;//Ponerle simpre un numero unico
    }

    return nuevoTanque;
}


TanqueAgua* UndavTanqueAgua::CrearTanqueAgua(int capacidad, int nivel) {
    TanqueAgua* nuevoTanque = CrearTanqueAguaVacio(capacidad);
    if (nuevoTanque != NULL) {
        AgregarNivel(nuevoTanque, nivel);
    }

    return nuevoTanque;
}

int UndavTanqueAgua::ObtenerId(const TanqueAgua* tanque) {
    return tanque->id;
}

int UndavTanqueAgua::ObtenerCaudalDisponible(const TanqueAgua* tanque) {
    int caudalDisponible = tanque->capacidad - tanque->nivel;
    return caudalDisponible;
}

int UndavTanqueAgua::ObtenerNivel(const TanqueAgua* tanque) {
    return tanque->nivel;
}

int UndavTanqueAgua::ObtenerCapacidad(const TanqueAgua* tanque) {
    return tanque->capacidad;
}

void UndavTanqueAgua::LlenarTanque(TanqueAgua* tanque) {
    tanque->nivel = tanque->capacidad;
}

void UndavTanqueAgua::VaciarTanque(TanqueAgua* tanque) {
    tanque->nivel = 0;
}

void UndavTanqueAgua::AgregarNivel(TanqueAgua* tanque, int nivel) {
    if (tanque->nivel + nivel <= tanque->capacidad) {
        tanque->nivel += nivel;
    }
}

void UndavTanqueAgua::SacarNivel(TanqueAgua* tanque, int nivel) {
    if (tanque->nivel - nivel >= 0) {
        tanque->nivel -= nivel;
    }
}

bool UndavTanqueAgua::TanqueVacio(const TanqueAgua* tanque) {
    return tanque->nivel == 0;
}

void UndavTanqueAgua::Destruir(TanqueAgua* tanque) {
    delete tanque;
}