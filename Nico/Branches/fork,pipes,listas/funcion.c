#include "header.h"
void listen_buffet(int *fd)
{
  char buffer[TAM];
  PEDIDO *p=NULL;
  close(fd[0]);
  printf("pedido:");
  scanf("%s",buffer);
  tostruct(buffer,p);
  
  exit(0);
}
void tostruct(char *buff,PEDIDO *h)
{
  
}