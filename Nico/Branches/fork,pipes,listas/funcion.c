#include "header.h"
void listen_buffet(int *fd)
{
  char buffer[TAM], *re;
  PEDIDO *aux='\0';
  close(fd[0]);
  printf("pedido:");
  scanf("%s",buffer);
  tostruct(buffer,aux);	//agarra el buffer y lo pasa a una struct del tipo PEDIDO
  //addlist(aux,p);	//lo agrega a una lista
  re=(char *)aux;
  write(fd[1],re,strlen(re));
  exit(0);
}
void tostruct(char *buff,PEDIDO *h)
{
  int i,j,k=0,aux1=0;
  char aux[TAM];
  h=(PEDIDO *)malloc(sizeof(PEDIDO));
  for(i=k,j=0;buff[i]!='.';i++,j++,k=i)
    aux[j]=buff[i];
  aux[j]='\0';
  h->pedido=(char *)malloc(sizeof(aux));
  strcpy(h->pedido,aux);
  for(i=k;buff[i]!='.';i++,k=i)
    aux1+=(buff[i]-48);
  h->precio=aux1;
  for(i=k;buff[i]!='.';i++,k=i)
    aux[j]=buff[i];
  aux[j]='\0';
  h->usuario=(char *)malloc(sizeof(aux));
  strcpy(h->usuario,aux);
  return;
}
void addlist(PEDIDO *a,PEDIDO *b)
{
  PEDIDO *last='\0';
  a->next='\0';
  if(b=='\0')
    b=a;
  else
    last->next=a;
  last=a;
  return;
}
void fail (int fd)
{
  char buffer[1024];
  if(fd==-1)
  {
    fd=open("error.log",O_CREAT||O_WRONLY);
    strcpy(buffer,strerror(errno));
    write(fd,buffer,strlen(buffer));
    close(fd);
    exit(1);
  }
}