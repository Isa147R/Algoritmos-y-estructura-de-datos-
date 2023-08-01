
// Online C++ Compiler - Build, Compile and Run your C++ programs online in your favorite browser

#include<iostream>

using namespace std;

int main()
{
    int num = 0;
    
    cout<<"El número es: "<<num<<endl;
    
    cout<<"Escriba un número: ";
    cin>>num;
    cout<<endl;
    
    cout<<"El número es: "<<num<<endl;
    
    cout<<"La mitad del número es: "<<(num/2.0)<<endl;
    
    if(num%2 == 0){
        cout<<"El número es par"<<endl;
    }else if(num%2 == 1){
        cout<<"El número es impar"<<endl;
    }else{
        cout<<"Imposible!"<<endl;
    }
    
    switch(num){
        case 1:
            cout<<"El número es 1"<<endl;
            break;
        
        case 2:
            cout<<"El número es 2"<<endl;
            break;
            
        default:
            cout<<"El número no es ni 1 ni 2"<<endl;
        break;
    }
    
    while(num > 0){
        cout<<"Hola "<<(num--)<<endl;
    }
    
    int i;
    num=1;
    for(i=0; i<10 && num<100; i++){
        cout<<"El número es: "<<(num*=5)<<endl;
    }
    
    cout<<"El número es: "<<num<<endl;
    
    
    do{
        cout<<"Escriba un número par: ";
        cin>>num;
    }while(num%2 == 1);
    
    cout<<"El número es: "<<num<<endl;
    
    return 0;
}
