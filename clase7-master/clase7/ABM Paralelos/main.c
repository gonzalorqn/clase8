#include <stdio.h>
#include <stdlib.h>
#define TAM 20

int buscarLibre(int[], int);
void mostrarAlumnos(int[], char[][20], int[], int[], float[], int);
float calcularPromedio(int, int);
int cargarAlumno(int[], char[][20], int[], int[], float[], int);
int modificarAlumno(int[], char[][20], int[], int[], float[], int);

int main()
{
    int legajo[TAM]= {1,2,3,4,5};
    char nombre[TAM][20]={"Juan", "Pedro", "Jose", "Maria", "Ana"};
    int nota1[TAM]={6,7,9,3,7};
    int nota2[TAM]={7,5,3,5,8};
    float promedio[TAM]={6.5,6,6,4,7.5};
    int opcion;
    int index;
    int i;
    do
    {
        printf("1. ALTAS\n2. MOSTRAR\n3. MODIFICAR\n4.BAJA\n5.ORDENAR (por nombre)\n9. SALIR\nElija una opcion: ");
        scanf("%d", &opcion);

        switch(opcion)
        {
        case 1:

            index=cargarAlumno(legajo,nombre,nota1,nota2,promedio,TAM);
            if(index == -1)
            {
                printf("No hay lugar\n");
            }
            else
            {
                printf("Alumno ingresado\n");
            }
            break;
        case 2:

        mostrarAlumnos(legajo,nombre,nota1,nota2,promedio,TAM);

        break;

        case 3:
            modificarAlumno(legajo,nombre,nota1,nota2,promedio,TAM);
            if(index == -1)
            {
                printf("Legajo no encontrado\n");
            }
            else
            {
                printf("Alumno modificado\n");
            }

        }

    }
    while(opcion!=9);




    return 0;
}

int buscarLibre(int legajos[], int tam)
{
    int index=-1;
    int i;

    for(i=0;i<tam;i++)
    {
        if(legajos[i]==0)
        {
            index=i;
            break;
        }
    }

    return index;
}

int cargarAlumno(int legajos[], char nombres[][20], int nota1[], int nota2[], float promedio[], int tam)
{
    int index;
    index = buscarLibre(legajos, tam);
            if(index!=-1)
            {
                printf("Ingrese legajo: ");
                scanf("%d", &legajos[index]);
                printf("Ingrese nombre: ");
                fflush(stdin);
                gets(nombres[index]);
                printf("Ingrese nota 1: ");
                scanf("%d", &nota1[index]);
                printf("Ingrese nota 2: ");
                scanf("%d", &nota2[index]);
                promedio[index]=calcularPromedio(nota1[index],nota2[index]);
            }
            return index;
}


float calcularPromedio(int nota1, int nota2)
{
    float promedio;
    promedio = (float)(nota1+nota2)/2;
    return promedio;
}

void mostrarAlumnos(int legajos[], char nombres[][20], int nota1[], int nota2[], float promedio[], int tam)
{
    int i;
    for(i=0; i<tam; i++)
            {
                if(legajos[i]!=0)
                {
                    printf("%d %s %d %d %.2f\n", legajos[i], nombres[i], nota1[i], nota2[i], promedio[i] );
                }

            }

}

int buscarInt(int enteros[], int tam, int cual)
{
    int indice = -1;
    int i;
    for(i=0; i<tam; i++)
    {
        if(enteros[i]==cual)
        {
            indice = i;
            break;
        }
    }
    return indice;
}
int modificarAlumno(int legajos[], char nombres[][20], int nota1[], int nota2[], float promedio[], int tam)
{
    int numeroLegajo;
    int index = -1;

    printf("\nIngrese legajo a modificar: ");
    scanf("%d", &numeroLegajo);

    index = buscarInt(legajos,tam,numeroLegajo);

    if(index!=-1)
    {
        printf("Ingrese legajo: ");
        scanf("%d", &legajos[index]);
        printf("Ingrese nombre: ");
        fflush(stdin);
        gets(nombres[index]);
        printf("Ingrese nota 1: ");
        scanf("%d", &nota1[index]);
        printf("Ingrese nota 2: ");
        scanf("%d", &nota2[index]);
        promedio[index]=calcularPromedio(nota1[index],nota2[index]);
    }

    return index;
}
