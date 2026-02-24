#ifndef EMPLEADO_TIEMPO_COMPLETO_H
#define EMPLEADO_TIEMPO_COMPLETO_H

#include "empleado.h"

class EmpleadoTiempoCompleto : public Empleado {
private:
    int horasSemanales;
    float bono;

public:
    // Constructores
    EmpleadoTiempoCompleto();
    EmpleadoTiempoCompleto(std::string nombre, std::string id, float salarioBase,
                           int horasSemanales, float bono);

    // Setters
    void actualizarHorasSemanales(int horasSemanales);
    void actualizarBono(float bono);

    // Getters
    int obtenerHorasSemanales() const;
    float obtenerBono() const;

    // Métodos
    void mostrarInformacion() const override;
    float calcularSalarioTotal() const;
};

#endif
