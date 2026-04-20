#pragma once

#include <filesystem>
#include <vector>
#include "Mensaje.h"

class Conversacion {
public:
    explicit Conversacion(std::filesystem::path carpeta = "conversacion");

    void agregarMensaje(const Mensaje& mensaje);
    void guardarPrompt(const Mensaje& mensaje) const;
    void guardarRespuesta(const Mensaje& mensaje) const;
    void guardar(const Mensaje& mensaje) const;

private:
    std::filesystem::path folder;
    std::vector<Mensaje> mensajes;
};
