#include "Socio.h"
#include <cstring>
#include <fstream>
#include "Funciones.h"
using namespace std;

unsigned int Socio::proxima_id=0;

Socio::Socio() {
	
}

Socio::Socio(string nom, string ape, unsigned int d){
	
	//asignacion de los datos del socio
	
	nombre=nom;
	apellido=ape;
	dni=d;
	
	//asignación automática del código y actualización del 
	//código para el proximo socio
	
	id=proxima_id;
	proxima_id++;
}

string Socio::GetApellido() const{
	return apellido;
}
string Socio::GetNombre() const{
	return nombre;
}
int Socio::GetDNI() const{
	return dni;
}
int Socio::GetCantPrestamos(){
	return prestamos.size();
}
unsigned int Socio::GetId() const{
	return id;
}

void Socio::SetApellido(string &s){
	apellido=s;
}
void Socio::SetNombre(string &s){
	nombre=s;
}
void Socio::SetDNI(int d){
	dni=d;	
}

bool Socio::Buscar_En_Apellido(string &b){
	string s(" ");
	s+=apellido;
	Pasar_a_Minusculas(s);
	return(s.find(b)!=string::npos);
}

void Socio::AddPrestamo(Prestamo& p){
	Prestamo* aux=&p;
	prestamos.push_back(aux);
}

void Socio::Cargar(ifstream &archivo){
	ficha_socio f;
	archivo.read((char*)&f,sizeof(f));
	nombre=f.nombre;
	apellido=f.apellido;
	dni=f.dni;
	id=f.id;
}
void Socio::Guardar(ofstream &archivo){
	ficha_socio f;
	strcpy(f.nombre,nombre.c_str());
	strcpy(f.apellido,apellido.c_str());
	f.id=id;
	f.dni=dni;
	archivo.write((char*)&f,sizeof(f));
}

Socio::~Socio() {
	
}

void S_SetProximoId(unsigned int a){
	Socio::proxima_id=a;
}
unsigned int S_GetProximoId(){
	return Socio::proxima_id;
}
