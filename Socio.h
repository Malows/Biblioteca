#ifndef SOCIO_H
#include <string>
#include <vector>
#include "Prestamo.h"
using namespace std;
#define SOCIO_H

struct ficha_socio{
	char nombre[100];
	char apellido[100];
	unsigned int id;
	int dni;
};

class Socio {
private:
	
	string nombre;
	string apellido;
	int dni;
	
	vector<Prestamo*> prestamos;
	
	unsigned int id;
	static unsigned int proxima_id;
	
public:
	Socio();
	Socio(string nom, string ape, unsigned int d);
	
	string GetNombre() const;
	string GetApellido() const;
	int GetDNI() const;
	int GetCantPrestamos();
	unsigned int GetId() const;
	
	void SetNombre(string &s);
	void SetApellido(string &s);
	void SetDNI(int d);
	
	bool Buscar_En_Apellido(string &b);
	
	void AddPrestamo(Prestamo& p);
	
	void Guardar(ofstream &archivo);
	void Cargar(ifstream &archivo);
	
	friend void S_SetProximoId(unsigned int a);
	friend unsigned int S_GetProximoId();
	
	~Socio();
};

void S_SetProximoId(unsigned int a);
unsigned int S_GetProximoId();

#endif

