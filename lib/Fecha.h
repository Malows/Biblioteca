#ifndef FECHA_H
#define FECHA_H

#include <ctime>
#include <string>
using namespace std;

typedef unsigned int fecha;

//funcion que genera un entero positivo que almacena la fecha
fecha GetFecha(time_t tiempo);
//funcion que usa la funcion GetFecha para obtener la fecha de hoy
fecha GetFechaHoy();
//funcion que usa la funcion GetFecha para obtener la fecha antes o despues de 
//cierta cantidad de dias a partir de la fecha de hoy, donde la variable "dias"
//representa esa diferencia
fecha GetFechaX(int dias);
//funcion que genera un string con la fecha en formato dia/mes/año
string EscribirFecha(fecha f);

#endif
