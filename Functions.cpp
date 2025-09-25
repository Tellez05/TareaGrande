#include "Functions.h"

void CargarLibreria(vector<Documento*> &Libreria){
    ifstream archivo("bitacora.txt");
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
        int diaActual {Libreria[i]->regresarDia()};
        int j {i};
        while(j < n && Libreria[j]->regresarDia() == diaActual){
            j++;
        }
        for(int k {i + 1}; k < j; k++){
            Documento* key {Libreria[k]};
            int keyHora {key->regresarH()};
            int keyMin  {key->RegresarMinutos()};
            int keySeg  {key->RegresarSegundos()};
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
void ArreglarArreglo(vector<Documento*> &Libreria, vector<int> &IndicesMeses){ 
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

    int JUN, FJUN, JUL, FJUL, AUG, FAUG, SEP, FSEP,OCT, FOCT; 
    JUN = 0;
    FJUN = MesJUN.size()-1; 
    JUL = FJUN + 1;
    FJUL = JUL+MesJUL.size();
    AUG = FJUL + 1; 
    FAUG = AUG + MesAUG.size(); 
    SEP = FAUG + 1; 
    FSEP = SEP + MesSEP.size(); 
    OCT = FSEP + 1; 
    FOCT = Libreria.size(); 
    IndicesMeses.push_back(JUN);
    IndicesMeses.push_back(FJUN);
    IndicesMeses.push_back(JUL);
    IndicesMeses.push_back(FJUL);
    IndicesMeses.push_back(AUG);
    IndicesMeses.push_back(FAUG);
    IndicesMeses.push_back(SEP);
    IndicesMeses.push_back(FSEP);
    IndicesMeses.push_back(OCT);
    IndicesMeses.push_back(FOCT);

}
void EntregarDocumento(vector<Documento*> Libreria){
    
    ofstream Myfile("BitacoraOrdenada1.3-eq1");
    for(int i {0}; i < Libreria.size(); i++){
        Myfile << Libreria[i] -> RegresarLinea()<<endl; 
    }
    Myfile.close();
}

void SacarDiaMes(string &PrimerMes, string &SegundoMes, int &PrimerDia, int &SegundoDia, string PrimeraBusqueda, string SegundaBusqueda){
    stringstream ss(PrimeraBusqueda);
    ss >> PrimerMes >> PrimerDia;
    stringstream ss2(SegundaBusqueda);
    ss2 >> SegundoMes >> SegundoDia;  
}

void SacarPrimerContador (int &contadorInicial ,string PrimerMes, int PrimerDia, vector<int> IndiceMeses, vector<Documento*> Libreria){
    int contadorMes{0};
    int finalMes{0};
    if(PrimerMes == "Jun"){
        contadorMes = IndiceMeses[0];
        finalMes = IndiceMeses[1];
    }
    else if(PrimerMes == "Jul"){
        contadorMes = IndiceMeses[2];
        finalMes = IndiceMeses[3]; 
    }
    else if(PrimerMes == "Aug"){
        contadorMes = IndiceMeses[4];
        finalMes = IndiceMeses[5];

    }
    else if(PrimerMes == "Sep"){
        contadorMes = IndiceMeses[6];
        finalMes = IndiceMeses[7];
    }else{
        contadorMes = IndiceMeses[8];
        finalMes = IndiceMeses[9];
    }
    
    int Inicio {contadorMes};
    int Medio {(Inicio + finalMes)/2}; 
    while(Inicio <= finalMes){
        Medio = (Inicio + finalMes)/2;
        if(PrimerDia == Libreria[Medio] -> regresarDia()){
            contadorInicial = Medio; 
            break; 
        }
        else if(PrimerDia < Libreria[Medio] -> regresarDia()){
            finalMes = Medio -1; 
        }
        else{
            Inicio = Medio +1; 
        }
    }

    while(Libreria[contadorInicial] -> regresarDia() == PrimerDia && Libreria[contadorInicial-1] -> regresarDia() == PrimerDia && contadorInicial > contadorMes){
        contadorInicial -= 1; 
    }

    
}

void SacarSegundoContador (int &contadorFinal ,string SegundoMes, int SegundoDia, vector<int> IndiceMeses, vector<Documento*> Libreria){
    int contadorMes{0};
    int finalMes{0};
    if(SegundoMes == "Jun"){
        contadorMes = IndiceMeses[0];
        finalMes = IndiceMeses[1];
    }
    else if(SegundoMes == "Jul"){
        contadorMes = IndiceMeses[2];
        finalMes = IndiceMeses[3]; 
    }
    else if(SegundoMes == "Aug"){
        contadorMes = IndiceMeses[4];
        finalMes = IndiceMeses[5];

    }
    else if(SegundoMes == "Sep"){
        contadorMes = IndiceMeses[6];
        finalMes = IndiceMeses[7];
    }else{
        contadorMes = IndiceMeses[8];
        finalMes = IndiceMeses[9];
    }
    
    int Inicio {contadorMes};
    int Medio {(Inicio + finalMes)/2}; 
    while(Inicio <= finalMes){
        Medio = (Inicio + finalMes)/2;
        if(SegundoDia == Libreria[Medio] -> regresarDia()){
            contadorFinal = Medio; 
            break; 
        }
        else if(SegundoDia < Libreria[Medio] -> regresarDia()){
            finalMes = Medio -1; 
        }
        else{
            Inicio = Medio +1; 
        }
    }

    while(Libreria[contadorFinal] -> regresarDia() == SegundoDia && Libreria[contadorFinal+1] -> regresarDia() == SegundoDia && contadorFinal < finalMes){
        contadorFinal += 1; 
    }

    
}

void SacarBusq(vector<Documento*> Libreria, vector<int> IndicesMeses, string BusquedaInicial, string BusquedaFinal,  int &contadorInicio, int &contadorFinal){ 
    string PrimerMes, SegundoMes; 
    int PrimerDia, SegundoDia;
    SacarDiaMes(PrimerMes, SegundoMes, PrimerDia, SegundoDia, BusquedaInicial, BusquedaFinal);
    SacarPrimerContador(contadorInicio, PrimerMes, PrimerDia, IndicesMeses, Libreria);
    SacarSegundoContador(contadorFinal, SegundoMes, SegundoDia, IndicesMeses, Libreria);
}

void EntregarDocumentoBusq(vector<Documento*> Libreria, vector<int> IndiceMeses, int Inicio, int Final, string nombre){
    ofstream MyDocument{nombre};
    for(int i {Inicio}; i <= Final; i++){
        MyDocument << Libreria[i] -> RegresarLinea()<<endl;
    }
    MyDocument.close();
}
string CreadorNombre(int contador){
    string numero {to_string(contador)};
    return "Salida"+numero+"-eq5"; 
}
bool Menu(vector<Documento*> Libreria, vector<int> IndiceMeses, int &contador){
    cout<<"Menu: "<<endl; 
    cout<<"1.- Busqueda"<<endl; 
    cout<<"2.- Salir"<<endl; 
    cout<<"Opcion: "; 
    int opcion {0}; 
    cin >> opcion ; 
    if(opcion == 1){
        int Inicio, Final; 
        cout<<"Formato es: Mes Dia,  (Eje: Oct 8) "<<endl; 
        string busquedaInicial, busquedaFinal, Nombre;
        Nombre = CreadorNombre(contador);
        cout<<"Que Mes y dia quieres buscar: ";
        cin.ignore(); 
        getline(cin,busquedaInicial); 
        cout<<endl;
        cout<<"Hasta que Mes y dia quieres buscar: ";
        getline(cin,busquedaFinal);
        SacarBusq(Libreria, IndiceMeses, busquedaInicial, busquedaFinal, Inicio, Final); 
        EntregarDocumentoBusq(Libreria, IndiceMeses, Inicio, Final, Nombre); 
        contador += 1; 
        return true; 
    }else if(opcion == 2){
        return false; 
    } 
    else{
        cout<<"Opcion invalida"<<endl; 
        return true;
    }
}