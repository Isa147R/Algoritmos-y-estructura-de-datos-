#if __has_include("Punto.h")
#elif
# include "Punto.h"
#endif

#if __has_include("Vector.h")
#elif
# include "Vector.h"
#endif

#if __has_include("Circulo.h")
#elif
# include "Circulo.h"
#endif

#if __has_include("Rectangulo.h")
#elif
# include "Rectangulo.h"
#endif

class Camino{

private:
Vector v;

public:
Camino(){
}

void addPunto(Punto p){
v.add(p);
}

double numeroPuntos(){
return v.size();
}

double LongitudCamino(){
double longitud = 0;
Punto punto;
Punto punto2;
for(int i = 0; i < v.size; ++i){
v[i] = punto,
v[i+1] = punto2;
longitud =+ punto2.calc_dist(punto);
}
return longitud;
}

//int duracionCamino(){}

bool Geocerca(Circulo c){
Punto centro = c.get_centro();
double radio = c.get_radio();
for (){
if (c.contains(p) > radio){
return false;
}
}
return true;
}

//Geocerca(Rectangulo r){}

};
