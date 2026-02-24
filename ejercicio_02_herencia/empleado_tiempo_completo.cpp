#include "empleado_tiempo_completo.h"
#include <iostream>

// Constructor por defecto
EmpleadoTiempoCompleto::EmpleadoTiempoCompleto()
    : Empleado(), horasSemanales(0), bono(0.0f) {}

// Constructor con parámetros
EmpleadoTiempoCompleto::EmpleadoTiempoCompleto(std::string nombre, std::string id,
                                               float salarioBase, int horasSemanales,
                                               float bono)
    : Empleado(nombre, id, salarioBase) {
    this->horasSemanales = horasSemanales;
    this->bono = bono;
}

// Setters
void EmpleadoTiempoCompleto::actualizarHorasSemanales(int horasSemanales) {
    this->horasSemanales = horasSemanales;
}

void EmpleadoTiempoCompleto::actualizarBono(float bono) {
    this->bono = bono;
}

// Getters
int EmpleadoTiempoCompleto::obtenerHorasSemanales() const {
    return horasSemanales;
}

float EmpleadoTiempoCompleto::obtenerBono() const {
    return bono;
}

// Mostrar información
void EmpleadoTiempoCompleto::mostrarInformacion() const {
    Empleado::mostrarInformacion();
    std::cout << "Horas semanales: " << horasSemanales << std::endl;
    std::cout << "Bono: " << bono << std::endl;
}

// Calcular salario total
float EmpleadoTiempoCompleto::calcularSalarioTotal() const {
    return salarioBase + bono;
}
