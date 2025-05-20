/* Taller: PRACTICA de taller 1 (Practica 3 de taller)*/
/* Nombre: Joe O^2 */
/* Materia: LENGUAJE C 531 */
/* Fecha: Febrero/12/2025 */

#include<stdio.h>

int main(void){
	int num_partidas;
	float p1=0, p2= 0, p3=0, p4=0, p5=0;
	float promedio, suma=0;
	char rango[15], premio[20];
	

	printf("Ingrese la cantidad de partidas (1-5): ");
	scanf("%d", &num_partidas);

	/* Capturar puntuaciones. */

	if(num_partidas >= 1){
		printf("Ingrese la puntuacion de la partida 1 (0-1000): ");
		scanf("%f", &p1);
		suma +=p1;
	}
	if(num_partidas >=2){
		printf("Ingrese la puntuacion de la partida 2 (0-1000): ");
		scanf("%f", &p2);
		suma +=p2;
	}
	if(num_partidas >=3){
		printf("Ingrese la puntuacion de la partida 3 (0-1000): ");
		scanf("%f", &p3);
		suma +=p3;
	}
	if(num_partidas>=4){
		printf("Ingrese la puntuacion de la partida 4 (0-1000): ");
		scanf("%f", &p4);
		suma +=p4;
	}
	if(num_partidas ==5){
		printf("Ingrese la puntuacion de la partida 5 (0-1000): ");
		scanf("%f", &p5);
		suma +=p5;
	}
	
	/*Calcular promedio*/
	promedio = suma / num_partidas;

		
	/* Determinar el rango usado*/
	if(promedio >= 900){
		sprintf(rango, "Leyenda");
	}else if(promedio >= 700){
		sprintf(rango, "Experto");
	}else if(promedio >= 500){
		sprintf(rango, "Avanzado");
	}else if(promedio >= 300){
		sprintf(rango, "Intermedio");
	}else if(promedio >= 100){
		sprintf(rango, "Principiante");
	}else{
		sprintf(rango, "Experto");
	}

	/*La función sprintf() en c se utiliza para formatear cadenas de caracteres 	y almacenalas en una varianle de tipo char[] (un arreglo e caracteres). Su 	propósito es similar a printf(), pero en lugar de imprimir la salida en la 	consola, se guarda en una variable*/
	
	/*Asigna promedio usando switch-case*/

	switch(rango[0]){
	case 'L':
		sprintf(premio,"Trofeo de Oro");
		break;
	case 'E':
		sprintf(premio,"Medalla de Plata");
		break;
	case 'A':
		sprintf(premio,"Medalla de Bronce");
		break;
	case 'I':
		sprintf(premio,"Insignia Digital");
		break;
	case 'P':
		sprintf(premio,"XP Aadicional");
		break;
	defaul:
		sprintf(premio,"Sin premio");
		break;

	}

	/* Mostrar resultados. */
	printf("\n Tu promedio de puntuación es: %.2f", promedio);
	printf("\n Tu rango es: %s", rango);
	printf("\n Promedio asignado: %s\n\n", premio);

	return 0;
}