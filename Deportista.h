/// Martinez Lopez, Sebastian
#ifndef DEPORTISTA_H
#define DEPORTISTA_H
#include <iostream>
#include <string>
#include <cstring>
using namespace std;
class Deportista{
    public:
        Deportista(int = 0, string = "",int = 0,string = "");
        ~Deportista();
        void establecerNumeroDeSocio(int);
        int obtenerNumeroDeSocio() const;
        void establecerNombre(string);
        string obtenerNombre() const;
        void establecerEdad(int);
        int obtenerEdad() const;
        void establecerDeporte(string);
        string obtenerDeporte()const;
    private:
        int numeroDeSocio;
        char nombre[15];
        int edad;
        char deporte[15];
};
#endif // DEPORTISTA_H
