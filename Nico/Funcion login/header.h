#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 40

typedef struct Alumno
{
  char nombre[TAM];
  char clave[TAM];
  struct Alumno *next;
}ALUMNO;

int login(char *,char *,ALUMNO *);
