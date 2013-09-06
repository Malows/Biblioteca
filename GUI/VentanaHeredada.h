#ifndef VENTANA_INICIAL_H
#define VENTANA_INICIAL_H
#include "VentanaGenerada.h"
#include <vector>
#include "Fecha.h"
using namespace std;

class Ventana_Inicial : public VentanaInicial {
	
private:
	fecha hoy;
	bool busqueda_activa_libro;
	bool busqueda_activa_socio;
	//vector de enteros que carga la posicion de cada libro en el vector de libros
	//se usa para ordenar y buscar en la lista de libros sin modificar el vector
	vector<unsigned int> l_indices;
	//vector que, en el caso de que haya una busqueda activa, guarda las posiciones
	//de los libros que no entran entre los resultados de la busqueda
	vector<unsigned int> l_restantes;
	vector<unsigned int> s_indices;//
	vector<unsigned int> s_restantes;//
protected:
	void CambiarOrdenSocios( wxCommandEvent& event ) ;
	void CambiarOrdenLibros( wxCommandEvent& event ) ;
	void ClickBotonPrestar( wxCommandEvent& event ) ;
	void ClickBotonModificarSocio( wxCommandEvent& event ) ;
	void CuadroBusquedaSociosCambia( wxCommandEvent& event ) ;
	void ClickBotonNuevoSocio( wxCommandEvent& event ) ;
	void ClickBotonNuevoLibro( wxCommandEvent& event ) ;
	void CuadroBusquedaLibrosCambia( wxCommandEvent& event ) ;
	void ClickMenuNuevoSocio( wxCommandEvent& event ) ;
	/*void CambiarOrden( wxCommandEvent& event ) ;*/
	void ClickBotonConsultar( wxCommandEvent& event ) ;
	void ClickBotonModificar( wxCommandEvent& event ) ;
	void ClickBotonEliminar( wxCommandEvent& event ) ;
	void ClickMenuNuevoLibro( wxCommandEvent& event ) ;
	
public:
	Ventana_Inicial(wxWindow *parent=NULL);
	void CargarFilaLibro(unsigned int i);
	void CargarFilaSocio(unsigned int i);
	void RecargarGrillaLibros();
	void RecargarGrillaSocios();
	~Ventana_Inicial();
};

#endif

