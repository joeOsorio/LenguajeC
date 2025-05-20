/* Practica: 4 ciclos de control*/
/* Nombre: Joshua Osorio */
/* Materia: LENGUAJE C 531 */
/* Fecha: Febrero/13/2025 */

#include<stdio.h>


int main(void){

	/* Declaración de variables */
	int inicio = 0, fin = 0, numero = 0, i = 0;

	/* Titulo */
	printf("\n\tSuma de los números del N a M (for)\n\n\n");

	printf("Indica los rangos de inicio y fin para sumar los numeros\n");
	
	/* Captura de datos inicio y fin */

	printf("\tInicio:\t");
	scanf("%d",&inicio);
	printf("\tFin:\t");
	scanf("%d",&fin);

	for(i = inicio ; i < fin ; i++){
		printf("%d ", numero+=i);
	}
	printf("\n\nFIN");
	return 0;
}