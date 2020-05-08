#include "MENU.h"

#define TAM 6
#define OCUPADO 1
#define LIBRE -1
#define SUSPENDIDO 0

void opcionesDeMenu()
{
    eAlumno listaAlumnos[TAM];
    eCurso listaCursos[3] = {{100,"Java",7},{101,"Inkscape", 10},{102,"Office", 9}};
    int opcion;
    int i;

    inicializarArray_Alumnos(listaAlumnos,TAM);
    hardCodear_Alumnos(listaAlumnos,TAM);
    do
    {
        menu();
        opcion = getInt("\nELIJA UNA OPCION ", "ERROR, REINGRESE UNA OPCION ", 0, 9);

        switch(opcion)
        {
        case 1:

            switch(cargar_Alumno(listaAlumnos, TAM))
            {
            case 0:
                printf("\n***** EL ALUMNO NO SE HA PODIDO INGRESAR *****\n\n");
                break;
            case 1:
                printf("\n***** EL ALUMNO HA SIDO INGRESADO *****\n\n");
                break;
            }
            break;

        case 2:

            mostrarTodos_Alumnos(listaAlumnos, TAM);

            switch(eliminar_Alumno(listaAlumnos,TAM, OCUPADO, SUSPENDIDO))
            {
            case 0:
                printf("\n***** EL ALUMNO NO EXISTE *****\n\n");
                break;
            case 1:
                printf("\n***** EL ALUMNO HA SIDO ELIMINADO *****\n\n");
                break;
            }
            break;

        case 3:

            mostrarTodos_Alumnos(listaAlumnos, TAM);

            switch(modificar_Alumno(listaAlumnos,TAM, OCUPADO))
            {
            case 0:
                printf("\n***** EL ALUMNO NO EXISTE *****\n\n");
                break;
            case 1:
                printf("\n***** EL ALUMNO HA SIDO MODIFICADO *****\n\n");
                break;
            }

            break;

        case 4:
            mostrarTodos_Alumnos(listaAlumnos, TAM);
            break;
        case 5:
            printf("LISTADO ORDENADO:\n");
            ordenarAlumnosPorNombre(listaAlumnos,TAM);
            break;
        case 6:
            mostrarTodos_Cursos(listaCursos, 3);
            break;
        case 7:
            mostrarAlumnosConSuCurso(listaAlumnos, TAM, listaCursos, 3);
            break;
        case 8:
            mostrarCursosConSusAlumnos(listaAlumnos, TAM, listaCursos, 3);
            break;
        case 9:
            mostrarCursoConMasAlumnos(listaAlumnos, TAM, listaCursos, 3);
            break;

        }

    }
    while(opcion!=0);


    /// printf("LISTADO DE PROMOCIONADOS:\n");
    /// mostrarAlumnosPromocionados(listaAlumnos, T, 6);

    /// mostrarTodos_Alumnos(listaAlumnos, T);
    /// printf("LISTADO DE ALUMNOS CON PROMEDIO MAXIMO:\n");
    /// mostrarAlumnosConMaximoPromedio(listaAlumnos, T);
    /// printf("LISTADO ORDENADO POR PROMEDIO:\n");
    /// ordenarAlumnosPorPromedio_Nombre(listaAlumnos,T);
    /// mostrarTodos_Alumnos(listaAlumnos, T);*/

    return 0;
}
