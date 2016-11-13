#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

#define TAM 1024

typedef struct pedido
{
  char *pedido;
  int precio;
  char *usuario;
  struct pedido *next;
}PEDIDO;

void listen_buffet(int *);
void tostruct(char *,PEDIDO *);
void addlist(PEDIDO *, PEDIDO *);
void fail (int);
int asciitocent(char *, PEDIDO *,int);
int asciitodec(char *, PEDIDO *,int);
