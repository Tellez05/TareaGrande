#include "Class.H"
#include "Functions.h"

int main(){
    vector<Documento*> Libreria; 
    CargarLibreria(Libreria); 
    ArreglarArreglo(Libreria); 
    EntregarDocumento(Libreria); 
    return 0; 
}