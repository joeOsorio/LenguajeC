/* Practica: 4 ciclos de control*/
/* Nombre: Joshua Osorio */
/* Materia: LENGUAJE C 531 */
/* Fecha: Febrero/13/2025 */


#include <stdio.h>
#include <windows.h> 

void programa1(void);
void programa2(void);
void programa3(void);
void programa4(void);

int main(void)
{
    printf("\n Práctica No. 5 Ciclos de control en programación\n");
    int seleccion = 0; 

    /* Variables de la práctica */

    do
    {
        system("cls");
        printf("\nSelecciona un programa:\n");
	printf("\t1 - Suma de los números del N a M (for)\n");
	printf("\t2 - Impresión de números primos (while)\n");
	printf("\t3 - Tablas de multiplicar (while)\n");
	printf("\t4 - Impresión de una pirámide de 1 (for)\n");

	printf("opción:");
        scanf("%d", &seleccion);
        
	switch (seleccion)
        {
        case 1:
          	programa1();
		fflush(stdin);
		getchar();
		system("cls");
            break;
        case 2:
		programa2();
		fflush(stdin);
		getchar();
		system("cls");           
            break;
        case 3:
           	programa3();
		fflush(stdin);
		getchar();
		system("cls");
            break;
        case 4:
           	programa4();
		fflush(stdin);
		getchar();
		system("cls");
            break;
        case 0:
         	printf("Saliendo");
		fflush(stdin);	
		getchar();
            break;
        default:
            	printf("Opción no válida, intente nuevamente.\n");
            	fflush(stdin);
		getchar();
		break;
        }
    } while (seleccion != 0);

    return 0;
}

void programa1(void){

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
}

void programa2(void){

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
}

void programa3(void){

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
}


void programa4(void){

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
}
