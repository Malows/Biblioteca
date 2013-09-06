#include "CuadroAgregarSocio.h"
#include "Biblioteca.h"
#include "Socio.h"
#include "Funciones.h"
#include <string>
using namespace std;

Cuadro_Agregar_Socio::Cuadro_Agregar_Socio(wxWindow *parent) : CuadroSocio(parent) {
	title = wxT("Agregar socio");
}

void Cuadro_Agregar_Socio::ClickBotonAgregar( wxCommandEvent& event )  {
	string n=tc_nombre->GetValue().c_str();
	string a=tc_apellido->GetValue().c_str();
	string d=tc_dni->GetValue().c_str();
	Socio S(n,a,StrToInt(d));
	La_Biblioteca->AgregarSocio(S);
	La_Biblioteca->GuardarSocios();
	EndModal(1);
}

void Cuadro_Agregar_Socio::ClickBotonCancelar( wxCommandEvent& event )  {
	EndModal(0);
}

Cuadro_Agregar_Socio::~Cuadro_Agregar_Socio() {
	
}

