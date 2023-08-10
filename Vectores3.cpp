
// Online C++ Compiler - Build, Compile and Run your C++ programs online in your favorite browser

#include<iostream>

using namespace std;

template <typename T>
class Vector{
private:
    T* v;
    int size;
    int capacidad;
public:
    Vector(){
        capacidad = 10;
        size = 0;
        v = new T[capacidad];
    }
    
    Vector(int c){
        capacidad = c;
        size = 0;
        v = new T[capacidad];
    }
    
    ~Vector(){
        delete[] v;
    }
    
    void incrementar_capacidad(){
        T* v2 = new T[capacidad*=2];
        for(int i=0; i<size; i++){
            v2[i] = v[i];
        }
        delete[] v ;
        v = v2;
    }
    
    void add(T dato){
        if(size == capacidad){
            incrementar_capacidad();
        }
        v[size++] = dato;
    }
  
  void print(){
      for(int i=0; i<size; i++){
          cout<<v[i]<<endl;
      }
  }  
  
  void insert(T dato, int pos){
      if(pos < 0){
          cout<<"Error - Fuera de rango"<<endl;
      }else if(pos >= size){
          add(dato);
      }else{
          if(size == capacidad){
            incrementar_capacidad();
          }
          for(int i=size; i>pos; i--){
              v[i] = v[i-1];
          }
          v[pos] = dato;
          size++;
      }
  }

  void eliminar(int pos){
      if(pos >= size || pos < 0){
          cout<<"Error - Fuera de rango"<<endl;
      }else{
          for(int i=pos; i<size-1; i++){
              v[i] = v[i+1];
          }
          size--;
      }
  }
    
};


int main()
{
    Vector<int> v;
    
    for(int i=0; i<100; i++){
        v.add(i);
    }
    
    v.print();
    
    return 0;
}
