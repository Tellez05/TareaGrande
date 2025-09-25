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