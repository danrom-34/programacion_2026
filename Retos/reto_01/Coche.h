#ifndef COCHE_H
#define COCHE_H

#include <string>
#include "vehiculo.h"

class Coche : public Vehiculo {
private:
    int numeroPuertas;

public:
    Coche();
    Coche(std::string marca, std::string modelo, int anio, std::string placa, int numeroPuertas);

    void actualizarNumeroPuertas(int nuevoNumero);

    void mostrarInformacion();

    int obtenerNumeroPuertas();
};

#endif