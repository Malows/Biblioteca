#include "VentanaHeredada.h"
#include "CuadroAgregarLibro.h"
#include "Biblioteca.h"
#include "Libro.h"
#include "Funciones.h"
#include <algorithm>
#include "CuadroAgregarSocio.h"
#include "Socio.h"

#include "CuadroModificarSocio.h"
#include "CuadroPrestamo.h"
using namespace std;

Ventana_Inicial::Ventana_Inicial(wxWindow *parent) : VentanaInicial(parent) {
	
	hoy=GetFecha(time(NULL));
//	string asdasda;
//	InToStr(La_Biblioteca->numerito,asdasda);
	string s=EscribirFecha(hoy)/*+asdasda*/;
	st_fecha->SetLabel(s.c_str());
	
	busqueda_activa_libro=false;
	busqueda_activa_socio=false;
	//seccion que se encarga de inicializar el vector de indices de libros, y
	//de cargar la grilla de libros
	l_indices.resize(La_Biblioteca->TotalLibros());
	grillalibros->AppendRows(l_indices.size());
	for (unsigned int i=0;i<l_indices.size();i++){
		l_indices[i]=i;
		CargarFilaLibro(i);
	}
	//seccion que se indica de inicializar el vector de indices de socios, y
	//de cargar la grilla de socios
	s_indices.resize(La_Biblioteca->TotalSocios());
	grillasocios->AppendRows(s_indices.size());
	for (unsigned int i=0;i<s_indices.size();i++){
		s_indices[i]=i;
		CargarFilaSocio(i);
	}
}

void Ventana_Inicial::CargarFilaLibro(unsigned int i){
	Libro l=La_Biblioteca->VerLibro(l_indices[i]);
	unsigned int auxanio=l.GetAnio();
	unsigned int auxid=l.GetId();
/*	unsigned int auxej=l.GetNumCopias();*/
	string an;
	string nid;
/*  string nej;*/
	InToStr(auxanio,an);
	InToStr(auxid,nid);
/*	InToStr(auxej,nej);*/
	grillalibros->SetCellValue(i,1,l.GetTitulo().c_str());
	grillalibros->SetCellValue(i,2,l.GetAutor().c_str());
	grillalibros->SetCellValue(i,3,l.GetEditorial().c_str());
	grillalibros->SetCellValue(i,6,l.GetISBN().c_str());
	grillalibros->SetCellValue(i,4,l.GetCategoria().c_str());
	grillalibros->SetCellValue(i,5,an.c_str());
	grillalibros->SetCellValue(i,0,nid.c_str());
/*	grillalibros->SetCellValue(i,7,nej.c_str());*/
	string estado;
	if (l.EstaDisponible()) estado="disponible";
	if (l.EstaPrestado()) estado="prestado";
	if (l.EstaAtrasado()) estado="atrasado";
	grillalibros->SetCellValue(i,7,estado.c_str());
}

void Ventana_Inicial::CargarFilaSocio(unsigned int i){
	Socio s=La_Biblioteca->VerSocio(s_indices[i]);
	int auxdni=s.GetDNI();
	int auxid=s.GetId();
	int auxnrop=s.GetCantPrestamos();
	string sid;
	string sdni;
	string snrop;
	InToStr(auxdni,sdni);
	InToStr(auxid,sid);
	InToStr(auxnrop,snrop);
	grillasocios->SetCellValue(i,0,sid.c_str());
	grillasocios->SetCellValue(i,1,s.GetNombre().c_str());
	grillasocios->SetCellValue(i,2,s.GetApellido().c_str());
	grillasocios->SetCellValue(i,3,sdni.c_str());
	grillasocios->SetCellValue(i,4,snrop.c_str());
}

void Ventana_Inicial::ClickMenuNuevoLibro( wxCommandEvent& event )  {
	Cuadro_Agregar_Libro* CNuevoLibro= new Cuadro_Agregar_Libro(this);
	int libagregados=CNuevoLibro->ShowModal();
	if (libagregados) {
		
		for (int i=0;i<libagregados;i++){
			unsigned int x=(l_indices.size()+l_restantes.size());
			unsigned int x2=l_indices.size();
			l_indices.push_back(x);
			
			string s=" "+La_Biblioteca->Ver_Ultima_Busqueda_Libro();
			if(La_Biblioteca->VerLibro(x).Buscar_En_Titulo(s)){
				grillalibros->AppendRows(1);
				CargarFilaLibro(x2);
			}
		}
	}
}

//void Ventana_Inicial::CambiarOrden( wxCommandEvent& event )  {
//	int aux=rboxlibros->GetSelection();
//	/*string saux;
//	InToStr(aux,saux);
//	int x=grillalibros->GetNumberRows();
//	grillalibros->AppendRows(1);
//	grillalibros->SetCellValue(x,0,saux.c_str());*/
//	comparar_por c;
//	switch(aux){
//	case 0:
//		c=libro_titulo;
//		break;
//	case 1:
//		c=libro_autor;
//		break;
//	case 2:
//		c=libro_editorial;
//		break;
//	case 3:
//		c=libro_categoria;
//		break;
//	}
//	La_Biblioteca->CambiarCriterio(c);
//	sort(l_indices.begin(),l_indices.end(),*La_Biblioteca);
//	
//	for(unsigned int i=0;i<l_indices.size();i++) CargarFilaLibro(i);
//}

void Ventana_Inicial::ClickBotonConsultar( wxCommandEvent& event )  {
	
}

void Ventana_Inicial::ClickBotonModificar( wxCommandEvent& event )  {
	
}

void Ventana_Inicial::ClickBotonEliminar( wxCommandEvent& event )  {
	int x=grillalibros->GetGridCursorRow();
	unsigned int xindice=l_indices[x];
	for (unsigned int i=0;i<x;i++){
		if (l_indices[i]>xindice)l_indices[i]--;
	}
	for (unsigned int i=x;i<(l_indices.size()-1);i++){
		l_indices[i]=l_indices[i+1];
		if (l_indices[i]>xindice)l_indices[i]--;
	}
	l_indices.pop_back();
	for (unsigned int i=0;i<l_restantes.size();i++){
		if (l_restantes[i]>xindice)l_restantes[i]--;
	}
	grillalibros->DeleteRows(x,1);
	La_Biblioteca->EliminarLibro(xindice);
	La_Biblioteca->GuardarLibros();
}

void Ventana_Inicial::ClickMenuNuevoSocio( wxCommandEvent& event )  {
	Cuadro_Agregar_Socio *C=new Cuadro_Agregar_Socio(this);
	if (C->ShowModal()){
		grillasocios->AppendRows(1);
		unsigned int x=s_indices.size();
		s_indices.push_back(x);
		CargarFilaSocio(x);
	}
}

Ventana_Inicial::~Ventana_Inicial() {
	Close();
}

void Ventana_Inicial::RecargarGrillaLibros(){
	int n=grillalibros->GetNumberRows();
	grillalibros->DeleteRows(0,n);
	unsigned int c=l_indices.size();
	grillalibros->AppendRows(c);
	for(unsigned int i=0;i<c;i++) CargarFilaLibro(i);
}

void Ventana_Inicial::RecargarGrillaSocios(){
	int n=grillasocios->GetNumberRows();
	grillasocios->DeleteRows(0,n);
	unsigned int c=s_indices.size();
	grillasocios->AppendRows(c);
	for(unsigned int i=0;i<c;i++) CargarFilaSocio(i);
}

void Ventana_Inicial::CuadroBusquedaLibrosCambia( wxCommandEvent& event )  {
	if (busqueda_activa_libro==false){
		busqueda_activa_libro=true;
		listaopclibros->Disable();
		string buscado=cuadrobusquedalibros->GetValue().c_str();
		while (buscado!=La_Biblioteca->Ver_Ultima_Busqueda_Libro()){
			La_Biblioteca->FiltrarLibrosPorTitulo(l_indices,l_restantes,buscado);
			RecargarGrillaLibros();
			buscado=cuadrobusquedalibros->GetValue().c_str();
		}
		busqueda_activa_libro=false;
		if(cuadrobusquedalibros->IsEmpty()) listaopclibros->Enable();
		
	}
}

void Ventana_Inicial::ClickBotonNuevoLibro( wxCommandEvent& event )  {
	ClickMenuNuevoLibro(event);
}

void Ventana_Inicial::CuadroBusquedaSociosCambia( wxCommandEvent& event )  {
	if (busqueda_activa_socio==false){
		busqueda_activa_socio=true;
		listaopcsocios->Disable();
		string buscado=cuadrobusquedasocio->GetValue().c_str();
		while (buscado!=La_Biblioteca->Ver_Ultima_Busqueda_Socio()){
			La_Biblioteca->FiltrarSociosPorApellido(s_indices,s_restantes,buscado);
			RecargarGrillaSocios();
			buscado=cuadrobusquedasocio->GetValue().c_str();
		}
		busqueda_activa_socio=false;
		if(cuadrobusquedasocio->IsEmpty()) listaopcsocios->Enable();
		
	}
	
}

void Ventana_Inicial::ClickBotonNuevoSocio( wxCommandEvent& event )  {
	event.Skip();
}

void Ventana_Inicial::ClickBotonModificarSocio( wxCommandEvent& event )  {
	int x=grillasocios->GetGridCursorRow();
	unsigned int xindice=s_indices[x];
	CuadroModificarSocio* CModSocio=new CuadroModificarSocio(xindice, this);
	if (CModSocio->ShowModal()) {
		RecargarGrillaSocios();
		La_Biblioteca->GuardarSocios();
	}
}

void Ventana_Inicial::ClickBotonPrestar( wxCommandEvent& event )  {
	int x=grillalibros->GetGridCursorRow();
	int xindice=l_indices[x];
	unsigned int idlibro=La_Biblioteca->VerLibro(xindice).GetId();
	Cuadro_Prestamo* cp = new Cuadro_Prestamo(idlibro);
	if(cp->ShowModal()){
		CargarFilaLibro(x);
	}
}

void Ventana_Inicial::CambiarOrdenLibros( wxCommandEvent& event )  {
	int aux=rboxlibros->GetSelection();
	/*string saux;
	InToStr(aux,saux);
	int x=grillalibros->GetNumberRows();
	grillalibros->AppendRows(1);
	grillalibros->SetCellValue(x,0,saux.c_str());*/
	comparar_por c;
	switch(aux){
	case 0:
		c=libro_titulo;
		break;
	case 1:
		c=libro_autor;
		break;
	case 2:
		c=libro_editorial;
		break;
	case 3:
		c=libro_categoria;
		break;
	}
	La_Biblioteca->CambiarCriterio(c);
	sort(l_indices.begin(),l_indices.end(),*La_Biblioteca);
	
	for(unsigned int i=0;i<l_indices.size();i++) CargarFilaLibro(i);
}

void Ventana_Inicial::CambiarOrdenSocios( wxCommandEvent& event )  {
	int aux=rboxsocios->GetSelection();
	/*string saux;
	InToStr(aux,saux);
	int x=grillalibros->GetNumberRows();
	grillalibros->AppendRows(1);
	grillalibros->SetCellValue(x,0,saux.c_str());*/
	comparar_por c;
	switch(aux){
	case 0:
		c=socio_apellido_y_nombre;
		break;
	case 1:
		c=socio_dni;
		break;
	}
	La_Biblioteca->CambiarCriterio(c);
	sort(s_indices.begin(),s_indices.end(),*La_Biblioteca);
	
	for(unsigned int i=0;i<s_indices.size();i++) CargarFilaSocio(i);
}

