#ifndef CUADROAGREGARSOCIO_H
#define CUADROAGREGARSOCIO_H
#include "VentanaGenerada.h"

class Cuadro_Agregar_Socio : public CuadroSocio {
	
private:
	
protected:
	void ClickBotonAgregar( wxCommandEvent& event ) ;
	void ClickBotonCancelar( wxCommandEvent& event ) ;
	
public:
	Cuadro_Agregar_Socio(wxWindow *parent=NULL);
	~Cuadro_Agregar_Socio();
};

#endif

