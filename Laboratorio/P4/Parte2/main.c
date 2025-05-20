/* Practica: 4 ciclos de control*/
/* Nombre: Joshua Osorio */
/* Materia: LENGUAJE C 531 */
/* Fecha: Febrero/13/2025 */

#include<stdio.h>


int main(void){

	/* Declaración de variables */
	int fin = 0, i =0;

	/* Titulo */
	printf("\n\tImpresión de números primos (while)\n\n\n");

	printf("Indica hasta que numero quieres parar.\n");
	
	/* Captura de datos inicio y fin */
	printf("\tFin:\t");
	scanf("%d",&fin);

	while(i <= fin){
		if(i%2){
			printf("%d ", i);
		}
		i++;
	}

	printf("\n\nFIN");
	return 0;
}