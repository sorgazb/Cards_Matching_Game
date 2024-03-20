/*
 * pr_TADCarta.cpp
 *
 *  Created on: 25 dic. 2021
 *      Author: alumno
 */

#include <iostream>
using namespace std;
#include "pr_TADCarta.h"

void pruebaCarta(){
	Carta c1;
	Carta c2;

	cout<<"-INICIO DE LAS PRUEBAS DEL TAD_CARTA: "<<endl;

	//Caso 1:

	crearCarta(c1, 1, 1, 1, 1);

	if(obtenerNumero(c1)!=1){
		cout<<"Error en el NUMERO de la Carta c1."<<endl;
	}

	if(obtenerForma(c1)!=1){
		cout<<"Error en la FORMA de la Carta c1."<<endl;
	}

	if(obtenerColor(c1)!=1){
		cout<<"Error en el COLOR de la Carta c1."<<endl;
	}

	if(obtenerRelleno(c1)!=1){
		cout<<"Error en el RELLENO de la Carta c1."<<endl;
	}

	//Caso 2:

	crearCarta(c2, 3, 1, 2, 2);

	if(obtenerNumero(c2)!=3){
		cout<<"Error en el NUMERO de la Carta c2."<<endl;
	}

	if(obtenerForma(c2)!=1){
		cout<<"Error en la FORMA de la Carta c2."<<endl;
	}

	if(obtenerColor(c2)!=2){
		cout<<"Error en el COLOR de la Carta c2."<<endl;
	}

	if(obtenerRelleno(c2)!=2){
		cout<<"Error en el RELLENO de la Carta c2."<<endl;
	}

	cout<<"- FIN DE LAS PRUEBAS DEL TAD_CARTA."<<endl;
}



