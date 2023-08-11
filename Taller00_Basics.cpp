//Punto 1

// como programa:  
#include <iostream>

int main() {
    int sum = 0;
    int num = 1;

    while (num <= 100) {
        sum += num;
        num++;
    }

    std::cout << "La suma de los números enteros del 1 al 100 es: " << sum << std::endl;

    return 0;
}
// como funcion: 
#include <iostream>

int sumarNumeros(int inicio, int fin) {
    int sum = 0;
    int num = inicio;

    while (num <= fin) {
        sum += num;
        num++;
    }

    return sum;
}

int main() {
    int resultado = sumarNumeros(1, 100);
    std::cout << "La suma de los números enteros del 1 al 100 es: " << resultado << std::endl;

    return 0;
}

//Punto 2
//como programa:
#include <iostream>

int main() {
    int numero;
    int suma = 0;

    std::cout << "Ingrese una lista de números enteros (terminar con un caracter no numérico):" << std::endl;

    while (std::cin >> numero) {
        suma += numero;
    }

    std::cout << "La suma de los números enteros ingresados es: " << suma << std::endl;

    return 0;
}
//como funcion:
#include <iostream>

int sumarListaDeNumeros() {
    int numero;
    int suma = 0;

    std::cout << "Ingrese una lista de números enteros (terminar con un caracter no numérico):" << std::endl;

    while (std::cin >> numero) {
        suma += numero;
    }

    return suma;
}

int main() {
    int resultado = sumarListaDeNumeros();
    std::cout << "La suma de los números enteros ingresados es: " << resultado << std::endl;

    return 0;
}

//Punto 3
//como progrma:
#include <iostream>

int main() {
    int numero;

    std::cout << "Ingrese un número entero: ";
    std::cin >> numero;

    if (numero % 2 == 0) {
        std::cout << "El número ingresado es par." << std::endl;
    } else {
        std::cout << "El número ingresado es impar." << std::endl;
    }

    return 0;
}
//como funcion:
#include <iostream>

bool esPar(int numero) {
    return numero % 2 == 0;
}

int main() {
    int numero;

    std::cout << "Ingrese un número entero: ";
    std::cin >> numero;

    if (esPar(numero)) {
        std::cout << "El número ingresado es par." << std::endl;
    } else {
        std::cout << "El número ingresado es impar." << std::endl;
    }

    return 0;
}

//Punto 4
//Incremento Prefijo (++x):
//primero se incrementa el valor de la variable y luego se devuelve el nuevo valor.
//Incremento Postfijo (x++):
//primero se devuelve el valor actual de la variable y luego se incrementa.
#include <iostream>

int main() {
    int x = 5;
    int y;

    y = ++x;  // Incremento prefijo
    std::cout << "x: " << x << ", y: " << y << std::endl;  // x: 6, y: 6

    x = 5;  // Reiniciamos x
    y = x++;  // Incremento postfijo
    std::cout << "x: " << x << ", y: " << y << std::endl;  // x: 6, y: 5

    return 0;
}

