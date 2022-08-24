#include "Funcion.h"
using namespace std;

void listarInvitado() {
	int cantidadInvitados = cantidadInvitadosTotal();
	Gentes aux;
	cout << "DNI\tNombre\t\tHorarios:\t" << endl;
	for (int i = 0; i < cantidadInvitados; i++) {
		aux.leerEnDisco(i);
		cout << aux.texto();
	}
}
int cantidadInvitadosTotal()
{
	FILE* p = fopen("Gentes.dat", "rb");
	if (p == NULL) {
		return 0;
	}
	size_t bytes;
	int cantidad;
	fseek(p, 0, SEEK_END);
	bytes = ftell(p);
	fclose(p);
	cantidad = bytes / sizeof(Gentes); // bytes totales sobre el tamaño de cada objeto
	return cantidad;
}
int buscarInvitado(int dni)
{
	Gentes aux;
	int i, cantidadInvitados = cantidadInvitadosTotal();
	for (i = 0; i < cantidadInvitados; i++) {
		aux.leerEnDisco(i);
		if (aux.getDni() == dni) {
			return i;
		}
	}
	return -1;
}
Gentes cargarInvitados()
{
	int dni;
	string nombre;
	cout << "DNI: " << endl;
	cin >> dni;
	cout << "Nombre: " << endl;
	cin >> nombre;
	Gentes aux;
	aux.setDni(dni);
	aux.setNombre(nombre);

	return aux;
}
bool nuevoInvitado() {
	//validacion de repeticion
	int cantidadInvitados = cantidadInvitadosTotal();
	int i = 0;
	bool ok = false;
	Gentes reg;
	reg = cargarInvitados();
	if (buscarInvitado(reg.getDni()) < 0) {
		bool ok = reg.guardarEnDisco();
	}
	else {
		return ok;
	}
}


bool ingresoInvitado()
{
	int dni,i=0 , hora, cantidadInvitados = cantidadInvitadosTotal();
	bool ok = false;
	cout << "ingrese dni del invitado: " << endl;
	cin >> dni;
	
	
	if (buscarInvitado(dni)>=0) {
		Gentes aux;
		aux.leerEnDisco(buscarInvitado(dni));
		cout << "Ingrese horario de entrada al evento: " << endl;
		cin >> hora;
		aux.setIngreso(hora);
		aux.guardarEnDisco(buscarInvitado(dni));
		return ok = true;
	}
	else {
		return ok;
	}
	
}

bool egresoInvitado()
{
	int dni, i = 0, hora, cantidadInvitados = cantidadInvitadosTotal();
	bool ok = false;
	cout << "ingrese dni del invitado: " << endl;
	cin >> dni;


	if (buscarInvitado(dni) >= 0) {
		Gentes aux;
		aux.leerEnDisco(buscarInvitado(dni));
		cout << "Ingrese horario de salida al evento: " << endl;
		cin >> hora;
		aux.setEgreso(hora);
		aux.guardarEnDisco(buscarInvitado(dni));
		return ok = true;
	}
	else {
		return ok;
	}
}

