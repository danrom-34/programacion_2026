// Polimorfismo en C++

#include <iostream>
#include <string>
#include <cstdlib> // Para system("pause")
using namespace std;

class Persona {
private:
    string nombre;
    int edad;
public:
    Persona(string, int);
    virtual void mostrar();
};

class Alumno : public Persona {
private:
    float notaFinal;
public:
    Alumno(string, int, float);
    void mostrar();
};

class Profesor : public Persona {
private:
    string materia;
public:
    Profesor(string, int, string);
    void mostrar();
};

Persona::Persona(string _nombre, int _edad) {
    nombre = _nombre;
    edad = _edad;
}

void Persona::mostrar() {
    cout << "Nombre: " << nombre << endl;
    cout << "Edad: " << edad << endl;
}

Alumno::Alumno(string _nombre, int _edad, float _notaFinal) : Persona(_nombre, _edad) {
    notaFinal = _notaFinal;
}

void Alumno::mostrar() {
    Persona::mostrar();
    cout << "Nota Final: " << notaFinal << endl;
}

Profesor::Profesor(string _nombre, int _edad, string _materia) : Persona(_nombre, _edad) {
    materia = _materia;
}

void Profesor::mostrar() {
    Persona::mostrar();
    cout << "Materia: " << materia << endl;
}

int main() {
    Persona* personas[3];

    personas[0] = new Alumno("Alejandro", 20, 18.9f);
    personas[1] = new Alumno("Maria", 19, 15.5f);
    personas[2] = new Profesor("Jose", 25, "Algoritmos");

    personas[0]->mostrar();
    cout << "\n";
    personas[1]->mostrar();
    cout << "\n";
    personas[2]->mostrar();

    // Liberar memoria
    for (int i = 0; i < 3; i++) {
        delete personas[i];
    }

    system("pause");
    return 0;
}