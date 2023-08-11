#include <stdio.h>
#include <iostream>
#include "Punto.h"
#include "Circulo.h"

int main()
{
    Punto p;
    
    Punto p2 = Punto(1,1);
    
    cout<<p.to_str()<<endl;
    cout<<p2.to_str()<<endl;
    
    cout<<p2.calc_dist(p)<<endl;
    cout<<p2.calc_dist(p2)<<endl;
    
    Circulo c = Circulo(0.5);

    cout<<"El circulo es: "<<c.to_str()<<endl;
    
    if(c.contains(p2))
        cout<<"Lo contiene"<<endl;
    else
        cout<<"No lo contiene"<<endl;

    return 0;
}
