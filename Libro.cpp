#include "Libro.h"
#include <cstring>
#include <fstream>
#include "Funciones.h"
using namespace std;

unsigned int Libro::proximo_id=0;

Libro::Libro() {
	prestamo_actual=NULL;
}
Libro::Libro(string tit, string aut, string edi, string isb, string cat, unsigned int an){
	titulo = tit;
	autor = aut;
	editorial = edi;
	ISBN = isb;
	categoria = cat;
	anio = an;
/*	nro_copias=nc;*/
	id = proximo_id;
	proximo_id++;
	prestamo_actual = NULL;
}

void Libro::SetTitulo(string a){
	titulo = a;
}
void Libro::SetAutor(string a){
	autor = a;
}
void Libro::SetEditorial(string a){
	editorial = a;
}
void Libro::SetISBN(string a){
	ISBN = a;
}
void Libro::SetCategoria(string a){
	categoria = a;
}
void Libro::SetAnio(unsigned int a){
	anio = a;
}
//void Libro::SetNroCopias(unsigned int a){
//	nro_copias=a;
//}

//void Libro::QuitarCopia(){
//	nro_copias--;
//}
//void Libro::AgregarCopia(){
//	nro_copias++;
//}

string Libro::GetTitulo() const{
	return titulo;
}
string Libro::GetAutor() const{
	return autor;
}
string Libro::GetEditorial() const{
	return editorial;
}
string Libro::GetISBN() const{
	return ISBN;
}
string Libro::GetCategoria() const{
	return categoria;
}
unsigned int Libro::GetId() const{
	return id;
}
unsigned int Libro::GetAnio() const{
	return anio;
}
//unsigned int Libro::GetNumCopias() const{
//	return nro_copias;
//}

void Libro::SetPrestamoActual(Prestamo& p){
	prestamo_actual=&p;
}

Prestamo* Libro::GetPrestamoActual() const{
	return prestamo_actual;
}

bool Libro::EstaDisponible(){
	return (prestamo_actual==NULL);
}
bool Libro::EstaPrestado(){
	return (prestamo_actual!=NULL);
}
bool Libro::EstaAtrasado(){
	//controla que el libro este prestado en primer lugar
	if (this->EstaDisponible()) return false;
	//si esta prestado llama a la funcion Atrasado de su propia instancia de prestamo
	else return (prestamo_actual->Atrasado());
}

void Libro::Cargar(ifstream &archivo){
	ficha_libro f;
	archivo.read((char*)&f,sizeof(f));
	titulo=f.titulo;
	autor=f.autor;
	editorial=f.editorial;
	ISBN=f.ISBN;
	categoria=f.categoria;
/*	nro_copias=f.ncop;*/
	anio=f.anio;
	id=f.id;
}

void Libro::Guardar(ofstream &archivo){
	ficha_libro f;
	strcpy( f.titulo, titulo.c_str() );
	strcpy(f.autor, autor.c_str() );
	strcpy(f.editorial, editorial.c_str() );
	strcpy(f.ISBN, ISBN.c_str() );
	strcpy(f.categoria, categoria.c_str() );
	f.anio = anio;
/*	f.ncop=nro_copias;*/
	f.id = id;
	archivo.write( (char*)&f, sizeof(f) );
}

//Las siguientes funciones reciben un string y buscan dicho string entre los 
//distintos atributos de la clase Libro, se añade un espacio al principio tanto
//del string buscado como al principio del string en el que hay que buscar, esto
//es porque solo interesa buscar el string como una palabra entera y no como parte
//de otras palabras, por ejemplo si el usuario busca solo la letra "a" solo tendria que
//ver los libros con palabras que empiecen con "a"

bool Libro::Buscar_En_Titulo(string &b){	//retorna la posicion
	string s(" ");
	s += titulo;
	//unsigned int n=s.size();
	Pasar_a_Minusculas( s );
	//for(unsigned int i=0;i<n;i++) s[i]=tolower(s[i]);
	return( s.find(b) != string::npos );
}
bool Libro::Buscar_En_Autor(string &b){
	string s(" ");
	s += autor;
	//unsigned int n=s.size();
	Pasar_a_Minusculas(s);
	//for(unsigned int i=0;i<n;i++) s[i]=tolower(s[i]);
	return(s.find(b)!=string::npos);
}
bool Libro::Buscar_En_Editorial(string &b){
	string s(" ");
	s+=editorial;
	//unsigned int n=s.size();
	Pasar_a_Minusculas(s);
	//for(unsigned int i=0;i<n;i++) s[i]=tolower(s[i]);
	return(s.find(b)!=string::npos);
}
bool Libro::Buscar_En_ISBN(string &b){
	string s(" ");
	s+=ISBN;
	//unsigned int n=s.size();
	Pasar_a_Minusculas(s);
	//for(unsigned int i=0;i<n;i++) s[i]=tolower(s[i]);
	return(s.find(b)!=string::npos);
}
bool Libro::Buscar_En_Categoria(string &b){
	string s(" ");
	s+=categoria;
	//unsigned int n=s.size();
	Pasar_a_Minusculas(s);
	//for(unsigned int i=0;i<n;i++) s[i]=tolower(s[i]);
	return(s.find(b)!=string::npos);
}
bool Libro::Buscar_Por_Anio(unsigned int n){
	return (anio==n);
}

//Las siguientes funciones permiten ver y modificar el valor de la variable static
//que genera el id de cada libro, esto permite que la variable tenga el valor correcto
//al iniciar el programa, ya que por defecto se inicializa en cero y solo se incrementa
//al llamar al constructor, pero si ya hay libros en existencia su valor deberia ser igual
//al valor del mayor valor de id existente mas uno

void SetProximoId(unsigned int a){
	Libro::proximo_id=a;
}

unsigned int GetProximoId() {
	return Libro::proximo_id;
}

Libro::~Libro() {
	
}
