#include "CuadroPrestamo.h"
#include <string>
#include "Funciones.h"
#include "Prestamo.h"
#include "Biblioteca.h"
using namespace std;

Cuadro_Prestamo::Cuadro_Prestamo(unsigned int idlibro, wxWindow *parent) : CuadroPrestamo(parent) {
	title = wxT("Prestamo");
	string s;
	InToStr(idlibro,s);
	tc_idlibro->SetValue(s.c_str());
}

void Cuadro_Prestamo::ClickBotonBuscarSocio( wxCommandEvent& event )  {
	event.Skip();
}

void Cuadro_Prestamo::ClickBotonAceptar( wxCommandEvent& event )  {
	string auxidlibro=tc_idlibro->GetValue().c_str();
	string auxidsocio=tc_idsocio->GetValue().c_str();
	string auxduracion=tc_duracion->GetValue().c_str();
	unsigned int idlibro=StrToInt(auxidlibro);
	unsigned int idsocio=StrToInt(auxidsocio);
	unsigned int duracion=StrToInt(auxduracion);
	Prestamo p(idlibro,idsocio,duracion);
	La_Biblioteca->AgregarPrestamo(p);
	EndModal(1);
}

void Cuadro_Prestamo::ClickBotonCancelar( wxCommandEvent& event )  {
	EndModal(0);
}

Cuadro_Prestamo::~Cuadro_Prestamo() {
	
}

