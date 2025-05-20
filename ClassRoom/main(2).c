/* Taller: Clasificación de triángulos */
/* Nombre: Joshua Osorio */
/* Materia: LENGUAJE C 531 */
/* Fecha: Febrero/13/2025 */


#include<stdio.h>


int main(void){
	float precioProducto = 0, desElectronicos =0.1, desRopa=0.15, desAlimento = 0.05, precioFinal, desOtros = 0;
	int categoria = 3;
	
	/* Titulo del programa */

	printf("Clasificación de triangulos\n");
	printf("--------------------------------\n\n");
	

	/* captura de precio */

	printf("Ingrese el precio del producto:\t");
	scanf("%f", &precioProducto);

	
	
	printf("Seleccione la categoria del producto:\n");
	printf("\t0) Electrocos -> 10%\n\t1)Ropa-> 15%\n\t2)Alimentos -> 5%\n\t3)Otros -> sin descuento\n\n");
	printf("Opcion:\t");
	scanf("%d", &categoria);
	
	/*Estructura de seleccion para mostrar el texto y aplicar el descuento deseado*/

	switch(categoria){
		case 0: 
			precioFinal =  precioProducto - (precioProducto * desElectronicos);
			printf("\nCategoria de electricos:\n\tPrecio:%.2f\n\tDescuento:%.2f %\n\tPrecio final:%.2f\n",precioProducto, desElectronicos *100 , precioFinal);
			break;
		case 1:
			precioFinal =  precioProducto - (precioProducto * desRopa);
			printf("\nCategoria de Ropa:\n\tPrecio:%.2f\n\tDescuento:%.2f %\n\tPrecio final:%.2f\n",precioProducto, desRopa *100 , precioFinal);
			break;
		case 2:
			precioFinal =   precioProducto - (precioProducto * desAlimento);
			printf("\nCategoria de Alimentos:\n\tPrecio:%.2f\n\tDescuento:%.2f %\n\tPrecio final:%.2f\n",precioProducto, desAlimento *100 , precioFinal);
			break;
		default:
			precioFinal =   precioProducto - (precioProducto * desOtros);
			printf("\nCategoria de otros:\n\tPrecio:%f\n\tDescuento:%.2f %\n\tPrecio final:%.2f\n",precioProducto, desOtros , precioFinal);			
	}

	printf("\n\nGracias por usar mi progrma.");

	return 0;
}