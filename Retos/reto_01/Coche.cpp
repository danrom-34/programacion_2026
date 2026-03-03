#include "coche.h"
#include <iostream>

Coche::Coche() : Vehiculo() {
    numeroPuertas = 0;
}

Coche::Coche(std::string marca, std::string modelo, int anio, std::string placa, int numeroPuertas)
    : Vehiculo(marca, modelo, anio, placa) {
    this->numeroPuertas = numeroPuertas;
}

void Coche::actualizarNumeroPuertas(int nuevoNumero) {
    numeroPuertas = nuevoNumero;
}

void Coche::mostrarInformacion() {
    Vehiculo::mostrarInformacion();
    std::cout << "Número de puertas: " << numeroPuertas << std::endl;
}

int Coche::obtenerNumeroPuertas() {
    return numeroPuertas;
}