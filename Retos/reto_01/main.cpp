#include <iostream>
#include "coche.h"
#include "moto.h"
#include "camion.h"
#include "autobus.h"

int main() {

    Coche coche("Toyota", "Corolla", 2020, "ABC123", 4);
    Moto moto("Yamaha", "R3", 2022, "XYZ789", 321);
    Camion camion("Volvo", "FH16", 2019, "TRK456", 18.5);
    Autobus autobus("Mercedes", "Sprinter", 2021, "BUS999", 20);

    std::cout << "=== INFORMACIÓN INICIAL ===\n";
    coche.mostrarInformacion();
    std::cout << std::endl;

    moto.mostrarInformacion();
    std::cout << std::endl;

    camion.mostrarInformacion();
    std::cout << std::endl;

    autobus.mostrarInformacion();
    std::cout << std::endl;

    // Cambio de placas
    coche.actualizarPlaca("NEW123");
    moto.actualizarPlaca("NEW789");

    std::cout << "\n=== DESPUÉS DE CAMBIAR PLACAS ===\n";
    coche.mostrarInformacion();
    std::cout << std::endl;

    moto.mostrarInformacion();

    return 0;
}
