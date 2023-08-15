#if __has_include("Punto.h")
#elif
# include "Punto.h"
#endif

class Rectangulo{
private:
Punto supIzq;
Punto infDer;
public:

Rectangulo(){

}

Rectangulo(Punto supI, Punto infD){
supIzq = supI;
infDer = infD;
}

Punto getSupIzq(Punto p){
return supIzq;
}

Punto getInfDer(Punto p){
return infDer;
}

bool contains(Punto p){
double x1 = supIzq.getLon();
double y1 = supIzq.getLat();
double x2 = infDer.getLon();
double y2 = infDer.getLat();
return p.getLon() >= x1 && p.getLon() <= x2 && p.getLat() >= y1 && p.getLat()<= y2;

}

};
