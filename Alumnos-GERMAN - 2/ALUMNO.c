#include "Alumno.h"
#include "UTN.h"
#define LEGAJO_MIN 1
#define LEGAJO_MAX 1000

eAlumno crearUnAlumno (void)
{
    eAlumno alumno;

    alumno.legajo = getInt("\nINGRESE EL LEGAJO: ", "ERROR, REINGRESE EL LEGAJO: ", 1, 1000);

    alumno.nota1 = getInt("\nINGRESE PRIMER NOTA: ", "ERROR, REINGRESE PRIMER NOTA: ", 1, 10);

    alumno.nota2 = getInt("\nINGRESE SEGUNDA NOTA: ", "ERROR, REINGRESE SEGUNDA NOTA: ", 1, 10);

    printf ("\n\nINGRESE NOMBRE: ");
    fflush(stdin);
    fgets(alumno.nombre,50,stdin);
    alumno.nombre[strlen(alumno.nombre)-1]='\0';

    printf ("\n\nINGRESE EMAIL: ");
    fflush(stdin);
    fgets (alumno.email,50,stdin);
    alumno.email[strlen(alumno.email)-1]='\0';

    alumno.fechaNacimiento = getDate();

    alumno.promedio = promediarNotasAlumno(alumno.nota1,alumno.nota2);

    alumno.estado = OCUPADO;

    return alumno;

}

int buscarLibre_Alumnos(eAlumno listado[], int tam)
{
    int i;
    int index = -1;

    for(i=0; i<tam; i++)
    {
        if(listado[i].estado==LIBRE)
        {
            index =  i;
            break;
        }
    }
    return index;

}

void inicializarArray_Alumnos(eAlumno listado[], int tam)
{
    int i;

    for(i=0; i<tam; i++)
    {
        listado[i].estado = LIBRE;
    }
}

void hardCodear_Alumnos(eAlumno listado[], int tam)
{
    int legajos[6]= {1,2,3,4,5,6};
    int nota1[6]= {10,4,9,8,7,8};
    int nota2[6]= {3,2,7,8,9,7};
    char nombre[6][20] = {"Juan","Maria","Ana","Pedro","Luisa","Octavio"};
    char mail[6][20] = {"Juan@lala.com","Maria@lala.com","Ana@lala.com","Pedro@lala.com","Luisa@lala.com","Octupus@Slack.com"};
    eFecha fechas[6] = {{10,5,1999},{7,3,1990},{5,7,1997},{18,2,2000},{4,8,1999}};
    int curso[6] = {101,100,101,102,100,100};
    int i;

    for(i=0; i<6; i++)
    {
        listado[i].legajo = legajos[i];
        listado[i].nota1 = nota1[i];
        listado[i].nota2 = nota2[i];
        listado[i].promedio = (float) (listado[i].nota1 + listado[i].nota2)/2;
        listado[i].fechaNacimiento = fechas[i];
        strcpy(listado[i].nombre, nombre[i]);
        strcpy(listado[i].email, mail[i]);
        listado[i].idCurso = curso[i];
        listado[i].estado = OCUPADO;
    }

    listado[3].estado = LIBRE;
    listado[5].estado = LIBRE;

}

int cargar_Alumno(eAlumno listado[], int tamanio)
{
    int retorno = 0;
    printf("\nCARGA DE DATOS:\n\n");

    int index;

    index = buscarLibre_Alumnos(listado, tamanio);

    if(index!=-1)
    {
        listado[index] = crearUnAlumno();//
        //ASOCIAR UN ALUMNO A UN CURSO
        retorno = 1;
    }

return retorno;
}

int eliminar_Alumno(eAlumno listado[], int tamanio, int estadoInicial, int estadoFinal)
{
    int retorno = 0;
    int legajoIngresado;
    int i;

    legajoIngresado = getInt("\nINGRESE EL LEGAJO: ", "ERROR, REINGRESE EL LEGAJO: ", LEGAJO_MIN, LEGAJO_MAX);

    for(i=0; i<tamanio; i++)
    {
        if(listado[i].estado == estadoInicial && listado[i].legajo == legajoIngresado)
        {
            retorno = 1;
            listado[i].estado = estadoFinal;
            break;
        }
    }

return retorno;
}

int modificar_Alumno(eAlumno listado[], int tamanio, int estadoInicial)
{
    int retorno = 0;
    int legajoIngresado;
    int i;

    legajoIngresado = getInt("\nINGRESE EL LEGAJO: ", "ERROR, REINGRESE EL LEGAJO: ", LEGAJO_MIN, LEGAJO_MAX);

    for(i=0; i<tamanio; i++)
    {
        if(listado[i].estado == estadoInicial && listado[i].legajo == legajoIngresado)
        {
            retorno = 1;

            printf("Reingrese EMAIL:");

            fflush(stdin);

            fgets(listado[i].email,20,stdin);

            listado[i].email[strlen(listado[i].email)-1]='\0';

            break;
        }
    }

return retorno;
}

void mostrar_Alumno(eAlumno alumno)
{
    printf ("\nLEGAJO: %d\tNOTA 1: %d\tNOTA 2: %d\tPROMEDIO: %.2f\tNOMBRE: %s\tEMAIL: %s\tFECHA DE NACIMIENTO: [%d/%d/%d]\tCURSO: %d\n",
            alumno.legajo,
            alumno.nota1,
            alumno.nota2,
            alumno.promedio,
            alumno.nombre,
            alumno.email,
            alumno.fechaNacimiento.dia,
            alumno.fechaNacimiento.mes,
            alumno.fechaNacimiento.anio,
            alumno.idCurso);
}

void mostrarTodos_Alumnos(eAlumno listado[], int tam)
{
    printf("\nLISTADO:\n\n");

    int i;

    for(i=0; i<tam; i++)
    {
        if(listado[i].estado==OCUPADO)
        {
            mostrar_Alumno(listado[i]);
        }

    }

}

void mostrarAlumnosPromocionados(eAlumno listado[], int tam, int aprobado)
{
    int i;

    for(i=0; i<tam; i++)
    {
        if(listado[i].nota1 >= aprobado && listado[i].nota2 >= aprobado)
        {
            mostrar_Alumno(listado[i]);
        }

    }
}

float promediarNotasAlumno(int nota1, int nota2)
{
    return (float) (nota1+nota2)/2;
}

void ordenarAlumnosPorNombre(eAlumno listado[], int tam)
{


    int i;
    int j;
    eAlumno auxAlumno;

    for(i=0; i<tam-1; i++)
    {
        for(j=i+1; j<tam; j++)
        {
            if(strcmp(listado[i].nombre,listado[j].nombre)>0)
            {
                auxAlumno = listado[i];
                listado[i] = listado[j];
                listado[j] = auxAlumno;
            }
        }

    }

}

float buscarPromedioMaximo(eAlumno listado[], int tam)
{
    int i;
    float maxPromedio;
    for(i=0; i<tam; i++)
    {
        if(listado[i].promedio>maxPromedio || i==0)
        {
            maxPromedio = listado[i].promedio;
        }
    }

    return maxPromedio;
}
void mostrarAlumnosConMaximoPromedio(eAlumno listado[], int tam)
{
    int i;
    float maximo;
    maximo = buscarPromedioMaximo(listado,tam);

    //mostrarAlumnosPromedioMaximo(listado,tam, maximo);

    for(i=0; i<tam; i++)
    {
        if(listado[i].promedio == maximo)
        {
            mostrar_Alumno(listado[i]);
        }
    }
}

void ordenarAlumnosPorPromedio_Nombre(eAlumno listado[], int tam)
{
    int i;
    int j;
    eAlumno auxAlumno;

    for(i=0; i<tam-1; i++)
    {
        for(j=i+1; j<tam; j++)
        {
            if(listado[i].promedio>listado[j].promedio)
            {
                auxAlumno = listado[i];
                listado[i] = listado[j];
                listado[j] = auxAlumno;
            }
            else
            {
                if(listado[i].promedio==listado[j].promedio)
                {
                    if(strcmp(listado[i].nombre,listado[j].nombre)>0)
                    {
                        auxAlumno = listado[i];
                        listado[i] = listado[j];
                        listado[j] = auxAlumno;
                    }
                }
            }
        }

    }
}
eFecha getDate(void)
{
    eFecha fecha;

    fecha.dia = getInt("\nINGRESE DIA: ", "\nERROR, REINGRESE DIA: ", 1, 31);
    fecha.mes = getInt("\nINGRESE MES: ", "\nERROR, REINGRESE MES: ", 1, 12);
    fecha.anio = getInt("\nINGRESE AÑO: ", "\nERROR, REINGRESE AÑO: ", 1980, 2020);

    return fecha;
}
