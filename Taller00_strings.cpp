//Punto 8 
#include <iostream>
#include <string>
#include <cctype>

namespace CustomStringFunctions {

    int contarVocales(const std::string& str) {
        int contador = 0;
        for (char c : str) {
            if (std::tolower(c) == 'a' || std::tolower(c) == 'e' ||
                std::tolower(c) == 'i' || std::tolower(c) == 'o' ||
                std::tolower(c) == 'u') {
                contador++;
            }
        }
        return contador;
    }

    int contarDigitos(const std::string& str) {
        int contador = 0;
        for (char c : str) {
            if (std::isdigit(c)) {
                contador++;
            }
        }
        return contador;
    }

    std::string convertirAMinusculas(const std::string& str) {
        std::string resultado = str;
        for (char& c : resultado) {
            c = std::tolower(c);
        }
        return resultado;
    }

    void convertirAMinusculasModificando(std::string& str) {
        for (char& c : str) {
            c = std::tolower(c);
        }
    }

    void eliminarEspaciosEnBlanco(std::string& str) {
        std::string resultado;

        for (char c : str) {
            if (!std::isspace(c)) {
                resultado += c;
            }
        }

        str = resultado;
    }


    std::string generarAcronimo(const std::string& str) {
        std::string acronimo;
        bool nuevaPalabra = true;

        for (char c : str) {
            if (nuevaPalabra && std::isalpha(c)) {
                acronimo += std::toupper(c);
                nuevaPalabra = false;
            } else if (std::isspace(c)) {
                nuevaPalabra = true;
            }
        }

        return acronimo;
    }
}

int main() {
    using namespace CustomStringFunctions;
    std::string input;

    std::cout << "Ingrese una cadena de texto: ";
    std::getline(std::cin, input);

    int vocales = contarVocales(input);
    int digitos = contarDigitos(input);

    std::cout << "Número de vocales: " << vocales << std::endl;
    std::cout << "Número de dígitos: " << digitos << std::endl;

    std::string minusculas = convertirAMinusculas(input);
    std::cout << "Cadena en minúsculas: " << minusculas << std::endl;

    convertirAMinusculasModificando(input);
    std::cout << "Cadena modificada a minúsculas: " << input << std::endl;

    eliminarEspaciosEnBlanco(input);
    std::cout << "Cadena sin espacios en blanco: " << input << std::endl;

    std::string acronimo = generarAcronimo(input);
    std::cout << "Acrónimo: " << acronimo << std::endl;

    return 0;
}

