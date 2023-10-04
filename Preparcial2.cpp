
#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Tarjeta {
private:
    int numero;
    int color;

public:
    Tarjeta() : numero(0), color(0) {}
    Tarjeta(int n, int c) : numero(n), color(c) {}

    int getNumero() { return numero; }
    int getColor() { return color; }

    string to_string() {
        return "(" + std::to_string(numero) + "," + std::to_string(color) + ")";
    }

    void print() {
        cout << to_string();
    }
};

class Jugador {
private:
    int id;
    vector<Tarjeta*> cartas;

public:
    Jugador() : id(0) {}
    Jugador(int n) : id(n) {}

    ~Jugador() {
        for (Tarjeta* t : cartas) {
            delete t;
        }
    }

    void addTarjeta(Tarjeta* t) {
        cartas.push_back(t);
    }

    void sortTarjetas() {
        // Ordenar las tarjetas, primero por número y luego por color
        sort(cartas.begin(), cartas.end(), [](Tarjeta* a, Tarjeta* b) {
            return (a->getNumero() < b->getNumero()) || (a->getNumero() == b->getNumero() && a->getColor() < b->getColor());
        });
    }

    int calc_points() {
        int sum = 0;
        for (Tarjeta* t : cartas) {
            sum += (t->getNumero() == 0) ? 20 : t->getNumero();
        }
        return sum;
    }

    int get_id() {
        return id;
    }

    string to_string() {
        string s = std::to_string(id) + " -> ";
        for (Tarjeta* t : cartas) {
            s += t->to_string() + " , ";
        }
        return s;
    }

    void print() {
        cout << to_string() << endl;
    }
};

class Uno {
private:
    vector<Jugador*> jugadores;

public:
    Uno() {}

    ~Uno() {
        for (Jugador* j : jugadores) {
            delete j;
        }
    }

    void addJugador(Jugador* p) {
        jugadores.push_back(p);
    }

    Jugador* getJugador(int i) {
        if (i >= 0 && i < jugadores.size()) {
            return jugadores[i];
        }
        return nullptr;
    }

    void sortPlayers() {
        // Ordenar los jugadores por puntaje
        sort(jugadores.begin(), jugadores.end(), [](Jugador* a, Jugador* b) {
            return a->calc_points() > b->calc_points();
        });
    }

    void sortTarjetas() {
        // Ordenar las tarjetas de cada jugador
        for (Jugador* j : jugadores) {
            j->sortTarjetas();
        }
    }

    void print() {
        for (Jugador* j : jugadores) {
            j->print();
        }
    }
};

int main() {
    srand(1234);
    int num_jugadores = 0;
    int num_colores = 4;
    int num_tarjetas = 10;

    // Leer el número de jugadores, hasta que cumpla con la condición
    do {
        cout << "Ingrese el numero de jugadores (minimo 2, maximo 5): ";
        cin >> num_jugadores;
    } while (num_jugadores < 2 || num_jugadores > 5);

    Uno u;

    // Añadir num_jugadores jugadores a la lista
    for (int i = 0; i < num_jugadores; i++) {
        u.addJugador(new Jugador(i));
    }

    int winner = rand() % num_jugadores;

    // Añadir num_tarjetas tarjetas a los jugadores
    for (int i = 0; i < num_colores; i++) {
        for (int j = 0; j < num_tarjetas; j++) {
            int temp = rand() % num_jugadores;
            if (temp != winner) {
                u.getJugador(temp)->addTarjeta(new Tarjeta(i, j));
            }
        }
    }

    // Mostrar el puntaje de los jugadores, en orden de id
    u.print();

    // Calcular el puntaje de cada jugador
    for (int i = 0; i < num_jugadores; i++) {
        cout << "Jugador " << i << " tiene " << u.getJugador(i)->calc_points() << " puntos" << endl;
    }

    // Ordenar a jugadores y sus cartas internamente
    u.sortPlayers();
    u.sortTarjetas();

    cout << endl;
    // Mostrar la lista ordenada
    u.print();

    return 0;
}
