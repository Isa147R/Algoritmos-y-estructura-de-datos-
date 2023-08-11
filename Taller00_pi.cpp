#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>

int main() {
    std::ofstream outputFile("compute_pi.dat");

    if (!outputFile) {
        std::cerr << "Error al abrir el archivo." << std::endl;
        return 1;
    }

    outputFile << std::setw(10) << "Términos" << std::setw(20) << "Aproximación" << std::setw(20) << "Diferencia" << std::endl;

    double pi_acos = std::acos(-1.0);
    double suma = 0.0;
    int numTerminos;

    for (int x = 1; x <= 9; ++x) {
        numTerminos = 10 * x;

        suma = 0.0;
        for (int i = 0; i < numTerminos; ++i) {
            suma += (i % 2 == 0 ? 1.0 : -1.0) * (1.0 / (2 * i + 1));
        }

        double diferencia = std::abs(suma - pi_acos);

        outputFile << std::setw(10) << numTerminos << std::setw(20) << suma << std::setw(20) << diferencia << std::endl;
    }

    outputFile.close();

    std::cout << "Tabla generada y escrita en 'compute_pi.dat'." << std::endl;

    return 0;
}
