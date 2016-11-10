#include "header.h"
void SendList (PEDIDO *pedido, char *buffer)
{
	int i;
	buffer=(char *)malloc(sizeof (pedido));
	i=load_producto(pedido,buffer);
	i=load_precio(pedido,buffer,i);
	i=load_user(pedido,buffer,i);	// Cargo usuario
	i=load_hour(pedido,buffer,i);	// Cargo hora
	buffer[i]='\0';
}
int load_producto(PEDIDO *pedido, char *buffer)
{
    PEDIDO *aux;
    int i,j=0;
    while(pedido!=NULL)
    {
	for(i=0;pedido->producto[i]!='\0';i++,j++)
	  buffer[j]=pedido->producto[i];
	buffer[j]=',';
	aux=pedido->next;
	pedido=aux;
    }
    buffer[j]='\0';
    printf("%s",buffer);
    return j;
}
int load_precio(PEDIDO *pedido, char *buffer,int j)
{
    PEDIDO *aux;
    int i=0;
    while(pedido!=NULL)
    {
	i+=pedido->precio;
	buffer[j]=(i+'0');
	aux=pedido->next;
	pedido=aux;
	j++;
    }
    buffer[j]='.';
    return j;
}
int load_user(PEDIDO *pedido, char *buffer,int j)
{
    int i,k;
    for(i=j,k=0;pedido->usuario[k]!='\0';i++,k++)
	  buffer[i]=pedido->usuario[k];
    buffer[i]='.';
    return i;
}
int load_hour(PEDIDO *pedido, char *buffer,int j)
{
    int i,k;
    for(i=j,k=0;pedido->hora[k]!='\0';i++,k++)
	  buffer[i]=pedido->hora[k];
    return i;
}