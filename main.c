#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct
{
    int matricula;
    char nombre[30];
    char genero[30];
} stAlumno;

int cargarAlumnosArray (stAlumno A [], int dimension);
void mostrarAlumnos(stAlumno A[], int validos);
stAlumno cargarAlumno ();
int buscarMenor(stAlumno a[], int pos, int validos);
void ordenarAlumnos (stAlumno a[], int posmenor, int pos);
void ordenamientoSeleccionAlumnos (stAlumno a[], int validos);
int buscarAlumnoChar (stAlumno A[], int validos);
int main()
{
    int validos=0;
    stAlumno A[200];
    validos=cargarAlumnosArray(A, 200);
    mostrarAlumnos(A, validos);

    buscarAlumno(A, validos);
    ordenamientoSeleccionAlumnos(A, validos);
    int alumns = buscarAlumnoChar(A, validos);
    printf("La cantidad de alumnos que pertenecen al genero elegido es: %i \n", alumns);
    return 0;
}
stAlumno cargarAlumno ()
{
    stAlumno A;
    printf("\nDime el numero de matricula del Alumno\n");
    scanf("%i", &A.matricula);

    printf("\nDime el nombre del alumno\n");
    fflush(stdin);
    gets(A.nombre);

    printf("\nDime el genero de este\n");
    fflush(stdin);
    gets(A.genero);

    return A;
}
int cargarAlumnosArray (stAlumno A [], int dimension)
{
    char s='s';
    int i=0;
    for(i=0; i<dimension && (s=='s' || s=='S'); i++)
    {
        A[i]=cargarAlumno();
        printf("\nQuieres seguir cargando alumnos? s/n\n");
        fflush(stdin);
        scanf("%c", &s);
    }
    return i;
}
void mostrarAlumnos(stAlumno A[], int validos)
{
    for(int i=0; i<validos; i++)
    {
        printf("|%i|  |%s|   |%s|\n", A[i].matricula,  A[i].nombre, A[i].genero);
    }
}

void buscarAlumno(stAlumno A[], int validos)
{
    int dato = 0, i = 0;
    int flag = 0;
    printf("\nDime el numero de matricula del alumno a buscar\n");
    scanf("%i", &dato);

    while(i<validos && flag == 0)
    {
        if(dato == A[i].matricula)
        {
            printf("%i\n", A[i].matricula);
            puts(A[i].nombre);
            puts(A[i].genero);
            flag = 1;
        }
        i++;
    }
}
int buscarMenor(stAlumno a[], int pos, int validos)
{
    int posmenor=pos;
    stAlumno aux;
    aux = a[pos];
    for(int i=pos+1; i<validos; i++)
    {
        if(aux.matricula>a[i].matricula)
        {
            aux = a[i];
            posmenor=i;
        }
    }
    return posmenor;
}
void ordenarAlumnos (stAlumno a[], int posmenor, int pos)
{
    stAlumno aux = a[pos];
    a[pos]=a[posmenor];
    a[posmenor]=aux;
}
void ordenamientoSeleccionAlumnos (stAlumno a[], int validos)
{
    int i=0;
    int posMenor=0;

    for(i=0; i<validos-1; i++)
    {
        posMenor=buscarMenor(a, i, validos);
        ordenarAlumnos(a, posMenor, i);
    }
}

int buscarAlumnoChar(stAlumno A[], int validos)
{
    char dato[20];
    int i = 0;
    printf("\nDime el genero del alumno a buscar\n");
    fflush(stdin);
    scanf("%s", &dato);
    int alumns = 0;
    while(i<validos)
    {

        if(strcmpi(dato, A[i].genero) == 0)
        {
            printf("%i\n", A[i].matricula);
            puts(A[i].nombre);
            puts(A[i].genero);
            alumns++;
        }
        i++;
    }
    return alumns;
}
