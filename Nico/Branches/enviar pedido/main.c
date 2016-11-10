#include "header.h"
int main(void)
{
  PEDIDO *pedido=NULL, *aux, *last;
  int i;
  char buffer[TAM];
  printf("Carga de lista de usuarios\n");
  for(i=0;i<3;i++)
  {
    aux=(PEDIDO *)malloc(sizeof(PEDIDO));
    printf("producto:");
    fgets(buffer,TAM,stdin);
    aux->producto=(char *)malloc(strlen(buffer));
    printf("precio:");
    scanf("%d",&aux->precio);
    printf("usuario:");
    scanf("%s",buffer);
    aux->usuario=(char *)malloc(strlen(buffer));
    printf("hora de retiro:");
    scanf("%s",aux->hora);
    aux->next=NULL;
    if(pedido==NULL)
      pedido=aux;
    else
      last->next=aux;
    last=aux;
  }
  SendList(pedido,buffer);
  printf("%s\n",buffer);
  return 0;
}