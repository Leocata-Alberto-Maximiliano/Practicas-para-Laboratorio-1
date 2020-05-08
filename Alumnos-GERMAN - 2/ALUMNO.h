#include <stdio.h>

#include <string.h>

#define LIBRE 0
#define OCUPADO 1

typedef struct
{
    int dia;
    int mes;
    int anio;
} eFecha;



typedef struct
{
    int legajo;//PK
    int nota1;
    int nota2;
    float promedio;
    char nombre[20];
    char email[20];
    eFecha fechaNacimiento;
    int idCurso;//FK
    int estado;
} eAlumno;

/// ABM ALUMNO
eAlumno crearUnAlumno (void);
int buscarLibre_Alumnos(eAlumno listado[], int tamanio);
void inicializarArray_Alumnos(eAlumno listado[], int tamanio);
void hardCodear_Alumnos(eAlumno listado[], int tamanio);
int cargar_Alumno(eAlumno listado[], int tamanio);
int eliminar_Alumno(eAlumno listado[], int tamanio, int estadoInicial, int estadoFinal);
int modificar_Alumno(eAlumno listado[], int tamanio, int estadoInicial);
void mostrar_Alumno(eAlumno miAlumno);
void mostrarTodos_Alumnos(eAlumno listado[], int tamanio);

/// FILTROS ALUMNO
void mostrarAlumnosPromocionados(eAlumno listado[], int tamanio, int aprobado);
float promediarNotasAlumno(int nota1, int nota2);
void ordenarAlumnosPorNombre(eAlumno listado[], int tamanio);
float buscarPromedioMaximo(eAlumno listado[], int tamanio);
void mostrarAlumnosConMaximoPromedio(eAlumno listado[], int tamanio);
void ordenarAlumnosPorPromedio_Nombre(eAlumno listado[], int tamanio);

eFecha getDate(void);
