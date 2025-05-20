/*------------------------------
-Taller: 7 Matrices y arreglos.
-Nombre: Joshua Osorio
-Materia: LENGUAJE C 531
-Fecha: Marzo/12/2025
------------------------------*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>

#define t 5
#define timeS 0.8

// Cracion de prototipos de funciones y procedimientos.
int aleatorio(void);
void asignarMatriz(int[][t]);
void asignarMatriz2(int[][t]);
void asignarMatriz3(int[][t]);
void asignarMatriz4(int[][t]);
void desplegarMatriz(int[][t]);

int main(void)
{
	// Semilla para la generacion de numeros aleatorios.
	srand(time(NULL));

	int opc = 0;
	// Declaracion de arraglo y matriz iniciando los valores en 0.
	int matriz[t][t] = {0};

	do
	{
		int matriz[t][t] = {0};
		// Menu de la practica.
		printf("\n---------Menu---------");
		printf("\n\t1) Caso 1");
		printf("\n\t2) Caso 2");
		printf("\n\t3) Caso 3");
		printf("\n\t4) Caso 4");
		printf("\n\t5) Salir");
		printf("\nSelecciona una opcion\n/>");
		scanf("%d", &opc);

		switch (opc)
		{
		case 1:
			asignarMatriz(matriz);
			break;
		case 2:
			asignarMatriz2(matriz);
			break;
		case 3:
			asignarMatriz3(matriz);
			break;
		case 4:
			asignarMatriz4(matriz);
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
		system("cls");
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

// Procedimiento invoca la funcion de numero aleatorio y la almacena en el espacio de la matriz.

void asignarMatriz(int matriz[][t])
{
	desplegarMatriz(matriz);
	int num = 1;
	for (int f = 0; f < t; f++)
	{
		for (int c = 0; c < t; c++)
		{
			system("cls");
			matriz[f][c] = num;
			// printf("\nValor asignado %d en la coordenada %d,%d", matriz[f][c], f, c);
			num += 1;
			desplegarMatriz(matriz);
			sleep(timeS);
		}
	}
}

// Procedimiento para rellenar la matriz 2.

void asignarMatriz2(int matriz[][t])
{
	int num = t * t;
	desplegarMatriz(matriz);
	for (int c = 0; c < t; c++)
	{
		// printf("\n Si te entra");
		for (int f = t - 1; f >= 0; f--)
		{
			system("cls");
			// printf("\n Si te entra 2");
			/*matriz[f][c] = aleatorio();*/
			matriz[f][c] = num;
			// printf("\nValor asignado %d en la coordenada %d,%d", matriz[f][c], f, c);
			num -= 1;
			desplegarMatriz(matriz);
			sleep(timeS);
		}
	}
}

// Caso 3.

void asignarMatriz3(int matriz[][t])
{
	int num = t * t;
	desplegarMatriz(matriz);
	for (int c = 0; c < t; c++)
	{
		// printf("\n Si te entra");
		for (int f = 0; f < t; f++)
		{
			system("cls");
			// printf("\n Si te entra 2");
			/*matriz[f][c] = aleatorio();*/
			matriz[c][f] = num;
			// printf("\nValor asignado %d en la coordenada %d,%d", matriz[f][c], f, c);
			num -= 1;
			desplegarMatriz(matriz);
			sleep(timeS);
		}
	}
}

// Caso 4.

void asignarMatriz4(int matriz[][t])
{
	int num = t * t;
	desplegarMatriz(matriz);
	for (int c = t - 1; c >= 0; c--)
	{
		for (int f = 0; f < t; f++)
		{
			printf("\n Si te entra");
			system("cls");
			// printf("\n Si te entra 2");
			/*matriz[f][c] = aleatorio();*/
			matriz[f][c] = num;
			// printf("\nValor asignado %d en la coordenada %d,%d", matriz[f][c], f, c);
			num -= 1;
			desplegarMatriz(matriz);
			sleep(timeS);
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
			printf("%d\t", matriz[f][c]);
		}
		printf("\n");
	}
}
