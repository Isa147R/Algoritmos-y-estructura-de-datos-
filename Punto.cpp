
// Online C++ Compiler - Build, Compile and Run your C++ programs online in your favorite browser

#include<iostream>
#include<math.h>
//#include<string>

using namespace std;

class Punto{
private:
    double lat;
    double lon;
    double alt;
public:
    Punto(){
        lat = 0;
        lon = 0;
        alt = 0;
    }
    
    Punto(double la, double lo){
        lat = la;
        lon = lo;
        alt = 0;
    }
    
    Punto(double la, double lo, double al){
        lat = la;
        lon = lo;
        alt = al;
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
    
    string to_str(){
        return ""+to_string(lat)+", "+to_string(lon)+", "+to_string(alt);
    }
    
    double cald_dist(Punto p){
        return sqrt(pow(lat-p.getLat(),2)+
        pow(lon-p.getLon(),2)+
        pow(alt-p.getAlt(),2));
    }
    
};

int main()
{
    Punto p;
    
    Punto p2 = Punto(1,1);
    
    cout<<p.to_str()<<endl;
    cout<<p2.to_str()<<endl;
    
    cout<<p2.cald_dist(p)<<endl;
    cout<<p2.cald_dist(p2)<<endl;
    
    return 0;
}
