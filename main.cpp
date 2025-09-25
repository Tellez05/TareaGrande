#include "Class.H"
#include "Functions.h"

int main(){
    vector<Documento*> Libreria;
    vector<int> IndicesMeses;  
    CargarLibreria(Libreria); 
    ArreglarArreglo(Libreria, IndicesMeses); 
    EntregarDocumento(Libreria);
    bool V {true}; 
    while(V == true){
        V = Menu(Libreria,IndicesMeses); 
    }
    return 0; 
}