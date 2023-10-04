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
    online() {}

    online(int mid, int tom, int c) : manga_id(mid), tomos(tom), calificacion(c) {}

    void califica(int c) {
        calificacion = static_cast<float>(c) / 33.33;
    }

    string to_string() const {
        return "(ID Manga = " + std::to_string(manga_id) + ", Tomos = " + std::to_string(tomos)
            + ", Calificación = " + std::to_string(calificacion) + ")";
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
};

template <typename T>
class Vector {
private:
    vector<T> v;

    void merge(int l, int m, int r, const string& variable);

public:
    void add(const T& element) {
        v.push_back(element);
    }

    void the_merge(const string& Rpo, const string& variable);

    void print() const {
        for (const auto& element : v) {
            cout << element.to_string() << "\n";
        }
        cout << endl;
    }
};

template <typename T>
void Vector<T>::merge(int l, int m, int r, const string& variable) {
    int n1 = m - l + 1;
    int n2 = r - m;

    vector<T> L, R;

    for (int i = 0; i < n1; i++)
        L.push_back(v[l + i]);
    for (int j = 0; j < n2; j++)
        R.push_back(v[m + 1 + j]);

    int i = 0;
    int j = 0;
    int k = l;

    while (i < n1 && j < n2) {
        if ((variable == "MAN" && L[i].getMangaId() <= R[j].getMangaId()) ||
            (variable == "TOM" && L[i].getTomos() <= R[j].getTomos()) ||
            (variable == "CAL" && L[i].getCalificacion() <= R[j].getCalificacion())) {
            v[k] = L[i];
            i++;
        } else {
            v[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        v[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        v[k] = R[j];
        j++;
        k++;
    }
}

template <typename T>
void Vector<T>::the_merge(const string& Rpo, const string& variable) {
    int n = v.size();
    if (n <= 1) {
        return;
    }

    int l = 0;
    int r = n - 1;

    if (Rpo == "ASC") {
        sort(v.begin(), v.end(), [&variable](const T& a, const T& b) {
            if (variable == "MAN") {
                return a.getMangaId() < b.getMangaId();
            } else if (variable == "TOM") {
                return a.getTomos() < b.getTomos();
            } else if (variable == "CAL") {
                return a.getCalificacion() < b.getCalificacion();
            }
            return false; // Default case
        });
    } else if (Rpo == "DES") {
        // Implementa el algoritmo de merge sort
        // Llama a la función merge para combinar las sublistas ordenadas
    }
}

int main() {
    srand(9605);

    Vector<online> v;

    int biblio = 10;
    for (int i = 0; i < biblio; i++) {
        int manga_id = rand() % 75;
        int tomos = rand() % 50;
        int calificacion = rand() % 100;

        online o(manga_id, tomos, calificacion);
        o.califica(calificacion);

        v.add(o);
    }

    cout << "Antes de ordenar:\n";
    v.print();

    string Rpo = "DES";
    string variable = "MAN";

    v.the_merge(Rpo, variable);

    cout << "Después de ordenar Rpo: " << Rpo << ", para la variable: " << variable << endl;
    v.print();

 

    
    
    return 0;
}
