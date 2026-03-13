#include "figura.h"
#include <iostream>

Figura::Figura(std::string nombre){
this->nombre = nombre;
}
//Destructor
Figura::~Figura() {}

//Getters
std::string Figura::obtenerNombre() {
    return nombre;
}
