/*
	INTRODUCCIÓN A LA PROGRAMACIÓN / FUNDAMENTOS DE PROGRAMACIÓN
	Curso 2021/2022

	Nombre: entorno.cpp
	Descripción: Implementación de la librería Entorno para el proyecto SetGame
	     	 	 encargado del manejo de la interfaz gráfica del juego.
	     	 	 versión allegro 5.2
	Autor:	Profesores de las asignaturas
    Fecha:	06/09/2021
*/
#include "entorno.h"

#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_image.h>

#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>

using namespace std;

// ---------------------------------------------------------------------
// Definicion de constantes
// ---------------------------------------------------------------------

const int MAX_COLUMNAS 	  = 5;		// Número máximo de columnas del tablero

// Colores utilizados en el juego

const int COLOR_NEGRO     = 0;		// Color de fondo de pantalla
const int COLOR_BLANCO    = 2;		// Color de Fondo de las cartas
const int COLOR_ROJO      = 1;		// Color del borde de las cartas seleccionadas
const int COLOR_AMARILLO  = 3;		// Color del borde de la carta actual

const int OFFSET_X = 15;			// Separación izquierda de la primera carta del tablero
const int OFFSET_Y = 20;			// Separación superior de la primera carta del tablero
									// (mayor que la izquierda para que quepa el marcador arriba)

const int GAP_X = 10;				// Separación horizontal entre cartas
const int GAP_Y = 10; 				// Separación vertical entre cartas

const int ANCHO_CARTA = 120;		// Ancho en píxels de una carta
const int ALTO_CARTA = 80;			// Alto en píxels de una carta
const float ZOOM = 0.35;			// Escala aplicada a los elementos en las cartas

const int anchoVentana = 800;		// Ancho de la ventana de la aplicación
const int ALTO_VENTANA  = 600;		// Alto de la ventana de la aplicación

const int FILA_MARCADOR = 110;		// Posición vertical en la que se muestra el marcador
const int COL_MARCADOR  = 14;		// Posición horizontal en la que se muestra el marcador

// ---------------------------------------------------------------------
// Definicion de variables globales
// ---------------------------------------------------------------------

ALLEGRO_DISPLAY     *display;
ALLEGRO_FONT        *font;
ALLEGRO_EVENT_QUEUE *colaEventos = NULL;
ALLEGRO_BITMAP 		*shape;

// ---------------------------------------------------------------------
// Definición de módulos PRIVADOS (no incluidos en la interfaz pública)
// ---------------------------------------------------------------------

ALLEGRO_COLOR makecolor2 ( int color ) {
	ALLEGRO_COLOR alColor;
	switch (color) {
	case COLOR_BLANCO:
		alColor = al_map_rgb (255, 255, 255);
		break;
	case COLOR_ROJO:
		alColor = al_map_rgb (255, 0, 0);
		break;
	case COLOR_AMARILLO:
		alColor = al_map_rgb (255, 255, 100);
		break;
	default:
		alColor = al_map_rgb (0, 0, 0);	//COLOR NEGRO
		break;
	}

	return alColor;
}

// ---------------------------------------------------------------------
// Implementación de la interfaz pública
// ---------------------------------------------------------------------

bool entornoCargarConfiguracion  ( int &columnasIniciales, int &puntosSet, int &objetivo, int &costeAyuda ) {
	bool leido;
	ifstream fEntrada;
	string linea;
	fEntrada.open ( "set.cnf" );
	if ( fEntrada.is_open ( ) ) {
		getline ( fEntrada, linea );
		columnasIniciales = atoi ( linea.c_str ( ) );
		getline ( fEntrada, linea );
		puntosSet = atoi ( linea.c_str ( ) );
		getline ( fEntrada, linea );
		objetivo = atoi(linea.c_str ( ) );
		getline ( fEntrada, linea );
		costeAyuda = atoi ( linea.c_str ( ) );
		leido = true;
		fEntrada.close ( );
	} else {
		cout << "Fichero de configuración no encontrado (<proyecto>/set.cnf)." << endl;
		leido = false;
	}
	return leido;
}

void entornoIniciar ( int numColumnas ) {
	int anchoVentana;
	int desplazamientoCentrado;
	string msg;
	if ( al_init ( ) ){
		al_install_keyboard ( );
		al_set_new_display_option ( ALLEGRO_SAMPLE_BUFFERS, 1, ALLEGRO_SUGGEST );
		al_set_new_display_option ( ALLEGRO_SAMPLES, 8, ALLEGRO_SUGGEST );
		al_set_new_display_option ( ALLEGRO_SINGLE_BUFFER, 1, ALLEGRO_REQUIRE );
		al_set_new_display_flags  ( ALLEGRO_WINDOWED );

		// El ancho de la ventana se calcula como la suma de:
		//   1. La separación a izquierda y a derecha de la primera y la última carta (OFFSET_X * 2);
		//   2. El ancho de las cartas por el número total de cartas (numColumnas) + 1 columna extra que se pueden añadir con la ayuda => ANCHO_CARTA * ( numColumnas + 1 );
		//   3. La separación entre las (numColumnas+1)-1 cartas => GAP_X * numColumnas.

		anchoVentana = OFFSET_X * 3 + ANCHO_CARTA * (numColumnas + 1) +   GAP_X * ( numColumnas + 1 );
		if (numColumnas < 5)
			anchoVentana = anchoVentana + 200;
		display = al_create_display ( anchoVentana, ALTO_VENTANA );

		al_init_primitives_addon ( );
		al_init_image_addon ( );
		al_init_font_addon ( );
		al_init_ttf_addon ( );
		font = al_load_ttf_font ( "./img/DroidSerif-Regular.ttf", 18, 0 );
		al_clear_to_color ( makecolor2 ( COLOR_NEGRO ) );
		al_set_window_title ( display, "UEX SET" );
		colaEventos = al_create_event_queue ( );
		al_register_event_source ( colaEventos, al_get_keyboard_event_source ( ) );
		al_register_event_source ( colaEventos, al_get_display_event_source ( display ) );
		msg = "Cursores: ←, →, ↑, ↓ - Esc: Salir - F1: 3 cartas extra - F2: Dame un set";
		desplazamientoCentrado = (anchoVentana - msg.length()*9)/2;  // pixels x caracter = 11
		al_draw_text ( font, makecolor2(COLOR_BLANCO), desplazamientoCentrado, ALTO_VENTANA - 50,  ALLEGRO_ALIGN_LEFT, msg.c_str());
		al_flip_display ( );
	}
}

void entornoTerminar ( ) {
	al_destroy_display           ( display );
	al_destroy_event_queue       ( colaEventos );
	al_destroy_font				 ( font );
	al_destroy_bitmap			 ( shape );
	al_shutdown_primitives_addon ( );
	al_shutdown_font_addon       ( );
}

void entornoPintarCarta ( int fila, int columna, int numero, int forma, int color, int relleno ) {

	int x1, y1;					// posición de la pantalla en la que se pintará la esquina superior izquierda de la carta
	int x2, y2;					// posición de la pantalla en la que se pintará la esquina inferior derecha de la carta
	int n;						// longitud del nombre del fichero
	char f, c, r;				// caracteres que indican la forma, el color y el relleno de los elementos de la carta para componer el nombre del fichero
	int shapeWidth;			// ancho (en píxels) de la figura que representa cada elemento que aparecerá en la carta
	int whiteSpaceNum;		// número de espacios en blanco entre cartas
	int whiteSpace;			// espacio en blanco (en píxels) entre los elementos de la carta
	int i;						// índice para recorrer los elementos de la carta

	// Pintamos una carta de color blanco en la posición (fila, columna) del tablero

	x1 = OFFSET_X + columna * ( ANCHO_CARTA + OFFSET_X );
	y1 = 50 + OFFSET_Y + fila * ( ALTO_CARTA + OFFSET_Y );
	x2 = x1 + ANCHO_CARTA;
	y2 = 15 + y1 + ALTO_CARTA;
	y1 = y1 + 8;

	al_draw_filled_rounded_rectangle ( x1 , y1, x2, y2, 10, 10, makecolor2 ( COLOR_BLANCO ) );
	// Pintamos en la carta *numero* formas de forma *forma*, color *color* y relleno *relleno*

	if ( forma == 1 ) f = 'e';
	else if ( forma == 2 ) f = 'r';
	else f = 'w';

	if ( color == 1 ) c = 'b';
	else if ( color == 2 ) c = 'g';
	else c = 'r';

	if ( relleno == 1 ) r = 'e';
	else if ( relleno == 2 ) r = 'l';
	else r = 's';

	string filename = "./img/";
	filename.push_back ( f );
	filename.push_back ( c );
	filename.push_back ( r );
	filename = filename + ".png";
	n = filename.length ( );
	char char_array[n + 1];
	strcpy ( char_array, filename.c_str ( ) );
	shape = al_load_bitmap ( char_array );

	shapeWidth = al_get_bitmap_width ( shape ) * ZOOM;

	whiteSpaceNum = numero + 1;
	whiteSpace = ( ANCHO_CARTA - shapeWidth * numero ) / whiteSpaceNum;
	for ( i = 0; i < numero; i++ ) {
		al_draw_scaled_rotated_bitmap ( shape, 0, 0, x1 + ( i + 1 ) * whiteSpace + i * shapeWidth, y1 + ALTO_CARTA / 5, ZOOM, ZOOM, 0, 0);
	}
    al_flip_display ( );
}

void entornoBorrarCarta ( int fila, int columna ) {
	int x1 = OFFSET_X + columna * ( ANCHO_CARTA + OFFSET_X );
	int y1 = 50 + OFFSET_Y + fila * ( ALTO_CARTA + OFFSET_Y );
	int x2 = x1 + ANCHO_CARTA;
	int y2 = 15 + y1 + ALTO_CARTA;
	al_draw_filled_rounded_rectangle ( x1 , y1, x2, y2, 10, 10, makecolor2 ( COLOR_NEGRO ) );
	al_flip_display ( );
}

void entornoMarcarCarta ( int fila, int columna ) {
	int x1 = OFFSET_X + columna * ( ANCHO_CARTA + OFFSET_X ) - 3;
	int y1 = 50 + OFFSET_Y + fila * ( ALTO_CARTA + OFFSET_Y ) - 3;
	int x2 = x1 + ANCHO_CARTA + 3;
	int y2 = 15 + y1 + ALTO_CARTA +3;
	y1 = y1 + 10;
	al_draw_rectangle ( x1 - 4, y1 - 4, x2 + 4, y2 + 4, makecolor2 ( COLOR_AMARILLO ), 2 );
	al_flip_display ( );
}

void entornoDesmarcarCarta ( int fila, int columna ) {
	int x1 = OFFSET_X + columna * ( ANCHO_CARTA + OFFSET_X ) - 3;
	int y1 = 50 + OFFSET_Y + fila * ( ALTO_CARTA + OFFSET_Y ) - 3;
	int x2 = x1 + ANCHO_CARTA + 3;
	int y2 = 15 + y1 + ALTO_CARTA +3;
	y1 = y1 + 10;
	al_draw_rectangle ( x1 - 4, y1 - 4, x2 + 4, y2 + 4, makecolor2 ( COLOR_NEGRO ), 2 );
	al_flip_display ( );
}

void entornoSeleccionarCarta ( int fila, int columna ) {
	int x1 = OFFSET_X + columna * ( ANCHO_CARTA + OFFSET_X ) - 3;
	int y1 = 50 + OFFSET_Y + fila * ( ALTO_CARTA + OFFSET_Y ) - 3;
	int x2 = x1 + ANCHO_CARTA + 3;
	int y2 = 15 + y1 + ALTO_CARTA + 3;
	y1 = y1 + 10;
	al_draw_rounded_rectangle ( x1, y1, x2, y2, 10, 10, makecolor2 ( COLOR_ROJO ), 4 );
	al_flip_display ( );
}

void entornoDeseleccionarCarta ( int fila, int columna ) {
	int x1 = OFFSET_X + columna * ( ANCHO_CARTA + OFFSET_X ) - 3;
	int y1 = 50 + OFFSET_Y + fila * ( ALTO_CARTA + OFFSET_Y ) - 3;
	int x2 = x1 + ANCHO_CARTA + 3;
	int y2 = 15 + y1 + ALTO_CARTA + 3;
	y1 = y1 + 10;
	al_draw_rounded_rectangle ( x1, y1, x2, y2, 10, 10, makecolor2 ( COLOR_NEGRO ), 4 );
	al_flip_display ( );
}

void entornoPonerPuntuacion ( int puntos ) {
	string msg;
	al_draw_filled_rectangle ( 130 , 15, 320, 35, makecolor2 ( COLOR_NEGRO) );
	msg = "Puntuación: " + to_string ( puntos );			 // mostramos el nuevo marcador
	al_draw_text ( font, makecolor2 ( COLOR_BLANCO ),140, 10, ALLEGRO_ALIGN_LEFT, msg.c_str ( ) );
	al_flip_display ( );
}

void entornoPonerDisponibles ( int numCartas ) {
	string msg;
	al_draw_filled_rectangle ( 330 , 15, 550, 35, makecolor2 ( COLOR_NEGRO) );
	msg = "Cartas disponibles: " + to_string ( numCartas );	  // mostramos el nuevo número de cartas
	al_draw_text ( font, makecolor2 ( COLOR_BLANCO ),340, 10, ALLEGRO_ALIGN_LEFT, msg.c_str ( ) );
	al_flip_display ( );
}

void entornoMostrarMensajeFin ( string msg ) {
	int i, j;
	int desplazamientoCentrado;
	for ( i = 0, j = 0; i < 40 && j < 40; i = i + 4, j = j + 4 ) {
		al_draw_filled_rectangle ( i + 100,     j + 200     , 700 - i, 	 400 - j,  makecolor2 ( COLOR_BLANCO ) );
		al_draw_filled_rectangle ( i + 100 + 2 ,j + 200 + 2 , 700 - 2 - i, 400 - 2 - j,  makecolor2 ( COLOR_ROJO ) );
		usleep(50000); // medio segundo
		al_flip_display ( );
	}
	desplazamientoCentrado = (anchoVentana - msg.length()*11)/2;  // pixels x caracter = 11
	al_draw_text ( font, makecolor2 ( COLOR_BLANCO ), desplazamientoCentrado, 280, ALLEGRO_ALIGN_LEFT, msg.c_str ( ) );
	al_flip_display ( );
	usleep(500000); // 5 segundos
}

void entornoMostrarMensaje ( string msg, float pausa ) {
	int desplazamientoCentrado;
	desplazamientoCentrado = (anchoVentana - msg.length()*11)/2;  // pixels x caracter = 11
	al_draw_text ( font, makecolor2 ( COLOR_BLANCO ), desplazamientoCentrado, ALTO_VENTANA - 100, ALLEGRO_ALIGN_LEFT, msg.c_str ( ) );
	al_flip_display ( );
	entornoPausa ( pausa );
	al_draw_filled_rectangle ( 0, ALTO_VENTANA -100,  anchoVentana, ALTO_VENTANA - 70, makecolor2 ( COLOR_NEGRO ) );
	al_flip_display ( );
}

TipoTecla entornoLeerTecla ( ) {
	TipoTecla tecla = TNada;
	ALLEGRO_EVENT evento;

	al_wait_for_event ( colaEventos, &evento );

	if ( evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE )
		tecla = TSalir;

	else if ( evento.type == ALLEGRO_EVENT_KEY_DOWN ) {

		switch ( evento.keyboard.keycode ) {

		case ALLEGRO_KEY_LEFT:
			tecla = TIzquierda;
			break;
		case ALLEGRO_KEY_RIGHT:
			tecla = TDerecha;
			break;
		case ALLEGRO_KEY_UP:
			tecla = TArriba;
			break;
		case ALLEGRO_KEY_DOWN:
			tecla = TAbajo;
			break;
		case ALLEGRO_KEY_ESCAPE:
			tecla = TSalir;
			break;
		case ALLEGRO_KEY_ENTER:
			tecla = TEnter;
			break;
		case ALLEGRO_KEY_F1:
			tecla = TF1;
			break;
		case ALLEGRO_KEY_F2:
			tecla = TF2;
			break;
		default:
			tecla = TNada;
			break;
		}
	};
	return tecla;
}

void entornoPausa ( float pausa ) {
	al_rest ( pausa );
}
