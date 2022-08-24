#include <iostream>
#include <Windows.h>
#include "Gentes.h"
#include "Funcion.h"

using namespace std;
//Practicando Archivos.
int main() {
	//menu
	bool clave = true;
	int opcion;

	while (clave) {
		system("cls");
		
		cout << "MENU" << endl;
		cout << " 1 - CARGAR INVITADOS" << endl;
		cout << " 2 - INGRESO DE INVITADO" << endl;
		cout << " 3 - EGRESO DE INVITADO" << endl;
		cout << " 4 - LISTA DE INVITADOS" << endl;
		cout << " 0 - SALIR" << endl << endl;
		cout << "Ingrese opcion: " << endl;
		cin >> opcion;
		switch (opcion) {
		case 1:
			if (nuevoInvitado()) {
				cout << "cargado correctamente" << endl;
			}
			else {
				cout << "No se pudo cargar" << endl;
			}
			
			break;
		case 2:
			if (ingresoInvitado()) {
				cout << "Modificado exitosamente" << endl;
			}
			else {
				cout << "No se encontró el DNI" << endl;
			}
			break;
		case 3:
			if (egresoInvitado()) {
				cout << "Modificado exitosamente" << endl;
			}
			else {
				cout << "No se encontró el DNI" << endl;
			}
			break;
		case 4:
			// Muestra un listado de todos los invitados, informando quienes no fueron al evento
			// quienes aun están en el evento y el tiempo que estuvieron en el evento
			//mostrarLista(g)
			listarInvitado();
			system("pause");
			break;
		case 0:
			exit(0);
			break;
		}
		system("pause");
	}


	return 0;
}