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

bool CompararMeses(Documento *mes1, Documento *mes2){
    int Size {5};
    int I1 {0};
    int I2 {0}; 
    string Meses[Size] {"Jun", "Jul", "Aug", "Sep", "Oct"}; 
    for(int i {0}; i < Size-1; i++){
        if(mes1->RegresarMes() == Meses[i]){
            I1 = i; 
        }
        if(mes2->RegresarMes() == Meses[i]){
            I2 = i; 
        }
        
    }
    if(I2 > I1){
    }


}