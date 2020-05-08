#include "Alumno.h"
#include "Curso.h"

typedef struct
{
    int idCurso;
    int cantidadAlumnos;
} Alumno_Curso;

void menu(void);
void mostrarAlumnosConSuCurso(eAlumno[], int, eCurso[], int);
void mostrarCursosConSusAlumnos(eAlumno[], int, eCurso[], int);
void mostrarCursoConMasAlumnos(eAlumno[], int, eCurso[], int);
