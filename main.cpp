/*
Andres Tellez Bermudez Matricula: A01640907
Luis Eduardo Michel    Matricula: A01641578
Jared Rafael Garcia    Matricula: A01640914
Fecha: 25/09/2025
Tarea 1.3
*/

#include "Class.H"
#include "Functions.h"

int main(){
    vector<Documento*> Libreria;
    int Contador {1};
    vector<int> IndicesMeses;  
    CargarLibreria(Libreria); 
    ArreglarArreglo(Libreria, IndicesMeses); 
    EntregarDocumento(Libreria);
    bool V {true}; 
    while(V == true){
        V = Menu(Libreria,IndicesMeses, Contador); 
    }
    return 0; 
}