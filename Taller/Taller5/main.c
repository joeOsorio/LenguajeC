/*------------------------------
-Taller: 5 Uso de Funciones
-Nombre: Joshua Osorio
-Materia: LENGUAJE C 531
-Fecha: Febrero/13/2025
------------------------------*/

#include <stdio.h>
#include <windows.h>

/* Protitipos de funciones */
void CapturaDatos(double *cel, double *faren, double *kel);

double CelciusFahrenheit(double cel);
double CelciusKelvin(double cel);
double FahrenheitCelcius(double faren);
double FahrenheitKelvin(double faren);
double KelvinCelcius(double kel);
double KelvinFahrenheit(double kel);

int main(void)
{
	/*Declaracion de variables*/
	double cel = 0;
	double kel = 0;
	double faren = 0;
	int seleccion = 0;

	printf("\n Taller No. 5 Ciclos de control en programación\n");
	do
	{
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
			CapturaDatos(&cel, &faren, &kel);
			fflush(stdin);
			getchar();
			break;
		case 2:
			faren = CelciusFahrenheit(cel);
			printf("Los grados a convertir son: %lf", faren);
			fflush(stdin);
			getchar();
			break;
		case 3:
			kel = CelciusKelvin(cel);
			printf("Los grados a convertir son: %lf", kel);
			fflush(stdin);
			getchar();
			break;
		case 4:
			cel = FahrenheitCelcius(faren);
			printf("Los grados a convertir son: %lf", cel);
			fflush(stdin);
			getchar();
			break;
		case 5:
			kel = FahrenheitKelvin(faren);
			printf("Los grados a convertir son: %lf", kel);
			fflush(stdin);
			getchar();
			break;
		case 6:
			cel = KelvinCelcius(kel);
			printf("Los grados a convertir son: %lf", cel);
			fflush(stdin);
			getchar();
			break;
		case 7:
			cel = KelvinFahrenheit(kel);
			printf("Los grados a convertir son: %lf", cel);
			fflush(stdin);
			getchar();
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

void CapturaDatos(double *cel, double *faren, double *kel)
{
	int seleccion = 0;
	system("cls");
	printf("\nCapturar datos\n");
	do
	{
		system("cls");
		printf("\nQue Valor deseas capturar\n");
		printf("\t1 - Celsius:\t%lf\n", &cel);
		printf("\t2 - Fahrenheit:\t%lf\n", &faren);
		printf("\t3 - Kelvin:\t%lf\n", &kel);
		printf("\t0 - Salir\n");
		printf("opción:");
		scanf("%d", &seleccion);

		fflush(stdin);
		switch (seleccion)
		{
		case 1:
			printf("Celsius:\t");
			scanf("%lf", cel);
			system("cls");
			break;
		case 2:
			printf("Fahrenheit:\t");
			scanf("%lf", faren);
			getchar();
			system("cls");
			break;
		case 3:
			printf("Kelvin:\t");
			scanf("%lf", kel);
			getchar();
			system("cls");
			break;
		case 0:
			printf("Regresando al menu principal\nPresiona cualquier tecla para continuar...");
			
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

double CelciusFahrenheit(double cel)
{
	return ((cel * 1.8) + 32);
}

double CelciusKelvin(double cel)
{
	return (cel + 273.15);
}

double FahrenheitCelcius(double faren)
{
	return ((faren - 32) * 0.55);
}

double FahrenheitKelvin(double faren)
{
	return (0.55 * (faren - 32) + 273.15);
}

double KelvinCelcius(double kel)
{
	return (kel - 273.15);
}

double KelvinFahrenheit(double kel)
{
	return (1.8 * (kel - 273.15) + 32);
}