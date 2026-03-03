#include "autobus.h"
#include <iostream>

Autobus::Autobus() : Vehiculo() {
    numeroPasajeros = 0;
}

Autobus::Autobus(std::string marca, std::string modelo, int anio, std::string placa, int numeroPasajeros)
    : Vehiculo(marca, modelo, anio, placa) {
    this->numeroPasajeros = numeroPasajeros;
}

void Autobus::mostrarInformacion() {
    Vehiculo::mostrarInformacion();
    std::cout << "Número de pasajeros: " << numeroPasajeros << std::endl;
}
