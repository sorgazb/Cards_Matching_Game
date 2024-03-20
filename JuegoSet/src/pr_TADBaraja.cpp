/*
 * pr_TADBaraja.cpp
 *
 *  Created on: 25 dic. 2021
 *      Author: alumno
 */

#include "pr_TADBaraja.h"

void pruebaCrearBaraja(){
	cout<<"Inicio de las pruebas crearBaraja:"<<endl;
	Baraja b;
	crearBaraja(b);
	if(cuantasCartas(b)!=MAX){
		cout<<"Error al iniciar el vov."<<endl;
	}
	cout<<"Fin de las pruebas crearBaraja."<<endl;
}

void pruebaSacarBaraja(){
	cout<<"Inicio de las pruebas sacarBaraja"<<endl;
	Baraja b;
	Carta c;
	crearBaraja(b);
	sacarCarta(b, c);
	if(cuantasCartas(b)==MAX){
		cout<<"Error al sacar la carta de la baraja"<<endl;
	}
	cout<<"Fin de las pruebas sacarBaraja."<<endl;
}

void pruebaBaraja(){
	cout<<"-INICIO DE LAS PRUEBAS DEL TAD_BARAJA: "<<endl;
	pruebaCrearBaraja();
	pruebaSacarBaraja();
	cout<<"-FIN DE LAS PRUEBAS DEL TAD_BARAJA."<<endl;
}



