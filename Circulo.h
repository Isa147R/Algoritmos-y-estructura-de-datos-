
#if __has_include("Punto.h")
#elif
#  include "Punto.h"
#endif

using namespace std;

class Circulo{
private:
    Punto centro;
    double radio;
public:
    Circulo(){
        radio  = 0;
    }
    
    Circulo(double r){
        radio  = r;
    }
    
    Circulo(Punto c, double r){
        centro = c;
        radio  = r;
    }
    
    Punto get_centro(){
        return centro;
    }
    
    void set_centro(Punto p){
        centro = p;
    }
    
    double get_radio(){
        return radio;
    }
    
    void set_radio(double r){
        radio = r;
    }
    
    bool contains(Punto p){
        return centro.calc_dist(p) <= radio;
    }
    
    string to_str(){
        return "Centro: "+centro.to_str()+", radio: "+to_string(radio);
    }
    
    
};