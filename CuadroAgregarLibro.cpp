#include "CuadroAgregarLibro.h"
#include "Biblioteca.h"
#include <string>
#include "Libro.h"
#include "Funciones.h"
#include <wx/msgdlg.h>
using namespace std;

Cuadro_Agregar_Libro::Cuadro_Agregar_Libro(wxWindow *parent) : CuadroLibro(parent) {
	title = wxT("Agregar libro");
}

void Cuadro_Agregar_Libro::ClickBotonAgregar( wxCommandEvent& event )  {
	string t = tc_titulo->GetValue().c_str();
	string a = tc_autor->GetValue().c_str();
	string e = tc_editorial->GetValue().c_str();
	string i = tc_isbn->GetValue().c_str();
	string c = tc_categoria->GetValue().c_str();
	string aux1 = tc_anio->GetValue().c_str();
	string aux2 = tc_nrocop->GetValue().c_str();
	int cant_copias = StrToInt(aux2);
	string errores = ValidarLibro(t,a,e,i,c,StrToInt(aux1),cant_copias);
	if (errores.size()){
		wxMessageBox(errores);
	}
	else {
		for(unsigned int cont = 0; cont < cant_copias; cont++){
			Libro L( t, a, e, i, c, StrToInt(aux1) );
			La_Biblioteca->AgregarLibro(L);
		}
		La_Biblioteca->GuardarLibros();
		EndModal(cant_copias);
	}
}

void Cuadro_Agregar_Libro::ClickBotonCancelar( wxCommandEvent& event )  {
	EndModal(0);
}

Cuadro_Agregar_Libro::~Cuadro_Agregar_Libro() {
	EndModal(0);
}

