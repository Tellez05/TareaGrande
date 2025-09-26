/*
Andres Tellez Bermudez Matricula: A01640907
Luis Eduardo Michel    Matricula: A01641578
Jared Rafael Garcia    Matricula: A01640914
Fecha: 25/09/2025
Tarea 1.3
*/
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
    string diaString; 
    int Dia; 
    string Hora; 
    int H ; 
    int Minuto; 
    int Segundos; 
    string IP; 
    string Razon; 
    public: 
    //Tiempo de Ejecucion O(1)
    Documento(string linea); 
    //Tiempo de Ejecucion O(1)
    void PonerStringDia(int linea); 
    //Tiempo de Ejecucion O(1)
    void Ponertiempo(string linea); 
    string RegresarMes(); 
    //Tiempo de Ejecucion O(1)
    int regresarDia(); 
    //Tiempo de Ejecucion O(1)
    int regresarH();
    //Tiempo de Ejecucion O(1)
    int RegresarMinutos();
    //Tiempo de Ejecucion O(1)
    int RegresarSegundos(); 
    //Tiempo de Ejecucion O(1)
    string RegresarLinea(); 
    
};

#endif