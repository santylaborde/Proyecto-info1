#include "header.h"
int main(void)
{
  char c;
  int pid1, pid2;
  
  mkfifo(FIFO,mode);
  
  pid1=fork();
  if(!pid1)
  { 
    //proceso hijo 1
    listen_buffet();
  }
  //proceso padre
  pid2=fork();
  if(!pid2)
  {
    //proceso hijo 2
    mostrar_pedido();
  }
  //proceso padre
  while(1)
  {
    /*cuando se ingrese f se acaba el programa*/
    if(scanf("%c",&c))
    {
      if(c=='f')
      {
	kill(pid1,SIGKILL);
	kill(pid2,SIGKILL);
	exit(0);
      }
    }
  }
  exit(EXIT_SUCCESS);
}