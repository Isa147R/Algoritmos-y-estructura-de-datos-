#include iostream;
using namespace std;

template class Vector{
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

void add(T valor){
if (size == capacidad) {
incrementar_capacidad();
}
v[size++] = valor;
}

void print(){
for (int i = 0; i < size; ++i){
cout << v[i] << endl;
}
}

T get (int x){
return v[x];
}

void incrementar_capacidad(){
T* v1 = new T[capacidad*=2];
for (int i = 0; i < size; ++i){
v1[i]=v[i];
}
delete[] v;
v = v1;
}
void insert(T dato, int p){
if (size == capacidad) {
incrementar_capacidad();
v[p]=dato;
size++;
}
v[p] = dato;
}

void set(T dato, int p){
v[p] = dato;
}

};

int main()
{
Vector vector1;
for (int i = 0; i < 5; i++){
vector1.add(i);
}
Vector vector2;
for (int i = 0; i < 5; i++){
vector2.add(i);
}

cout << "Vector Normal " << endl;
vector1.print();

cout << "Metodo set" << endl;
vector1.set(9,2);
vector1.print();


cout << "Metodo insert" << endl;
vector2.insert(9,2);
vector2.print();
return 0;
}
