#include "Application.h"

#include <wx/image.h>
#include "Ventana_Inicial.h"
#include "Biblioteca.h"

bool mxApplication::OnInit() {
	wxImage::AddHandler(new wxPNGHandler);
	wxImage::AddHandler(new wxXPMHandler);//wut wut?
	wxImage::AddHandler(new wxJPEGHandler);
	wxImage::AddHandler(new wxBMPHandler);
	La_Biblioteca = new Biblioteca("libros.inv","socios.inv","prestamos.inv");
	Ventana_Inicial *v = new Ventana_Inicial(NULL);
	v->Show();
	return true;
}
