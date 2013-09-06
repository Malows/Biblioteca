#include "Fecha.h"
#include "Funciones.h"

fecha GetFecha(time_t tiempo){
	tm* aux=localtime(&tiempo);
	unsigned int dia;
	unsigned int mes;
	unsigned int anio;
	
	dia=aux->tm_mday;
	mes=aux->tm_mon;
	anio=aux->tm_year;
	mes++;
	anio+=1900;
	fecha f=(anio*10000)+(mes*100)+dia;
	return f;
}

fecha GetFechaHoy(){
	return GetFecha(time(NULL));
}

fecha GetFechaX(int dias){
	//se multiplica la cantidad de dias por la cantidad de segundos en un dia
	int diferencia=dias*84600;
	//la funcion GetFecha obtiene una fecha en base a un time_t, si se pasa como
	//parámetro time(NULL)la función devuelve la fecha de hoy, al sumarle a este
	//valor la cantidad de segundos en un periodo dado de dias, se obtienen
	//fechas anteriores y posteriores al dia de hoy, dependiendo el valor del
	//parametro "dias" en la funcion
	return GetFecha(time(NULL)+diferencia);
}

string EscribirFecha(fecha f){
	
	string fec;
	
	unsigned int aux=f%10000;
	unsigned int anio=(f-aux)/10000;
	
	unsigned int aux2=aux%100;
	unsigned int mes=(aux-aux2)/100;
	
	unsigned int dia=aux2;
	
	string s;
	string t;
	string u;
	
	InToStr(dia,s);
	InToStr(mes,t);
	InToStr(anio,u);
	
	fec=s+"/"+t+"/"+u;
	return fec;
	
}
