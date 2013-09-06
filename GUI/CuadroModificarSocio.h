#ifndef CUADROMODIFICARSOCIO_H
#define CUADROMODIFICARSOCIO_H
#include "VentanaGenerada.h"

class CuadroModificarSocio : public CuadroSocio {
	
private:
	unsigned int posicion;
protected:
	void ClickBotonAgregar( wxCommandEvent& event ) ;
	void ClickBotonCancelar( wxCommandEvent& event ) ;
	
public:
	CuadroModificarSocio(unsigned int pos, wxWindow *parent=NULL);
	~CuadroModificarSocio();
};

#endif

