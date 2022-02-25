/// Martinez Lopez, Sebastian
#include <cstring>
#include <string>
#include "Deportista.h"
using namespace std;
Deportista::Deportista(int valorNumeroDeSocio,string valorNombre, int valorEdad,string valorDeporte)
{
    establecerNumeroDeSocio(valorNumeroDeSocio);
    establecerNombre(valorNombre);
    establecerEdad(valorEdad);
    establecerDeporte(valorDeporte);
}
Deportista::~Deportista(){}
void Deportista::establecerNumeroDeSocio(int valorNumeroDeSocio){
    numeroDeSocio = valorNumeroDeSocio;
}
int Deportista::obtenerNumeroDeSocio() const{
    return numeroDeSocio;
}
void Deportista::establecerNombre(string b){
     const char *valorNombre= b.data();
     int longd = b.size();
     longd = ( longd < 15 ? longd : 14 );
     strncpy( nombre, valorNombre, longd );
     nombre[ longd ] = '\0';
}
string Deportista::obtenerNombre() const{
    return nombre;
}
void Deportista::establecerEdad(int valorEdad){
    edad = valorEdad;
}
int Deportista::obtenerEdad() const{
    return edad;
}
void Deportista::establecerDeporte(string d){
     const char *valorDeporte = d.data();
     int longd = d.size();
     longd = ( longd < 15 ? longd : 14 );
     strncpy( deporte, valorDeporte, longd );
     deporte[ longd ] = '\0';
}
string Deportista::obtenerDeporte()const{
    return deporte;
}
