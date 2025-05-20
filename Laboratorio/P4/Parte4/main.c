/* Practica: 4 ciclos de control*/
/* Nombre: Joshua Osorio */
/* Materia: LENGUAJE C 531 */
/* Fecha: Febrero/13/2025 */

#include<stdio.h>


int main(void){

	/* Declaración de variables */
	int base = 0, i, j;

	/* Titulo */
	printf("\n\t Impresión de una pirámide de 1\n\n\n");

	printf("Indique el tamaño de la base\n");
	
	/* Captura de datos para la piramide*/
	printf("\tBase:\t");
	scanf("%d",&base);

	for( i = 0; i < base; i++){
    		for(j=0;j<=i;j++){
       				printf("1");
		}
    		printf("\n");
	}

	printf("\n\nFIN");
	return 0;
}