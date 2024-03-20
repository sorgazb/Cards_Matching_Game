/*
 * TAD Baraja.h
 *
 *  Created on: 25 dic. 2021
 *      Author: alumno
 */

#ifndef TAD_BARAJA_H_
#define TAD_BARAJA_H_
#include "TAD Carta.h"

//Definición de la estructura

const int MAX=81;

typedef Carta TVectorCarta[MAX];

struct Baraja{
	TVectorCarta vBaraja;
	int ocupadas;
};

//Declaración de los módulos:

/*
 * PRE:{}
 * POST:{Inicia la estructura}
 * Complejidad:O(n2).
 */
void crearBaraja(Baraja &b);

/*
 * PRE:{Vector iniciado correctamente}
 * POST:{Muestra una carta y despues borra esa carta de la baraja}
 * Complejidad:O(n).
 */
void sacarCarta(Baraja &b, Carta &c);

/*
 * PRE:{Vector iniciado correctamente}
 * POST:{Devuelve el numero total de cartas almacenadas en la baraja}
 * Complejidad:O(1).
 */
int cuantasCartas(Baraja b);




#endif /* TAD_BARAJA_H_ */
