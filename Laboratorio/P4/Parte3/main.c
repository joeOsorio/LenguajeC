/* Practica: 4 ciclos de control*/
/* Nombre: Joshua Osorio */
/* Materia: LENGUAJE C 531 */
/* Fecha: Febrero/13/2025 */

#include<stdio.h>


int main(void){

	/* Declaración de variables */
	int multipliacador = 0, i =0;

	/* Titulo */
	printf("\n\tTablas de multiplicar (while)\n\n\n");

	printf("Indica que tabla deseas imprimir.\n");
	
	/* Captura de datos tabla*/
	printf("\tTabla del :\t");
	scanf("%d",&multipliacador);

	while(i <= 10){
		printf("\t%d x %d = %d\n", multipliacador, i, multipliacador*i);
		i++;
	}

	printf("\n\nFIN");
	return 0;
}