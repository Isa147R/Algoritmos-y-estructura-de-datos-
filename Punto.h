#include<math.h>

using namespace std;

class Punto{
private:
    double lat;
    double lon;
    double alt;
    double time;
    
public:
    Punto(){
        lat = 0;
        lon = 0;
        alt = 0;
        time = 0;
    }
    
    Punto(double la, double lo){
        lat = la;
        lon = lo;
        alt = 0;
        time = 0;
    }
    
    Punto(double la, double lo, double al){
        lat = la;
        lon = lo;
        alt = al;
        time = 0;
    }
    
    Punto(double la, double lo, double al, double t){
        lat = la;
        lon = lo;
        alt = al;
        time = t;
    }
    
    double getLat(){
        return lat;
    }
    
    double getLon(){
        return lon;
    }
    
    double getAlt(){
        return alt;
    }
    
    double getTime(){
        return time;
    }
    
    string to_str(){
        return ""+to_string(lat)+", "+to_string(lon)+", "+to_string(alt);
    }
    
    double calc_dist(Punto p){
        return sqrt(pow(lat-p.getLat(),2)+
        pow(lon-p.getLon(),2)+
        pow(alt-p.getAlt(),2));
    }
    
};