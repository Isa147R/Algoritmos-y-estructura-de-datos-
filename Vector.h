#include <iostream>
using namespace std;

template <typename T>
class Vector {
private:
    T* v;
    int size;
    int capacidad;

public:
    Vector() {
        capacidad = 10;
        size = 0;
        v = new T[capacidad];
    }

    Vector(int c) {
        capacidad = c;
        size = 0;
        v = new T[capacidad];
    }

    ~Vector() {
        delete[] v;
    }

    void add(T valor) {
        if (size == capacidad) {
            incrementar_capacidad();
        }
        v[size++] = valor;
    }

    void print() {
        for (int i = 0; i < size; ++i) {
            cout << v[i] << " ";
        }
        cout << endl;
    }

    T get(int x) {
        return v[x];
    }

    void incrementar_capacidad() {
        T* v1 = new T[capacidad *= 2];
        for (int i = 0; i < size; ++i) {
            v1[i] = v[i];
        }
        delete[] v;
        v = v1;
    }

    void set(T dato, int p) {
        v[p] = dato;
    }

    void insert(T dato, int p) {
        if (size == capacidad) {
            incrementar_capacidad();
        }
        for (int i = size; i > p; --i) {
            v[i] = v[i - 1];
        }
        v[p] = dato;
        size++;
    }

    void remove(int p) {
        for (int i = p; i < size - 1; ++i) {
            v[i] = v[i + 1];
        }
        size--;
    }
};

int main() {
    Vector<int> vector1;
    for (int i = 0; i < 5; i++) {
        vector1.add(i);
    }

    cout << "Vector Normal: ";
    vector1.print();

    cout << "Metodo set" << endl;
    vector1.set(9, 2);
    vector1.print();

    cout << "Metodo insert" << endl;
    vector1.insert(4, 2);
    vector1.print();

    cout << "Metodo remove" << endl;
    vector1.remove(1);
    vector1.print();

    return 0;
}
