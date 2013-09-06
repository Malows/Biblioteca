#include "Biblioteca.h"
#include <fstream>
#include "Funciones.h"
using namespace std;

Biblioteca* La_Biblioteca;

Biblioteca::Biblioteca() {
	
}

Biblioteca::Biblioteca( string dlibros, string dsocios, string dprestamos ){
	//--------------------Carga de los libros al sistema------------------------
	datoslibros = dlibros;
	ifstream archivo( datoslibros.c_str(), ios::binary );
	bool ordenado_por_id = true;
	
	unsigned int totallibros;
	archivo.read( (char*)&totallibros, sizeof(totallibros) );
	if( totallibros > 0 ){
		v_libros.resize( totallibros );
		for ( unsigned int i = 0; i < totallibros; i++ ){
			v_libros[i].Cargar( archivo );
			if( v_libros[i].GetId() >= GetProximoId() ){
				SetProximoId( v_libros[i].GetId() );
			} else {
				ordenado_por_id = false;
			}
		}
		SetProximoId( GetProximoId() + 1 );
	}
	//--------------------Carga de los socios al sistema------------------------
	datossocios = dsocios;
	ifstream archivo2( datossocios.c_str(), ios::binary );
	ordenado_por_id=true;
	
	unsigned int totalsocios;
	archivo2.read( (char*)&totalsocios, sizeof(totalsocios) );
	if(totalsocios > 0){
		ordenado_por_id = true;
		v_socios.resize( totalsocios );
		for ( unsigned int i = 0; i < totalsocios; i++ ){
			v_socios[i].Cargar( archivo2 );
			if( v_socios[i].GetId() >= S_GetProximoId()){
				S_SetProximoId(v_socios[i].GetId());
			} else {
				ordenado_por_id = false;
			}
		}
		S_SetProximoId( S_GetProximoId() + 1 );
	}
	
	//--------------------Carga de los prestamos al sistema---------------------
	datosprestamos = dprestamos;
		
	//con el objetivo de poder hacer un historial, los prestamos se guardan todos en el
	//mismo archivo, los que ya terminaron y los que están pendientes
	//para el funcionamiento regular del programa, solo interesa cargar los pendientes
	//el programa guarda los prestamos de modo que los pendientes queden al final del archivo
	
	//el archivo de préstamos se abre con el cursor posicionado al final
	ifstream archivo3(datosprestamos.c_str(), ios::binary|ios::ate );
// 	numerito=archivo3.tellg();
	//la variable tprestamos contendrá la cantidad de préstamos en el archivo
	int cant_prestamos=archivo3.tellg()/sizeof(ficha_prestamo);
	//esta variable contará cuántos préstamos se llevan leídos, permitirá controlar que
	//no se supere la capacidad del archivo
	int prestamos_leidos = 0;
	//la siguiente bandera indicará cuando se terminen los préstamos pendientes, lo cual
	//sucederá cuando se lea un préstamo con fecha de devolución distinta a cero (devuelto)
	bool quedan_prestamos_pendientes = true;
	//la siguiente variable calcula cuánto hay que moverse en el archivo para leer una nueva
	//ficha de préstamo, como se lee a partir del último el desplazamiento es negativo
	int desplazamiento = (-1) * sizeof( ficha_prestamo );
	
	while ( quedan_prestamos_pendientes && prestamos_leidos < cant_prestamos ){
		archivo3.seekg( desplazamiento, ios::cur );
		Prestamo p;
		p.Cargar(archivo3);
		if ( p.Pendiente() ){
			//si el prestamo esta pendiente hay que cargarlo en la lista
			list<Prestamo>::iterator it = l_prestamos.insert( l_prestamos.begin(), p );
			//a continuacion, hay que dar de alta los punteros en 
			//el libro y socio correspondientes, para eso primero los buscamos
			//se extrae la id del libro correspondiente y se obtiene su posición en el vector
			int pos_libro = BuscarLibro( it->GetIdLibro() );
			//se pasa la direccion del prestamo en la lista al Libro para crear el puntero
			v_libros[pos_libro].SetPrestamoActual( *it );
			//se extrae la id del socio correspondiente para obtener su posición en el vector
			int pos_socio = BuscarSocio( it->GetIdSocio() );
			//se pasa la direccion en memoria del prestamo al Socio para crear el puntero
			v_socios[pos_socio].AddPrestamo( *it );
			//como hay que seguir leyendo prestamos, hay que volver a mover el cursor de lectura
			//del archivo, de modo que en el siguiente bucle pueda leer un prestamo nuevo
			//el cursor quedo al final del ultimo prestamo leido asi que lo movemos para atras
			//por un valor igual a todo el prestamo
			archivo3.seekg( desplazamiento, ios::cur );
			//además, hay que incrementar el contador de prestamos leidos
			prestamos_leidos++;
		} else {
			//si el prestamo no esta pendiente, hay que finalizar la carga, y para eso se 
			//modifica la bandera quedan_prestamos_pendientes
			quedan_prestamos_pendientes = false;
		}
		
	}
	
}

void Biblioteca::GuardarLibros(){
	ofstream archivo( datoslibros.c_str(), ios::binary );
	unsigned int totallibros = v_libros.size();
	archivo.write( (char*)&totallibros, sizeof(totallibros) );	
	for( unsigned int i = 0; i < totallibros; i++ ){
		v_libros[i].Guardar(archivo);
	}
}

void Biblioteca::AgregarLibro( Libro& l ){
	v_libros.push_back(l);
}

void Biblioteca::EliminarLibro( unsigned int indice ){
	v_libros.erase( v_libros.begin() + indice );
}

Libro& Biblioteca::VerLibro( unsigned int indice ){
	return v_libros[indice];
}

//la siguiente funcion aprovecha el hecho de que los libros estan ordenados por
//su id, lo que hace es ir, lo que significa que el libro con id=x debe estar 
//necesariamente antes de la posicion x del vector (en el caso de que algunos 
// libros hayan sido eliminados) o en la posicion x del vector
int Biblioteca::BuscarLibro( unsigned int codigo ){
	unsigned int n = codigo;
	//primero se revisa el caso en que el codigo buscado es menor que el total de libros
	//en el vector, en este caso se va a la posicion [codigo] del vector y se revisa para
	//atras hasta encontrar un codigo igual o menor al buscado, en caso de que sea menor
	//se concluye que el codigo no existe y se retorna -1, también se controla que el
	//valor de n no llegue a cero, en cuyo caso se llegó al principio del vector
	if( n < v_libros.size() ){
		while ( ( v_libros[n].GetId() > codigo ) && ( n > 0 ) )
			n--;
		if ( v_libros[n].GetId() == codigo )
			return n;
		else
			return -1;
		
		//en caso de que el codigo buscado sea mayor que el tamaño del vector de libros,
		//la busqueda arranca desde el ultimo libro para arriba hasta encontrar el codigo
		//buscado o uno menor (en cuyo caso no hay libro con el codigo buscado y se retorna -1)
	} else {
		n = v_libros.size()-1;
		while( ( v_libros[n].GetId() > codigo ) && ( n > 0 ) )
			n--;
		if ( v_libros[n].GetId() == codigo )
			return n;
		else
			return -1;
	}//es igual? podes usar un continue en el else, n = val -1; continue
	//despues de la reduccion volveria a evaluar el if y de ser necesario volveria a reducir
}

unsigned int Biblioteca::TotalLibros(){
	return v_libros.size();
}


//Esta funciones toman una lista de enteros correspondientes a las posiciones de los libros (en
//el vector de indices) y filtra todos aquellos que no contienen al string que se usa como filtro
//colocandolos en el vector de restantes, o revisa el vector de restantes y reubica a aquellos que
//contienen al filtro en el vector de indices


void Biblioteca::FiltrarLibrosPorTitulo( vector<unsigned int>& indices, vector<unsigned int>& restantes, string filtro ){
	//si se llama la funcion con un string vacio, entonces la funcion simplemente pone todo en el vector indices
	if( filtro.empty() ){
		for( unsigned int aux = 0; aux<restantes.size(); aux++ ){
			indices.push_back( restantes[aux] );
		}
		restantes.clear();
	} else {
		string s(" ");
		s+=filtro;
		//unsigned int n=s.size();
		//for(unsigned int i=0;i<n;i++) s[i]=tolower(s[i]);
		Pasar_a_Minusculas(s);
		if ( filtro.size() > ultima_cadena_buscada_libro.size() ){
			//este codigo corresponde al caso en que el nuevo string es mayor que el
			//ultimo string que se uso para filtrar
			if( filtro.find( ultima_cadena_buscada_libro ) != string::npos ){
				//este codigo se llama si el nuevo string a usar de filtro contiene 
				//al ultimo string que se uso como filtro, en ese caso solo hay que buscar
				//entre los libros cuyos indices esten en el arreglo de indices
				unsigned int i = 0;
				unsigned int j = 0;
				while ( (i+j) < indices.size() ){
					indices[i] = indices[i+j];
					if (v_libros[indices[i]].Buscar_En_Titulo(s))
						i++;
					else {
						restantes.push_back(indices[i]);
						j++;
					}
				}
				indices.erase( (indices.begin()+i), indices.end() );
			} else {
				//este codigo se llama si el nuevo string no contiene al ultimo string
				//usado como filtro, en este caso hay que realizar la busqueda entre 
				//todos los libros
			}
		} else {
			//este codigo se llama si el nuevo string es menor que el ultimo string 
			//usado como filtro, por ejemplo si el usuario borro una letra en la barra
			//de busqueda
			if( ultima_cadena_buscada_libro.find(filtro) != string::npos ){
				//este codigo se llama cuando el nuevo string a usar como filtro es el resultante 
				//de borrar una parte del ultimo string usado como filtro, lo que significa que
				//todos los libros cuyo indice esta en el arreglo de indices lo contienen
				//y por lo tanto hay que buscar entre los restantes
				unsigned int i=0;
				unsigned int j=0;
				while ( (i+j) < restantes.size() ){
					restantes[i]=restantes[i+j];
					if (v_libros[restantes[i]].Buscar_En_Titulo(s)) {
						indices.push_back(restantes[i]);
						j++;
					} else
						i++;
				}
				restantes.erase( (restantes.begin()+i),restantes.end() );
			} else {
				//este codigo se llama cuando el nuevo string no forma parte del ultimo
				//string usado como filtro, por lo tanto hay que buscar entre todos los libros
			}
		}
	}
	ultima_cadena_buscada_libro = filtro;
}

void Biblioteca::FiltrarSociosPorApellido( vector<unsigned int>& indices, vector<unsigned int>& restantes, string filtro ){
	//si se llama la funcion con un string vacio, entonces la funcion simplemente pone todo en el vector indices
	if( filtro.empty() ){
		for ( unsigned int aux = 0; aux<restantes.size(); aux++ ){
			indices.push_back( restantes[aux] );
		}
		restantes.clear();
	}
	else{
		string s(" ");
		s += filtro;
		//unsigned int n=s.size();
		//for(unsigned int i=0;i<n;i++) s[i]=tolower(s[i]);
		Pasar_a_Minusculas(s);
		if ( filtro.size() > ultima_cadena_buscada_socio.size() ){
			//este codigo corresponde al caso en que el nuevo string es mayor que el
			//ultimo string que se uso para filtrar
			if( filtro.find( ultima_cadena_buscada_socio ) != string::npos ){
				//este codigo se llama si el nuevo string a usar de filtro contiene 
				//al ultimo string que se uso como filtro, en ese caso solo hay que buscar
				//entre los socios cuyos indices esten en el arreglo de indices
				unsigned int i = 0;
				unsigned int j = 0;
				while ( (i+j) < indices.size() ){
					indices[i] = indices[i+j];
					if ( v_socios[indices[i]].Buscar_En_Apellido(s))
						i++;
					else {
						restantes.push_back(indices[i]);
						j++;
					}
				}
				indices.erase( (indices.begin()+i),indices.end() );
			} else {
				//este codigo se llama si el nuevo string no contiene al ultimo string
				//usado como filtro, en este caso hay que realizar la busqueda entre 
				//todos los socios
			}
		} else {
			//este codigo se llama si el nuevo string es menor que el ultimo string 
			//usado como filtro, por ejemplo si el usuario borro una letra en la barra
			//de busqueda
			if(ultima_cadena_buscada_socio.find(filtro)!=string::npos){
				//este codigo se llama cuando el nuevo string a usar como filtro es el resultante 
				//de borrar una parte del ultimo string usado como filtro, lo que significa que
				//todos los libros cuyo indice esta en el arreglo de indices lo contienen
				//y por lo tanto hay que buscar entre los restantes
				unsigned int i=0;
				unsigned int j=0;
				while ( (i+j) < restantes.size() ){
					restantes[i]=restantes[i+j];
					if (v_socios[restantes[i]].Buscar_En_Apellido(s)) {
						indices.push_back(restantes[i]);
						j++;
					}
					else i++;
				}
				restantes.erase( (restantes.begin()+i),restantes.end() );
			}
			else{
				//este codigo se llama cuando el nuevo string no forma parte del ultimo
				//string usado como filtro, por lo tanto hay que buscar entre todos los libros
			}
		}
	}
	ultima_cadena_buscada_socio=filtro;
}

Socio& Biblioteca::VerSocio(unsigned int indice){
	return v_socios[indice];
}
int Biblioteca::BuscarSocio(unsigned int codigo){
	unsigned int n=codigo;
	if(n<v_socios.size()){
		while (v_socios[n].GetId()>codigo && n>0) n--;
		if (v_socios[n].GetId()==codigo) return n;
		else return -1;
	}
	else{
		n=v_libros.size()-1;
		while(v_socios[n].GetId()>codigo && n>0) n--;
		if (v_socios[n].GetId()==codigo) return n;
		else return -1;
	}
}
void Biblioteca::AgregarSocio(Socio &S){
	v_socios.push_back(S);
}
void Biblioteca::EliminarSocio(unsigned int indice){
	v_socios.erase(v_socios.begin()+indice);
}
unsigned int Biblioteca::TotalSocios(){
	return v_socios.size();
}
void Biblioteca::GuardarSocios(){
	ofstream archivo(datossocios.c_str(),ios::binary);
	unsigned int totalsocios=v_socios.size();
	archivo.write((char*)&totalsocios,sizeof(totalsocios));	
	for (unsigned int i=0;i<totalsocios;i++){
		v_socios[i].Guardar(archivo);
	}
}

void Biblioteca::AgregarPrestamo( Prestamo p ){
	list<Prestamo>::iterator it=l_prestamos.insert( l_prestamos.end(), p );
	int pos_libro=BuscarLibro(p.GetIdLibro());
	int pos_socio=BuscarSocio(p.GetIdSocio());
	v_libros[pos_libro].SetPrestamoActual(*it);
	v_socios[pos_socio].AddPrestamo(*it);
}

//Esta Funcion me permite cambiar el criterio por el cual 
//
void Biblioteca::CambiarCriterio( comparar_por c ){
	crit = c;
}


//sobrecarga del operador() que me permite usar a Biblioteca para comparar dos 
//enteros en base al libro o socio que ocupa una posicion en su vector igual a dichos enteros
//de este modo puedo usar mi instancia de Biblioteca para ordenar los vectores de enteros de la
//clase Ventana Inicial
bool Biblioteca::operator()(unsigned int a, unsigned int b){
    switch( crit ){
	case libro_titulo:
		return ( v_libros[a].GetTitulo() < v_libros[b].GetTitulo() );
	case libro_autor:
		return ( v_libros[a].GetAutor() < v_libros[b].GetAutor() );
    case libro_categoria:
		return ( v_libros[a].GetCategoria() < v_libros[b].GetCategoria() );
	case libro_editorial:
		return ( v_libros[a].GetEditorial() < v_libros[b].GetEditorial() );
	case socio_apellido_y_nombre:
		return ( v_socios[a].GetApellido() + v_socios[a].GetNombre() < v_socios[b].GetApellido() + v_socios[b].GetNombre() );
	case socio_dni:
		return ( v_socios[a].GetDNI() < v_socios[b].GetDNI() );
	}
}

string Biblioteca::Ver_Ultima_Busqueda_Libro() const{
	return ultima_cadena_buscada_libro;
}

string Biblioteca::Ver_Ultima_Busqueda_Socio() const{
	return ultima_cadena_buscada_socio;
}

Biblioteca::~Biblioteca() {
	
}
