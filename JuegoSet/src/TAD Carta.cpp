/*
 * TAD Carta.cpp
 *
 *  Created on: 25 dic. 2021
 *      Author: alumno
 */

#include "TAD Carta.h"

void crearCarta(Carta &c, int numero, int forma, int color, int relleno){ //Roles: valores fijos.
	c.numero=numero;
	c.forma=forma;
	c.color=color;
	c.relleno=relleno;
	c.seleccion=false;
}

int obtenerNumero(Carta c){
	return c.numero;
}

int obtenerForma(Carta c){
	return c.forma;
}

int obtenerColor(Carta c){
	return c.color;
}

int obtenerRelleno(Carta c){
	return c.relleno;
}

void intercambiar(Carta &c1, Carta &c2){
	Carta aux;
	aux=c1;
	c1=c2;
	c2=aux;
}

bool obtenerSeleccion(Carta c){
	return c.seleccion;
}

void cambiarSeleccion(Carta &c, bool sel){
	c.seleccion= sel;
}






