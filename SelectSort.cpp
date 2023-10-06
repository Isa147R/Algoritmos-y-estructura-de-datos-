#include <iostream>
#include <vector>

using namespace std;

template <typename T>
void customSwap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

template <typename T>
void selectionSort(T& data, int size) {
    for (int i = 0; i < size - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < size; ++j) {
            if (data[j] < data[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            customSwap(data[i], data[minIndex]);
        }
    }
}

// Función para imprimir elementos de un contenedor
template <typename T>
void printContainer(const T& container) {
    for (const auto& element : container) {
        cout << element << " ";
    }
    cout << endl;
}

int main() {
    // Ejemplo con un vector de enteros
    vector<int> intVector = {64, 25, 12, 22, 11};
    int vectorSize = intVector.size();

    cout << "Vector antes de ordenar: ";
    printContainer(intVector);

    selectionSort(intVector, vectorSize);

    cout << "Vector después de ordenar: ";
    printContainer(intVector);

    // Puedes utilizar el mismo enfoque para otras estructuras como arreglos, nodos, multilistas, etc.

    return 0;
}
