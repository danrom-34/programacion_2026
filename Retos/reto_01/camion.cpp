#include "camion.h"
#include <iostream>

Camion::Camion() : Vehiculo() {
    capacidadCarga = 0;
}

Camion::Camion(std::string marca, std::string modelo, int anio, std::string placa, double capacidadCarga)
    : Vehiculo(marca, modelo, anio, placa) {
    this->capacidadCarga = capacidadCarga;
}

void Camion::mostrarInformacion() {
    Vehiculo::mostrarInformacion();
    std::cout << "Capacidad de carga: " << capacidadCarga << " toneladas" << std::endl;
}
