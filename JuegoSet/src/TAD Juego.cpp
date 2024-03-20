/*
 * TAD Juego.cpp
 *
 *  Created on: 5 ene. 2022
 *      Author: alumno
 */
#include "TAD Juego.h"

void iniciarJuego(Juego &juego) {
	int nColumnas;
	int puntosSet;
	int puntosGanar;
	int puntosAyuda;
	if (entornoCargarConfiguracion(nColumnas, puntosSet, puntosGanar, puntosAyuda)) {
		entornoIniciar(nColumnas);
		iniciarTablero(juego.tablero, nColumnas);
		juego.puntos = 0;
		juego.cartasRestantes = obtenerCuantasCartasQuedanTablero(juego.tablero);
		juego.puntosSuman = puntosSet;
		juego.puntosAlcanzar = puntosGanar;
		pintarJuego(juego);
	}
}

void jugarJuego(Juego &juego) {
	bool salir=false;
	TipoTecla tecla;
	int num_filas=3;
	int fila_act=0;
	int col_act=0;
	int marcadas=0;
	entornoMarcarCarta(fila_act, col_act);
	entornoPonerPuntuacion(juego.puntos);
	entornoPonerDisponibles(juego.cartasRestantes);
	entornoMostrarMensaje("Pulsa ENTER para seleccionar la carta", 2);
	while (!salir) {
		tecla = entornoLeerTecla();
		switch (tecla) {
		case TEnter:
			seleccionarCartaTablero(juego.tablero, fila_act, col_act);
			if(obtenerSeleccionTablero(juego.tablero, fila_act, col_act)){
				entornoSeleccionarCarta(fila_act, col_act);
				marcadas ++;
			}
			else{
				entornoDeseleccionarCarta(fila_act, col_act);
				marcadas --;
			}
			if(marcadas==3){
				if(comprobarSetTablero(juego.tablero)){
					meterCartasNuevasTablero(juego.tablero);
					pintarJuego(juego);
					juego.puntos=juego.puntos + juego.puntosSuman;
					entornoPonerPuntuacion(juego.puntos);
					entornoPonerDisponibles(obtenerCuantasCartasQuedanTablero(juego.tablero));
					if(juego.puntos==juego.puntosAlcanzar){
						salir=true;
						terminarJuego(juego, "Enhorabuena, HAS GANADO !!!");
					}
				}
				else{
					desmarcarLasCartasTablero(juego.tablero);
					pintarJuego(juego);
				}
				marcadas=0;
				entornoDesmarcarCarta(fila_act, col_act);
				fila_act=0;
				col_act=0;
				entornoMarcarCarta(fila_act, col_act);
			}
			break;
		case TDerecha:
			entornoDesmarcarCarta(fila_act, col_act);
			if(col_act < obtenerNumeroColumnasTablero(juego.tablero)-1)
				col_act++;
			else
				col_act=0;
			entornoMarcarCarta(fila_act, col_act);
			break;
		case TIzquierda:
			entornoDesmarcarCarta(fila_act, col_act);
			if(col_act>0)
				col_act--;
			else
				col_act=obtenerNumeroColumnasTablero(juego.tablero)-1;
			entornoMarcarCarta(fila_act, col_act);
			break;
		case TArriba:
			entornoDesmarcarCarta(fila_act, col_act);
			if (fila_act > 0)
				fila_act--;
			else
				fila_act = num_filas - 1;
			entornoMarcarCarta(fila_act, col_act);
			break;
		case TAbajo:
			entornoDesmarcarCarta(fila_act, col_act);
			if (fila_act < num_filas - 1)
				fila_act++;
			else
				fila_act = 0;
			entornoMarcarCarta(fila_act, col_act);
			break;
		case TSalir:
			salir = true;
			terminarJuego(juego, "Fin . . .");
			break;
		case TF1:
			break;
		case TF2:
			break;
		case TNada:
			break;
		}
	}
}

void terminarJuego(Juego &j, string mensaje) {
	entornoMostrarMensajeFin(mensaje);
	entornoPausa(1.5);
	entornoTerminar();
}

//MÓDULO AUXILIAR
void pintarJuego(Juego juego){
	int numero, forma, color, relleno;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < obtenerNumeroColumnasTablero(juego.tablero); j++) {
			numero = obtenerNumeroCartaConcretaTablero(juego.tablero, i, j);
			forma = obtenerFormaCartaConcretaTablero(juego.tablero, i, j);
			color = obtenerColorCartaConcretaTablero(juego.tablero, i, j);
			relleno = obtenerRellenoCartaConcretaTablero(juego.tablero, i, j);
			entornoPintarCarta(i, j, numero, forma, color, relleno);
			entornoDeseleccionarCarta(i, j);
		}
	}
}
