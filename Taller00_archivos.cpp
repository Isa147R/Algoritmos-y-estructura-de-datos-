#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream inputFile("input_file.txt");
    std::ofstream outputFile("output_file.txt");

    if (!inputFile || !outputFile) {
        std::cerr << "Error al abrir los archivos." << std::endl;
        return 1;
    }

    double valor;
    int contadorMayores = 0;

    while (inputFile >> valor) {
        if (valor > 100.0) {
            contadorMayores++;
        }
    }

    std::cout << "Número de datos mayores a 100.0: " << contadorMayores << std::endl;
    outputFile << "Número de datos mayores a 100.0: " << contadorMayores << std::endl;

    inputFile.close();
    outputFile.close();

    std::cout << "Resultado almacenado en 'output_file.txt'." << std::endl;

    return 0;
}
