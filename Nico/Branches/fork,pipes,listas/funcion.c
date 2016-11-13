#include "header.h"
void listen_buffet(int *fd)
{
  char buffer[TAM];
  PEDIDO *aux=NULL;
  close(fd[0]);
  printf("pedido:");
  scanf("%s",buffer);
  tostruct(buffer,aux);	//agarra el buffer y lo pasa a una struct del tipo PEDIDO
  write(fd[1],(char *)aux,sizeof(char *));
  printf("hola\n");
  exit(0);
}
void tostruct(char *buff,PEDIDO *h)
{
  int i,j,k=0;
  char aux[TAM];
  h=(PEDIDO *)malloc(sizeof(PEDIDO));
  /*separo el producto del pedido*/
  for(i=k,j=0;buff[i]!='.';i++,j++,k=i)
    aux[j]=buff[i];
  aux[j]='\0';
  h->pedido=(char *)malloc(sizeof(aux));
  strcpy(h->pedido,aux);
  k++;
  /*separo el precio del pedido*/
  for(j=k;buff[j]!='.';j++);
  j-=k;
  if(j==3)
    k=asciitocent(buff,h,k);
  if(j==2)
    k=asciitodec(buff,h,k);
  k++;
  /*separo el usuario que hizo el pedido*/
  for(i=k,j=0;buff[i]!='.';i++,j++)
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
int asciitocent(char *buff, PEDIDO *h,int i)
{
  int aux, k, j, r;
  for(k=i,j=0;buff[k]!='.';k++,j++)
  {
    aux=(buff[k]-'0');
    if(0==j)
      r=aux*100;
    if(1==j)
      r+=aux*10;
    if(2==j)
      r+=aux;
  }
  h->precio=r;
  return k;
}
int asciitodec(char *buff, PEDIDO *h,int i)
{
  int aux, k, j, r;
  for(k=i,j=0;buff[k]!='.';k++,j++)
  {
    aux=(buff[k]-'0');
    if(0==j)
      r=aux*10;
    else
      r+=aux;
  }
  h->precio=r;
  return k;
}