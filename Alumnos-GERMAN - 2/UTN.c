#include <stdio.h>
#include <stdlib.h>
#include"UTN.h"
#include <string.h>
int getString(char* input,char message[],char errorMessage[], int lowLimit, int hiLimit)
{
    int succesfully = -1;

    char auxChain[hiLimit];

    printf("%s", message);

    fflush(stdin);

    scanf("%[^\n]", auxChain);

    strcpy(*input, auxChain);

    while(strlen(*input) < lowLimit || strlen(*input) > hiLimit)
    {

        printf("%s", errorMessage);

        fflush(stdin);

        scanf("%[^\n]", auxChain);

        strcpy(*input, auxChain);

        succesfully = 0;
    }

    return succesfully;

}

char getChar(char message[],char errorMessage[], char min, char max)
{
    char value;

    printf("%s", message);
    fflush(stdin);
    scanf("%c", &value);

    while(value < min || value > max )
    {
        printf("%s", errorMessage);
        fflush(stdin);
        scanf("%c", &value);
    }

    return value;
}

int getInt(char message[],char errorMessage[], int min, int max)
{
    char chain[4096];
    int value;
    int retorno = -1;

    printf("%s", message);
    fflush(stdin);
    scanf("%[^\n]", chain);

    if(isNumber(chain))
    {
        value = atoi(chain);
    }

    if(value >= min && value <= max)
    {
        retorno = value;
    }

    while(value <  min || value > max || isNumber(chain) == 0)
    {
        printf("%s", errorMessage);
        fflush(stdin);
        scanf("%[^\n]", chain);

        if(isNumber(chain))
        {
            value = atoi(chain);
        }

        if(value >= min && value <= max)
        {
            retorno = value;
        }
    }

    return value;
}


float getFloat(char message[],char errorMessage[], float min, float max)
{
    float value;

    printf("%s", message);
    scanf("%f", &value);

    while(value <  min || value > max )
    {
        printf("%s", errorMessage);
        scanf("%f", &value);
    }

    return value;
}


int isNumber(char chain[])
{
    int i;
    int ret = 1;

    for(i=0; chain[i] != '\0'; i++)
    {
        if(chain[i] < '0' || chain[i] > '9')
        {
            ret = 0;
            break;
        }
    }

    return ret;
}
