/****************************************************
 * File: main
 * Author: Joshua Osorio Osorio
 * Materia:  LENGUAJE C (531)
 * Date: 08/May/2025
 * Comments:
 *
 * Objetivo:
 * Crear un programa en C que simule la gestión de asientos en una sala de cine. El programa asignará asientos y los asociará con un tipo de ticket: niño, adulto, o mayor     
 * de 60 años. También mostrará el estado actual de los asientos (ocupados/libres) y generará un resumen al final.

 * Descripción del programa:
 * 1. La sala de cine tiene una capacidad de n filas y m columnas (puedes ajustar el tamaño).
 * 2. Cada asiento puede estar libre o ocupado.
 * 3. Si está ocupado, el programa almacenará el tipo de ticket que ocupa el asiento.
 * 4. El programa permitirá las siguientes operaciones:
 * Mostrar el estado actual de la sala.
 * Asignar un asiento a un cliente indicando el tipo de ticket.
 * Mostrar un resumen de los tickets vendidos por tipo.
 * Los usuarios no podrán ocupar un asiento ya asignado. 
 ***************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define FILAS    5
#define COLUMNAS 5

typedef struct{
	int estado;
	char *Tipo;
}ASIENTO;


typedef struct{
	int filas = FILAS;
	int columnas = COLUMNAS;
	int totalAsientos;
	ASIENTO asiento[FILAS][COLUMNAS];
}SALA;

void estadoActualSala(SALA *sala);
void asignarAsiento(SALA *sala);
void resumen(SALA *sala);


int main(void){
	

	return 0;
}

void asignarAsiento(SALA *sala){
	
	char *tiposAsientos[10] = {"Niño", "adulto", "Mayor"};
	int fila, columna; 	

	printf("Que asiento deseas?");
	do{
	printf("\tFila");
	scanf("\t%d", &fila);
	if(!(fila > 0 &  fila < FILAS)){
		printf("Fila no existe intenta nuevamente");
	}
	}while(columna > 0 & columna < COLUMNAS );

	do{
	printf("\tColumna");
	scanf("%d", &columna);
	if(!(fila > 0 &  fila < FILAS)){
		printf("Columna no existe intenta nuevamente");
	}
	}while(fila > 0 &  fila < FILAS);

	if(sala.asiento[fila][columna].)
	
}






















