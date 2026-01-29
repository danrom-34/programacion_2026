E#include <stdio.h>
#include <string.h>

#define MAX_ESTUDIANTES 50

// ===== ESTRUCTURA =====
struct Estudiante {
    char nombre[100];
    char codigo[20];
    int edad;
    float promedio;
    int activo; // 1 = activo, 0 = inactivo
};

// ===== VARIABLES GLOBALES =====
struct Estudiante estudiantes[MAX_ESTUDIANTES];
int totalEstudiantes = 0;

// ===== FUNCIONES DE ACTUALIZACIÓN =====
void actualizarNombre(struct Estudiante *e, char nuevoNombre[]) {
    strcpy(e->nombre, nuevoNombre);
}

void actualizarCodigo(struct Estudiante *e, char nuevoCodigo[]) {
    strcpy(e->codigo, nuevoCodigo);
}

void actualizarEdad(struct Estudiante *e, int nuevaEdad) {
    e->edad = nuevaEdad;
}

void actualizarPromedio(struct Estudiante *e, float nuevoPromedio) {
    if (nuevoPromedio >= 0.0 && nuevoPromedio <= 10.0) {
        e->promedio = nuevoPromedio;
    } else {
        printf("Promedio inválido\n");
    }
}

void actualizarActivo(struct Estudiante *e, int nuevoEstado) {
    e->activo = nuevoEstado;
}

// ===== FUNCIONES DE VISUALIZACIÓN =====
void mostrarNombre(struct Estudiante e) {
    printf("Nombre: %s\n", e.nombre);
}

void mostrarCodigo(struct Estudiante e) {
    printf("Código: %s\n", e.codigo);
}

void mostrarEdad(struct Estudiante e) {
    printf("Edad: %d años\n", e.edad);
}

void mostrarPromedio(struct Estudiante e) {
    printf("Promedio: %.2f\n", e.promedio);
}

void mostrarActivo(struct Estudiante e) {
    if (e.activo)
        printf("Estado: Activo\n");
    else
        printf("Estado: Inactivo\n");
}

void mostrarInformacionCompleta(struct Estudiante e) {
    mostrarNombre(e);
    mostrarCodigo(e);
    mostrarEdad(e);
    mostrarPromedio(e);
    mostrarActivo(e);
}

// ===== FUNCIONES DEL MENÚ =====
void agregarEstudiante() {
    struct Estudiante e;

    printf("Nombre: ");
    getchar(); 
    fgets(e.nombre, 100, stdin);
    e.nombre[strcspn(e.nombre, "\n")] = 0;

    printf("Código: ");
    fgets(e.codigo, 20, stdin);
    e.codigo[strcspn(e.codigo, "\n")] = 0;

    printf("Edad: ");
    scanf("%d", &e.edad);

    printf("Promedio: ");
    scanf("%f", &e.promedio);

    printf("Activo (1 = sí, 0 = no): ");
    scanf("%d", &e.activo);

    estudiantes[totalEstudiantes] = e;
    totalEstudiantes++;

    printf("Estudiante agregado correctamente\n");
}

void mostrarEstudiantePorCodigo() {
    char codigoBuscado[20];
    int encontrado = 0;

    printf("Ingrese el código del estudiante: ");
    getchar();
    fgets(codigoBuscado, 20, stdin);
    codigoBuscado[strcspn(codigoBuscado, "\n")] = 0;

    for (int i = 0; i < totalEstudiantes; i++) {
        if (strcmp(estudiantes[i].codigo, codigoBuscado) == 0) {
            mostrarInformacionCompleta(estudiantes[i]);
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("Estudiante no encontrado\n");
    }
}

void mostrarTodos() {
    for (int i = 0; i < totalEstudiantes; i++) {
        printf("\nEstudiante %d\n", i + 1);
        mostrarInformacionCompleta(estudiantes[i]);
    }
}

// ===== MAIN =====
int main() {
    int opcion;

    while (1) {
        printf("\n===== MENÚ =====\n");
        printf("1. Agregar estudiante\n");
        printf("2. Mostrar estudiante por código\n");
        printf("3. Mostrar todos los estudiantes\n");
        printf("4. Salir\n");
        printf("Opción: ");
        scanf("%d", &opcion);

        if (opcion == 4) {
            printf("Saliendo...\n");
            break;
        }

        switch (opcion) {
            case 1:
                agregarEstudiante();
                break;
            case 2:
                mostrarEstudiantePorCodigo();
                break;
            case 3:
                mostrarTodos();
                break;
            default:
                printf("Opción inválida\n");
        }
    }

    return 0;
}
