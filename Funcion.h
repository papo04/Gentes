#pragma once
#include "Gentes.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <string.h>
using namespace std;

Gentes cargarInvitados();
bool nuevoInvitado();
bool ingresoInvitado();
bool egresoInvitado();
void listarInvitado();
int cantidadInvitadosTotal();
int buscarInvitado(int dni);//devuelve posicion del invitado
