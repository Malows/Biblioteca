#ifndef Funciones_H
#define Funciones_H



#include <string>
using namespace std;

//funciones para convertir un entero a string, y viceversa

int StrToInt(string &s);
void InToStr(int x, string &s);
void Pasar_a_Minusculas(string &s);
string ValidarLibro(string tit, string aut, string edi, string isb, string cat, unsigned int an, int nrocopias);




#endif
