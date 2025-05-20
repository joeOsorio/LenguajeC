/* Taller: 4 Ciclos */
/* Nombre: Joshua Osorio */
/* Materia: LENGUAJE C 531 */
/* Fecha: Febrero/19/2025 */


#include<stdio.h>

int main(void){
	int factorial=1, resp=0, opcion=0, inicio = 0, fin = 0, suma=0, par = 0, i = 0, j = 0;
	int tam[10];
	

	printf("Dame los valores de inicio y fin a utilizar para ejercicios:\n");
	scanf("%d	%d", &inicio, &fin);
	/* printf("\tInicio:\t");
	scanf("%d", & inicio);
	printf("\n\tFin:\t");
	scanf("%d", fin);*/

	for(int i = 0; i < 10;i++){
		tam[i]=1;		
	}
	
	do{
		printf("\n\nMenu");
		printf("\n\t1)-Suma de numeros pares usando for");
		printf("\n\t2)-Suma de numeros pares usando while");
		printf("\n\t3)-Impresion de diagonal tamanio definido usando for");
		printf("\n\t4)-Impresion de diagonal tamanio definido usando while");
		printf("\n\t5)-Calculo de factorial usando for");
		printf("\n\t6)-Calculo de factorial usando While");
		printf("\n\t7)-Salir");
		printf("\nElige una opcion del menu:\t");
		scanf("%d", &opcion);
		
		switch(opcion){
		case 1: /*Suma de numeros pares a partir de un rango usando for*/
			
			if((inicio%2) == 1){par = inicio + 1;}
			else{par = inicio;}
		
			for(int i = par; i <= fin; i + 2){
				suma+= i;
			}
			printf("\nSuma: %d", suma);
			break;

		case 2: /*Suma de numeros pares usando while*/
			
			if((inicio%2) == 1){par = inicio + 1;}
			else{par = inicio;}
			j = par;
			while(j <= fin){
				suma+= j;
				j+=2;
			}
			printf("\nSuma: %d", suma);
			

			break;

		case 3: /*Impresion de diagonal tamanio definido usando for*/

			for(int i = 0; i < 10;i++){
				printf("%d", tam[i]);	
			}
			
			break;

		case 4: /*Impresion de diagonal tamanio definido usando while*/

			i=0;
			while(i < 10){
				printf("%d", tam[i]);
				i++;	
			}

			break;

		case 5: /*Calculo de factorial usando for*/

			if(fin == 0 || fin == 1){
			printf("El resultado del factorial es = 1");}
			else{
				for(int i = 1; i<= fin; i++){
					factorial*= i;
					printf("\n%d", factorial);
				}
	
			}
			break;

		case 6: /*Calculo de factorial usando While*/
		
			if(fin == 0 || fin == 1){
			printf("El resultado del factorial es = 1");}
			else{
				j=1;
				while(i<= fin){
					factorial*= j;
					printf("\n%d", factorial);
					j++;
				}
	
			}

			break;
		
		}

	}while(opcion != 7);


	return 0; 
}