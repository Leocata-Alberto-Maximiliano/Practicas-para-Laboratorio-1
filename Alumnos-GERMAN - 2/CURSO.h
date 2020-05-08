#include <stdio.h>
#include <string.h>

typedef struct
{
    int idCurso;//PK
    char descripcion[50];
    int duracion;
    int estado;
} eCurso;

/// ABM CURSO
int buscarLibre_Cursos(eCurso listado[], int tamanio);
void inicializarArray_Cursos(eCurso listado[], int tamanio);
void hardCodear_Cursos(eCurso listado[], int tamanio);
int cargar_Curso(eCurso listado[], int tamanio);
int eliminar_Curso(eCurso listado[], int tamanio, int estadoInicial, int estadoFinal);
int modificar_Curso(eCurso listado[], int tamanio, int estadoInicial);
void mostrar_Curso(eCurso curso);
void mostrarTodos_Cursos(eCurso[], int);
