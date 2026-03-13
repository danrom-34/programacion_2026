#include "rectangulo.h"
#include <iostream>

Rectangulo::Rectangulo(std::string nombre, double base, double altura)
: Figura(nombre){
    this-> base = base;
    this-> altura = altura;
}

double Rectangulo::calcularArea(){
    return base * altura;
}

void Rectangulo::describir(){
    std::cout << "La base del Rectangulo es: " << base << ", y su altura es: " << altura << std::endl;
}

double Rectangulo::obtenerBase(){
    return base;
}

double Rectangulo::obtenerAltura(){
    return altura;
}