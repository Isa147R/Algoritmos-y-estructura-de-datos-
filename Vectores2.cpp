// Online C++ Compiler - Build, Compile and Run your C++ programs online in your favorite
browser
#include<iostream>
using namespace std;
void asignar_val(int n, int v[], int tam){
    cout<<"DirMem Asignar "<<v<<" "<<&n<<" "<<&tam<<endl;
    n++;
    for(int i = 0; i<tam; i++){
v[i] = n; }
    for(int i = 0; i<tam; i++){
        cout<<"El valor "<<i<<"es "<<v[i]<<endl;
} }
int main() {
    int tam = 5;
    int v[tam];
    for(int i = 0; i<6; i++){
        v[i] = 0;
}
    for(int i = 0; i<tam; i++){
        cout<<"El valor "<<i<<"es "<<v[i]<<endl;
}
int val = 5;
    cout<<"DirMem Main "<<v<<" "<<&val<<" "<<&tam<<endl;
    asignar_val(val, v, tam);
    for(int i = 0; i<tam; i++){
        cout<<"El valor "<<i<<"es "<<v[i]<<endl;
}
    cout<<"Val es "<<val<<endl;
}
