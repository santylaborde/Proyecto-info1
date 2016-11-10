#include "header.h"
int main(void)
{
  int fd[2];//,fp;
  //FILE *fp;
  PEDIDO *p='\0', *aux;
  char buffer[TAM];
  
  fail(pipe(fd));
  
  if(!fork())
  { 
    //proceso hijo
    listen_buffet(fd);
  }
  //proceso padre
  close(fd[1]);
  while(1)
  {
    if(read(fd[0],buffer,TAM)!=-1)
    {
      buffer[strlen(buffer)]='\0';
      aux=(PEDIDO *)buffer;
      addlist(aux,p);
      printf("%s\n%d\n%s\n",aux->pedido,aux->precio,aux->usuario);
    }
  }
}