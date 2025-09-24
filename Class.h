#ifndef CLASS_H
#define CLASS_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
using namespace std; 

class Documento{
    
    private: 
    string Mes; 
    int Dia; 
    string Hora; 
    int H ; 
    int Minuto; 
    int Segundos; 
    string IP; 
    string Razon; 
    
    public: 
    Documento(string linea); 
    void Imprimir(); 
    void Ponertiempo(string linea); 
    string RegresarMes(); 
    int regresarDia(); 
    int regresarH();
    int RegresarMinutos();
    int RegresarSegundos(); 

    
};

#endif