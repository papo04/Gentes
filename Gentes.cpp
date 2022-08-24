#include "Gentes.h"

void Gentes::setNombre(string nombre)
{
	std::strcpy(_nombre, nombre.c_str());
}

void Gentes::setDni(int dni)
{
	_dni = dni;
}

void Gentes::setIngreso(int hora)
{
	_horaIngreso = hora;
}

void Gentes::setEgreso(int hora)
{
	_horaSalida = hora;
}

int Gentes::getDni()
{
	return _dni;
}

int Gentes::getIngreso()
{
	return _horaIngreso;
}

int Gentes::getEgreso()
{
	return _horaSalida;
}

string Gentes::getNombre()
{
	string nombre(_nombre);
	return nombre;
}
string Gentes::texto() {
	time_t time_ptr;
	time_ptr = time(NULL);
	tm* tm_local = localtime(&time_ptr);
	string cadena = to_string(_dni) + "\t" + _nombre;
	
	if (_horaIngreso == NULL) {
		cadena += "\t\t-\t-\tNO INGRESO A LA FIESTA\n";
	}
	else if (_horaSalida == NULL) {
		if (tm_local->tm_hour < _horaIngreso)
			cadena += "\t\t" + to_string(_horaIngreso) + "\t" + to_string(tm_local->tm_hour) + " \tNeto: " + to_string(tm_local->tm_hour - _horaIngreso +24) + "\tNO SALIO DE LA FIESTA\n";
		else
			cadena += "\t\t" + to_string(_horaIngreso) + "\t" + to_string(tm_local->tm_hour) + " \tNeto: " + to_string(tm_local->tm_hour - _horaIngreso) + "\tNO SALIO DE LA FIESTA\n";
	}
	else {
		if(_horaSalida<_horaIngreso)
			cadena += "\t\t" + to_string(_horaIngreso) + "\t" + to_string(_horaSalida) + " \tNeto: " + to_string(_horaSalida - _horaIngreso+24) + "\n";
		else
			cadena += "\t\t" + to_string(_horaIngreso) + "\t" + to_string(_horaSalida) + " \tNeto: " + to_string(_horaSalida - _horaIngreso) + "\n";
	}
	return cadena;
}

bool Gentes::leerEnDisco(int pos)
{
	FILE *p = fopen("Gentes.dat","rb");
	if (p == NULL) {
		return false;
	}
	fseek(p, pos * sizeof(Gentes), SEEK_SET);
	bool ok = fread(this, sizeof(Gentes), 1, p);
	fclose(p);
	return ok;
}

bool Gentes::guardarEnDisco()
{
	FILE* p = fopen("Gentes.dat", "ab");
	if (p == NULL) {
		return false;
	}
	bool ok = fwrite(this, sizeof(Gentes), 1, p);
	fclose(p);
	return ok;
}

bool Gentes::guardarEnDisco(int pos)
{
	FILE* p = fopen("Gentes.dat", "rb+");
	if (p == NULL) {
		return false;
	}
	fseek(p, pos * sizeof(Gentes), SEEK_SET);
	bool ok = fwrite(this, sizeof(Gentes), 1, p);
	fclose(p);
	return ok;
}
