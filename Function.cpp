#include "Functions.h"

void CargarLibreria(vector<Documento*> &Libreria){
    ifstream archivo("Texto.txt");
    string linea; 

    while(getline(archivo, linea)){
        Documento* Linea = new Documento(linea); 
        Libreria.push_back(Linea);
    }
}



void ImprimirTodo(vector<Documento*> Libreria){
    for(auto *Linea: Libreria){
        Linea -> Imprimir(); 
    }
}