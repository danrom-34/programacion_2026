#ifndef RECTANGULO_H
#define RECTANGULO_H

#include "figura.h"
#include <string>

class Rectangulo: public Figura{
    private:
    double base;
    double altura;

    public:
    Rectangulo(std::string nombre, double base, double altura);

    //Metodos
    double calcularArea() override;
    void describir() override;

    //getters
    double obtenerBase();
    double obtenerAltura();
};

#endif