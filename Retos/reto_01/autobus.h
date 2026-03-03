#ifndef AUTOBUS_H
#define AUTOBUS_H

#include "vehiculo.h"

class Autobus : public Vehiculo {
private:
    int numeroPasajeros;

public:
    Autobus();
    Autobus(std::string marca, std::string modelo, int anio, std::string placa, int numeroPasajeros);

    void mostrarInformacion();
};

#endif
