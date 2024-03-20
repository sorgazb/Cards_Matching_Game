/*
 * TAD Carta.h
 *
 *  Created on: 25 dic. 2021
 *      Author: alumno
 */

#ifndef TAD_CARTA_H_
#define TAD_CARTA_H_

#include <iostream>
using namespace std;

//Definición de la estructura
struct Carta{
	int numero;
	int forma;
	int color;
	int relleno;
	bool seleccion;
};

//Declaración de los módulos:

/*
 * PRE:{}
 * POST:{Devuelve c inicializada con los valores pasados como parámetros}
 * Complejidad:O(1).
 */
void crearCarta(Carta &c, int numero, int forma, int color, int relleno);

/*
 * PRE:{c inicializada}
 * POST:{Devuelve c.numero}
 * Complejidad:O(1).
 */
int obtenerNumero(Carta c);

/*
 * PRE:{c inicializada}
 * POST:{Devueleve c.forma}
 * Complejidad:O(1).
 */
int obtenerForma(Carta c);

/*
 * PRE:{c inicializada}
 * POST:{Devuelve c.color}
 * Complejidad:O(1).
 */
int obtenerColor(Carta c);

/*
 * PRE:{c inicializada}
 * POST:{Devuelve c.relleno}
 * Complejidad:O(1).
 */
int obtenerRelleno(Carta c);

//Módulo auxliar:

/*
 * PRE:{c inicializada}
 * POST:{Intercambia dos cartas de la baraja}
 * Complejidad:O(1).
 */
void intercambiar(Carta &c1, Carta &c2);



bool obtenerSeleccion(Carta c);

void cambiarSeleccion(Carta &c, bool sel);



#endif /* TAD_CARTA_H_ */
