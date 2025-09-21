#include "Class.h"


Documento::Documento(string linea){
    stringstream ss(linea); 
    
    string mes, dia , hora, ip, v1, v2, v3 , v4 ,v5 ,v6; 
    ss >> mes >> dia >> hora >> ip >> v1 >> v2 >> v3 >> v4 >> v5 >> v6; 
    
    string razon; 
    string espacio {" "}; 
    
    razon += v1 + espacio + v2 + espacio + v3 + espacio + v4; 
    if(!v5.empty()){
        razon += espacio + v5 + espacio + v6; 
    }

    

}   