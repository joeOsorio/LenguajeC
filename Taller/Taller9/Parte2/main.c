/* Taller: Clasificación de triángulos */
/* Nombre: Joshua Osorio */
/* Materia: LENGUAJE C 531 */
/* Fecha: Febrero/13/2025 */


#include <stdio.h>

struct Triangulo {
    char nombre[100];
    int tipoTriangulo; // 1=equilátero, 2=isósceles, 3=escaleno, 4=inválido
    double l1, l2, l3;
};

int main(void) {
    struct Triangulo a;

    printf("Clasificación de triángulos\n");
    printf("----------------------------\n\n");

    printf("Escribe las 3 longitudes del triángulo separadas por un enter:\n");
    scanf("%lf %lf %lf", &a.l1, &a.l2, &a.l3);

    double lado1 = a.l1, lado2 = a.l2, lado3 = a.l3;

    // Verificación de triángulo válido
    if ((lado1 + lado2 > lado3) && (lado1 + lado3 > lado2) && (lado2 + lado3 > lado1)) {
        // Clasificación por lados
        if (lado1 == lado2 && lado2 == lado3) {
            a.tipoTriangulo = 1;
        } else if (lado1 == lado2 || lado1 == lado3 || lado2 == lado3) {
            a.tipoTriangulo = 2;
        } else {
            a.tipoTriangulo = 3;
        }

        // Mostrar tipo
        printf("\nTipo de triángulo: ");
        switch (a.tipoTriangulo) {
            case 1:
                printf("Equilátero\n");
                break;
            case 2:
                printf("Isósceles\n");
                break;
            case 3:
                printf("Escaleno\n");
                break;
        }

        // Verificación de triángulo rectángulo (sin fabs)
        if ((lado1*lado1 + lado2*lado2 == lado3*lado3) ||
            (lado1*lado1 + lado3*lado3 == lado2*lado2) ||
            (lado2*lado2 + lado3*lado3 == lado1*lado1)) {
            printf("Además, es un triángulo rectángulo.\n");
        } else {
            printf("No es un triángulo rectángulo.\n");
        }

    } else {
        printf("No es un triángulo válido.\n");
    }

    printf("\nLados: L1=%.2f, L2=%.2f, L3=%.2f\n", lado1, lado2, lado3);
    printf("Gracias por usar mi programa.\n");

    return 0;
}
