// Online C++ Compiler - Build, Compile and Run your C++ programs online in your favorite
browser
#include<iostream>
using namespace std;
void leer_v(int v[], int t){
    int r = 0;
    for(int i = 0; i<10; i++){
        /*cout<<"Entre el dato "<<i<<": ";
        cin>>v[i];*/
        r = rand()%100;
        cout<<"El dato "<<i<<": "<<r<<endl;
        v[i] = r;
} }
int** crear_mat(int f, int c, int val, int max){
    int** m = new int*[f];
    for(int i=0; i<f; i++){
        m[i] = new int[c];
        for(int j=0; j<c; j++){
} }
if(val >= 0)
    m[i][j] = val;
else
    m[i][j] = rand()%max;
return m; }
int** crear_mat(int f, int c){
    return crear_mat(f, c, 0, 0);
}
int** crear_mat(int f, int c, int val){
    return crear_mat(f, c, val, 0);
}
void print_mat(int** m, int f, int c){
    for(int i=0; i<f; i++){
        for(int j=0; j<c; j++){
            cout<<m[i][j]<<"\t";
}
        cout<<endl;
    }
    cout<<endl;
}
int* crear_v(int t, int val, int max){
    int* v = new int[t];
    for(int i=0; i<t; i++){
        if(val >= 0)
            v[i] = val;
        else
            v[i] = rand()%max;
}
return v; }

int* crear_v(int t){
    return crear_v(t, 0, 0);
}
int* crear_v(int t, int val){
    return crear_v(t, val, 0);
}
float average_v(int v[], int t){
    double a = 0;
    for(int i = 0; i<10; i++){
        a+=v[i];
}
return a/t; }
float average_m(int m[][10], int c, int f){
    double a = 0;
    for(int i = 0; i<f; i++){
        for(int j=0; j<f; j++){
            a+=m[i][j];
        }
}
    return a/(c*f);
}
void leer_m(int m[][10], int c, int f){
    int r = 0;
    for(int i = 0; i<f; i++){
        for(int j=0; j<c; j++){
            r = rand()%100;
            cout<<"El dato "<<i<<","<<j<<": "<<r<<endl;
            m[i][j] = r;
} }
}
/*
int[] crear_v(){
    int v[10];
    leer_v(v,10);
    return v;
} */
int main() {
    /*
    int v[10];
    int m[10][10];
    /*for(int i = 0; i<10; i++){
        cout<<"Entre el dato "<<i<<": ";
        cin>>v[i];
    }*/
    /*
    leer_v(v,10);
    cout<<"El promedio es: "<<average_v(v, 10)<<endl;
leer_m(m,10,10);

cout<<"El promedio es: "<<average_m(m, 10,10)<<endl;
    /*
    int[] v2 = crear_v();
    cout<<"El promedio es: "<<average_v(v2, 10)<<endl;
    */
int* v = NULL;
v = new int;
*v = 2;
    cout<<"El apuntador es "<<&v<<" contiene la dirección "<<v<<" que tiene el valor: "
<<(*v)<<endl;
    int k = *v;
    cout<<"El valor de k es: "<<k<<endl;
    int* v3 = NULL;
    v3 = v;
    cout<<"El apuntador es "<<&v3<<" contiene la dirección "<<v3<<" que tiene el valor: "
<<(*v3)<<endl;
    (*v3)++;
    cout<<"V: "<<(*v)<<" V3: "<<(*v3)<<endl;
    int* v2 = NULL;
    int tam = 10;
    v2 = crear_v(tam, 5);
    /*
    for(int i=0; i<tam; i++){
        v2[i] = rand()%100;
    }
*/
    for(int i=0; i<tam; i++){
        cout<<"En valor en "<<i<<" es: "<<v2[i]<<endl;
}
    int f = 10;
    int c = 10;
    int** m = crear_mat(f,c,-1,100);
    print_mat(m,f,c);
    delete[] v;
    delete[] m;
return 0; }
