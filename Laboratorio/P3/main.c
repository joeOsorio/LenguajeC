/* Taller: Clasificación de triángulos */
/* Nombre: Joshua Osorio */
/* Materia: LENGUAJE C 531 */
/* Fecha: Febrero/13/2025 */


#include<stdio.h>


int main(void){
	int tipoTriangulo=0;
	float lado1=0, lado2=0, lado3=0, suma1, suma2, suma3;

	/* Captura de lados de triangulo */

	printf("Clasificación de triangulos\n");
	printf("--------------------------------\n\n");
	
	printf("Ingrese el valor del lado 1:\t");
	scanf("%f", &lado1);
	fflush(stdin);	

	printf("\nIngrese el valor del lado 2:\t");
	scanf("%f", &lado2);

	printf("\nIngrese el valor del lado 3:\t");
	scanf("%f", &lado3);
	
	/* Clasificación de triangulos */

	/*Se tiene que revisar los 3 casos porque sino no es un triangulo */
	suma1= lado1 + lado2;
	suma2= lado1 + lado3;
	suma3= lado2 + lado3;
	
	if(lado1 == lado2 == lado3){tipoTriangulo = 1;}
	else if (((lado1 == lado2)||(lado1 == lado3) || (lado2 == lado3) )&& ((lado1!=0) && (lado3!=0 ))){tipoTriangulo = 2;}
	else if (((lado1 != 0)&&(lado2 != 0) && (lado3 != 0))&& !(suma1 <  lado3) || (suma2 <  lado2) || (suma3 <  lado1)){tipoTriangulo = 3;}
	else if ((suma1 >  lado3) || (suma2 >  lado2) || (suma3 >  lado1)){tipoTriangulo= 4;}
	
	
	/*printf("\ntipo de triangulo:%d\n", tipoTriangulo);*/
	
	/* Mostrar el tipo de triangulo en terminal.*/

	switch(tipoTriangulo){
		case 1: 
			printf("Es un triangulo equilatero.\nL1:%.2f\tL2:%.2f\tL3:%.2f.\n", lado1, lado2, lado3);
			break;
		case 2:
			printf("Es un triangulo isoceles.\nL1:%.2f\tL2:%.2f\tL3:%.2f.\n", lado1, lado2, lado3);
			break;
		case 3:
			printf("Es un triangulo escaleno.\nL1:%.2f\tL2:%.2f\tL3:%.2f.\n", lado1, lado2, lado3);
			break;
		case 4:
			printf("Invalido.\nL1:%.2f\tL2:%.2f\tL3:%.2f.\n", lado1, lado2, lado3);
			break;
		default:
			printf("No es un triangulo porque sus lados miden 0.\nL1:%.2f\tL2:%.2f\tL3:%.2f.\n", lado1, lado2, lado3);
			
	}

	printf("\nGracias por usar mi progrma.");
	return 0;
}