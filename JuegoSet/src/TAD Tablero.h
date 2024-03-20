/*
 * TAD Tablero.h
 *
 *  Created on: 5 ene. 2022
 *      Author: alumno
 */

#ifndef TAD_TABLERO_H_
#define TAD_TABLERO_H_
#include "TAD Baraja.h"

const int MAX1=5;
typedef Carta Matriz[3][MAX1];

struct Tablero{
	Matriz m;
	int numColumnas;
	Baraja baraja;
};

/*
 * PRE:{}
 * POST:{Inicia el Tablero t, relleno con el numColumnas que le llega por el fichero cnf y las cartas que se distribuyen de forma aleatoria}
 * Complejidad:O(n)
 */
void iniciarTablero(Tablero &t, int columnas);

/*
 * PRE:{Que el Tablero t este correctamente iniciado}
 * POST:{Devuelve el numero de columnas que hay}
 * Complejidad:O(1)
 */
int obtenerNumeroColumnasTablero(Tablero t);

/*
 * PRE:{Que el Tablero t este correctamente inicializado}
 * POST:{Devuelve el numero de cartas que quedan en la baraja}
 * Complejidad:O(1)
 */
int obtenerCuantasCartasQuedanTablero(Tablero t);

/*
 * PRE:{Que el Tablero t esté correctamente inicializado}
 * POST:{Devuelve la carta que se encuentra en la fila y columna de tablero que le llega por parámetros}
 * Complejidad:O(1)
 */
Carta obtenerCartaConcretaTablero(Tablero t, int fila, int columna);

/*
 * PRE:{Que el Tablero t esté correctamente inicializado}
 * POST:{Devuelve por parámetros las 4 caracteristicas de la carta que se encuentra en la fila y columna concreta del tablero que le llegan por parametros}
 * Complejidad:O(1)
 */
void caracteristicasCartaTablero(Tablero t, int fila, int columna, int &numero, int &forma, int &color, int &relleno);

/*
 * PRE:{Que el Tablero t esté correctamente inicializado}
 * POST:{Cambia el parametro seleccion de la Carta que se encuentra en la fila y columna del tablero que le llegan por parámetros}
 * Complejidad:O(1)
 */
void seleccionarCartaTablero(Tablero &t, int fila, int columna);

/*
 * PRE:{Que el tablero t esté correctamente inicializado}
 * POST:{Devuelve si la carta que se encuentra en la fila y columna del tablero que le llega por parametros está seleccionada o no}
 * Complejidad: O(1)
 */
bool estaSeleccionadaCartaTablero(Tablero t, int fila, int columna);

/*
 * PRE:{Que el Tablero t esté correctamente inicializado}
 * POST:{Dado el tablero y las coordenadas y una carta pone esa carta en la casilla del tablero inidcada}
 * Complejidad:O(1)
 */
void anadirCartaTablero(Tablero &t, int fila, int columna, Carta c);

/*
 * PRE:{Que el Tablero t esté correctamente inicializado}
 * POST:{Dadas tres cartas devuelve true si estas forman un set}
 * Complejidad:O(n)
 */
bool formaSetTablero(Tablero t, Carta c1, Carta c2, Carta c3);

//MÓDULOS AUXILIARES:

/*
 * PRE:{Que el Tablero t esté correctamente inicializado}
 * POST:{Dadas tres cartas, devuleve true si su atributo color son iguales o distintos todos entre si}
 * Complejidad:O(n)
 */
bool setColor(Carta c1, Carta c2, Carta c3);

/*
 * PRE:{Que el Tablero t esté correctamente inicializado}
 * POST:{Dadas tres cartas, devuleve true si su atributo forma son iguales o distintos todos entre si}
 * Complejidad: O(n)
 */
bool setForma(Carta c1, Carta c2, Carta c3);

/*
 * PRE:{Que el Tablero t esté correctamente inicializado}
 * POST:{Dadas tres cartas, devuleve true si su atributo numero son iguales o distintos todos entre si}
 * Complejidad: O(n)
 */
bool setNumero(Carta c1, Carta c2, Carta c3);

/*
 * PRE:{Que el Tablero t esté correctamente inicializado}
 * POST:{Dadas tres cartas, devuleve true si su atributo relleno son iguales o distintos todos entre si}
 * Complejidad: O(n)
 */
bool setRelleno(Carta c1, Carta c2, Carta c3);

/*
 * PRE:{Que el Tablero t esté correctamente inicializado}
 * POST:{Devuelve el numero de la carta que se encuentra en la fila y columna del tablero que le llega por parámetros}
 * Complejidad:O(1)
 */
int obtenerNumeroCartaConcretaTablero(Tablero t, int i, int j);

/*
 * PRE:{Que el Tablero t esté correctamente inicializado}
 * POST:{Devuelve la forma de la carta que se encuentra en la fila y columna del tablero que le llega por parámetros}
 * Complejidad:O(1)
 */
int obtenerFormaCartaConcretaTablero(Tablero t, int i, int j);

/*
 * PRE:{Que el Tablero t esté correctamente inicializado}
 * POST:{Devuelve el color de la carta que se encuentra en la fila y columna del tablero que le llega por parámetros}
 * Complejidad:O(1)
 */
int obtenerColorCartaConcretaTablero(Tablero t, int i, int j);

/*
 * PRE:{Que el Tablero t esté correctamente inicializado}
 * POST:{Devuelve el relleno de la carta que se encuentra en la fila y columna del tablero que le llega por parámetros}
 * Complejidad:O(1)
 */
int obtenerRellenoCartaConcretaTablero(Tablero t, int i, int j);

/*
 * PRE:{Que el Tablero t esté correctamente inicializado}
 * POST:{Devuelve la seleccion de la carta que se encuentra en la fila y columna del tablero que le llega por parámetros}
 * Complejidad:O(1)
 */
bool obtenerSeleccionTablero(Tablero t, int i, int j);

/*
 * PRE:{Que el Tablero t esté correctamente inicializado}
 * POST:{Devuelve true si se ha formado un set y false en el caso contrario}
 * Complejidad:O(1)
 */
bool comprobarSetTablero(Tablero t);

/*
 * PRE:{Que el Tablero t esté correctamente inicializado}
 * POST:{Si hay 3 cartas seleccionadas, lo que hace es borrar estas y meter en el tablero otras tres cartas aleatorias}
 * Complejidad:O(n²)
 */
void meterCartasNuevasTablero(Tablero &t);

/*
 * PRE:{Que el Tablero t esté correctamente inicializado}
 * POST:{Lo que hace este módulo que una vez haya tres cartas seleccionadas las deselecciona}
 * Complejidad:O(n²)
 */
void desmarcarLasCartasTablero(Tablero &t);

/*
 * PRE:{Que el Tablero t esté correctamente inicializado}
 * POST:{Este módulo devuelve el numero de cartas que hay seleccionadas en el tablero y tambien devuelve esas tres cartas por parámetros}
 * Complejidad: O(n²)
 */
int buscarCartasSelccionadasTablero(Tablero t, Carta &c1, Carta &c2, Carta &c3);


#endif /* TAD_TABLERO_H_ */
