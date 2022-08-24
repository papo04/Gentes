#pragma once
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>

using namespace std;
class Gentes
{
private:
	int _dni;
	char _nombre[50];
	int _horaIngreso=NULL;
	int _horaSalida=NULL;
	bool _entro = false;
public:
	void setNombre(string nombre);
	void setDni(int dni);
	void setIngreso(int hora);
	void setEgreso(int hora);
	int getDni();
	int getIngreso();
	int getEgreso();
	string getNombre();
	string texto();
	bool leerEnDisco(int pos);
	bool guardarEnDisco();
	bool guardarEnDisco(int pos);
};
