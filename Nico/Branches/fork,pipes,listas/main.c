#include "header.h"
int main(void)
{
  int fd[2];
  FILE *fp;
  char buffer[TAM];
  if(pipe(fd)==-1)
  {
    fp=fopen("errorpipe.log","w+");
    fprintf(fp,stderr);
    fclose(fp);
  }
  if(!fork())
  { //proceso hijo
    listen_buffet(fd);
  }
  //proceso padre
  close(fd[1);
  if(read(fd[0],buffer,TAM)!=-1)
  {
    
  }
}