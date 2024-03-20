/*
 * TAD Tablero.cpp
 *
 *  Created on: 5 ene. 2022
 *      Author: alumno
 */
#include "TAD Tablero.h"

void iniciarTablero(Tablero &t, int columnas){
	t.numColumnas=columnas;
	crearBaraja(t.baraja);
	int i,j;
	for(i=0; i<3; i++){
		for(j=0; j<columnas; j++){
			sacarCarta(t.baraja,t.m[i][j]);
		}
	}
}

int obtenerNumeroColumnasTablero(Tablero t){
	return t.numColumnas;
}

int obtenerCuantasCartasQuedanTablero(Tablero t){
	int cuantasQuedan= cuantasCartas(t.baraja);
	return cuantasQuedan;
}

Carta obtenerCartaConcretaTablero(Tablero t, int fila, int columna){
	Carta c;
	if(fila>=0 && columna>=0 && fila<3 && columna<t.numColumnas){
		c=t.m[fila][columna];
	}
	return c;
}

void caracteristicasCartaTablero(Tablero t, int fila, int columna, int &numero, int &forma, int &color, int &relleno){
	Carta c;
	if(fila>=0 && columna>=0 && fila<3 && columna<t.numColumnas){
		c=obtenerCartaConcretaTablero(t, fila, columna);
		numero=obtenerNumero(c);
		forma=obtenerForma(c);
		color=obtenerColor(c);
		relleno=obtenerRelleno(c);
	}
}

void seleccionarCartaTablero(Tablero &t, int fila, int columna){
	if(fila>=0 && columna>=0 && fila<3 && columna<t.numColumnas){
		if(obtenerSeleccion(t.m[fila][columna])==true){
			cambiarSeleccion(t.m[fila][columna], false);
		}
		else{
			cambiarSeleccion(t.m[fila][columna], true);
		}
	}
}

bool estaSeleccionadaCartaTablero(Tablero t, int fila, int columna){
	bool seleccion;
	if(fila>=0 && columna>=0 && fila<3 && columna<t.numColumnas){
		seleccion=obtenerSeleccion(t.m[fila][columna]);
	}
	return seleccion;
}

void anadirCartaTablero(Tablero &t, int fila, int columna, Carta c){
	if(fila>=0 && columna>=0 && fila<3 && columna<t.numColumnas){
		t.m[fila][columna]=c;
	}
}

bool formaSetTablero(Tablero t, Carta c1, Carta c2, Carta c3){
	bool set=false;
	if(obtenerSeleccion(c1)==true && obtenerSeleccion(c2)==true && obtenerSeleccion(c3)==true){
		if(setColor(c1, c2, c3)==true && setForma(c1, c2, c3)==true && setNumero(c1, c2, c3)==true && setRelleno(c1, c2, c3)==true){
			set=true;
		}
	}
	return set;
}


bool setColor(Carta c1, Carta c2, Carta c3){
	bool enc=false;
	if(obtenerColor(c1)==obtenerColor(c2) && obtenerColor(c2)==obtenerColor(c3)){
		enc=true;
	}
	else{
		if(obtenerColor(c1)!=obtenerColor(c2) && obtenerColor(c2)!=obtenerColor(c3) && obtenerColor(c1)!=obtenerColor(c3)){
			enc=true;
		}
	}
	return enc;
}

bool setForma(Carta c1, Carta c2, Carta c3){
	bool enc=false;
	if(obtenerForma(c1)==obtenerForma(c2) && obtenerForma(c2)==obtenerForma(c3)){
		enc=true;
	}
	else{
		if(obtenerForma(c1)!=obtenerForma(c2) && obtenerForma(c2)!=obtenerForma(c3) && obtenerForma(c1)!=obtenerForma(c3)){
			enc=true;
		}
	}
	return enc;
}

bool setNumero(Carta c1, Carta c2, Carta c3){
	bool enc=false;
	if(obtenerNumero(c1)==obtenerNumero(c2) && obtenerNumero(c2)==obtenerNumero(c3)){
		enc=true;
	}
	else{
		if(obtenerNumero(c1)!=obtenerNumero(c2) && obtenerNumero(c2)!=obtenerNumero(c3) && obtenerNumero(c1)!=obtenerNumero(c3)){
			enc=true;
		}
	}
	return enc;
}

bool setRelleno(Carta c1, Carta c2, Carta c3){
	bool enc=false;
	if(obtenerRelleno(c1)==obtenerRelleno(c2) && obtenerRelleno(c2)==obtenerRelleno(c3)){
		enc=true;
	}
	else{
		if(obtenerRelleno(c1)!=obtenerRelleno(c2) && obtenerRelleno(c2)!=obtenerRelleno(c3) && obtenerRelleno(c1)!=obtenerRelleno(c3)){
			enc=true;
		}
	}
	return enc;
}



int obtenerNumeroCartaConcretaTablero(Tablero t, int i, int j){
	return obtenerNumero(t.m[i][j]);
}

int obtenerFormaCartaConcretaTablero(Tablero t, int i, int j){
	return obtenerForma(t.m[i][j]);
}

int obtenerColorCartaConcretaTablero(Tablero t, int i, int j){
	return obtenerColor(t.m[i][j]);
}

int obtenerRellenoCartaConcretaTablero(Tablero t, int i, int j){
	return obtenerRelleno(t.m[i][j]);
}

bool obtenerSeleccionTablero(Tablero t, int i, int j){
	return obtenerSeleccion(t.m[i][j]);
}


bool comprobarSetTablero(Tablero t){
	Carta c1;
	Carta c2;
	Carta c3;
	bool set=false;
	if(buscarCartasSelccionadasTablero(t, c1, c2, c3)==3){
		if(formaSetTablero(t, c1, c2, c3)==true){
			set=true;
		}
	}
	return set;
}


void desmarcarLasCartasTablero(Tablero &t){
	int seleccionadas=0;
	int i, j;
	i=0;
	while(i<3 && seleccionadas<3){
		j=0;
		while(j<t.numColumnas && seleccionadas<3){
			if(obtenerSeleccion(t.m[i][j])==true){
				cambiarSeleccion(t.m[i][j], false);
				seleccionadas++;
			}
			j++;
		}
		i++;
	}
}


void meterCartasNuevasTablero(Tablero &t){
	bool enc=false;
	int i, j;
	int cont=0;
	if(cuantasCartas(t.baraja)>=3){
		i=0;
		while(i<3 && !enc){
			j=0;
			while(j<t.numColumnas && !enc){
				if(obtenerSeleccion(t.m[i][j])){
					sacarCarta(t.baraja, t.m[i][j]);
					cont++;
					if(cont==3){
						enc=true;
					}
				}
				j++;
			}
			i++;
		}
	}
}

int buscarCartasSelccionadasTablero(Tablero t, Carta &c1, Carta &c2, Carta &c3){
	int cont=0;
	int i, j;
	i=0;
	while(i<3 && cont<3){
			j=0;
			while(j<t.numColumnas && cont<3){
				if(obtenerSeleccion(t.m[i][j])==true){
					if(cont==0){
						c1=t.m[i][j];
						cont++;
					}
					else{
						if(cont==1){
							c2=t.m[i][j];
							cont++;
						}
						else{
							c3=t.m[i][j];
							cont++;
						}
					}
				}
				j++;
			}
			i++;
		}
	return cont;
}
