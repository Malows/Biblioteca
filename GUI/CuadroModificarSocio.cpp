#include "CuadroModificarSocio.h"
#include <string>
#include "Biblioteca.h"
#include "Funciones.h"
using namespace std;

CuadroModificarSocio::CuadroModificarSocio(unsigned int pos, wxWindow *parent) : CuadroSocio(parent) {
	title = wxT("Modificar socio");
	btagregar->SetLabel("Guardar Cambios");
	posicion=pos;
	tc_nombre->SetValue(La_Biblioteca->VerSocio(pos).GetNombre().c_str());
	tc_apellido->SetValue(La_Biblioteca->VerSocio(pos).GetApellido().c_str());
	int dni=La_Biblioteca->VerSocio(pos).GetDNI();
	string sdni;
	InToStr(dni,sdni);
	tc_dni->SetValue(sdni.c_str());
}

void CuadroModificarSocio::ClickBotonAgregar( wxCommandEvent& event )  {
	string snombre=tc_nombre->GetValue().c_str();
	La_Biblioteca->VerSocio(posicion).SetNombre(snombre);
	string sapellido=tc_apellido->GetValue().c_str();
	La_Biblioteca->VerSocio(posicion).SetApellido(sapellido);
	string sdni=tc_dni->GetValue().c_str();
	int x=StrToInt(sdni);
	La_Biblioteca->VerSocio(posicion).SetDNI(x);
	EndModal(1);
}

void CuadroModificarSocio::ClickBotonCancelar( wxCommandEvent& event )  {
	EndModal(0);
}

CuadroModificarSocio::~CuadroModificarSocio() {
	
}

