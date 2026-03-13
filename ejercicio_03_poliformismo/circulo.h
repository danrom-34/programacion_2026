#ifndef CIRCULO_H
#define CIRCULO_H

#include "figura.h"
#include <string>

class Circulo: public Figura{
    private:
    double radio;
    
    public:
    Circulo(std::string nombre, double radio);
    
    //Metodos
    double calcularArea() override;
    void describir() override;
    
    //Getters
    double obtenerRadio();
};

#endif