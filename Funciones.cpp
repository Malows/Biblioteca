#include "Funciones.h"

#include "Fecha.h"
#include <ctime>
using namespace std;

int StrToInt(string &s){
	int x=0;
	
	bool neg=false;
	unsigned int ssize=s.size();
	if (s[0]=='-') neg=true;
	
	for (unsigned int i=neg;i<ssize;i++){
		x=x*10;
		x=x+(s[i]-'0');
	}
	if(neg)x=x*(-1);
	return x;	
}

void InToStr(int x, string &s){
	if (x==0){
		string cero(1,'0');
		s=cero;
		return;
	}
	bool neg=false;
	unsigned int tam=0;
	if (x<0){
		neg=true;
		x*=(-1);
		tam++;
	}
	int control=1;
	while (x>=control){
		tam++;
		control=control*10;
	}
	string num(tam,'n');
	if(neg){
		num[0]='-';
	}
	unsigned int i=1;
	int aux=0;
	while(tam>=i && x!=0){
		aux=x%10;
		num[tam-i]='0'+aux;
		x=(x-aux)/10;
		i++;
	}
	s=num;
	return;
}

void Pasar_a_Minusculas(string &s) {
	unsigned int c=s.size();
	for (unsigned int i=0;i<c;i++)
		s[i]=tolower(s[i]);
}

string ValidarLibro(string tit, string aut, string edi, string isb, string cat, unsigned int an, int nrocopias){
	string errores;
	fecha fecha_actual=GetFecha(time(NULL));
	unsigned int anio_actual=fecha_actual/10000;
	if (tit.empty()) errores+="El titulo está vacío\n";
	if (tit.size()>100) errores+="El titulo debe tener menos de 100 caracteres\n";
	if (aut.empty()) errores+="El autor está vacío\n";
	if (aut.size()>100) errores+="El autor debe tener menos de 100 caracteres\n";
	if (edi.empty()) errores+="La editorial está vacía\n";
	if (edi.size()>100) errores+="La editorial debe tener menos de 100 caracteres\n";
	if (isb.empty()) errores+="El ISBN está vacío\n";
	if (isb.size()>100) errores+="El ISBN debe tener menos de 100 caracteres\n";
	if (cat.empty()) errores+="La categoría está vacía\n";
	if (cat.size()>100) errores+="La categoría debe tener menos de 100 caracteres\n";
	if (an==0) errores+="No ingreso año de publicacion\n";
	if (an>anio_actual) {
		string s;
		InToStr(anio_actual,s);
		errores+="El año no puede ser mayor a ";
		errores+=s;
		errores+="\n";
	}
	if (nrocopias<1) errores+="Debe indicar cuantas copias del libro va a agregar\n";
	return errores;
}
