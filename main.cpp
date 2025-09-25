#include "Class.H"
#include "Functions.h"

int main(){
    vector<Documento*> Libreria; 
    CargarLibreria(Libreria); 
    ArreglarArreglo(Libreria); 
    bool V {true}; 
    while(V == true){
        V = Menu(Libreria); 
    }

  
    return 0; 
}