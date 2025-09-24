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
void ArreglarTiempo(vector<Documento*> &Libreria){
    for(int i {0}; i<Libreria.size(); i++){
        Documento* PTR {Libreria[i]};
    }
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

void ArreglarTiempoCompleto(vector<Documento*> &Libreria) {
    int n = Libreria.size();
    for(int i {0}; i < n; i++){
        int diaActual = Libreria[i]->regresarDia();
        int j {i};
        while(j < n && Libreria[j]->regresarDia() == diaActual){
            j++;
        }
        for(int k {i + 1}; k < j; k++){
            Documento* key = Libreria[k];
            int keyHora = key->regresarH();
            int keyMin = key->RegresarMinutos();
            int keySeg = key->RegresarSegundos();
            int l = k - 1;
            while(l >= i){
                Documento* curr {Libreria[l]};
                if(curr->regresarH() > keyHora ||
                   (curr->regresarH() == keyHora && curr->RegresarMinutos() > keyMin) ||
                   (curr->regresarH() == keyHora && curr->RegresarMinutos() == keyMin && curr->RegresarSegundos() > keySeg)) {
                    Libreria[l+1] = Libreria[l];
                    l--;
                } else {
                    break;
                }
            }
            Libreria[l+1] = key;
        }
        i = j - 1; 
    }
}

void ArreglarArreglo(vector<Documento*> &Libreria){ 
    int contadorH {0}; 
    int contador {0};
    vector<Documento*> MesJUN; 
    vector<Documento*> MesJUL; 
    vector<Documento*> MesAUG; 
    vector<Documento*> MesSEP; 
    vector<Documento*> MesOCT; 

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

    ArreglarTiempoCompleto(Libreria);
    ImprimirTodo(Libreria);
}
