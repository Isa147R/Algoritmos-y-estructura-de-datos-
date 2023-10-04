#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class online {
private:
    int manga_id;
    int tomos;
    float calificacion;

public:
    online(int mid, int tom, int c) : manga_id(mid), tomos(tom), calificacion(c) {}

    online() {
        manga_id = rand() % 75 + 1;
        tomos = rand() % 50 + 1;
        calificacion = rand() % 100 + 1;
    }

    void califica() {
        calificacion = static_cast<float>(calificacion) / 33.3; // Convierte a escala de 0 a 3
    }

    int getMangaId() const {
        return manga_id;
    }

    int getTomos() const {
        return tomos;
    }

    float getCalificacion() const {
        return calificacion;
    }

    string to_string() const {
        return "(ID Manga = " + std::to_string(manga_id) + " ,Tomos = " + std::to_string(tomos) +
               " ,Calificación = " + std::to_string(calificacion) + ")";
    }

    // Agrega el operador de comparación necesario para el ordenamiento
    bool operator<(const online &other) const {
        return calificacion < other.calificacion;
    }
};

template <typename T>
class Vector {
private:
    vector<T> v;

public:
    void add(const T &element) {
        v.push_back(element);
    }

    void the_merge(const string &order, const string &variable) {
        if (order == "ASC") {
            if (variable == "MAN") {
                sort(v.begin(), v.end(), [](const T &a, const T &b) {
                    return a.getMangaId() < b.getMangaId();
                });
            } else if (variable == "TOM") {
                sort(v.begin(), v.end(), [](const T &a, const T &b) {
                    return a.getTomos() < b.getTomos();
                });
            } else if (variable == "CAL") {
                sort(v.begin(), v.end(), [](const T &a, const T &b) {
                    return a.getCalificacion() < b.getCalificacion();
                });
            }
        } else if (order == "DES") {
            if (variable == "MAN") {
                sort(v.rbegin(), v.rend(), [](const T &a, const T &b) {
                    return a.getMangaId() < b.getMangaId();
                });
            } else if (variable == "TOM") {
                sort(v.rbegin(), v.rend(), [](const T &a, const T &b) {
                    return a.getTomos() < b.getTomos();
                });
            } else if (variable == "CAL") {
                sort(v.rbegin(), v.rend(), [](const T &a, const T &b) {
                    return a.getCalificacion() < b.getCalificacion();
                });
            }
        }
    }

    string to_string() const {
        string s;
        for (const auto &element : v) {
            s += element.to_string() + "\n";
        }
        return s;
    }
};

int main() {
    srand(9605);

    Vector<online> v;

    int biblio;
    cout << "Ingrese la cantidad de elementos para la base de datos: ";
    cin >> biblio;

    for (int i = 0; i < biblio; i++) {
        online o;
        o.califica();
        v.add(o);
    }

    cout << "Antes de ordenar:\n";
    cout << v.to_string();

    string order, variable;
    cout << "Ingrese el tipo de ordenamiento (ASC/DES): ";
    cin >> order;
    cout << "Ingrese la variable a ordenar (MAN/TOM/CAL): ";
    cin >> variable;

    v.the_merge(order, variable);

    cout << "Después de ordenar Rpo: " << order << ", para la variable: " << variable << endl;
    cout << v.to_string();

    return 0;
}
