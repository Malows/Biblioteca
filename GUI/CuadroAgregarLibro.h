#ifndef CUADROAGREGARLIBRO_H
#define CUADROAGREGARLIBRO_H
#include "VentanaGenerada.h"

class Cuadro_Agregar_Libro : public CuadroLibro {
	
private:
	
protected:
	void ClickBotonAgregar( wxCommandEvent& event ) ;
	void ClickBotonCancelar( wxCommandEvent& event ) ;
	
public:
	Cuadro_Agregar_Libro(wxWindow *parent=NULL);
	~Cuadro_Agregar_Libro();
};

#endif

