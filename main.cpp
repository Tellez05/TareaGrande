#include "Class.H"
#include "Functions.h"

int main(){
    vector<Documento*> Libreria; 
    CargarLibreria(Libreria); 
    ImprimirTodo(Libreria); 
    return 0; 
}