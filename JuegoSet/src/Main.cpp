//============================================================================
// Name        : SetGame.cpp
// Author      : Profesores de la asignatura IP/FP
// Version     : curso 21/22
// Copyright   : Your copyright notice
// Description : Proyecto base para el juego SetGame
//============================================================================

#include "TAD Juego.h"
#include <ctime>

void ejemplo_entorno() {
	TipoTecla tecla;
	bool salir = false;
	int puntos;
	int cartas_disponibles;
	int numero, forma, color, relleno; //características de las cartas
	int num_filas = 3;

	int n;//número de columnas de 3 cartas con las que se iniciará el juego, valores permitidos 3,4,5
	int pc;	//número de puntos que se sumarán cada vez que el usuario compile un SET (> 0)
	int p;		//número de puntos que debe lograr el usuario para ganar (> 0)
	int pa;		//número de puntos mínimos para poder solicitar la ayuda (>= 0)

	int fila_act, col_act;   //coordenadas de la carta actual en el tablero

	srand((time(NULL)));

	if (entornoCargarConfiguracion(n, pc, p, pa)) { //se obtienen, del fichero de configuración, valores necesarios para el juego
		entornoIniciar(n);

		//se dibujan en el entorno 3*n cartas con características generadas de forma aleatoria
		//¡Cuidado! Aquí no creamos las cartas ni las guardamos en el tablero; sólo las pintamos en el entorno!!
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < n; j++) {
				numero = rand() % 3 + 1;
				forma = rand() % 3 + 1;
				color = rand() % 3 + 1;
				relleno = rand() % 3 + 1;
				entornoPintarCarta(i, j, numero, forma, color, relleno);
			}

		fila_act = 0;
		col_act = 0;
		entornoMarcarCarta(fila_act, col_act);

		puntos = 0;
		cartas_disponibles = 81;
		entornoPonerPuntuacion(puntos);
		entornoPonerDisponibles(cartas_disponibles);

		entornoMostrarMensaje("Pulsa ENTER para seleccionar la carta", 2);

		while (!salir) {
			//A partir de este momento se procesan las teclas que pulse el jugador:
			//Si se pulsan las teclas arriba o abajo el cursor se desplaza en vertical por el tablero;
			//Si se pulsa la tecla Enter se selecciona la carta sobre la que está el cursor durante
			//dos segundos, se decrementa en 1 el número de cartas disponibles y se incrementa la
			//puntuación con los puntos indicados en el fichero de configuración

			tecla = entornoLeerTecla();
			switch (tecla) {
			case TEnter:
				entornoSeleccionarCarta(fila_act, col_act);
				entornoPausa(2);
				entornoDeseleccionarCarta(fila_act, col_act);
				puntos = puntos + pc;
				cartas_disponibles--;
				entornoPonerPuntuacion(puntos);
				entornoPonerDisponibles(cartas_disponibles);
				break;
			case TDerecha:
				break;
			case TIzquierda:
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
				break;
			case TF1:
				break;
			case TF2:
				break;
			case TNada:
				break;
			}
		}

		entornoMostrarMensajeFin(" Fin...  ");
		entornoPausa(1.5);
		entornoTerminar();
	}

}

int main() {
	//ejemplo_entorno();
	srand((time(NULL)));
	Juego juego;
	iniciarJuego(juego);
	jugarJuego(juego);
	return 0;
}
