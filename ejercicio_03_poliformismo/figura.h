#ifndef FIGURA_H
#define FIGURA_H

#include <string>

class Figura {
    protected:
    std::string nombre;
    public:
    Figura(std::string nombre);
    virtual ~Figura();

    //Funcioines viruales
    virtual double calcularArea() = 0;
    virtual void describir() = 0;
     //Getters
     std::string obtenerNombre();
};
#endif
