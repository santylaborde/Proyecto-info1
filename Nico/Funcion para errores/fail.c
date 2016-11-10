#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

void fail (int);

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