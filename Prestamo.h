#ifndef PRESTAMO_H
#define PRESTAMO_H
#include "Fecha.h"

//forward declaration tanto de Socio como de Libro, para poder declarar punteros
//a ambas clases dentro de la declaracion de la clase Prestamo
class Libro;
class Socio;

struct ficha_prestamo{
	unsigned int id_libro;
	unsigned int id_socio;
	fecha inicio;
	fecha limite;
	fecha devolucion;
};

class Prestamo {
private:
	
//	Libro* plibro;
//	Socio* psocio;
	
	unsigned int id_libro;
	unsigned int id_socio;
	
	//fecha en la cual se realiza el prestamo
	fecha inicio;
	//fecha en la cual el libro prestado deberia ser devuelto
	fecha limite;
	//fecha real en la cual el socio devuelve el libro
	//vale cero hasta que el prestamo es cancelado
	fecha devolucion;
	
public:
	Prestamo();
	Prestamo(unsigned int idlibro, unsigned int idsocio, unsigned int duracion);
	Prestamo(unsigned int idlibro, unsigned int idsocio, fecha ini, fecha lim);
	
	unsigned int GetIdLibro() const;
	unsigned int GetIdSocio() const;
	
	bool Devuelto();
	bool Pendiente();
	bool Atrasado();

	void Cargar(ifstream &archivo);
	void Guardar(ofstream &archivo);
	
	~Prestamo();
};

#endif

