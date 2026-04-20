#pragma once

#include <chrono>
#include <filesystem>
#include <optional>
#include <string>

class Mensaje {
public:
    Mensaje(std::string promptText);

    void setRespuesta(std::string respuestaText);

    const std::string& getPrompt() const;
    const std::string& getRespuesta() const;

    std::string promptFecha() const;
    std::string respuestaFecha() const;
    std::string toString() const;

    void guardarPrompt(const std::filesystem::path& folder) const;
    void guardarRespuesta(const std::filesystem::path& folder) const;
    void guardar(const std::filesystem::path& folder) const;

private:
    static std::string formatTime(const std::chrono::system_clock::time_point& tp);
    void guardarArchivo(const std::filesystem::path& folder, const std::string& prefix) const;

    std::string prompt;
    std::chrono::system_clock::time_point promptTime;
    std::string respuesta;
    std::optional<std::chrono::system_clock::time_point> respuestaTime;
};
