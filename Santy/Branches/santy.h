#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/wait.h>
#include <signal.h>
#include <netdb.h>

#define TAM 50
#define PATH "Comida.txt"

/* Elementos de cada lista */
typedef struct lista2
{
  char mercaderia[TAM];
  char precio[TAM];
  char id[TAM];
  
  struct lista2 *next;
  
}lista2;

/*
typedef struct lista2_Manager
{
  lista2 *inicio;
  lista2 *fin;
  int TAM;
} lista2_Manager;
*/

/*Lista de Secciones*/
typedef struct lista1
{
    char    nombre[TAM]; 
    int     cantidad;
    lista2  *producto;
    lista2  *inicio;
    
    struct lista1 *next;
    
}lista1;

/*
typedef struct lista1_Manager
{
  lista1 *inicio;
  lista1 *fin;
  int TAM;
} lista1_Manager;
*/

int nueva_seccion(lista1 **);
void visualizar(lista1 *);
int leer_archivo(FILE *, lista1 **);
void crear_backup(lista1 *, char *);
