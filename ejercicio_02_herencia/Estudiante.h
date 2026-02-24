#ifndef Gestion_H
#define Gestion_H
#include <string>


class Gestion{
    private:
    std::string nombre;
    std::string codigo;
    int edad;
    float promedio;
    bool activo;

    public:
    Gestion();
    Gestion(std::string nombre, std::string codigo, int edad, float promedio, bool activo);

    //Setters

    void actualizarNombre(std::string nuevoNombre);
    void actualizarCodigo(std::string nuevoCodigo);
    void actualizarEdad(int nuevaEdad);
    void actualizarPromedio(float nuevoPromedio);
    void actualizarActivo(bool nuevoEstado);

    //Getters

    std::string obtenerNombre();
    std::string obtenerCodigo();
    int obtenerEdad();
    float obtenerPromedio();
    bool obtenerActivo();

    //Metodo de visualizacion

    void mostrarNombre();
    void mostrarCodigo();
    void mostrarEdad();
    void mostrarPromedio();
    void mostrarActivo();
    void mostrarInformacionCompleta();

    //Metodos de Utilidad

    void incrementarEdad();
    void calcularEstadoAcademico();

};
#endif