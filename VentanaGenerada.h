///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Sep  8 2010)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __VentanaGenerada__
#define __VentanaGenerada__

#include <wx/string.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/menu.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/stattext.h>
#include <wx/sizer.h>
#include <wx/panel.h>
#include <wx/radiobox.h>
#include <wx/textctrl.h>
#include <wx/choice.h>
#include <wx/button.h>
#include <wx/grid.h>
#include <wx/listbook.h>
#include <wx/listctrl.h>
#include <wx/frame.h>
#include <wx/dialog.h>
#include <wx/statline.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class VentanaInicial
///////////////////////////////////////////////////////////////////////////////
class VentanaInicial : public wxFrame 
{
	private:
	
	protected:
		wxMenuBar* m_menubar1;
		wxMenu* menu_libros;
		wxMenu* m_menu2;
		wxListbook* m_listbook1;
		wxPanel* m_panel1;
		wxStaticText* m_staticText22;
		wxStaticText* st_fecha;
		wxPanel* m_panel2;
		wxStaticText* m_staticText14;
		wxRadioBox* rboxlibros;
		wxStaticText* m_staticText6;
		wxTextCtrl* cuadrobusquedalibros;
		wxStaticText* m_staticText11;
		wxChoice* listaopclibros;
		wxButton* m_button11;
		wxButton* m_button3;
		wxButton* m_button4;
		wxButton* m_button13;
		wxButton* m_button5;
		wxGrid* grillalibros;
		wxPanel* m_panel3;
		wxStaticText* m_staticText17;
		wxRadioBox* rboxsocios;
		wxStaticText* m_staticText21;
		wxChoice* m_choice4;
		wxStaticText* m_staticText15;
		wxTextCtrl* cuadrobusquedasocio;
		wxStaticText* m_staticText16;
		wxChoice* listaopcsocios;
		wxButton* m_button12;
		wxButton* m_button6;
		wxButton* m_button7;
		wxButton* m_button8;
		wxGrid* grillasocios;
		
		// Virtual event handlers, overide them in your derived class
		virtual void ClickMenuNuevoLibro( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickMenuNuevoSocio( wxCommandEvent& event ) { event.Skip(); }
		virtual void CambiarOrdenLibros( wxCommandEvent& event ) { event.Skip(); }
		virtual void CuadroBusquedaLibrosCambia( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickBotonNuevoLibro( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickBotonConsultar( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickBotonModificar( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickBotonPrestar( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickBotonEliminar( wxCommandEvent& event ) { event.Skip(); }
		virtual void CambiarOrdenSocios( wxCommandEvent& event ) { event.Skip(); }
		virtual void CuadroBusquedaSociosCambia( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickBotonNuevoSocio( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickBotonModificarSocio( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		VentanaInicial( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Biblioteca 3000"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 936,480 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
		~VentanaInicial();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class VentanaAyuda
///////////////////////////////////////////////////////////////////////////////
class VentanaAyuda : public wxFrame 
{
	private:
	
	protected:
		wxListbook* m_listbook2;
		wxPanel* m_panel4;
		wxPanel* m_panel5;
		wxPanel* m_panel6;
		wxPanel* m_panel7;
		wxPanel* m_panel8;
		wxPanel* m_panel9;
		wxPanel* m_panel10;
		wxPanel* m_panel11;
	
	public:
		
		VentanaAyuda( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 500,300 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
		~VentanaAyuda();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class CuadroLibro
///////////////////////////////////////////////////////////////////////////////
class CuadroLibro : public wxDialog 
{
	private:
	
	protected:
		wxStaticText* m_staticText1;
		wxTextCtrl* tc_titulo;
		wxStaticText* m_staticText2;
		wxTextCtrl* tc_autor;
		wxStaticText* m_staticText3;
		wxTextCtrl* tc_editorial;
		wxStaticText* m_staticText4;
		wxTextCtrl* tc_categoria;
		wxStaticText* m_staticText5;
		wxTextCtrl* tc_isbn;
		wxStaticText* m_staticText12;
		wxTextCtrl* tc_anio;
		wxStaticText* m_staticText13;
		wxTextCtrl* tc_nrocop;
		wxButton* m_button1;
		wxButton* m_button2;
		
		// Virtual event handlers, overide them in your derived class
		virtual void ClickBotonAgregar( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickBotonCancelar( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		CuadroLibro( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 430,242 ), long style = wxDEFAULT_DIALOG_STYLE );
		~CuadroLibro();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class CuadroSocio
///////////////////////////////////////////////////////////////////////////////
class CuadroSocio : public wxDialog 
{
	private:
	
	protected:
		wxStaticText* m_staticText19;
		wxTextCtrl* tc_nombre;
		wxStaticText* m_staticText20;
		wxTextCtrl* tc_apellido;
		wxStaticText* m_staticText21;
		wxTextCtrl* tc_dni;
		wxButton* btagregar;
		wxButton* m_button10;
		
		// Virtual event handlers, overide them in your derived class
		virtual void ClickBotonAgregar( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickBotonCancelar( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		CuadroSocio( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 332,146 ), long style = wxDEFAULT_DIALOG_STYLE );
		~CuadroSocio();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class CuadroPrestamo
///////////////////////////////////////////////////////////////////////////////
class CuadroPrestamo : public wxDialog 
{
	private:
	
	protected:
		wxStaticText* m_staticText23;
		wxTextCtrl* tc_idlibro;
		wxStaticLine* m_staticline4;
		wxStaticText* m_staticText21;
		wxStaticText* m_staticText24;
		wxTextCtrl* tc_idsocio;
		wxButton* m_button14;
		wxStaticLine* m_staticline3;
		wxStaticText* m_staticText22;
		wxTextCtrl* tc_duracion;
		wxStaticText* m_staticText25;
		wxStaticLine* m_staticline5;
		wxButton* m_button15;
		wxButton* m_button16;
		
		// Virtual event handlers, overide them in your derived class
		virtual void ClickBotonBuscarSocio( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickBotonAceptar( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickBotonCancelar( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		CuadroPrestamo( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 403,219 ), long style = wxDEFAULT_DIALOG_STYLE );
		~CuadroPrestamo();
	
};

#endif //__VentanaGenerada__
