#include <stdio.h>

struct Alumno{
	char nombre[100];
	int edad;
	double c1, c2, c3;

};


//Prototipos de la funcion y procedimientos 

void Impresion(struct Alumno a);

double Calcular(struct Alumno a);

void Promedio(struct Alumno a);

void CambiarEdad(struct Alumno a);

//Inicio del bloque principal (main)

int main(){


	//Inicializacion de la estructura con un alias struct Alumno
	struct Alumno a;
	
	//Impresion y captura 
	printf("\nCual es el nombre del alumno?: ");

	scanf(" %[^\n]", a.nombre); 
	printf("\nCual es la edad del alumno?: ");
	scanf("%d", &a.edad);
	printf("\nEscribe las 3 calificaciones del alumno separadas por un enter: ");	
	scanf("%lf %lf %lf", &a.c1,&a.c2,&a.c3);
	
	//Llamada a funcion y procedimientos

	Impresion(a); 
	Promedio(a);
	CambiarEdad(a);
	Impresion(a);

	return 0;
}

	//Procedimiento para impresion de datos 

void Impresion(struct Alumno a){
	printf("\n%s", a.nombre);
	printf("\n%d", a.edad);
	printf("\n%lf", a.c1);
	printf("\n%lf", a.c2);
	printf("\n%lf", a.c3);
}

//Funon para el calculo del promedio.

double Calcular(struct Alumno a){
	return (a.c1 + a.c2 + a.c3)/3; 
}

//Procedimiento para mensaje de aprobado o reprobado en donde se llama a la funcion anterior

void Promedio(struct Alumno a){
	if(Calcular(a)<6){
		printf("\nAlumno reprobado");
	} else{
		printf("\nAlumno aprovado");
	}
}

//Promedio para cambiar edad

void CambiarEdad(struct Alumno a){
	printf("\n Calcular es la Nueva eded del alumno?: ");
	scanf(" %d", &a.edad);
	printf("\nLe edad actualizada desde el metodo es :%d ", a.edad);
}
