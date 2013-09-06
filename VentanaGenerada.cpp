///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Sep  8 2010)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "VentanaGenerada.h"

///////////////////////////////////////////////////////////////////////////

VentanaInicial::VentanaInicial( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	m_menubar1 = new wxMenuBar( 0 );
	menu_libros = new wxMenu();
	wxMenuItem* m_menuItem1;
	m_menuItem1 = new wxMenuItem( menu_libros, wxID_ANY, wxString( wxT("Nuevo Libro") ) , wxEmptyString, wxITEM_NORMAL );
	menu_libros->Append( m_menuItem1 );
	
	m_menubar1->Append( menu_libros, wxT("Libros") ); 
	
	m_menu2 = new wxMenu();
	wxMenuItem* m_menuItem2;
	m_menuItem2 = new wxMenuItem( m_menu2, wxID_ANY, wxString( wxT("Nuevo Socio") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu2->Append( m_menuItem2 );
	
	m_menubar1->Append( m_menu2, wxT("Socios") ); 
	
	this->SetMenuBar( m_menubar1 );
	
	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxVERTICAL );
	
	m_listbook1 = new wxListbook( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLB_DEFAULT );
	m_panel1 = new wxPanel( m_listbook1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer31;
	bSizer31 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer32;
	bSizer32 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText22 = new wxStaticText( m_panel1, wxID_ANY, wxT("Fecha de Hoy:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText22->Wrap( -1 );
	bSizer32->Add( m_staticText22, 0, wxALL, 5 );
	
	st_fecha = new wxStaticText( m_panel1, wxID_ANY, wxT("dd/mm/aaaa"), wxDefaultPosition, wxDefaultSize, 0 );
	st_fecha->Wrap( -1 );
	bSizer32->Add( st_fecha, 0, wxALL, 5 );
	
	bSizer31->Add( bSizer32, 1, wxEXPAND, 5 );
	
	m_panel1->SetSizer( bSizer31 );
	m_panel1->Layout();
	bSizer31->Fit( m_panel1 );
	m_listbook1->AddPage( m_panel1, wxT("Inicio"), false );
	m_panel2 = new wxPanel( m_listbook1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer10;
	bSizer10 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer17;
	bSizer17 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText14 = new wxStaticText( m_panel2, wxID_ANY, wxT("Ordenar por:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText14->Wrap( -1 );
	bSizer17->Add( m_staticText14, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	wxString rboxlibrosChoices[] = { wxT("Titulo"), wxT("Autor"), wxT("Editorial"), wxT("Categoria") };
	int rboxlibrosNChoices = sizeof( rboxlibrosChoices ) / sizeof( wxString );
	rboxlibros = new wxRadioBox( m_panel2, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, rboxlibrosNChoices, rboxlibrosChoices, 1, wxRA_SPECIFY_ROWS );
	rboxlibros->SetSelection( 0 );
	bSizer17->Add( rboxlibros, 0, wxALIGN_CENTER|wxALL, 5 );
	
	bSizer10->Add( bSizer17, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer11;
	bSizer11 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText6 = new wxStaticText( m_panel2, wxID_ANY, wxT("Buscar:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText6->Wrap( -1 );
	bSizer11->Add( m_staticText6, 0, wxALL, 5 );
	
	cuadrobusquedalibros = new wxTextCtrl( m_panel2, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer11->Add( cuadrobusquedalibros, 1, wxALL, 5 );
	
	m_staticText11 = new wxStaticText( m_panel2, wxID_ANY, wxT("En:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText11->Wrap( -1 );
	bSizer11->Add( m_staticText11, 0, wxALL, 5 );
	
	wxString listaopclibrosChoices[] = { wxT("Titulo"), wxT("Autor"), wxT("Editorial"), wxT("Categoria") };
	int listaopclibrosNChoices = sizeof( listaopclibrosChoices ) / sizeof( wxString );
	listaopclibros = new wxChoice( m_panel2, wxID_ANY, wxDefaultPosition, wxDefaultSize, listaopclibrosNChoices, listaopclibrosChoices, 0 );
	listaopclibros->SetSelection( 0 );
	bSizer11->Add( listaopclibros, 1, wxALL, 5 );
	
	bSizer10->Add( bSizer11, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer12;
	bSizer12 = new wxBoxSizer( wxHORIZONTAL );
	
	wxBoxSizer* bSizer16;
	bSizer16 = new wxBoxSizer( wxVERTICAL );
	
	m_button11 = new wxButton( m_panel2, wxID_ANY, wxT("Nuevo Libro"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer16->Add( m_button11, 0, wxALL, 5 );
	
	m_button3 = new wxButton( m_panel2, wxID_ANY, wxT("Consultar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer16->Add( m_button3, 0, wxALL, 5 );
	
	m_button4 = new wxButton( m_panel2, wxID_ANY, wxT("Modificar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer16->Add( m_button4, 0, wxALL, 5 );
	
	m_button13 = new wxButton( m_panel2, wxID_ANY, wxT("Prestar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer16->Add( m_button13, 0, wxALL, 5 );
	
	m_button5 = new wxButton( m_panel2, wxID_ANY, wxT("Eliminar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer16->Add( m_button5, 0, wxALL, 5 );
	
	bSizer12->Add( bSizer16, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer15;
	bSizer15 = new wxBoxSizer( wxVERTICAL );
	
	grillalibros = new wxGrid( m_panel2, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	
	// Grid
	grillalibros->CreateGrid( 0, 8 );
	grillalibros->EnableEditing( false );
	grillalibros->EnableGridLines( true );
	grillalibros->EnableDragGridSize( false );
	grillalibros->SetMargins( 0, 0 );
	
	// Columns
	grillalibros->SetColSize( 0, 48 );
	grillalibros->SetColSize( 1, 114 );
	grillalibros->SetColSize( 2, 112 );
	grillalibros->SetColSize( 3, 117 );
	grillalibros->SetColSize( 4, 90 );
	grillalibros->SetColSize( 5, 72 );
	grillalibros->SetColSize( 6, 76 );
	grillalibros->SetColSize( 7, 66 );
	grillalibros->EnableDragColMove( false );
	grillalibros->EnableDragColSize( true );
	grillalibros->SetColLabelSize( 30 );
	grillalibros->SetColLabelValue( 0, wxT("Codigo") );
	grillalibros->SetColLabelValue( 1, wxT("Titulo") );
	grillalibros->SetColLabelValue( 2, wxT("Autor") );
	grillalibros->SetColLabelValue( 3, wxT("Editorial") );
	grillalibros->SetColLabelValue( 4, wxT("Categoria") );
	grillalibros->SetColLabelValue( 5, wxT("Año") );
	grillalibros->SetColLabelValue( 6, wxT("ISBN") );
	grillalibros->SetColLabelValue( 7, wxT("Estado") );
	grillalibros->SetColLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Rows
	grillalibros->EnableDragRowSize( true );
	grillalibros->SetRowLabelSize( 0 );
	grillalibros->SetRowLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Label Appearance
	
	// Cell Defaults
	grillalibros->SetDefaultCellAlignment( wxALIGN_LEFT, wxALIGN_TOP );
	bSizer15->Add( grillalibros, 1, wxALL, 5 );
	
	bSizer12->Add( bSizer15, 1, wxEXPAND, 5 );
	
	bSizer10->Add( bSizer12, 1, wxEXPAND, 5 );
	
	m_panel2->SetSizer( bSizer10 );
	m_panel2->Layout();
	bSizer10->Fit( m_panel2 );
	m_listbook1->AddPage( m_panel2, wxT("Lista de Libros"), true );
	m_panel3 = new wxPanel( m_listbook1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer23;
	bSizer23 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer26;
	bSizer26 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText17 = new wxStaticText( m_panel3, wxID_ANY, wxT("Ordenar por:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText17->Wrap( -1 );
	bSizer26->Add( m_staticText17, 0, wxALIGN_CENTER|wxALL, 5 );
	
	wxString rboxsociosChoices[] = { wxT("Apellido y Nombre"), wxT("DNI") };
	int rboxsociosNChoices = sizeof( rboxsociosChoices ) / sizeof( wxString );
	rboxsocios = new wxRadioBox( m_panel3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, rboxsociosNChoices, rboxsociosChoices, 1, wxRA_SPECIFY_ROWS );
	rboxsocios->SetSelection( 0 );
	bSizer26->Add( rboxsocios, 0, wxALL, 5 );
	
	wxBoxSizer* bSizer29;
	bSizer29 = new wxBoxSizer( wxHORIZONTAL );
	
	bSizer26->Add( bSizer29, 1, wxEXPAND, 5 );
	
	m_staticText21 = new wxStaticText( m_panel3, wxID_ANY, wxT("Ver Socios:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText21->Wrap( -1 );
	bSizer26->Add( m_staticText21, 0, wxALIGN_CENTER|wxALL, 5 );
	
	wxString m_choice4Choices[] = { wxT("Todos los Socios"), wxT("con Prestamos Pendientes"), wxT("con Prestamos Atrasados"), wxT("Sancionados") };
	int m_choice4NChoices = sizeof( m_choice4Choices ) / sizeof( wxString );
	m_choice4 = new wxChoice( m_panel3, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choice4NChoices, m_choice4Choices, 0 );
	m_choice4->SetSelection( 0 );
	bSizer26->Add( m_choice4, 1, wxALIGN_CENTER|wxALL, 5 );
	
	bSizer23->Add( bSizer26, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer25;
	bSizer25 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText15 = new wxStaticText( m_panel3, wxID_ANY, wxT("Buscar:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText15->Wrap( -1 );
	bSizer25->Add( m_staticText15, 0, wxALL, 5 );
	
	cuadrobusquedasocio = new wxTextCtrl( m_panel3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer25->Add( cuadrobusquedasocio, 1, wxALL, 5 );
	
	m_staticText16 = new wxStaticText( m_panel3, wxID_ANY, wxT("En:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText16->Wrap( -1 );
	bSizer25->Add( m_staticText16, 0, wxALL, 5 );
	
	wxString listaopcsociosChoices[] = { wxT("Nombre"), wxT("Apellido"), wxT("DNI") };
	int listaopcsociosNChoices = sizeof( listaopcsociosChoices ) / sizeof( wxString );
	listaopcsocios = new wxChoice( m_panel3, wxID_ANY, wxDefaultPosition, wxDefaultSize, listaopcsociosNChoices, listaopcsociosChoices, 0 );
	listaopcsocios->SetSelection( 1 );
	bSizer25->Add( listaopcsocios, 1, wxALL, 5 );
	
	bSizer23->Add( bSizer25, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer18;
	bSizer18 = new wxBoxSizer( wxHORIZONTAL );
	
	wxBoxSizer* bSizer19;
	bSizer19 = new wxBoxSizer( wxVERTICAL );
	
	m_button12 = new wxButton( m_panel3, wxID_ANY, wxT("Nuevo Socio"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer19->Add( m_button12, 0, wxALL, 5 );
	
	m_button6 = new wxButton( m_panel3, wxID_ANY, wxT("Consultar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer19->Add( m_button6, 0, wxALL, 5 );
	
	m_button7 = new wxButton( m_panel3, wxID_ANY, wxT("Modificar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer19->Add( m_button7, 0, wxALL, 5 );
	
	m_button8 = new wxButton( m_panel3, wxID_ANY, wxT("Eliminar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer19->Add( m_button8, 0, wxALL, 5 );
	
	bSizer18->Add( bSizer19, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer20;
	bSizer20 = new wxBoxSizer( wxVERTICAL );
	
	grillasocios = new wxGrid( m_panel3, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	
	// Grid
	grillasocios->CreateGrid( 0, 6 );
	grillasocios->EnableEditing( true );
	grillasocios->EnableGridLines( true );
	grillasocios->EnableDragGridSize( false );
	grillasocios->SetMargins( 0, 0 );
	
	// Columns
	grillasocios->SetColSize( 0, 57 );
	grillasocios->SetColSize( 1, 157 );
	grillasocios->SetColSize( 2, 172 );
	grillasocios->SetColSize( 3, 86 );
	grillasocios->SetColSize( 4, 92 );
	grillasocios->SetColSize( 5, 80 );
	grillasocios->EnableDragColMove( false );
	grillasocios->EnableDragColSize( true );
	grillasocios->SetColLabelSize( 30 );
	grillasocios->SetColLabelValue( 0, wxT("Codigo") );
	grillasocios->SetColLabelValue( 1, wxT("Nombre") );
	grillasocios->SetColLabelValue( 2, wxT("Apellido") );
	grillasocios->SetColLabelValue( 3, wxT("DNI") );
	grillasocios->SetColLabelValue( 4, wxT("Prestamos") );
	grillasocios->SetColLabelValue( 5, wxT("Estado") );
	grillasocios->SetColLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Rows
	grillasocios->EnableDragRowSize( true );
	grillasocios->SetRowLabelSize( 0 );
	grillasocios->SetRowLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Label Appearance
	
	// Cell Defaults
	grillasocios->SetDefaultCellAlignment( wxALIGN_LEFT, wxALIGN_TOP );
	bSizer20->Add( grillasocios, 1, wxALL, 5 );
	
	bSizer18->Add( bSizer20, 1, wxEXPAND, 5 );
	
	bSizer23->Add( bSizer18, 1, wxEXPAND, 5 );
	
	m_panel3->SetSizer( bSizer23 );
	m_panel3->Layout();
	bSizer23->Fit( m_panel3 );
	m_listbook1->AddPage( m_panel3, wxT("Lista de Socios"), false );
	#ifndef __WXGTK__ // Small icon style not supported in GTK
	wxListView* m_listbook1ListView = m_listbook1->GetListView();
	long m_listbook1Flags = m_listbook1ListView->GetWindowStyleFlag();
	m_listbook1Flags = ( m_listbook1Flags & ~wxLC_ICON ) | wxLC_SMALL_ICON;
	m_listbook1ListView->SetWindowStyleFlag( m_listbook1Flags );
	#endif
	
	bSizer1->Add( m_listbook1, 1, wxEXPAND | wxALL, 5 );
	
	this->SetSizer( bSizer1 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	this->Connect( m_menuItem1->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( VentanaInicial::ClickMenuNuevoLibro ) );
	this->Connect( m_menuItem2->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( VentanaInicial::ClickMenuNuevoSocio ) );
	rboxlibros->Connect( wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler( VentanaInicial::CambiarOrdenLibros ), NULL, this );
	cuadrobusquedalibros->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( VentanaInicial::CuadroBusquedaLibrosCambia ), NULL, this );
	m_button11->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaInicial::ClickBotonNuevoLibro ), NULL, this );
	m_button3->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaInicial::ClickBotonConsultar ), NULL, this );
	m_button4->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaInicial::ClickBotonModificar ), NULL, this );
	m_button13->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaInicial::ClickBotonPrestar ), NULL, this );
	m_button5->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaInicial::ClickBotonEliminar ), NULL, this );
	rboxsocios->Connect( wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler( VentanaInicial::CambiarOrdenSocios ), NULL, this );
	cuadrobusquedasocio->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( VentanaInicial::CuadroBusquedaSociosCambia ), NULL, this );
	m_button12->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaInicial::ClickBotonNuevoSocio ), NULL, this );
	m_button7->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaInicial::ClickBotonModificarSocio ), NULL, this );
}

VentanaInicial::~VentanaInicial()
{
	// Disconnect Events
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( VentanaInicial::ClickMenuNuevoLibro ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( VentanaInicial::ClickMenuNuevoSocio ) );
	rboxlibros->Disconnect( wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler( VentanaInicial::CambiarOrdenLibros ), NULL, this );
	cuadrobusquedalibros->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( VentanaInicial::CuadroBusquedaLibrosCambia ), NULL, this );
	m_button11->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaInicial::ClickBotonNuevoLibro ), NULL, this );
	m_button3->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaInicial::ClickBotonConsultar ), NULL, this );
	m_button4->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaInicial::ClickBotonModificar ), NULL, this );
	m_button13->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaInicial::ClickBotonPrestar ), NULL, this );
	m_button5->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaInicial::ClickBotonEliminar ), NULL, this );
	rboxsocios->Disconnect( wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler( VentanaInicial::CambiarOrdenSocios ), NULL, this );
	cuadrobusquedasocio->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( VentanaInicial::CuadroBusquedaSociosCambia ), NULL, this );
	m_button12->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaInicial::ClickBotonNuevoSocio ), NULL, this );
	m_button7->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaInicial::ClickBotonModificarSocio ), NULL, this );
	
}

VentanaAyuda::VentanaAyuda( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxVERTICAL );
	
	m_listbook2 = new wxListbook( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLB_DEFAULT );
	m_panel4 = new wxPanel( m_listbook2, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	m_listbook2->AddPage( m_panel4, wxT("a page"), false );
	m_panel5 = new wxPanel( m_listbook2, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	m_listbook2->AddPage( m_panel5, wxT("a page"), false );
	m_panel6 = new wxPanel( m_listbook2, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	m_listbook2->AddPage( m_panel6, wxT("a page"), false );
	m_panel7 = new wxPanel( m_listbook2, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	m_listbook2->AddPage( m_panel7, wxT("a page"), false );
	m_panel8 = new wxPanel( m_listbook2, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	m_listbook2->AddPage( m_panel8, wxT("a page"), false );
	m_panel9 = new wxPanel( m_listbook2, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	m_listbook2->AddPage( m_panel9, wxT("a page"), false );
	m_panel10 = new wxPanel( m_listbook2, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	m_listbook2->AddPage( m_panel10, wxT("a page"), false );
	m_panel11 = new wxPanel( m_listbook2, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	m_listbook2->AddPage( m_panel11, wxT("a page"), false );
	#ifndef __WXGTK__ // Small icon style not supported in GTK
	wxListView* m_listbook2ListView = m_listbook2->GetListView();
	long m_listbook2Flags = m_listbook2ListView->GetWindowStyleFlag();
	m_listbook2Flags = ( m_listbook2Flags & ~wxLC_ICON ) | wxLC_SMALL_ICON;
	m_listbook2ListView->SetWindowStyleFlag( m_listbook2Flags );
	#endif
	
	bSizer2->Add( m_listbook2, 1, wxEXPAND | wxALL, 5 );
	
	this->SetSizer( bSizer2 );
	this->Layout();
	
	this->Centre( wxBOTH );
}

VentanaAyuda::~VentanaAyuda()
{
}

CuadroLibro::CuadroLibro( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText1 = new wxStaticText( this, wxID_ANY, wxT("Titulo      "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1->Wrap( -1 );
	bSizer4->Add( m_staticText1, 0, wxALL, 5 );
	
	tc_titulo = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer4->Add( tc_titulo, 1, wxALL, 5 );
	
	bSizer3->Add( bSizer4, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer5;
	bSizer5 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText2 = new wxStaticText( this, wxID_ANY, wxT("Autor       "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2->Wrap( -1 );
	bSizer5->Add( m_staticText2, 0, wxALL, 5 );
	
	tc_autor = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer5->Add( tc_autor, 1, wxALL, 5 );
	
	bSizer3->Add( bSizer5, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer6;
	bSizer6 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText3 = new wxStaticText( this, wxID_ANY, wxT("Editorial   "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText3->Wrap( -1 );
	bSizer6->Add( m_staticText3, 0, wxALL, 5 );
	
	tc_editorial = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer6->Add( tc_editorial, 1, wxALL, 5 );
	
	bSizer3->Add( bSizer6, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer8;
	bSizer8 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText4 = new wxStaticText( this, wxID_ANY, wxT("Categoria"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText4->Wrap( -1 );
	bSizer8->Add( m_staticText4, 0, wxALL, 5 );
	
	tc_categoria = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer8->Add( tc_categoria, 1, wxALL, 5 );
	
	bSizer3->Add( bSizer8, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer9;
	bSizer9 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText5 = new wxStaticText( this, wxID_ANY, wxT("ISBN        "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText5->Wrap( -1 );
	bSizer9->Add( m_staticText5, 0, wxALL, 5 );
	
	tc_isbn = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer9->Add( tc_isbn, 1, wxALL, 5 );
	
	bSizer3->Add( bSizer9, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer14;
	bSizer14 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText12 = new wxStaticText( this, wxID_ANY, wxT("Año"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText12->Wrap( -1 );
	bSizer14->Add( m_staticText12, 0, wxALL, 5 );
	
	tc_anio = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer14->Add( tc_anio, 0, wxALL, 5 );
	
	m_staticText13 = new wxStaticText( this, wxID_ANY, wxT("Número de Ejemplares:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText13->Wrap( -1 );
	bSizer14->Add( m_staticText13, 0, wxALL, 5 );
	
	tc_nrocop = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer14->Add( tc_nrocop, 0, wxALL, 5 );
	
	bSizer3->Add( bSizer14, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer13;
	bSizer13 = new wxBoxSizer( wxHORIZONTAL );
	
	m_button1 = new wxButton( this, wxID_ANY, wxT("Agregar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer13->Add( m_button1, 0, wxALL, 5 );
	
	m_button2 = new wxButton( this, wxID_ANY, wxT("Cancelar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer13->Add( m_button2, 0, wxALL, 5 );
	
	bSizer3->Add( bSizer13, 1, wxEXPAND, 5 );
	
	this->SetSizer( bSizer3 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	m_button1->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CuadroLibro::ClickBotonAgregar ), NULL, this );
	m_button2->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CuadroLibro::ClickBotonCancelar ), NULL, this );
}

CuadroLibro::~CuadroLibro()
{
	// Disconnect Events
	m_button1->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CuadroLibro::ClickBotonAgregar ), NULL, this );
	m_button2->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CuadroLibro::ClickBotonCancelar ), NULL, this );
	
}

CuadroSocio::CuadroSocio( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer25;
	bSizer25 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer26;
	bSizer26 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText19 = new wxStaticText( this, wxID_ANY, wxT("Nombre"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText19->Wrap( -1 );
	bSizer26->Add( m_staticText19, 0, wxALL, 5 );
	
	tc_nombre = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer26->Add( tc_nombre, 1, wxALL, 5 );
	
	bSizer25->Add( bSizer26, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer27;
	bSizer27 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText20 = new wxStaticText( this, wxID_ANY, wxT("Apellido"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText20->Wrap( -1 );
	bSizer27->Add( m_staticText20, 0, wxALL, 5 );
	
	tc_apellido = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer27->Add( tc_apellido, 1, wxALL, 5 );
	
	bSizer25->Add( bSizer27, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer28;
	bSizer28 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText21 = new wxStaticText( this, wxID_ANY, wxT("DNI"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText21->Wrap( -1 );
	bSizer28->Add( m_staticText21, 0, wxALL, 5 );
	
	tc_dni = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer28->Add( tc_dni, 0, wxALL, 5 );
	
	bSizer25->Add( bSizer28, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer29;
	bSizer29 = new wxBoxSizer( wxHORIZONTAL );
	
	wxBoxSizer* bSizer30;
	bSizer30 = new wxBoxSizer( wxVERTICAL );
	
	bSizer29->Add( bSizer30, 1, wxEXPAND, 5 );
	
	btagregar = new wxButton( this, wxID_ANY, wxT("Agregar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer29->Add( btagregar, 0, wxALL, 5 );
	
	m_button10 = new wxButton( this, wxID_ANY, wxT("Cancelar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer29->Add( m_button10, 0, wxALL, 5 );
	
	bSizer25->Add( bSizer29, 1, wxEXPAND, 5 );
	
	this->SetSizer( bSizer25 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	btagregar->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CuadroSocio::ClickBotonAgregar ), NULL, this );
	m_button10->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CuadroSocio::ClickBotonCancelar ), NULL, this );
}

CuadroSocio::~CuadroSocio()
{
	// Disconnect Events
	btagregar->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CuadroSocio::ClickBotonAgregar ), NULL, this );
	m_button10->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CuadroSocio::ClickBotonCancelar ), NULL, this );
	
}

CuadroPrestamo::CuadroPrestamo( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer32;
	bSizer32 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer33;
	bSizer33 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText23 = new wxStaticText( this, wxID_ANY, wxT("Libro Prestado"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText23->Wrap( -1 );
	bSizer33->Add( m_staticText23, 0, wxALIGN_CENTER|wxALL, 5 );
	
	tc_idlibro = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( -1,-1 ), 0 );
	tc_idlibro->Enable( false );
	
	bSizer33->Add( tc_idlibro, 0, wxALIGN_CENTER|wxALL, 5 );
	
	bSizer32->Add( bSizer33, 0, wxEXPAND, 5 );
	
	m_staticline4 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer32->Add( m_staticline4, 0, wxEXPAND | wxALL, 5 );
	
	wxBoxSizer* bSizer34;
	bSizer34 = new wxBoxSizer( wxVERTICAL );
	
	m_staticText21 = new wxStaticText( this, wxID_ANY, wxT("Socio que lo retira"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText21->Wrap( -1 );
	bSizer34->Add( m_staticText21, 0, wxALL, 5 );
	
	wxBoxSizer* bSizer39;
	bSizer39 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText24 = new wxStaticText( this, wxID_ANY, wxT("Código de Socio:"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE );
	m_staticText24->Wrap( -1 );
	bSizer39->Add( m_staticText24, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	tc_idsocio = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer39->Add( tc_idsocio, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_button14 = new wxButton( this, wxID_ANY, wxT("Buscar Socio"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer39->Add( m_button14, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	bSizer34->Add( bSizer39, 0, wxEXPAND, 5 );
	
	bSizer32->Add( bSizer34, 0, wxEXPAND, 5 );
	
	m_staticline3 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer32->Add( m_staticline3, 0, wxEXPAND | wxALL, 5 );
	
	wxBoxSizer* bSizer35;
	bSizer35 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText22 = new wxStaticText( this, wxID_ANY, wxT("Duración del Prestamo:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText22->Wrap( -1 );
	bSizer35->Add( m_staticText22, 0, wxALIGN_CENTER|wxALL, 5 );
	
	tc_duracion = new wxTextCtrl( this, wxID_ANY, wxT("7"), wxDefaultPosition, wxSize( 30,-1 ), 0 );
	tc_duracion->SetMaxLength( 3 ); 
	bSizer35->Add( tc_duracion, 0, wxALIGN_CENTER|wxALL, 5 );
	
	m_staticText25 = new wxStaticText( this, wxID_ANY, wxT("Días"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText25->Wrap( -1 );
	bSizer35->Add( m_staticText25, 0, wxALIGN_CENTER|wxALL, 5 );
	
	bSizer32->Add( bSizer35, 0, wxEXPAND, 5 );
	
	m_staticline5 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer32->Add( m_staticline5, 0, wxEXPAND | wxALL, 5 );
	
	wxBoxSizer* bSizer40;
	bSizer40 = new wxBoxSizer( wxHORIZONTAL );
	
	m_button15 = new wxButton( this, wxID_ANY, wxT("Aceptar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer40->Add( m_button15, 0, wxALL, 5 );
	
	m_button16 = new wxButton( this, wxID_ANY, wxT("Cancelar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer40->Add( m_button16, 0, wxALL, 5 );
	
	bSizer32->Add( bSizer40, 0, wxEXPAND, 5 );
	
	this->SetSizer( bSizer32 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	m_button14->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CuadroPrestamo::ClickBotonBuscarSocio ), NULL, this );
	m_button15->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CuadroPrestamo::ClickBotonAceptar ), NULL, this );
	m_button16->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CuadroPrestamo::ClickBotonCancelar ), NULL, this );
}

CuadroPrestamo::~CuadroPrestamo()
{
	// Disconnect Events
	m_button14->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CuadroPrestamo::ClickBotonBuscarSocio ), NULL, this );
	m_button15->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CuadroPrestamo::ClickBotonAceptar ), NULL, this );
	m_button16->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CuadroPrestamo::ClickBotonCancelar ), NULL, this );
	
}
