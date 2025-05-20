/*------------------------------
-Taller: 7 Matrices y arreglos.
-Nombre: Joshua Osorio
-Materia: LENGUAJE C 531
-Fecha: Marzo/12/2025
------------------------------*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define t 10

// Cracion de prototipos de funciones y procedimientos.
int aleatorio(void);
void asignarArreglo(int[]);
void desplegarArreglo(int[]);
void asignarMatriz(int[][t]);
void desplegarMatriz(int[][t]);

int main(void)
{
	// Semilla para la generacion de numeros aleatorios.
	srand(time(NULL));

	int opc = 0;
	// Declaracion de arraglo y matriz iniciando los valores en 0.
	int arreglo[t] = {0};
	int matriz[t][t] = {0};

	do
	{
		// Menu de la practica.
		printf("\n---------Menu---------");
		printf("\n\t1) Asignarvalores al arreglo");
		printf("\n\t2) Desplegar valores del arreglo");
		printf("\n\t3) Asignar valores a la matriz");
		printf("\n\t4) Desplegar valores de la matriz");
		printf("\n\t5) Salir");
		printf("\nSelecciona una opcion\n/>");
		scanf("%d", &opc);

		switch (opc)
		{
		case 1:
			asignarArreglo(arreglo);
			break;
		case 2:
			desplegarArreglo(arreglo);
			break;
		case 3:
			asignarMatriz(matriz);
			break;
		case 4:
			desplegarMatriz(matriz);
			break;
		case 5:
			printf("\nSaliendo del programa");
			break;
		default:
			printf("\nOpcion no disponible =(");
			break;
		}
		printf("\nPresione cualquier tecla para continua");
		fflush(stdin);
		getchar();
	} while (opc != 0);
	return 0;
}

// Funcion de generacion de numeros aleatorios, regresar el valor aleatorio para asignar al arreglo o matriz.

int aleatorio(void)
{
	int num;
	num = rand() % 100 + 1;
	return num;
}

// Procedimiento invocar la funcion de numero aleatorio y la almacena en el espacio del arrglo.

void asignarArreglo(int arreglo[])
{
	for (int i = 0; i < t; i++)
	{
		arreglo[i] = aleatorio();
		printf("\nValor asignado %d en el espacio %d", arreglo[i], i + 1);
	}
}

// Procedimiento para impresion de datos del arreglo.

void desplegarArreglo(int arreglo[])
{
	for (int i = 0; i < t; i++)
	{
		printf("\n%d", arreglo[i]);
	}
}

// Procedimiento invoca la funcion de numero aleatorio y la almacena en el espacio de la matriz.

void asignarMatriz(int matriz[][t])
{
	for (int f = 0; f < t; f++)
	{
		for (int c = 0; c < t; c++)
		{
			matriz[f][c] = aleatorio();
			printf("\nValor asignado %d en la coordenada %d,%d", matriz[f][c], f, c);
		}
	}
}

// Procedimiento para impresion de datos de la matriz.

void desplegarMatriz(int matriz[][t])
{
	for (int f = 0; f < t; f++)
	{
		for (int c = 0; c < t; c++)
		{
			printf(" %d", matriz[f][c]);
		}
		printf("\n");
	}
}
