#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TAM 1024

typedef struct pedido
{
	char *producto;
	int precio;
	char *usuario;
	char hora[10];
	struct pedido *next;
}PEDIDO;

void SendList(PEDIDO *, char *);
int load_producto(PEDIDO *, char *);
int load_precio(PEDIDO *, char *,int);
int load_user(PEDIDO *, char *,int);
int load_hour(PEDIDO *, char *,int);