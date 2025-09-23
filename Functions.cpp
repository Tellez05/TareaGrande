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
        return true; 
    }
    return false; 

}


void Arreglarminiarreglos(vector<Documento*> &Libreriachica, vector<Documento*> &LibreriaGrande,int &contador){
    for(int  i {0}; i < Libreriachica.size();i++){
        Documento* Keypuntero {Libreriachica[i]};
        int key {Keypuntero -> regresarDia()}; 
        int j {i-1};
        while(j >= 0 && Libreriachica.at(j) -> regresarDia() > key ){
            Libreriachica[j+1] = Libreriachica[j];
            j--;   
        }
        Libreriachica[j+1] = Keypuntero;
    }

    for(int k {0}; k < Libreriachica.size(); k++){
        LibreriaGrande[contador] = Libreriachica[k];
        contador ++; 
    }
}


void ArreglarArreglo(vector<Documento*> &Libreria){ 
    int contador {0};
    vector<Documento*> MesJUN ; 
    vector<Documento*> MesJUL ; 
    vector<Documento*> MesAUG ; 
    vector<Documento*> MesSEP ; 
    vector<Documento*> MesOCT ; 

    for(auto *linea: Libreria){
        if(linea->RegresarMes() == "Jun"){
            MesJUN.push_back(linea);
        }
        else if(linea->RegresarMes() == "Jul"){
            MesJUL.push_back(linea);            
        }
        else if(linea->RegresarMes() == "Aug"){
            MesAUG.push_back(linea);
        }
        else if(linea->RegresarMes() == "Sep"){
            MesSEP.push_back(linea);
        }else{
            MesOCT.push_back(linea);
        }
    }
    Arreglarminiarreglos(MesJUN, Libreria,contador); 
    Arreglarminiarreglos(MesJUL, Libreria,contador);     
    Arreglarminiarreglos(MesAUG, Libreria,contador);
    Arreglarminiarreglos(MesSEP, Libreria,contador);
    Arreglarminiarreglos(MesOCT, Libreria,contador);
    ImprimirTodo(Libreria);
}
