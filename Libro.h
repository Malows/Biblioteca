#ifndef LIBRO_H

#include <string>
#include <vector>

#include "Prestamo.h"
using namespace std;
#define LIBRO_H

struct ficha_libro{
	char titulo[100];
	char autor[100];
	char editorial[100];
	char ISBN[13];
	char categoria[100];
	unsigned int anio;
	int numeroEjemplar
	unsigned int id;
};

class Libro {
private:
	//datos que hacen al libro
	string titulo;
	string autor;
	string editorial;
	string ISBN;
	string categoria;
	unsigned int anio;
	
	int numeroEjemplar;
	
//	unsigned int nro_copias;
//	vector <Prestamo*> prestamos;
	
	Prestamo* prestamo_actual;
	
	//codigo unico del libro asignado automaticamente
	unsigned int id;
	//variable que almacena el valor del proximo codigo
	static unsigned int proximo_id;
	
public:
	Libro();
	~Libro();
	
	Libro( string tit, string aut, string edi, string isb, string cat, unsigned int an );
	
	//funciones para modificar atributos
	
	void SetTitulo( string );
	void SetAutor( string );
	void SetEditorial( string );
	void SetISBN( string );
	void SetCategoria( string );
	void SetAnio( unsigned int );
//	void SetNroCopias(unsigned int a);
//	void QuitarCopia();
//	void AgregarCopia();
	
	//funciones para obtener atributos
	
	string GetTitulo() const;
	string GetAutor() const;
	string GetEditorial() const;
	string GetISBN() const;
	string GetCategoria() const;
	unsigned int GetAnio() const;
	unsigned int GetId() const;
/*	unsigned int GetNumCopias() const;*/
	
	//funciones para buscar un valor en cada atributo
	
	bool Buscar_En_Titulo( string& b );
	bool Buscar_En_Autor( string& b );
	bool Buscar_En_Editorial( string& b );
	bool Buscar_En_ISBN( string& b );
	bool Buscar_En_Categoria( string& b );
	bool Buscar_Por_Anio( unsigned int n );
	
	void SetPrestamoActual( Prestamo& p );
	Prestamo* GetPrestamoActual() const;
	
	bool EstaDisponible();
	bool EstaPrestado();
	bool EstaAtrasado();
	
	void Cargar( ifstream& archivo );
	void Guardar( ofstream& archivo );
	
	friend void SetProximoId(unsigned int a);
	friend unsigned int GetProximoId();
	
};

void SetProximoId(unsigned int a);
unsigned int GetProximoId();

#endif
