#include "Conversacion.h"

Conversacion::Conversacion(std::filesystem::path carpeta)
    : folder(std::move(carpeta)) {
    std::filesystem::create_directories(folder);
}

void Conversacion::agregarMensaje(const Mensaje& mensaje) {
    mensajes.push_back(mensaje);
}

void Conversacion::guardarPrompt(const Mensaje& mensaje) const {
    mensaje.guardarPrompt(folder);
}

void Conversacion::guardarRespuesta(const Mensaje& mensaje) const {
    mensaje.guardarRespuesta(folder);
}

void Conversacion::guardar(const Mensaje& mensaje) const {
    mensaje.guardar(folder);
}
