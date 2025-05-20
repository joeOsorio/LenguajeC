#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct Lanzamiento{
	int dado1;
	int dado2;
	int suma;
};

struct Jugador{
	char nombre[50];
	int lanzamiento[20];
	int cantidad_lanzamientos;
	int exito;
};

void lanzarDados(struct Lanzamiento *lanzamiento);
int jugarRondas(struct Jugador *j);
void determinarGanador(struct Jugador jugadores[], int numJugadores);
void registrarJugadores(struct Jugador jugadores[], int jmax);
void jugarConJugadores(struct Jugador *jugadores, int *numJugadores);

int main(){
	srand(time(NULL));
	int jmax = 0;
	printf("Ingresa la cantidad de jugadores: ");
	scanf("%d", jmax);
	struct Jugador jugadores[jmax];
	registrarJugadores(jugadores, jmax);
	jugarConJugadores(jugadores, &jmax);
	determinarGanador(jugadores, jmax);
return 0;
}

void lanzarDados(struct Lanzamiento *lanzamiento){
	lanzamiento -> dado1 = rand() %6 + 1;
	lanzamiento -> dado2 = rand() %6 + 1;
	lanzamiento -> suma = 	lanzamiento -> dado1 + lanzamiento -> dado2;
}

int jugarRondas(struct Jugador *j){
	struct Lanzamiento lanzamiento;
	j-> cantidad_lanzamientos = 0;
	for(int i = 0; i<20; i++){
		lanzarDados(&lanzamiento);
		j->lanzamiento[i]=lanzamiento.suma;
		j->cantidad_lanzamientos++;
		printf("Jugador %10s Lanzamiento %-10d Dado 1 = %-10d Dado 2 = %-10d Suma = %-10d \n", j->nombre, i+1, lanzamiento.dado1,lanzamiento.dado2,lanzamiento.suma);
		if(lanzamiento.suma == 12){
			j->exito = 1;
			break;
		}

	}
return j->cantidad_lanzamientos;	
}


void determinarGanador(struct Jugador jugadores[], int numJugadores){
	int indiceGanador = -1;
	int minLanzamientos = 21;
	for(int i = 0; i< numJugadores; i++){
		if(jugadores[i].exito && jugadores[i].cantidad_lanzamientos < minLanzamientos){
			minLanzamientos = jugadores[i].cantidad_lanzamientos;
			indiceGanador = i;
		}
	}
	if(indiceGanador != -1){
		printf("\nEl ganador es %s con %d lanzamientos\n", jugadores[indiceGanador].nombre, jugadores[indiceGanador].cantidad_lanzamientos);
	}else{
		printf("\nNo hubo ningun ganador; ningun jugador logro una suma de 12.\n");
	}
}

void registrarJugadores(struct Jugador jugadores[], int jmax){
	for(int i = 0; i < jmax ; i++){
		printf("Ingrese el nombre del jugador[%d]: ", i + 1);
		scanf("%s",jugadores[i].nombre);
		jugadores[i].cantidad_lanzamientos = 0;
		jugadores[i].exito = 0;
	}
}

void jugarConJugadores(struct Jugador *jugadores, int *numJugadores){
	for(int i = 0; i < *numJugadores; i++){
		int lanzamientos_realizados = jugarRondas(&jugadores[i]);
		printf("Jugador %s realizo %d lanzamientos. ", jugadores[i].nombre, lanzamientos_realizados);
		if(jugadores[i].exito){
			printf("\nObtuvo una suma de 12\n");
		}else{
			printf("\nNo logro una suma de 12 en 20 lanzamientos.\n");
		}
		printf("\n");
	}
}