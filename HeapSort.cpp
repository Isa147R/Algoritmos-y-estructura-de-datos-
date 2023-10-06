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
void heapify(vector<T>& arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != i) {
        customSwap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

template <typename T>
void heapSort(vector<T>& arr) {
    int n = arr.size();

    // Construir el heap (reorganizar el vector)
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    // Extraer elementos uno por uno del heap
    for (int i = n - 1; i > 0; i--) {
        customSwap(arr[0], arr[i]);
        heapify(arr, i, 0);
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
    vector<int> intVector = {12, 11, 13, 5, 6, 7};
    int vectorSize = intVector.size();

    cout << "Vector antes de ordenar: ";
    printContainer(intVector);

    heapSort(intVector);

    cout << "Vector después de ordenar: ";
    printContainer(intVector);

    // Puedes utilizar el mismo enfoque para otras estructuras como arreglos, nodos, multilistas, etc.

    return 0;
}
