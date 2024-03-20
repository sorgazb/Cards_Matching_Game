/*
 * TAD Baraja.cpp
 *
 *  Created on: 25 dic. 2021
 *      Author: alumno
 */

#include "TAD Baraja.h"

void crearBaraja(Baraja &b){
	Carta c;
	int numero, forma, color, relleno; //Roles: inidices y valores fijos.
	b.ocupadas=0;
	for(numero=1; numero<=3;  numero++){
		for(forma=1; forma<=3; forma++){
			for(color=1; color<=3; color++){
				for(relleno=1; relleno<=3; relleno++){
					crearCarta(c, numero, forma, color, relleno);
					b.vBaraja[b.ocupadas]=c;
					b.ocupadas++;
				}
			}
		}
	}
	Carta aux;
	for(int i=0; i<MAX; i++){ //Rol: indice
		int z= rand() % MAX; //Rol: mejor hasta ahora
		int y= rand() % MAX; //Rol: mejor hasta ahora
		c=b.vBaraja[z];
		aux=b.vBaraja[y];
		intercambiar(c, aux);
		b.vBaraja[z]=c;
		b.vBaraja[y]=aux;
	}
}

void sacarCarta(Baraja &b, Carta &c){
	int p= rand() % b.ocupadas; //Rol: mejor hasta ahora
	c=b.vBaraja[p];
	for(int i=p; i<MAX; i++){ //Rol: indice
		b.vBaraja[i]= b.vBaraja[i+1];
	}
	b.ocupadas--;
}

int cuantasCartas(Baraja b){
	return b.ocupadas;
}




