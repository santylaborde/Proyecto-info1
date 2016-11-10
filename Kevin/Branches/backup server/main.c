#include "header.h"
int main(void)
{
  char buff[1024];
  int fd,i;
  fd=open("backup",O_WRONLY);
  scanf("%s",buff);
  i=strlen(buff);
  buff[i]='\r';
  buff[i+1]='\n';
  write(fd,buff,strlen(buff));
  scanf("%s",buff);
  i=strlen(buff);
  buff[i]='\r';
  buff[i+1]='\n';
  write(fd,buff,strlen(buff));
  system("cat backup");
  return 0;
}