/// Martinez Lopez, Sebastian
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include "Deportista.h"
using namespace std;
    ///Funciones
    void altas(fstream&);
    void bajas(fstream&);
    void cambios(fstream&);
    void consultind(fstream&);
    void consultgen(fstream&);
    enum opciones{
        ALTAS =1,
        BAJAS,
        CAMBIOS,
        CONSULTIND,
        CONSULTGEN,
        SALIR
    };
int main(){
    int opc;
    do{
        system("cls");
        Deportista d;
        fstream archivoDeporEntradaSalida("deportistas.dat",ios::binary|ios::in|ios::out);
        if(!archivoDeporEntradaSalida){
            cerr<<"\n No se logro abrir el archivo "<<endl;
            exit(1);
        }
        cout<<"\n\t\tMenu - Asociacion de Deportistas Tapatios"<<endl<<endl
            <<" "<<ALTAS<<". Altas"<<endl
            <<" "<<BAJAS<<". Bajas"<<endl
            <<" "<<CAMBIOS<<". Cambios"<<endl
            <<" "<<CONSULTIND<<". Consultas individuales(num.de socio)"<<endl
            <<" "<<CONSULTGEN<<". Consultas generales"<<endl
            <<" "<<SALIR<<". Salir"<<endl<<endl
            <<" Elige tu opcion:";
            cin >>opc;
        switch(opc){
        case ALTAS:
            altas(archivoDeporEntradaSalida);
            break;
        case BAJAS:
            bajas(archivoDeporEntradaSalida);
            break;
        case CAMBIOS:
            cambios(archivoDeporEntradaSalida);
            break;
        case CONSULTIND:
            consultind(archivoDeporEntradaSalida);
            break;
        case CONSULTGEN:
            consultgen(archivoDeporEntradaSalida);
            break;
        case SALIR:
            cout <<"\n Saliendo del sistema..."<<endl;
            break;
        default:
            cout <<"\n Opcion invalida..."<<endl;
            cout<<" ";system("pause");
        }
    }while(opc != SALIR);
    return 0;
}
void altas( fstream &archivoDeporEntradaSalida){
    int numeroDeSocio;
    char nombre[15];
    int edad;
    char deporte[15];
    Deportista d;
    cout <<" Escriba el num.de socio (De 1 a 100, 0 para terminar la entrada)\n >>";
    cin >> numeroDeSocio;
    archivoDeporEntradaSalida.seekg((numeroDeSocio-1)*sizeof(Deportista));
    archivoDeporEntradaSalida.read(reinterpret_cast< char *>(&d),sizeof(Deportista));
    if(d.obtenerNumeroDeSocio() == 0 && numeroDeSocio >=1 && numeroDeSocio<=100){
        d.establecerNumeroDeSocio(numeroDeSocio);
        cout << " Teclea nombre, edad y deporte\n >>";
        cin >> setw(15) >> nombre;
        cin >> edad;
        cin >> setw(15) >> deporte;
        d.establecerNombre(nombre);
        d.establecerEdad(edad);
        d.establecerDeporte(deporte);
        archivoDeporEntradaSalida.seekp((d.obtenerNumeroDeSocio()-1)*sizeof(Deportista));
        archivoDeporEntradaSalida.write(reinterpret_cast< const char*>(&d),sizeof(Deportista));
        cout <<"\n El socio se a agregado correctamente"<<endl;
    }else if( numeroDeSocio <= 0 || numeroDeSocio >= 101){
        cout <<"\n El numero de socio no cumple los requerimientos..."<<endl<<endl;
    }
    else{
        cout <<"\n El numero de socio ya existe..."<<endl<<endl;
    }
    cout<<" ";system("pause");
}
void bajas( fstream &archivoDeporEntradaSalida){
    int numeroDeSocio, opbajas = 0;
    Deportista d;
    Deportista deportistaEnBlanco;
    cout << " Ingresa el numero de socio a eliminar:";
    cin >> numeroDeSocio;
    archivoDeporEntradaSalida.seekg((numeroDeSocio-1)*sizeof(Deportista));
    archivoDeporEntradaSalida.read(reinterpret_cast< char *>(&d),sizeof(Deportista));
    if(d.obtenerNumeroDeSocio() != 0){
        cout<<left<<setw(14)<<"\n NUM DE SOCIO "<<":"<<d.obtenerNumeroDeSocio()<<endl
                <<setw(14)<<" NOMBRE"<<":"<<d.obtenerNombre()<<endl
                <<setw(14)<<" EDAD"<<":"<<d.obtenerEdad()<<endl
                <<setw(14)<<" DEPORTE"<<":"<<d.obtenerDeporte()<<endl<<endl;
        do{
            cout <<" Se eliminara el socio:\n 1.Aceptar\n 2.Cancelar\n >>";
            cin >>opbajas;
            if(opbajas == 1){
                archivoDeporEntradaSalida.seekp((d.obtenerNumeroDeSocio()-1)*sizeof(Deportista));
                archivoDeporEntradaSalida.write(reinterpret_cast<const char *>(&deportistaEnBlanco),sizeof(Deportista));
                cout<<"\n Socio eliminado"<<endl;
            }else if(opbajas == 2){
                cout<<" Cancelando operacion..."<<endl;
            }else{
                cout<<" Opcion erronea..."<<endl;
            }
        }while(opbajas != 1 && opbajas != 2);
    }else{
        cout<<"\n El numero de socio no existe..."<<endl;
    }
    cout<<" ";system("pause");
}
void cambios( fstream &archivoDeporEntradaSalida){
    int numeroDeSocio;
    char nombre[15];
    int edad;
    char deporte[15];
    Deportista d;
    cout<<" Ingresa el numero de socio a actualizar:";
    cin >>numeroDeSocio;
    archivoDeporEntradaSalida.seekg((numeroDeSocio-1)*sizeof(Deportista));
    archivoDeporEntradaSalida.read(reinterpret_cast< char *>(&d),sizeof(Deportista));
    if(d.obtenerNumeroDeSocio() != 0){
      cout<<left<<setw(14)<<"\n NUM DE SOCIO "<<":"<<d.obtenerNumeroDeSocio()<<endl
                <<setw(14)<<" NOMBRE"<<":"<<d.obtenerNombre()<<endl
                <<setw(14)<<" EDAD"<<":"<<d.obtenerEdad()<<endl
                <<setw(14)<<" DEPORTE"<<":"<<d.obtenerDeporte()<<endl<<endl;
      cout << " Ingresa los datos actualizados: nombre, edad y deporte\n >>";
      cin >> setw(15) >> nombre;
      cin >> edad;
      cin >> setw(15) >> deporte;
      d.establecerNombre(nombre);
      d.establecerEdad(edad);
      d.establecerDeporte(deporte);
      cout<<"\n\tActualizacion de socio:";
      cout<<left<<setw(14)<<"\n NUM DE SOCIO "<<":"<<d.obtenerNumeroDeSocio()<<endl
                <<setw(14)<<" NOMBRE"<<":"<<d.obtenerNombre()<<endl
                <<setw(14)<<" EDAD"<<":"<<d.obtenerEdad()<<endl
                <<setw(14)<<" DEPORTE"<<":"<<d.obtenerDeporte()<<endl<<endl;
      archivoDeporEntradaSalida.seekp((d.obtenerNumeroDeSocio()-1)*sizeof(Deportista));
      archivoDeporEntradaSalida.write(reinterpret_cast< const char *>(&d),sizeof(Deportista));
    }else{
        cout<<"\n El numero de socio no existe..."<<endl<<endl;
    }
    cout<<" ";system("pause");
}
void consultind( fstream &archivoDeporEntradaSalida){
    int numeroDeSocio;
    Deportista d;
    cout << " Teclea el numero de socio:";
    cin >> numeroDeSocio;
    archivoDeporEntradaSalida.seekg((numeroDeSocio-1)*sizeof(Deportista));
    archivoDeporEntradaSalida.read(reinterpret_cast< char *>(&d),sizeof(Deportista));
    if(d.obtenerNumeroDeSocio() != 0){
            cout<<left<<setw(14)<<"\n NUM DE SOCIO "<<":"<<d.obtenerNumeroDeSocio()<<endl
                <<setw(14)<<" NOMBRE"<<":"<<d.obtenerNombre()<<endl
                <<setw(14)<<" EDAD"<<":"<<d.obtenerEdad()<<endl
                <<setw(14)<<" DEPORTE"<<":"<<d.obtenerDeporte()<<endl<<endl;
    }else{
                cout <<"\n El numero de socio no existe..."<<endl<<endl;
    }
    cout<<" ";system("pause");
}
void consultgen( fstream &archivoDeporEntradaSalida){
    Deportista d;
    cout <<" ----------------------------------------------------------"<<endl;
    cout <<left<<" |"<<setw(11)<<" NUM SOCIO "<<"|"<<setw(16)<<"     NOMBRE     "<<"|"<<setw(10)<<"   EDAD   "<<"|"<<setw(16)<<"   DEPORTE  "<<"|"<<endl;
    cout <<" ----------------------------------------------------------"<<endl;
    while(!archivoDeporEntradaSalida.eof())
    {
    if(d.obtenerNumeroDeSocio() != 0)
if(d.obtenerNumeroDeSocio() != 0)
            cout<<left<<" |"<<setw(11)<<d.obtenerNumeroDeSocio()
                      <<"|"<<setw(16)<<d.obtenerNombre()
                      <<"|"<<setw(10)<<d.obtenerEdad()
                      <<"|"<<setw(16)<<d.obtenerDeporte()<<"|"<<endl;
        archivoDeporEntradaSalida.read(reinterpret_cast< char *>(&d),sizeof(Deportista));
            }
    cout <<" ----------------------------------------------------------"<<endl;
    cout<<" ";system("pause");
}
