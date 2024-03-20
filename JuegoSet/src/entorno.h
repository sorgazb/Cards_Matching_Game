/*
	INTRODUCCIÓN A LA PROGRAMACIÓN / FUNDAMENTOS DE PROGRAMACIÓN
	Curso 2021/2022

	Nombre: entorno.h
	Descripción: Especificación de la librería Entorno para el proyecto SetGame
	     	 	 encargado del manejo de la interfaz gráfica del juego.
	     	 	 versión allegro 5.2
	Autor:	Profesores de las asignaturas
    Fecha:	06/09/2021
*/

#ifndef ENTORNO_H_
#define ENTORNO_H_

#include <iostream>
#include <string>
using namespace std;

// ---------------------------------------------------------------------
// Definicion de tipos
// ---------------------------------------------------------------------

// Tipo devuelto por el módulo entornoLeerTecla
enum TipoTecla {TNada, TEnter, TIzquierda, TDerecha, TArriba, TAbajo, TSalir, TF1, TF2};


// ---------------------------------------------------------------------
// Especificación de la interfaz pública (operaciones disponibles)
// ---------------------------------------------------------------------

// DESCRIPCIÓN: Devuelve true si se ha podido acceder al fichero de configuración; false en caso contrario. Además, devuelve:
//				n = 3,4,5, 	número de columnas de 3 cartas con las que se iniciará el juego => columnas iniciales >= 3
//				pc > 0,	 	número de puntos que se sumarán cada vez que el usuario compile un SET => puntos_set
//				p > 0,    	número de puntos que debe lograr el usuario para ganar => objetivo
//				pa >= 0, 	número de puntos mínimos para poder solicitar la ayuda (se restarán del marcador) => coste_ayuda

bool entornoCargarConfiguracion ( int &n, int &pc, int &p, int &pa );

// PRE: { 3 <= tam <= MAX_COLUMNAS }
// DESCRIPCIÓN: Inicia la interfaz gráfica del juego para un tablero de máximo 3 * (tam+1) cartas.
//
// NOTA:		En este entorno se dispondrán inicialmente (utilizando los módulos correspondientes) 3 * tam cartas,
//				quedando la última columna vacía. Esta última columna sólo se rellenará si se activa la ayuda.
void entornoIniciar ( int tam );

// DESCRIPCIÓN: Libera los recursos usados por el entorno gráfico
void entornoTerminar ( );

// PRE: { 0 <= fila < 3, 0 <= columna < MAX_COLUMNAS }
// 		{ 1 <= numero  <= 3: número de elementos que contiene de la carta }
// 		{ 1 <= forma   <= 3: forma de los elementos   => 1 = elipse | 2 = rombo   | 3 = onda }
// 		{ 1 <= color   <= 3: color de los elementos   => 1 = azul   | 2 = verde   | 3 = rojo }
//		{ 1 <= relleno <= 3: relleno de los elementos => 1 = vacío  | 2 = rayado  | 3 = relleno }
// DESCRIPCIÓN: Pinta una carta en la posición (fila, columna) del tablero con *numero* elementos
// 				con forma *forma*, color *color* y relleno *relleno*
void entornoPintarCarta ( int fila, int columna, int numero, int forma, int color, int relleno );

// PRE: { 0 <= fila < 3, 0 <= columna < MAX_COLUMNAS }
// DESCRIPCIÓN: Borra la carta en la posición (fila, columna) pintando sobre ella un rectángulo negro
void entornoBorrarCarta ( int fila, int columna );

// PRE: { 0 <= fila < 3, 0 <= columna < MAX_COLUMNAS }
// DESCRIPCIÓN: Marca con un borde amarillo fino la carta en la posición (fila, columna) indicando que el cursor está sobre ella
void entornoMarcarCarta ( int fila, int columna );

// PRE: { 0 <= fila < 3, 0 <= columna < MAX_COLUMNAS }
// DESCRIPCIÓN: Quita el borde amarillo de la carta en la posición (fila, columna) indicando que el cursor ya no está sobre ella
void entornoDesmarcarCarta ( int fila, int columna );

// PRE: { 0 <= fila < 3, 0 <= columna < MAX_COLUMNAS }
// DESCRIPCIÓN: Marca con un borde rojo grueso la carta en la posición (fila, columna) indicando que la carta
//				ha sido seleccionada por el usuario como parte de un posible SET
void entornoSeleccionarCarta ( int fila, int columna );

// PRE: { 0 <= fila < 3, 0 <= columna < MAX_COLUMNAS }
// DESCRIPCIÓN: Quita el borde rojo de la carta en la posición (fila, columna) indicando que la carta
//				no está ya seleccionada como parte de un posible SET
void entornoDeseleccionarCarta ( int fila, int columna );

// PRE: { puntos >= 0  }
// DESCRIPCIÓN: Muestra el valor *puntos* en el marcador situado en la parte superior de la pantalla
void entornoPonerPuntuacion ( int puntos );

// PRE: { numCartas >= 0  }
// DESCRIPCIÓN: Muestra el las cartas disponibles en la baraja *numCartas* en la parte superior de la pantalla
void entornoPonerDisponibles ( int numCartas );

// DESCRIPCIÓN: Devuelve el valor enumerado de TipoTecla que corresponde a la tecla que se haya pulsado
TipoTecla entornoLeerTecla ( );

// PRE: msg correctamente inicializado
// DESCRIPCIÓN: Muestra el mensaje *msg* en el centro de la ventana para indicar que ha finalizado el juego
void entornoMostrarMensajeFin ( string msg );

// PRE: msg correctamente inicializado, secs > 0
// DESCRIPCIÓN:	Muestra el mensaje *msg en la parte inferior de la pantalla durante secs segundos
void entornoMostrarMensaje ( string msg, float secs );

// PRE: pausa > 0
// DESCRIPCIÓN: pausa la ejecución de la aplicación durante *secs* segundos
void entornoPausa ( float secs );

#endif
