/*
 * pr_TAD Tablero.cpp
 *
 *  Created on: 12 ene. 2022
 *      Author: alumno
 */
#include "pr_TAD Tablero.h"



void pruebaIniciarTablero(){
	Tablero t;
	iniciarTablero(t, 5);
	if(t.numColumnas!=5){
		cout<<"Error al iniciar el Tablero"<<endl;
	}
}

void pruebaNumeroColumnasTablero(){
	Tablero t;
	if(obtenerNumeroColumnasTablero(t)!=t.numColumnas){
		cout<<"Error al obtener el numero de Columnas del Tablero"<<endl;
	}
}

void pruebaCuantasCartasQuedanTablero(){
	Tablero t;
	if(obtenerCuantasCartasQuedanTablero(t)!=t.baraja.ocupadas){
		cout<<"Error al obtener cuantas cartas quedan en el Tablero"<<endl;
	}
}

void pruebaObtenerCaracteristicas(){
	Tablero t;
	int i=0;
	int j=0;
	obtenerNumeroCartaConcretaTablero(t, i, j);
	obtenerFormaCartaConcretaTablero(t, i, j);
	obtenerColorCartaConcretaTablero(t, i, j);
	obtenerRellenoCartaConcretaTablero(t, i, j);
}

void pruebaSeleccionarCartaTablero(){
	Tablero t;
	int i=0;
	int j=0;
	if(obtenerSeleccionTablero(t, i, j)==true){
		cout<<"Error al seleccionar la carta del Tablero"<<endl;
	}
}

void pruebasTablero(){
	cout<<"Inicio de las Pruebas del Tablero"<<endl;
	Tablero t;
	iniciarTablero(t, t.numColumnas);
	pruebaIniciarTablero();
	pruebaNumeroColumnasTablero();
	pruebaCuantasCartasQuedanTablero();
	pruebaObtenerCaracteristicas();
	pruebaSeleccionarCartaTablero();
	cout<<"Fin de las Pruebas Tablero"<<endl;
}

