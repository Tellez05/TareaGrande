    #include "Class.h"

    Documento::Documento(string linea){
        stringstream ss(linea); 
        int dia; 
        string mes, hora, ip, v1, v2, v3 , v4 ,v5 ,v6; 
        ss >> mes >> dia >> hora >> ip >> v1 >> v2 >> v3 >> v4 >> v5 >> v6; 
        PonerStringDia(dia);
        string razon; 
        string espacio {" "}; 
        
        razon += v1 + espacio + v2; 
        if(!v5.empty()){
            razon += espacio + v5 + espacio + v6; 
        }
        else if (!v3.empty()){
            razon += espacio + v3 +espacio + v4 + espacio + v5 + espacio + v6; 
        }
        
        Mes = mes; 
        Dia = dia; 
        Hora = hora; 
        IP = ip; 
        Razon = razon; 
        Ponertiempo(Hora);
    }   

    void Documento::Imprimir(){
        cout<<Mes<<" "<<Dia<<" "<<Hora<<" "<<IP<<" "<<Razon<<endl; 

    }   
    void Documento::Ponertiempo(string linea){
        string creador {linea[0]}; 
        string creador2 {linea[3]};
        string creador3 {linea[6]}; 
        creador += linea[1];
        creador2 += linea[4];
        creador3 += linea[7];
        stringstream ss(creador);
        ss>>H;
        stringstream ss2(creador2);
        ss2>>Minuto;
        stringstream ss3(creador3);
        ss3>>Segundos;
    }

    string Documento::RegresarMes(){
        return Mes; 
    }
    int Documento::regresarH(){
        return H;
    }
    int Documento::RegresarMinutos(){
        return Minuto;
    }
    int Documento::RegresarSegundos(){
        return Segundos; 
    }
    int Documento::regresarDia(){ 
        return Dia; 
    }
    void Documento::PonerStringDia(int numero){
        diaString = to_string(numero);
    }
    string Documento::RegresarLinea(){
        string espacio {" "};
        return Mes + espacio + diaString + espacio + Hora + espacio + IP + espacio + Razon;
    }