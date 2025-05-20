#include <stdio.h>


int main(void){
	/* variables que guardan los valores de entrada */
	int num1, num2;

	/* variables que guardan operaciones aritmeticas */
	int suma, resta, multiplicacion, modulo;
	float division;

	/* variables que guardan operaciones relacionales */

	int igual, diferente, mayor, menor, mayorIgual, manorIgual;

	/* variables que guardan operaciones logicas */
	int yy, oo, no;


	/* Entrada de datos*/
	printf("Calculadora sin condicionales en C/n/n");
	printf("Ingrese dos numeros enteros\n");
	printf("Numero 1: ");
	scanf("%d", &num1);
	printf("\nNumero 2: ");
	scanf("%d", &num2);

	/*Operaciones aritmeticas */

	printf("/n Operaciones Aritmeticas /n");
	printf("Suma: %d + %d = %d\n", num1, num2, num1 + num2);
	printf("Resta: %d + %d = %d\n", num1, num2, num1 - num2);
	printf("Multiplicaión: %d + %d = %d\n", num1, num2, num1 * num2);


	/*Division con conversion a flotante */
	
	division = (float)num1 / num2;
	printf("Division: %d / %d = %.2f \n", num1, num2, division);

	/*Modulo (solo muestra si num2 es distinto de 0)*/
	printf("Modulo: %d %% %d = %d \n",num1, num2, num1 % num2);

	/*operaciones Realacionales */
	printf("\nOperaciones Relacionales\n");
	printf("%d == %d = %d\n", num1, num2, num1 == num2);
	printf("%d != %d = %d\n", num1, num2, num1 != num2);
	printf("%d > %d = %d\n", num1, num2, num1 > num2);
	printf("%d < %d = %d\n", num1, num2, num1 < num2);
	printf("%d >= %d = %d\n", num1, num2, num1 >= num2);
	printf("%d <= %d = %d\n", num1, num2, num1 <= num2);

	/*Operaciones Logicas*/
	printf("(%d > 0 ) && (%d > 0) = %d\n", num1, num2, (num1 > 0 ) && (num2 > 0));
	printf("(%d > 0 ) || (%d > 0) = %d\n", num1, num2, (num1 > 0 ) || (num2 > 0)); 
	printf("!(%d > 0) = %d\n", num1, !(num1 > 0));

	/*
	Otra forma de hacerlo
	*/
			
	/*Operaciones aritmeticas */

	printf("/n Operaciones Aritmeticas /n");
	suma = num1 + num2;
	printf("Suma: %d + %d = %d\n", num1, num2, suma);
	resta = num1 - num2;
	printf("Resta: %d + %d = %d\n", num1, num2, resta);\
	multiplicacion = num1 * num2;
	printf("Multiplicaión: %d + %d = %d\n", num1, num2, multiplicacion);


	/*Division con conversion a flotante */
	
	division = (float)num1 / num2;
	printf("Division: %d / %d = %.2f \n", num1, num2, division);

	/*Modulo (solo muestra si num2 es distinto de 0)*/
	modulo = num1 % num2;
	printf("Modulo: %d %% %d = %d \n",num1, num2, modulo);

	/*operaciones Realacionales */
	/* igual, diferente, mayor, menor, mayorIgual, manorIgual; */


		
	printf("\nOperaciones Relacionales\n");
	igual = num1 == num2;
	printf("%d == %d = %d\n", num1, num2, igual);
	diferente = num1 != num2;
	printf("%d != %d = %d\n", num1, num2, diferente);
	mayor = num1 > num2;
	printf("%d > %d = %d\n", num1, num2, mayor);
	menor= num1 < num2;
	printf("%d < %d = %d\n", num1, num2);
	mayorIgual= num1 >= num2;
	printf("%d >= %d = %d\n", num1, num2, mayorIgual);
	manorIgual=num1 <= num2;
	printf("%d <= %d = %d\n", num1, num2, manorIgual);

	/*Operaciones Logicas*/
	/*int yy, oo, no*/
	yy=(num1 > 0 ) && (num2 > 0);
	printf("(%d > 0 ) && (%d > 0) = %d\n", num1, num2, yy);
	oo=(num1 > 0 ) || (num2 > 0);
	printf("(%d > 0 ) || (%d > 0) = %d\n", num1, num2, oo); 
	no=!(num1 > 0);
	printf("!(%d > 0) = %d\n", num1, no);

	return 0;
}