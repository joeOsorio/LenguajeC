/*------------------------------
-LABORATORIO: 7 Matrices y arreglos.
-Nombre: Joshua Osorio
-Materia: LENGUAJE C 531
-Fecha: Marzo/12/2025

Descripción del Ejercicio:
Crear un arreglo unidimensional de 5 posiciones que almacene los nombres de 5 alumnos.
Implementar una matriz de 5x5 en la que cada fila corresponderá a un alumno, y cada columna almacenará su calificación en una de las 5 unidades.
Crear un segundo arreglo unidimensional de 5 posiciones que almacenará el promedio de las 5 unidades para cada alumno. El programa debe calcular automáticamente los promedios a partir de las calificaciones almacenadas en la matriz.

Mostrar en pantalla una tabla que incluya:

• Los nombres de los alumnos.
• Las calificaciones de las 5 unidades.
• El promedio final de cada alumno.
------------------------------*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define numAlum 5
#define unidades 5

void AsignarNombres(char[][50]);
void AsignarCalificaciones(char nombreAlumno[numAlum][50], float calificaciones[numAlum][unidades], float promedio[numAlum]);
void CalcularPromedio(char nombreAlumno[][50], float calificaciones[numAlum][unidades], float promedio[numAlum]);
void MostrarInformacion(char nombreAlumno[][50], float calificaciones[numAlum][unidades], float promedio[numAlum]);

int main(void)
{
	/* Semilla para la generacion de numeros aleatorios. */
	srand(time(NULL));

	int opc = 0;

	/* Declaracion de arraglo y matriz iniciando los valores en 0. */
	char nombreAlumnos[numAlum][50] = {""};
	/* Datos de prueba */
	/* char nombreAlumnos[numAlum][50] = {"Julian", "Chris", "Manuel", "Ghala", "Joshua"}; */
	float calificaciones[numAlum][unidades] = {0};
	float promedio[numAlum] = {0};

	do
	{
		/* Menu de la practica. */
		printf("\n---------------Menu---------------");
		printf("\n\t1) Capturar nombres");
		printf("\n\t2) Asignar calificaciones");
		printf("\n\t3) Calcular promedio");
		printf("\n\t4) Mostrar informcion");
		printf("\n\t5) Salir");
		printf("\nSelecciona una opcion:\t");
		scanf("%d", &opc);

		switch (opc)
		{
		case 1:
			AsignarNombres(nombreAlumnos);
			break;
		case 2:
			AsignarCalificaciones(nombreAlumnos, calificaciones, promedio);
			break;
		case 3:
			CalcularPromedio(nombreAlumnos, calificaciones, promedio);
			break;
		case 4:
			MostrarInformacion(nombreAlumnos, calificaciones, promedio);
			break;
		case 5:
			printf("\nSaliendo del programa");
			break;
		default:
			printf("\nOpcion no disponible =(");
			break;
		}
		printf("\n\nPresione cualquier tecla para continua");
		fflush(stdin);
		getchar();
	} while (opc != 5);
	return 0;
}

int aleatorio(void)
{
	int num;
	num = rand() % 10 + 1;
	return num;
}

void AsignarNombres(char arreglo[][50])
{
	char nombre[50] = "";
	for (int i = 0; i < numAlum; i++)
	{
		printf("\nIngresa el nombre del %d Alumno:", i + 1);
		scanf("%49s", nombre);
		strncpy(arreglo[i], nombre, 50);
	}
}

/* Funcion para rellenar aleatoriamente las calificaciones */
/* void AsignarCalificaciones(float arreglo[numAlum][unidades]){

	printf("\n Alumno   |P1\tP2\tP3\tP4\tP5\t");
	for(int f = 0; f < numAlum; f++){
		printf("\n Alumno %d |", f+1);
		for(int c = 0; c < unidades; c++){
			arreglo[f][c] = aleatorio();
			printf("%.2f  ", arreglo[f][c]);

		}
	}
} */
void AsignarCalificaciones(char nombreAlumno[numAlum][50], float calificaciones[numAlum][unidades], float promedio[numAlum])
{
	float cal = 0;
	printf("\n Capturar calificaciones.");
	for (int f = 0; f < numAlum; f++)
	{
		printf("\nAlumno: %s\n", nombreAlumno[f]);
		for (int c = 0; c < unidades; c++)
		{
			printf("Parcial %d:", c + 1);
			scanf("%f", &cal);
			calificaciones[f][c] = cal;
		}
	}
}

void CalcularPromedio(char nombreAlumno[][50], float calificaciones[numAlum][unidades], float promedio[numAlum])
{
	for (int f = 0; f < numAlum; f++)
	{
		for (int c = 0; c < unidades; c++)
		{
			promedio[f] += calificaciones[f][c];
		}
		promedio[f] = promedio[f] / unidades;
		printf("\n%s:  %0.2f ", nombreAlumno[f], promedio[f]);
	}
}

void MostrarInformacion(char nombreAlumno[][50], float calificaciones[numAlum][unidades], float promedio[numAlum])
{
	printf("\nAlumno  |P1\tP2\tP3\tP4\tP5\t| Promedio");
	for (int f = 0; f < numAlum; f++)
	{
		printf("\n %s |", nombreAlumno[f]);
		for (int c = 0; c < unidades; c++)
		{
			printf("%.2f\t", calificaciones[f][c]);
		}
		printf(" | %.2f", promedio[f]);
	}
}