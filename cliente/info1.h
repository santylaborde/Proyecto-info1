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

#define TAM	1024
#define PORT	12345
#define BACKLOG 10
#define IP "10.5.24.192"

typedef struct svar	//variables del server
{
  int sockfd, new_sockfd,numbytes;
  char buffer[TAM];
  struct sockaddr_in my_addr;
  struct sockaddr_in their_addr;
  socklen_t size;
}SVAR;

typedef struct cvar
{
  int sockfd,numbytes;
  char *op;
  char buffer[TAM],usr[20],pass[20];
  struct hostent *he;
  struct sockaddr_in their_addr;
}CLIENTE;

typedef struct menu
{
    //datos menu
    char Menu[TAM];      //para el menu general
    char MenuEst[TAM];   //para el menu estudiantil
    char Post[TAM];      //para los postres
    char MenuDia[TAM];   //menu del dia
    char Beb[TAM];       //Bebidas
    char Ensal[TAM];     //Ensaladas
    char Menues[TAM];    //Menues
    char aux[TAM];
}MENU;

void child_process(int);
void sigchld_handler(int);