#include "Class.h"


void CargarLibreria(vector<Documento*> &Libreria);
void ImprimirTodo(vector<Documento*> Libreria); 
void ArreglarArreglo(vector<Documento*> &Libreria, vector<int> &IndicesMeses); 
void Arreglarminiarreglos(vector<Documento*> &Libreriachica, vector<Documento*> &LibreriaGrande, int &contador); 
void ArreglarTiempoCompleto(vector<Documento*> &Libreria);
void EntregarDocumento(vector<Documento*> Libreria); 
bool Menu(vector<Documento*> Libreria, vector<int> IndiceMeses); 
void EntregarDocumentoBusq(vector<Documento*>Libreria, vector<int> IndiceMeses); 
void SacarBusq(vector<Documento*> Libreria, vector<int> IndiceMeses); 
string CreadorNombre(int contador); 