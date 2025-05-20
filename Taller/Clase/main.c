/****************************************************
 * File: Arreglo de estructuras
 * Author: Joe O^2 *
 * Materia: Algoritmos y Estructura de Datos (551)
 * Date: Abr/28/2025
 * Comments:

 ***************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Declaración de la estructura */

struct Triangulo
{
    char nombre[100];
    int tipoTriangulo; // 1=equilátero, 2=isósceles, 3=escaleno, 4=inválido
    double l1, l2, l3;
};

/* Declaración de la función */
void clasificaTriangulo(struct Triangulo *a);
void imprimeTriangulo(struct Triangulo *a);
void imprimeTriangulos(struct Triangulo *a, int n);

void clasificaTriangulo(struct Triangulo *a)
{
    double lado1 = a->l1, lado2 = a->l2, lado3 = a->l3;

    // Verificación de triángulo válido
    if ((lado1 + lado2 > lado3) && (lado1 + lado3 > lado2) && (lado2 + lado3 > lado1))
    {
        // Clasificación por lados
        if (lado1 == lado2 && lado2 == lado3)
        {
            a->tipoTriangulo = 1; // Equilátero
        }
        else if (lado1 == lado2 || lado1 == lado3 || lado2 == lado3)
        {
            a->tipoTriangulo = 2; // Isósceles
        }
        else
        {
            a->tipoTriangulo = 3; // Escaleno
        }
    }
    else
    {
        a->tipoTriangulo = 4; // Inválido
    }
}
void imprimeTriangulo(struct Triangulo *a)
{
    printf("Lado 1: %.2f\n", a->l1);
    printf("Lado 2: %.2f\n", a->l2);
    printf("Lado 3: %.2f\n", a->l3);

    // Mostrar tipo
    switch (a->tipoTriangulo)
    {
    case 1:
        printf("Tipo de triángulo: Equilátero\n");
        break;
    case 2:
        printf("Tipo de triángulo: Isósceles\n");
        break;
    case 3:
        printf("Tipo de triángulo: Escaleno\n");
        break;
    case 4:
        printf("Tipo de triángulo: Inválido\n");
        break;
    }

    // Verificación de triángulo rectángulo (sin fabs)
    if ((a->l1 * a->l1 + a->l2 * a->l2 == a->l3 * a->l3) ||
        (a->l1 * a->l1 + a->l3 * a->l3 == a->l2 * a->l2) ||
        (a->l2 * a->l2 + a->l3 * a->l3 == a->l1 * a->l1))
    {
        printf("Además, es un triángulo rectángulo.\n");
    }
    else
    {
        printf("No es un triángulo rectángulo.\n");
    }
}

void imprimeTriangulos(struct Triangulo *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("Triángulo %d:\n", i + 1);
        imprimeTriangulo(&a[i]);
    }
}

int main(void)
{
    struct Triangulo a[10];
    int n = 0;
    char continuar = 's';
    printf("Clasificación de triángulos\n");
    printf("----------------------------\n\n");

    int opcion, subOpcion;

    do
    {
        printf("\n\nMenu");
        printf("\n\t1)- Capturar datos de los triángulos");
        printf("\n\t2)- Clasificar triángulos");
        printf("\n\t3)- Mostrar triángulos");
        printf("\n\t4)- Salir");
        printf("\nElige una opción del menú:\t");
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1:
            do
            {
                printf("\nCapturar datos de los triángulos");
                printf("\n\t1)- Triángulo 1");
                printf("\n\t2)- Triángulo 2");
                printf("\n\t3)- Triángulo 3");
                printf("\n\t4)- Regresar al menú principal");
                printf("\nElige una opción del submenú:\t");
                scanf("%d", &subOpcion);

                if (subOpcion >= 1 && subOpcion <= 3)
                {
                    printf("Introduce el nombre del triángulo %d: ", subOpcion);
                    scanf("%s", a[subOpcion - 1].nombre);
                    printf("Introduce los lados del triángulo %d (l1 l2 l3): ", subOpcion);
                    scanf("%lf %lf %lf", &a[subOpcion - 1].l1, &a[subOpcion - 1].l2, &a[subOpcion - 1].l3);
                    n = n < subOpcion ? subOpcion : n; // Asegurar que el número de triángulos capturados es correcto
                }
                else if (subOpcion == 4)
                {
                    printf("Regresando al menú principal...\n");
                }
                else
                {
                    printf("Opción no válida en el submenú.\n");
                }
                break;
            } while (subOpcion != 4);

            break;
        case 2:
            for (int i = 0; i < n; i++)
            {
                clasificaTriangulo(&a[i]);
            }
            printf("Triángulos clasificados.\n");
            break;

        case 3:
            imprimeTriangulos(a, n);
            break;

        case 4:
            printf("Saliendo del programa...\n");
            break;

        default:
            printf("Opción no válida. Intenta de nuevo.\n");
            break;
        }
    } while (opcion != 4);

    return 0;
}
