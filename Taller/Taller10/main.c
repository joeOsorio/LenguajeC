#include <stdio.h>

#define MAX 5

typedef struct Alumno
{
	char nombre[50];
	double calificaciones[3];
	double promedio;
} Alumno;

void Capturar(Alumno a[], int n);
double Promedio(double calificaciones[], int nc);
void Imprimir(Alumno a[], int n);
void MejorPromedio(Alumno a[], int n);
// Crear un procedimiento que compare calificaciones de cada parcial e indique quien fue el mejor en cada parcial.

void ComparaCadaParcial(Alumno a[], int n);

int main()
{
	Alumno alumnos[MAX];
	Capturar(alumnos, MAX);
	Imprimir(alumnos, MAX);
	MejorPromedio(alumnos, MAX);
	ComparaCadaParcial(alumnos, MAX);
	return 0;
}

void Capturar(Alumno a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("Alumno %d\n", i + 1);
		printf("Nombre: ");
		scanf(" %[^\n]", a[i].nombre);
		for (int j = 0; j < 3; j++)
		{
			printf("Calificacion %d: ", j + 1);
			scanf("%lf", &a[i].calificaciones[j]);
		}
		a[i].promedio = Promedio(a[i].calificaciones, 3);
		printf("\n");
	}
}

double Promedio(double calificaciones[], int n)
{
	double suma = 0;
	for (int i = 0; i < n; i++)
	{
		suma += calificaciones[i];
	}
	return suma / n;
}

void Imprimir(Alumno a[], int n)
{
	printf("\n%-20s %-10s %-10s %-10s %-10s\n", "Nombre", "C1", "C2", "C3", "Promedio");
	for (int i = 0; i < n; i++)
	{
		printf("%-20s %-10.2lf %-10.2lf %-10.2lf %-10.2lf\n", a[i].nombre, a[i].calificaciones[0], a[i].calificaciones[1], a[i].calificaciones[2], a[i].promedio);
	}
}

void MejorPromedio(Alumno a[], int n)
{
	int mejor = 0;
	for (int i = 1; i < n; i++)
	{
		if (a[i].promedio > a[mejor].promedio)
		{
			mejor = i;
		}
	}

	double mejorPromedio = a[mejor].promedio;
	printf("\nAlumno con el mejor promedio: %.2lf\n", mejorPromedio);
	for (int i = 0; i < n; i++)
	{
		if (a[i].promedio == mejorPromedio)
		{
			printf("%s Promedio: %.2lf\n", a[i].nombre, a[i].promedio);
		}
	}
}

void ComparaCadaParcial(Alumno a[], int n)
{
	// Se crea un arreglo donde guardar los indices de los alumnos
	double mejorPromedio[MAX] = {0};
	// Se recorre sobre 3 que son las calificaciones
	for (int c = 0; c < 3; c++)
	{
		int mejor = 0;
		for (int i = 1; i < n; i++)
		{
			if (a[i].calificaciones[c] > a[mejor].calificaciones[c])
			{
				mejor = i;
			}
		}
		mejorPromedio[c] = a[mejor].calificaciones[c];
		printf("\nAlumno con la mejor calificacion en C%d: %s %.2lf\n", c + 1, a[mejor], mejorPromedio[c]);
	}
}
