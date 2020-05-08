#include "Alumno-Curso.h"

void menu()
{
    printf("\n0.SALIR\n");
    printf("1.Cargar un ALUMNO\n");
    printf("2.Eliminar un ALUMNO\n");
    printf("3.Modificar un ALUMNO\n");
    printf("4.Listar ALUMNOS\n");
    printf("5.Ordenar ALUMNOS\n");
    printf("6.Mostrar CURSOS\n");
    printf("7.Mostrar ALUMNOS CON SU CURSO\n");
    printf("8.Mostrar CURSOS CON SUS ALUMNOS\n");

}

void mostrarAlumnosConSuCurso(eAlumno listaDeAlumnos[], int sizeAlumnos, eCurso listaDeCursos[], int sizeCursos)
{
    int i; /// ALUMNOS
    int j;/// CURSOS
    //Tener en cuenta que hay alumnos que pueden estar dados de baja
    //Tener en cuenta que hay cursos que pueden estar dados de baja
    for(i=0; i<sizeAlumnos; i++)
    {
        for(j=0; j<sizeCursos; j++)
        {
            if(listaDeAlumnos[i].idCurso /*FK*/ == listaDeCursos[j].idCurso /*PK*/)
            {
                printf("%4d %15s %15s %4d\n", listaDeAlumnos[i].legajo, listaDeAlumnos[i].nombre, listaDeCursos[j].descripcion, listaDeCursos[j].duracion);
                break;
            }
        }
    }


}

void mostrarCursosConSusAlumnos(eAlumno listaDeAlumnos[], int sizeAlumnos, eCurso listaDeCursos[], int sizeCursos)
{
    int i;//Cursos
    int j;//Alumnos

    for(i=0; i<sizeCursos; i++)
    {
        printf("CURSO: %s\n", listaDeCursos[i].descripcion);
        for(j=0; j<sizeAlumnos; j++)
        {
            //Preguntar si el alumno esta disponible
            if(listaDeAlumnos[j].idCurso /*FK*/ == listaDeCursos[i].idCurso /*PK*/)
            {
                mostrar_Alumno(listaDeAlumnos[j]);
            }

        }
    }

}

void mostrarCursoConMasAlumnos(eAlumno listaDeAlumnos[], int sizeAlumnos, eCurso listaDeCursos[], int sizeCursos)
{
    Alumno_Curso auxAlumnoCurso[sizeCursos];
    int i;
    int j;
    int maximo;

    //Inicializar el array alumno-curso

    for(i=0; i<sizeCursos; i++)
    {
        auxAlumnoCurso[i].idCurso = listaDeCursos[i].idCurso;
        auxAlumnoCurso[i].cantidadAlumnos = 0;
    }

    /********************************************/

    for(i=0; i<sizeCursos; i++)
    {
        for(j=0; j<sizeAlumnos; j++)
        {
            if(listaDeAlumnos[j].estado==OCUPADO && auxAlumnoCurso[i].idCurso == listaDeAlumnos[j].idCurso)
            {
                auxAlumnoCurso[i].cantidadAlumnos++;
            }
        }
    }


    /********************************************/

    for(i=0; i<sizeCursos; i++)
    {
        if(i==0 || auxAlumnoCurso[i].cantidadAlumnos>maximo)
        {
            maximo = auxAlumnoCurso[i].cantidadAlumnos;
        }
    }

    /********************************************/
    printf("\nMAXIMO: %d\n", maximo);
    for(i=0; i<sizeCursos; i++)
    {
        if(auxAlumnoCurso[i].cantidadAlumnos == maximo)
        {
            for(j=0; j<sizeCursos; j++)
            {
                if(auxAlumnoCurso[i].idCurso == listaDeCursos[j].idCurso)
                {
                    printf("%s\n", listaDeCursos[j].descripcion);
                }
            }
        }
    }


    /*for(i=0; i<sizeCursos; i++)
    {
        printf("%d - %d\n", auxAlumnoCurso[i].idCurso,  auxAlumnoCurso[i].cantidadAlumnos);
    }

    */

}
