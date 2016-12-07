#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>
#include <signal.h>

#define TAM 1024
/*define el tipo de estructura con el que se va a trabajar en la funcion add_nodofinal*/
#define TYPESTRUCT	PEDIDO
#define mode	0666
#define FIFO	"mififo"
#define FIFO2	"mififo2"

typedef struct pedido
{
  char *pedido;
  int precio;
  char *usuario;
  char hora[10]; // el formato de la hora es hh:mm
  struct pedido *next;
}PEDIDO;

void listen_buffet(void);
void mostrar_pedido(void);
void tostruct(char *,PEDIDO **);
void add_nodofinal(TYPESTRUCT **, TYPESTRUCT *, TYPESTRUCT **);
void fail (int);
void precio(char *, PEDIDO **);
void pedido(char *, PEDIDO **);
void usuario(char *, PEDIDO **);
void hora(char *, PEDIDO **);
void handler(int);
void ver_lista(PEDIDO *);