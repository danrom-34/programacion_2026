#ifndef VEHICULO_H
#define VEHICULO_H

#include <string>

class Vehiculo {
protected:
    std::string marca;
    std::string modelo;
    int anio;
    std::string placa;   // NUEVO ATRIBUTO

public:
    // Constructores
    Vehiculo();
    Vehiculo(std::string marca, std::string modelo, int anio, std::string placa);

    // Métodos para actualizar
    void actualizarMarca(std::string nuevaMarca);
    void actualizarModelo(std::string nuevoModelo);
    void actualizarAnio(int nuevoAnio);
    void actualizarPlaca(std::string nuevaPlaca);  // NUEVO MÉTODO

    // Método para mostrar
    void mostrarInformacion();

    // Getters
    std::string obtenerMarca();
    std::string obtenerModelo();
    int obtenerAnio();
    std::string obtenerPlaca();  // NUEVO GETTER
};

#endif