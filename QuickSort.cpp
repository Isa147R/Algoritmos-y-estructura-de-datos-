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
int partition(vector<T>& arr, int low, int high) {
    T pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            customSwap(arr[i], arr[j]);
        }
    }
    customSwap(arr[i + 1], arr[high]);
    return (i + 1);
}

template <typename T>
void quickSort(vector<T>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Función para imprimir elementos de un contenedor
template <typename T>
void printContainer(const vector<T>& container) {
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

    quickSort(intVector, 0, vectorSize - 1);

    cout << "Vector después de ordenar: ";
    printContainer(intVector);

    // Puedes utilizar el mismo enfoque para otras estructuras como arreglos, nodos, multilistas, etc.

    return 0;
}
