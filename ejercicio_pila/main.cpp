#include "custom_stack.h"
#include "custom_stack.cpp"
#include <iostream>

int main() {
    CustomStack mi_pila;
    mi_pila.push(1);
    mi_pila.push(2);
    mi_pila.push(3);
    std::cout<<"tamanio de la pila es: "<< mi_pila.size()<< std::endl;
    mi_pila.pop();
    std::cout<<"Se a eliminado un valor, ahora el tamanio de la pila es: "<< mi_pila.size()<< std::endl;
    std::cout<<"El ultimo valor ingresado es: "<<mi_pila.top()<<std::endl;

    return 0;
}