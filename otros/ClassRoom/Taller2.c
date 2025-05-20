/* Taller: Cálculo de Rendimiento de un Procesador */
/* Nombre: Joe O^2 */
/* Materia: LENGUAJE C 531 */
/* Fecha: Febrero/06/2025 */


#include <stdio.h>


int main(void){

	int CPI, instruccionesEjecutadas, nucleos, memoriaCache;
	float GHz, tiempoEjecucion, IPS;
	


	printf("Rendindimiento del procesador\n\n\n");
	
	
	printf("Ciclos de reloj por instrucción (CPI):\t");
	scanf("%d", &CPI);
	fflush(stdin);

	printf("Frecuencia del procesador (en GHz):\t");
	scanf("%f", &GHz);
	fflush(stdin);

	printf("Cantidad total de instrucciones ejecutadas:\t");
	scanf("%d", &instruccionesEjecutadas);
	fflush(stdin);

	printf("Cantidad de núcleos:\t");
	scanf("%d", &nucleos);
	fflush(stdin);

	printf("Cantidad de memoria caché :\t");
	scanf("%f", &memoriaCache);
	fflush(stdin);

	tiempoEjecucion= (float)(instruccionesEjecutadas*CPI)/(GHz*10);

	IPS = instruccionesEjecutadas/tiempoEjecucion;
	
	printf("\n\nTiempo de ejecución:\t %.2f \n", tiempoEjecucion);
	printf("Número de instrucciones ejecutadas por segundo (IPS):\t %.2f \n", IPS);

	if((GHz >= 3.5) && (nucleos >= 8)){
		printf("El procesador es de alto rendimiento\n");
	}
	else if ((nucleos>=4) || (GHz > 2.5)){
		printf("Es óptimo para tareas generales\n");
	}
	else if (12 <= memoriaCache){
		printf("Tiene buena capacidad de caché\n");
	}
	else{
		printf("Se considera obsoleto\n");
	}
	
		
}