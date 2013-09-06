#ifndef CUADROPRESTAMO_H
#define CUADROPRESTAMO_H
#include "VentanaGenerada.h"

class Cuadro_Prestamo : public CuadroPrestamo {
	
private:
	
protected:
	void ClickBotonBuscarSocio( wxCommandEvent& event ) ;
	void ClickBotonAceptar( wxCommandEvent& event ) ;
	void ClickBotonCancelar( wxCommandEvent& event ) ;
	
public:
	Cuadro_Prestamo(unsigned int idlibro, wxWindow *parent=NULL);
	~Cuadro_Prestamo();
};

#endif

