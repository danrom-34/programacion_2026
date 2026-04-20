#include <cstdlib>
#include <fstream>
#include <iostream>
#include <regex>
#include <string>
#include <cstdio>
#include <vector>
#include <cctype>
#include <algorithm> // Para transformar a minúsculas
#include <filesystem>
#include <chrono>
#include <iomanip>
#include <sstream>
#include <optional>
#include "Mensaje.h"
#include "Conversacion.h"

namespace {

static std::vector<std::string> dotenv_env_vars;

static std::string trim(const std::string& s) {
    size_t start = 0;
    while (start < s.size() && std::isspace(static_cast<unsigned char>(s[start]))) start++;
    size_t end = s.size();
    while (end > start && std::isspace(static_cast<unsigned char>(s[end - 1]))) end--;
    return s.substr(start, end - start);
}

static std::string remove_bom(const std::string& s) {
    if (s.size() >= 3 && static_cast<unsigned char>(s[0]) == 0xEF && static_cast<unsigned char>(s[1]) == 0xBB && static_cast<unsigned char>(s[2]) == 0xBF) {
        return s.substr(3);
    }
    return s;
}

static std::filesystem::path find_dotenv_path(const std::filesystem::path& start) {
    std::filesystem::path candidate = start / ".env";
    if (std::filesystem::exists(candidate)) return candidate;
    if (std::filesystem::exists(".env")) return std::filesystem::absolute(".env");
    if (start.has_parent_path()) {
        candidate = start.parent_path() / ".env";
        if (std::filesystem::exists(candidate)) return candidate;
    }
    return {};
}

void load_dotenv_file(const std::filesystem::path& path) {
    std::filesystem::path dotenv_path = find_dotenv_path(path);
    if (dotenv_path.empty()) return;
    std::ifstream dotenv_file(dotenv_path);
    if (!dotenv_file.is_open()) return;
    std::string line;
    while (std::getline(dotenv_file, line)) {
        line = remove_bom(line);
        line = trim(line);
        if (line.empty() || line[0] == '#') continue;
        if (line.rfind("export ", 0) == 0) {
            line = trim(line.substr(7));
        }
        size_t sep = line.find('=');
        if (sep == std::string::npos) continue;
        std::string key = trim(line.substr(0, sep));
        std::string val = trim(line.substr(sep + 1));
        if (key.empty() || key[0] == '#') continue;
        if (!val.empty() && (val.front() == '"' || val.front() == '\'')) val.erase(0, 1);
        if (!val.empty() && (val.back() == '"' || val.back() == '\'')) val.pop_back();
        dotenv_env_vars.push_back(key + "=" + val);
        _putenv(dotenv_env_vars.back().c_str());
    }
}

std::string clean_json_to_text(const std::string& json) {
    std::regex re("\"text\"\\s*:\\s*\"((?:\\\\.|[^\\\"])*)\"");
    std::smatch match;
    std::string result = "";
    auto words_begin = std::sregex_iterator(json.begin(), json.end(), re);
    auto words_end = std::sregex_iterator();
    for (std::sregex_iterator i = words_begin; i != words_end; ++i) {
        std::smatch m = *i;
        std::string part = m[1].str();
        size_t pos = 0;
        while ((pos = part.find("\\n", pos)) != std::string::npos) {
            part.replace(pos, 2, "\n");
            pos += 1;
        }
        pos = 0;
        while ((pos = part.find("\\\"", pos)) != std::string::npos) {
            part.replace(pos, 2, "\"");
            pos += 1;
        }
        result += part;
    }
    return result;
}

std::string request_gemini(const std::string& key, const std::string& model, const std::string& prompt) {
    std::string url = "https://generativelanguage.googleapis.com/v1beta/models/" + model + ":generateContent?key=" + key;
    std::string escaped = "";
    for(char c : prompt) {
        if(c == '"') escaped += "\\\"";
        else if(c == '\\') escaped += "\\\\";
        else if(c == '\n') escaped += "\\n";
        else if(c == '\r') continue;
        else escaped += c;
    }
    std::string payload = "{\\\"contents\\\":[{\\\"parts\\\":[{\\\"text\\\":\\\"" + escaped + "\\\"}]}]}";
    std::string cmd = "curl -s -L -X POST \"" + url + "\" -H \"Content-Type: application/json\" -d \"" + payload + "\"";
    std::string response;
    char buffer[512];
    FILE* pipe = _popen(cmd.c_str(), "r");
    if (!pipe) return "ERROR_SISTEMA";
    while (fgets(buffer, sizeof(buffer), pipe)) response += buffer;
    _pclose(pipe);
    return response;
}

} // namespace

int main(int argc, char* argv[]) {
    std::filesystem::path exe_path = std::filesystem::current_path();
    if (argc > 0) {
        std::filesystem::path path_arg(argv[0]);
        if (path_arg.has_parent_path()) {
            exe_path = path_arg.parent_path();
        }
    }
    load_dotenv_file(exe_path);
    std::filesystem::path dotenv_path = find_dotenv_path(exe_path);
    if (!dotenv_path.empty()) {
        std::cerr << "DEBUG: .env loaded from " << dotenv_path.string() << "\n";
    } else {
        std::cerr << "DEBUG: .env not found in " << exe_path.string() << "\n";
    }
    const char* api_key = std::getenv("GEMINI_API_KEY");
    std::filesystem::path save_folder = exe_path / "conversaciones";
    std::filesystem::create_directories(save_folder);

    if (!api_key) {
        std::cerr << "Error: No se encontro la API KEY.\n";
        return 1;
    }

    std::cout << "==========================================" << std::endl;
    std::cout << "   CHATBOT CON GEMINI 2.5 FLASH ACTIVADO   " << std::endl;
    std::cout << "   (Escribe 'fin, salir o exit' para salir)   " << std::endl;
    std::cout << "==========================================" << std::endl;

    std::string prompt;
    std::string modelo_a_usar = "gemini-2.5-flash";
    Conversacion conversacion(save_folder);

    // BUCLE INFINITO DE CONVERSACIÓN
    while (true) {
        std::cout << "\nTú: ";
        if (!std::getline(std::cin, prompt) || prompt.empty()) continue;

        // Comprobar si el usuario quiere terminar
        std::string check_exit = prompt;
        std::transform(check_exit.begin(), check_exit.end(), check_exit.begin(), ::tolower);
        if (check_exit == "fin" || check_exit == "salir" || check_exit == "exit") {
            std::cout << "\nGeminiIA: ¡Hasta luego! Suerte con tus estudios de C++.\n";
            break;
        }

        Mensaje mensaje(prompt);
        conversacion.guardarPrompt(mensaje);

        std::cout << "Obteniendo respuesta..."; // Indicador de carga simple

        std::string raw = request_gemini(api_key, modelo_a_usar, prompt);
        std::string final_text = clean_json_to_text(raw);

        if (!final_text.empty()) {
            mensaje.setRespuesta(final_text);
            conversacion.agregarMensaje(mensaje);
            conversacion.guardarRespuesta(mensaje);
            std::cout << "\rGeminiIA: " << final_text << "\n";
            std::cout << "------------------------------------------\n";
        } else {
            std::cout << "\nError en la respuesta. Reintenta.\n";
            if (raw.find("503") != std::string::npos) std::cout << "(Servidor saturado)\n";
        }
    }

    return 0;
}