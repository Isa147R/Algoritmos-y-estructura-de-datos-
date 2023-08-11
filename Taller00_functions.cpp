//Punto 5 
#include <iostream>
#include <cctype> // Incluimos esta biblioteca para usar la función std::isalpha

bool esConsonante(char letra) {
    letra = std::tolower(letra); // Convertimos la letra a minúscula para manejar ambos casos

    if (std::isalpha(letra)) {
        // Verificamos si la letra no es una vocal (a, e, i, o, u)
        if (letra != 'a' && letra != 'e' && letra != 'i' && letra != 'o' && letra != 'u') {
            return true; // La letra es una consonante
        }
    }
    
    return false; // La letra no es una consonante o no es una letra válida
}

int main() {
    char letra;

    std::cout << "Ingrese una letra: ";
    std::cin >> letra;

    if (esConsonante(letra)) {
        std::cout << "La letra ingresada es una consonante." << std::endl;
    } else {
        std::cout << "La letra ingresada no es una consonante." << std::endl;
    }

    return 0;
}

//Punto 6
#include <iostream>

unsigned long long calcularCombinaciones(int n, int k) {
    if (k < 0 || k > n) {
        return 0; // Si k no está en el rango válido, el resultado es 0
    }

    unsigned long long numerador = 1;
    unsigned long long denominador = 1;

    // Calculamos el factorial del numerador y del denominador de forma separada
    for (int i = 1; i <= n; ++i) {
        numerador *= i;
        if (i <= k) {
            denominador *= i;
        }
        if (i <= n - k) {
            denominador *= i;
        }
    }

    return numerador / denominador;
}

int main() {
    int n, k;

    std::cout << "Ingrese el valor de n: ";
    std::cin >> n;

    std::cout << "Ingrese el valor de k (debe ser menor que n): ";
    std::cin >> k;

    unsigned long long combinaciones = calcularCombinaciones(n, k);
    std::cout << "El número de combinaciones C(" << n << ", " << k << ") es: " << combinaciones << std::endl;

    return 0;
}

//Punto 7 
#include <iostream>
#include <string>

int bin2dec(const std::string& s) {
    int decimal = 0;
    int longitud = s.length();

    for (int i = 0; i < longitud; ++i) {
        if (s[i] != '0' && s[i] != '1') {
            // Si algún carácter no es '0' ni '1', retorna un valor inválido (-1)
            return -1;
        }
        int bit = s[i] - '0';
        decimal += bit * (1 << (longitud - 1 - i));
    }

    return decimal;
}

int main() {
    std::string binario;
    
    std::cout << "Enter a binary string: ";
    std::cin >> binario;

    int decimal = bin2dec(binario);
    if (decimal != -1) {
        std::cout << "Binary \"" << binario << "\" to decimal is: " << decimal << std::endl;
    } else {
        std::cout << "ERROR: invalid binary string \"" << binario << "\"" << std::endl;
    }

    return 0;
}
