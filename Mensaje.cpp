#include "Mensaje.h"
#include <fstream>
#include <iomanip>
#include <sstream>

Mensaje::Mensaje(std::string promptText)
    : prompt(std::move(promptText)),
      promptTime(std::chrono::system_clock::now()) {}

void Mensaje::setRespuesta(std::string respuestaText) {
    respuesta = std::move(respuestaText);
    respuestaTime = std::chrono::system_clock::now();
}

const std::string& Mensaje::getPrompt() const {
    return prompt;
}

const std::string& Mensaje::getRespuesta() const {
    return respuesta;
}

std::string Mensaje::promptFecha() const {
    return formatTime(promptTime);
}

std::string Mensaje::respuestaFecha() const {
    return respuestaTime ? formatTime(*respuestaTime) : std::string();
}

std::string Mensaje::toString() const {
    std::ostringstream out;
    out << "PROMPT (" << promptFecha() << "): " << prompt << "\n";
    if (!respuesta.empty()) {
        out << "RESPUESTA (" << respuestaFecha() << "): " << respuesta << "\n";
    }
    return out.str();
}

void Mensaje::guardarPrompt(const std::filesystem::path& folder) const {
    guardarArchivo(folder, "prompt_");
}

void Mensaje::guardarRespuesta(const std::filesystem::path& folder) const {
    if (respuesta.empty()) return;
    guardarArchivo(folder, "respuesta_");
}

void Mensaje::guardar(const std::filesystem::path& folder) const {
    guardarArchivo(folder, "mensaje_");
}

std::string Mensaje::formatTime(const std::chrono::system_clock::time_point& tp) {
    std::time_t t = std::chrono::system_clock::to_time_t(tp);
    std::tm tm;
#if defined(_WIN32)
    localtime_s(&tm, &t);
#else
    localtime_r(&t, &tm);
#endif
    std::ostringstream ss;
    ss << std::put_time(&tm, "%Y-%m-%d_%H-%M-%S");
    return ss.str();
}

void Mensaje::guardarArchivo(const std::filesystem::path& folder, const std::string& prefix) const {
    std::filesystem::create_directories(folder);
    std::string filename = prefix + formatTime(promptTime) + ".txt";
    std::filesystem::path filePath = folder / filename;
    std::ofstream file(filePath);
    if (!file.is_open()) return;
    if (prefix == "prompt_") {
        file << "PROMPT: " << prompt << "\n";
        file << "FECHA_PROMPT: " << promptFecha() << "\n";
    } else if (prefix == "respuesta_") {
        file << "PROMPT: " << prompt << "\n";
        file << "FECHA_PROMPT: " << promptFecha() << "\n";
        file << "RESPUESTA: " << respuesta << "\n";
        file << "FECHA_RESPUESTA: " << respuestaFecha() << "\n";
    } else {
        file << toString();
    }
}
