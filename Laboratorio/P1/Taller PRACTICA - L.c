/* Taller: PRACTICA - L */
/* Nombre: Joe O^2 */
/* Materia: LENGUAJE C 531 */
/* Fecha: Febrero/06/2025 */


#include <stdio.h>

#define LongMaxCadena 100

int main(void){
	char *marca, *modelo;
	int fabricacion, ram;
	float espacioDisco,frecuenciaCPU;
	
	/* Capturar datos */
	
	printf("Marca: (max %d caracteres):", LongMaxCadena - 1);
	scanf("%s", &marca);
	fflush(stdin);
		
	printf("\nModelo: (max %d caracteres):", LongMaxCadena - 1);
	scanf("%s", &modelo);
	fflush(stdin);

	printf("\nAño de fabricación:");
	scanf("%i", &fabricacion);
	fflush(stdin);
	
	printf("\nCantidad de RAM en GB:");
	scanf("%i", &ram);
	fflush(stdin);	

	printf("\nCapacidad del disco en TB:");
	scanf("%f", &espacioDisco);
	fflush(stdin);

	printf("\nFrecuencia del procesador en GHz:\n", LongMaxCadena - 1);
	scanf("%f", &frecuenciaCPU);
	fflush(stdin);


	/*  Mostrar datos */

	printf("\n\n Información\n\n");
	printf("Marca:\t%s\n", marca);
	printf("Modelo:\t%s\n", &modelo);
	printf("Año de fabricacion:\t%d\n", fabricacion);
	printf("Cantidad de RAM en GB:\t%d\n", ram);
	printf("Capacidad del disco en TB:\t%.2f\n", espacioDisco);
	printf("Frecuencia del procesador en GHz:\t%.2f\n", frecuenciaCPU);
	printf("\n\n************ FIN ************\n");

}