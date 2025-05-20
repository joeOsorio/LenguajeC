#include<stdio.h>
#include<stdlib.h>
#include<time.h>


void CrearChar(char **arr, int n){
	*arr = (char*)malloc(n * sizeof(char));
}

void LiberarChar(char **arr)
{
	free(*arr);
	*arr = NULL;
}

void LlenarChar(char *arr, int n){
	for(int i = 0; i < n; i++){
		arr[i] = 'A' + rand() % 26;
	}

}

void ImprimirChar(char *arr, int n){
	printf("\nArreglo de caracteres: ");
	for(int i = 0; i < n; i++){
		printf("%c ", arr[i]);
	}
	printf("\n");
}

void CrearDoble(double **arr, int n){
	*arr = (double*)malloc(n * sizeof(double));
}

void LiberarDouble(double **arr){
	free(*arr);
	*arr = NULL;

}

void LlenarDouble(double * arr, int n){
	for(int i = 0; i < n; i++){
		arr[i] = (rand() % 10000) / 100.0;
	}
}


void ImprimirDouble(double *arr, int n){
	printf("\nArreglo de numeros double: ");
	for(int i = 0; i < n; i++){
		printf("%.2f ", arr[i]);
	}
	printf("\n");
}

void CrearMatriz(int ***matriz, int filas, int columnas){
	*matriz = (int **)malloc(filas * sizeof(int *));
	for(int i = 0; i < filas; i++){
		(*matriz)[i] = (int *)malloc(columnas * sizeof(int));
	}
}

void LiberarMatriz(int *** matriz, int filas){
	for(int i = 0; i < filas; i++){
		free((*matriz)[i]);
	}
	free(*matriz);
	*matriz = NULL;
}

void LlenarMatriz(int **matriz, int filas, int columnas){
	for(int i = 0; i < filas; i++){
		for(int j = 0; j < columnas; j++){
			matriz[i][j] = rand() % 100;
		}
	}
}

void ImprimirMatriz(int **matriz, int filas, int columnas){
	printf("\nMatriz de enteros:\n");
	for(int i = 0; i < filas ; i++){
		for(int j = 0; j < columnas; j++){
			printf("%3d ", matriz[i][j]);
		}
	printf("\n");
	}
}


int main(){
	srand(time(NULL));
	int n = 10, filas = 4, columnas = 5, opcion;
	char *arrChar;
	double *arrDouble;
	int **matriz;
	do{
		printf("\nMenu");
		printf("\n1.Arreglo de caracteres");
		printf("\n2.Arreglo de doubles");
		printf("\n3.Matriz de enteros");
		printf("\n4.Salir");
		printf("Seleccione una opcion: ");
		scanf("%d", &opcion);
		switch(opcion){
			case 1:
				CrearChar(&arrChar, n);
				LlenarChar(arrChar, n);
				ImprimirChar(arrChar, n);
				LiberarChar(&arrChar);
			break;
			case 2:
				CrearDoble(&arrDouble, n);
				LlenarDouble(arrDouble, n);
				ImprimirDouble(arrDouble,n);
				LiberarDouble(&arrDouble);
			break;
			case 3:
				CrearMatriz(&matriz, filas, columnas);
				LlenarMatriz(matriz, filas, columnas);
				ImprimirMatriz(matriz, filas, columnas);
				LiberarMatriz(&matriz, filas);
			break;
			case 4:
				printf("Hasta la vista bebe... =) ");
			break;
			default:
				printf("Ocion incorrecta\n");

		}
	}while (opcion != 4);
	return 0;
}





