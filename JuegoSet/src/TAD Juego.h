/*
 * TAD Juego.h
 *
 *  Created on: 5 ene. 2022
 *      Author: alumno
 */

#ifndef TAD_JUEGO_H_
#define TAD_JUEGO_H_
#include "TAD Tablero.h"
#include "entorno.h"

struct Juego{
	Tablero tablero;
	int cartasRestantes;
	int puntos;
	int puntosSuman;
	int puntosAlcanzar;
};

/*
 * PRE:{}
 * POST:{Se encarga de iniciar el juego}
 * Complejidad:O(n)
 */
void iniciarJuego(Juego &juego);

/*
 * PRE:{Que el Juego juego se haya iniciado correcramente}
 * POST:{Se encarga de realizar la partida, es decir, realiza toda la logica del juego, asi como mostrar los datos por la pantalla}
 * Complejidad:O(n)
 */
void jugarJuego(Juego &juego);

/*
 * PRE:{Que el Juego juego se haya iniciado correcramente}
 * POST:{Finaliza la partida y mostrar un mensaje de despedida}
 * Complejidad:O(1)
 */
void terminarJuego(Juego &juego, string mensaje);

//MÓDULO AUXILIAR

/*
 * PRE:{Que el Juego juego se haya iniciado correcramente}
 * POST:{Se encarga de pintar (mostrar por pantalla) el juego}
 * Complejidad:O(n²)
 */
void pintarJuego(Juego juego);

#endif /* TAD_JUEGO_H_ */
