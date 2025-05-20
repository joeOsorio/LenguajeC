/*------------------------------ 
-Taller: 5 Uso de Funciones
-Nombre: Joshua Osorio
-Materia: LENGUAJE C 531
-Fecha: Febrero/13/2025 
------------------------------*/


#include <stdio.h>
#include <windows.h> 

/* Protitipos de funciones */
void CapturaDatos(double *cel, double *far, double *kel);

double CelciusFarenheit(double cel);
double CelciusKelvin(double cel);
double FarenheitCelcius(double far);
double FarenheitKelvin(double far);
double KelvinCelcius(double kel);
double KelvinFarenheit(double kel);

int main(void){
	/*Declar variables */
	double cel = 0;
	double far = 0;
	double kel = 0;
	int seleccion = 0;

	printf("\n Taller No. 5 Ciclos de control en programación\n");
	do{
        system("cls");
        printf("\nMenu de conversión de valores\n");
	printf("\t1 - Capturar Valores\n");	
	printf("\t2 - Celcius - Farenheit\n");
	printf("\t3 - Celcius - Kelvin\n");
	printf("\t4 - Farenheit - Celcius\n");
	printf("\t5 - Farenheit - Kelvin\n");
	printf("\t6 - Kelvin - Celcius\n");
	printf("\t7 - Kelvin- Farenheit\n");
	printf("\t0 - Salir\n");
	printf("opción:");
        scanf("%d", &seleccion);
     
	switch (seleccion)
        {
        case 1:
		CapturaDatos(&cel, &far, &kel);
            break;
        case 2:
		far = CelciusFarenheit(cel);
		printf("Los grados a convertir son: %lf", &far);	
		fflush(stdin);
		getchar();
		system("cls");           
            break;
        case 3:
		kel = CelciusKelvin(cel); 		
		printf("Los grados a convertir son: %lf", &kel);
		fflush(stdin);
		getchar();
		system("cls");		
            break;
        case 4:
		cel = FarenheitCelcius(far);
		printf("Los grados a convertir son: %lf", &cel);
		fflush(stdin);
		getchar();
		system("cls");
	case 5:
		kel = FarenheitKelvin(far);		
		printf("Los grados a convertir son: %lf", &kel);
		fflush(stdin);
		getchar();
		system("cls");
            break;
	case 6:
		cel = KelvinCelcius(kel);		
		printf("Los grados a convertir son: %lf", &kel);
		fflush(stdin);
		getchar();
		system("cls");
            break;
	case 7:
		cel = KelvinFarenheit(kel);		
		printf("Los grados a convertir son: %lf", &cel);
          	fflush(stdin);
		getchar();
		system("cls");
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

void CapturaDatos(double *cel, double *far, double *kel){
	int seleccion = 0;
	system("cls");
	printf("\nCapturar datos\n");
	do{
        system("cls");
        printf("\nQue Valor deseas capturar\n");
	printf("\t1 - Celsius\n");	
	printf("\t2 - Farenheit\n");
	printf("\t3 - Kelvin\n");
	printf("\t0 - Salir\n");
	printf("opción:");
        scanf("%d", &seleccion);
     
	fflush(stdin);
	switch (seleccion)
        {
        case 1:
		printf("Celsius:\t");
		scanf("%lf", &cel);
		getchar();
		system("cls"); 
            break;
        case 2:
		printf("Farenheit:\t");
		scanf("%lf", &far);
		getchar();
		system("cls");           
            break;
        case 3:
           	printf("Kelvin:\t");
		scanf("%lf", &kel);
		getchar();
		system("cls");
            break;
        case 0:
         	printf("Regresando al menu principal");
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

}


double CelciusFarenheit(double cel){
	return ((cel * 1.8 ) + 32);
}

double CelciusKelvin(double cel){
	return (cel + 273.15);
}

double FarenheitCelcius(double far){
	return ((far - 32) * 0.55);
}

double FarenheitKelvin(double far){
	return (0.55 * (far - 32) +273.15);
}

double KelvinCelcius(double kel){
	return ( kel - 273.15);
}

double KelvinFarenheit(double kel){
	return (1.8 * (kel - 273.15) + 32 );
}
