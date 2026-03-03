#ifndef CAMION_H
#define CAMION_H

#include "vehiculo.h"

class Camion : public Vehiculo {
private:
    double capacidadCarga;

public:
    Camion();
    Camion(std::string marca, std::string modelo, int anio, std::string placa, double capacidadCarga);

    void mostrarInformacion();
};

#endif
