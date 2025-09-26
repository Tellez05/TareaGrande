/*
Andres Tellez Bermudez Matricula: A01640907
Luis Eduardo Michel    Matricula: A01641578
Jared Rafael Garcia    Matricula: A01640914
Fecha: 25/09/2025
Tarea 1.3
*/
#include "Class.h"


void CargarLibreria(vector<Documento*> &Libreria);
void ArreglarArreglo(vector<Documento*> &Libreria, vector<int> &IndicesMeses); 
void Arreglarminiarreglos(vector<Documento*> &Libreriachica, vector<Documento*> &LibreriaGrande, int &contador); 
void ArreglarTiempoCompleto(vector<Documento*> &Libreria);
void EntregarDocumento(vector<Documento*> Libreria); 
bool Menu(vector<Documento*> Libreria, vector<int> IndiceMeses, int &contador); 
void EntregarDocumentoBusq(vector<Documento*>Libreria, vector<int> IndiceMeses, int Inicio, int Final, string nombre); 
void SacarBusq(vector<Documento*> Libreria, vector<int> IndiceMeses, string BusquedaInicial, string BusquedaFinal, int &inicio, int &final); 
void SacarDiaMes(string &PrimerMes, string &SegundoMes, int &PrimerDia, int &SegundoDia, string PrimeraBusqueda, string SegundaBusqueda); 
void SacarPrimerContador (int &contadorInicial,string PrimerMes, int PrimerDia,vector<int> IndiceMeses, vector<Documento*> Libreria);
void SacarSegundoContador (int &contadorFinal ,string SegundoMes, int SegundoDia, vector<int> IndiceMeses, vector<Documento*> Libreria);
string CreadorNombre(int contador); 