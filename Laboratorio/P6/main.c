/*--------------------------------------------------------------------------------------- 
- Practica: 6 ciclos de control
- Nombre: Joshua Osorio 
- Materia: LENGUAJE C 531 
- Fecha: Febrero/13/2025 

Desarollo:
* Calcular el perímetro de cualquier tipo de figura o polígono regular
* Identificar si un número es primo
* Identificar si el número capturado es múltiplo de algún número base, definir Cuál es y cuantas veces cabe en dicho número
* Identificar si un número tiene raíz cuadrada exacta
---------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <windows.h>


void calcularPerimetro();
void numeroPrimo();
//void multiploNumbase();
//void raizCuadradaExacta();


int main(){
	/* Declaracion de variables */
	int opc;


	printf("\nPractica No. 6 Funciones\n");
	
	do{
        system("cls");
        printf("\nSelecciona un programa:\n");
	printf("\t1 - Calcular perímetro\n");
	printf("\t2 - Número Primo\n");
	printf("\t3 - Número base\n");
	printf("\t4 - Raiz cuadra exata\n");
	printf("\t0 - Salir\n");
	
	printf("opción:");
        scanf("%d", &opc);
	//opc = 3; // Para porbar las opciones mas rapido.
   
	system("cls");
	switch (opc)
        {
        case 1:

          	calcularPerimetro();
		printf("\nPresiona enter para continuar...\n");
		fflush(stdin);
		getchar();
		system("cls");
            break;
        case 2:
		numeroPrimo();
		printf("\nPresiona enter para continuar...\n");
		fflush(stdin);
		getchar();
		system("cls");           
            break;
        case 3:
           	//programa3();
		printf("\nPresiona enter para continuar...\n");
		fflush(stdin);
		getchar();
		system("cls");
            break;
        case 4:
           	//programa4();
		printf("\nPresiona enter para continuar...\n");
		fflush(stdin);
		getchar();
		system("cls");
            break;
        case 0:
         	printf("Saliendo...");
		fflush(stdin);	
		getchar();
            break;
        default:
            	printf("Opción no válida, intente nuevamente.\n");
            	fflush(stdin);
		getchar();
		break;
        }
    } while (opc != 0);


	return 0;
}


void calcularPerimetro(){
	int aristas = 0, i = 0 ;
	float longitud = 0, perimetro = 0;

	
        printf("\nCalcular perímetro\n");
	printf("\tCalcular el perímetro de cualquier tipo de figura o polígono regular\n");
	

	printf("\n\tCantidad de aristas del poligono?:\t");
        scanf("%d", &aristas);
	
	for(i; i < aristas; i++){
		printf("\nLongitud de la arista %i:\t", i+1);
        	scanf("%f", &longitud);
		perimetro +=longitud;
		//printf("%.2f", perimetro);
	}
	printf("\nEl perimetro del poligono es de %.2f u\t", perimetro);
}



void numeroPrimo(){
	int num = 0 , i= 2, esPrimo = 0, seDividio = 0;

	/*numeros primos= [2,3,5,7,11,13,17,19,23,29]*/

	printf("\nNúmero Primo\n");
	printf("\tIdentificar si un número es primo\n");
	
	printf("\n\tIngresa un numero:\t");
        scanf("%d", &num);
	
	if(num ==1){
		esPrimo =0;
	}
	// inicie i en 2 para simplificar el codigo, ya que todos sondivisibles entre 1.
	for(i;i <= num; i++){
		//printf("\nSi entro %d \n", i); // Solo para debugear. =)
		//printf("\n------Siguio %d\n", num % i); // Solo estaba debugeando
		if(num % i ==0 && i !=num){seDividio = 1;}
		//printf("\n------seDividio %d\n", seDividio);
		if( num % i==0 && !seDividio){
			esPrimo = 1;
			break;
		}

	}
	if(esPrimo){ 
		printf("\nEl numero si es primo");
	}
	else{
		printf("\nEl numero no es primo");
	}
}


//void multiploNumbase();
//void raizCuadradaExacta(){
//	int num = 0, i = 0;
//
//	printf("\nRaiz cuadra exata\n");
//	printf("\tIdentificar si un número tiene raíz cuadrada exacta\n");
//	
//	printf("\n\tIngresa un numero:\t");
//      scanf("%d", &num);
//
//	for(i; i <= num; i++){
//		if( num )
//	}
//}




