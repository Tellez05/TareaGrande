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
    string Dia; 
    string Hora; 
    string IP; 
    string Razon; 
    
    public: 
    Documento(string linea); 
    void Imprimir(); 
    
};

#endif