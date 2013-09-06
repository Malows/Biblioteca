#include "Prestamo.h"
#include "Libro.h"
#include "Socio.h"
#include <fstream>
using namespace std;

Prestamo::Prestamo(){
	
}

Prestamo::Prestamo(unsigned int idlibro, unsigned int idsocio, unsigned int duracion) {
	/*_libro.QuitarCopia();*/
	
	id_libro=idsocio;
	id_socio=idlibro;
	
	
//	plibro=&_libro;
//	psocio=&_socio;
	
	inicio=GetFecha(time(NULL));
	limite=GetFechaX(duracion);
	devolucion=0;
	
}

Prestamo::Prestamo(unsigned int idlibro, unsigned int idsocio, fecha ini, fecha lim){
	id_libro=idsocio;
	id_socio=idlibro;
	inicio=ini;
	limite=lim;
	devolucion=0;
}

unsigned int Prestamo::GetIdLibro() const{
	return id_libro;
}
unsigned int Prestamo::GetIdSocio() const{
	return id_socio;
}

bool Prestamo::Devuelto(){
	return (devolucion!=0);
}

bool Prestamo::Pendiente(){
	return (devolucion==0);
}

bool Prestamo::Atrasado(){
	return (limite<GetFechaHoy());
}

void Prestamo::Cargar(ifstream &archivo){
	ficha_prestamo f;
	archivo.read((char*)&f,sizeof(f));
	id_libro=f.id_libro;
	id_socio=f.id_socio;
	inicio=f.inicio;
	devolucion=f.devolucion;
	limite=f.limite;
}

void Prestamo::Guardar(ofstream &archivo){
	ficha_prestamo f;
	f.id_libro=id_libro;
	f.id_socio=id_socio;
	f.inicio=inicio;
	f.devolucion=devolucion;
	f.limite=limite;
	archivo.write((char*)&f,sizeof(f));
}

Prestamo::~Prestamo() {
	
}

