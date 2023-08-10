#include <iostream>
using namespace std;
template <typename T>

class Vector
{
private:
    int *datos;
    int tam;
    int capacidad;

public:
    // Constructor
    Vector(T initial_capacidad = 10)
    {
        datos = new T[initial_capacidad];
        tam = 0;
        capacidad = initial_capacidad;
    }

    // Destructor
    ~Vector()
    {
        delete[] datos;
    }

    //  Agregar un ultimo dato
    void Ultimo_dato(int value)
    {
        if (tam == capacidad)
        {
            New_tam(capacidad * 2);
        }
        datos[tam] = value;
        tam++;
    }

    // eliminar el ultimo dato
    void Eliminar_Udato()
    {
        if (tam == 0)
        {
            cout << "vector vacio";
        }
        tam--;
    }

    // obtenemos un elemento especifico
    int get_dato(int index)
    {
        if (index < 0 || index >= tam)
        {
            cout << "Indice fuera de rango";
        }
        return datos[index];
    }

    // obtenemos el tamañ0
    int get_tam()
    {
        return tam;
    }

    // agregar un dato en cualquier index

    void print()
    {
        for (int i = 0; i < tam; i++)
        {
            cout << datos[i] << " ";
        }
        cout << endl;
    }

    // obtenemos tamaño
    int get_capacidad()
    {
        return capacidad;
    }

    // ampliamos la capacidad
    void New_tam(int new_capacidad)
    {
        T *new_datos = new T[new_capacidad];
        for (int i = 0; i < tam; i++)
        {
            new_datos[i] = datos[i];
        }
        delete[] datos;
        datos = new_datos;
        capacidad = new_capacidad;
    }

    // insertamos un dato en cualquier index
    void Insert(int ndato, int index)
    {
        if (index < 0 || index > tam)
        {
            cout << "Fuera de rango"<<endl;
            return;
        }

        if (tam == capacidad)
        {
            New_tam(capacidad * 2);
        }

        T *datos_mov = new T[capacidad];
        for (int i = 0; i < tam; i++)
        {
            datos_mov[i] = datos[i];
        }

        datos[index] = ndato;

        for (int i = index + 1; i <= tam; i++)
        {
            datos[i] = datos_mov[i-1];
        }

        tam++;
        delete[] datos_mov;
    }


    // eliminamos el dato de cualquier index
    void remove(int index)
    {
        if (index < 0 || index >= tam)
        {
            cout << "Fuera de rango" << endl;
            return;
        }

        T *datos_mov = new T[capacidad];
        for (int i = 0; i < index; i++)
        {
            datos_mov[i] = datos[i];
        }

        for (int i = index + 1; i < tam; i++)
        {
            datos_mov[i - 1] = datos[i];
        }

        tam--;
        delete[] datos;
        datos = datos_mov;
    }
		//Promediar todos los datos
    double promedio(){
        int suma = 0;
        double prom = 0;
        for (int i = 0; i < 5; i++)
        {
            suma += datos[i];
        }
        prom = suma / 10.0;
        return prom;
    }

};

int main()
{
    Vector<int> v;
    for (int i = 0; i < 10; i++)
    {
        v.Ultimo_dato(i);
    }
    v.print();

    v.Insert(4,6);
    v.print();
    v.remove(5);
    v.print();
    return 0;
}
