#ifndef BIBLIOTECA_H
#include <vector>
#include <list>
#include <string>
#include "Libro.h"
#include "Socio.h"
#include "Prestamo.h"
using namespace std;
#define BIBLIOTECA_H

enum comparar_por{
	libro_titulo,
	libro_autor,
	libro_categoria,
	libro_editorial,
	socio_apellido_y_nombre,
	socio_dni
	};

class Biblioteca {
private:
	
	string ultima_cadena_buscada_libro;
	string ultima_cadena_buscada_socio;
	comparar_por crit;
	
	string datoslibros;
	string datossocios;
	string datosprestamos;
	
	vector<Libro> v_libros;
	vector<Socio> v_socios;
	list<Prestamo> l_prestamos;
	//para los préstamos se decidió usar una lista STL en lugar de un vector STL 
	//por varias razones:
	//a)no se necesita acceso aleatorio al conjunto de préstamos
	//b)se realizarán muchas altas y bajas de préstamos por día
	//c)como tanto la clase Socio como la clase Libro utilizan punteros hacia instancias
	//de la clase Préstamo, un vector de Préstamos implicaría que al eliminar uno se pueda
	//modificar la posicion en memoria de las instancias restantes lo cual no ocurre con la lista
	
public:
	
//	int numerito;
	
	Biblioteca();
	Biblioteca( string dlibros, string dsocios, string dprestamos );
	
	//Metodos correspondientes a los libros
	Libro& VerLibro(unsigned int indice);
	//funcion que, dado un numero de id, retorna la posicion del libro con ese id, o -1 si no existe
	int BuscarLibro(unsigned int codigo);
	
	//funciones para filtrar la lista de libros de acuerdo a los distintos campos posibles
	void FiltrarLibrosPorTitulo( vector<unsigned int>& indices, vector<unsigned int>& restantes, string filtro );
	void FiltrarLibrosPorAutor( vector<unsigned int>& indices, vector<unsigned int>& restantes, string filtro );
	void FiltrarLibrosPorEditorial( vector<unsigned int>& indices, vector<unsigned int>& restantes, string filtro );
	void FiltrarLibrosPorCategoria( vector<unsigned int>& indices, vector<unsigned int>& restantes, string filtro );
	//funcion que guarda la ultima cadena que se uso para buscar libros, utilizada para mantener la busqueda
	string Ver_Ultima_Busqueda_Libro() const;
	
	
	void AgregarLibro( Libro& l );
	void EliminarLibro( unsigned int indice );
	unsigned int TotalLibros();
	void GuardarLibros();
	
	//Metodos correspondientes a los socios
	Socio& VerSocio(unsigned int indice);
	int BuscarSocio(unsigned int codigo);
	
	//funciones para filtrar la lista de socios de acuerdo a los distintos campos posibles
	void FiltrarSociosPorApellido(vector<unsigned int>& indices,vector<unsigned int>& restantes,string filtro);
	//funcion que guarda la ultima cadena que se uso para buscar socios, utilizada para mantener la busqueda
	string Ver_Ultima_Busqueda_Socio() const;
	
	//funcion para agregar un socio al arreglo
	void AgregarSocio(Socio &S);
	//funcion para quitar un socio del arreglo
	void EliminarSocio(unsigned int indice);
	unsigned int TotalSocios();
	void GuardarSocios();
	
	//metodos correspondientes a los préstamos
	void GuardarPrestamos();
	void AgregarPrestamo(Prestamo p);	
	
	//Otros metodos
	
	//para ordenar los libros o los socios, en lugar de ordenar el vector correspondiente
	//se ordena un vector de enteros cuyos valores son las posiciones de los libros 
	//o los socios en su respectivo vector
	//estos vectores de enteros no estan dentro de la clase Biblioteca, sino que son 
	//utilizadas por distintas instancias de las clases que componen la interfaz
	//el operador paréntesis sobrecargado nos permite ordenar estas listas usando la
	//funcion sort, con una instancia de la clase Biblioteca como tercer argumento
	bool operator()(unsigned int a, unsigned int b);
	//permite modificar la variable que se usa para indicarle a la biblioteca qué 
	//vector y campo se va a usar para ordenar
	void CambiarCriterio(comparar_por c);
	
	~Biblioteca();
};

extern Biblioteca* La_Biblioteca;

#endif

