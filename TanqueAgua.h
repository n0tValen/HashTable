//TDA:  TipoDatoAbstracto (ADT abstract data type)
namespace UndavTanqueAgua {
    struct TanqueAgua;

    // Primitivas creacionales
    TanqueAgua* CrearTanqueAguaVacio(int capacidad);
    TanqueAgua* CrearTanqueAguaLleno(int capacidad);
    TanqueAgua* CrearTanqueAgua(int capacidad, int nivel);
    
    // Primitivas generales
    int ObtenerId(const TanqueAgua* tanque);
    int ObtenerNivel(const TanqueAgua* tanque);
    int ObtenerCapacidad(const TanqueAgua* tanque);
    void LlenarTanque(TanqueAgua* tanque);
    void VaciarTanque(TanqueAgua* tanque);
    void AgregarNivel(TanqueAgua* tanque, int nivel);
    void SacarNivel(TanqueAgua* tanque, int caudal);
    bool TanqueVacio(const TanqueAgua* tanque);
    int ObtenerCaudalDisponible(const TanqueAgua* tanque);

    // Destruir
    void Destruir(TanqueAgua* tanque);
}

