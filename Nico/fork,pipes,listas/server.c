#include "header.h"
int main(void)
{
  char buff[TAM], buff2[TAM], buff3[TAM];
  int w_fifo;
  
  mkfifo(FIFO2,mode);
  w_fifo = open(FIFO2,O_WRONLY);
  while(1)
  {
    printf("buff:");
    fgets(buff,TAM,stdin);
    printf("buff2:");
    fgets(buff2,TAM,stdin);
    printf("buff3:");
    fgets(buff3,TAM,stdin);
    write(w_fifo,buff,strlen(buff));
    sleep(1);
    write(w_fifo,buff2,strlen(buff));
    sleep(1);
    write(w_fifo,buff3,strlen(buff));
  }
  exit(EXIT_SUCCESS);
}