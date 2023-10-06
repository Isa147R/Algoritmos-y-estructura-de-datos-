#include<iostream>
#include<string>

using namespace std;

template <typename T>
class Nodo {
private:
    T dato;
    Nodo* next;

public:
    Nodo() : next(nullptr) {}
    Nodo(T d) : dato(d), next(nullptr) {}

    T get_dato() { return dato; }
    void set_dato(T d) { dato = d; }

    Nodo<T>* get_next() { return next; }
    void set_next(Nodo<T>* n) { next = n; }

    Nodo<T>& operator=(const Nodo<T>& f) {
        dato = f.dato;
        next = f.next;
        return *this;
    }

    string to_string() { return std::to_string(dato); }

    friend ostream& operator<<(ostream& os, Nodo<T>& b) {
        return os << b.to_string();
    }
};

template <typename T>
class Lista {
private:
    Nodo<T>* ptr;
    int size;

public:
    Lista() : ptr(nullptr), size(0) {}
    ~Lista() {
        Nodo<T>* temp = ptr;
        Nodo<T>* next_temp = ptr;

        while (next_temp != nullptr) {
            delete temp;
            temp = next_temp;
            next_temp = temp->get_next();
        }
        delete temp;
    }

    void add(T d) {
        Nodo<T>* n = new Nodo<T>(d);
        if (ptr == nullptr) {
            ptr = n;
        } else {
            Nodo<T>* t = ptr;
            while (t->get_next() != nullptr) {
                t = t->get_next();
            }
            t->set_next(n);
        }
        size++;
    }

    void print() {
        Nodo<T>* t = ptr;
        while (t != nullptr) {
            cout << (*t) << endl;
            t = t->get_next();
        }
    }

    void insert(T dato, int pos) {
        Nodo<T>* new_nodo = new Nodo<T>(dato);

        if (ptr == nullptr || pos <= 0) {
            new_nodo->set_next(ptr);
            ptr = new_nodo;
            size++;
        } else if (pos >= size) {
            add(dato);
        } else {
            Nodo<T>* t = ptr;
            int i = 0;
            while (i < pos - 1) {
                t = t->get_next();
                i++;
            }
            new_nodo->set_next(t->get_next());
            t->set_next(new_nodo);
            size++;
        }
    }
};

template <typename T, typename T2>
class NodoP {
private:
    T dato;
    NodoP* nextP;
    Lista<T2>* l;

public:
    NodoP() : nextP(nullptr), l(new Lista<T2>()) {}
    NodoP(T d) : dato(d), nextP(nullptr), l(new Lista<T2>()) {}

    T get_dato() { return dato; }
    void set_dato(T d) { dato = d; }

    NodoP<T, T2>* get_next() { return nextP; }
    void set_next(NodoP<T, T2>* n) { nextP = n; }

    Lista<T2>* get_lista() { return l; }

    void add(T2 d) { l->add(d); }

    void print() {
        cout << dato << " -> " << endl;
        l->print();
    }
};

template <typename T, typename T2>
class Multilista {
private:
    NodoP<T, T2>* ptr;
    int size;

public:
    Multilista() : ptr(nullptr), size(0) {}
    ~Multilista() {
        NodoP<T, T2>* temp = ptr;
        NodoP<T, T2>* next_temp = ptr;

        while (next_temp != nullptr) {
            delete temp;
            temp = next_temp;
            next_temp = temp->get_next();
        }
        delete temp;
    }

    void add(T d) {
        NodoP<T, T2>* n = new NodoP<T, T2>(d);
        if (ptr == nullptr) {
            ptr = n;
        } else {
            NodoP<T, T2>* t = ptr;
            while (t->get_next() != nullptr) {
                t = t->get_next();
            }
            t->set_next(n);
        }
        size++;
    }

    void print() {
        NodoP<T, T2>* t = ptr;
        while (t != nullptr) {
            t->print();
            t = t->get_next();
        }
    }

    void insert(T dato, int pos) {
        NodoP<T, T2>* new_nodo = new NodoP<T, T2>(dato);

        if (ptr == nullptr || pos <= 0) {
            new_nodo->set_next(ptr);
            ptr = new_nodo;
            size++;
        } else if (pos >= size) {
            add(dato);
        } else {
            NodoP<T, T2>* t = ptr;
            int i = 0;
            while (i < pos - 1) {
                t = t->get_next();
                i++;
            }
            new_nodo->set_next(t->get_next());
            t->set_next(new_nodo);
            size++;
        }
    }

    NodoP<T, T2>* get(int i) {
        NodoP<T, T2>* t = ptr;
        int j = 0;
        while (t != nullptr && j < i) {
            t = t->get_next();
            j++;
        }
        return t;
    }
};

int main() {
    Multilista<int, float> m;

    m.add(5);
    m.add(6);
    m.add(7);

    m.get(0)->add(5.1);
    m.get(0)->add(5.2);

    m.get(1)->add(6.3);
    m.get(1)->add(6.4);

    m.get(2)->add(7.5);
    m.get(2)->add(7.6);

    m.print();

    return 0;
}
