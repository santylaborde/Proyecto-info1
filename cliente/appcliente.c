#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/wait.h>
#include <signal.h>
#include <netdb.h>

#define TAM	1024
#define PORT	6424

typedef struct cvar
{
  int sockfd,numbytes;
  char ip[20];
  char buffer[TAM],usr[20],pass[20];
  struct hostent *he;
  struct sockaddr_in their_addr;
}CVAR;

int main()
{
  CVAR c;
  printf("ingrese ip server:");
  scanf("%s",ip);
  if((c.he = gethostbyname(ip)) == NULL)
  {
    perror("gethostbyname");
    exit(1);
  }
  if((c.sockfd = socket(AF_INET,SOCK_STREAM,0)) == -1)
  {
    perror("socket");
    exit(1);
  }
  c.their_addr.sin_family = AF_INET;
  c.their_addr.sin_port = htons(PORT);
  c.their_addr.sin_addr = *((struct in_addr *)c.he->h_addr);
  memset(&(c.their_addr.sin_zero),'\0',8);
  if(connect(c.sockfd,(struct sockaddr*)&c.their_addr,sizeof(struct sockaddr)) == -1)
  {
    perror("connect");
    exit(1);
  }
  if((c.numbytes = recv(c.sockfd,c.buffer,TAM,0)) == -1)
  {
    perror("recv");
  }
  c.buffer[c.numbytes]='\0';
  printf("%s\n",c.buffer);
  printf("Usuario:");
  scanf("%s",c.usr);
  printf("Clave:");
  scanf("%s",c.pass);
  if(send(c.sockfd,c.usr,strlen(c.usr)+1,0)==-1)
    {
      perror("send");
    }
  if(send(c.sockfd,c.pass,strlen(c.pass)+1,0)==-1)
    {
      perror("send");
    }
  if((c.numbytes = recv(c.sockfd,c.buffer,TAM,0)) == -1)
  {
    perror("recv");
  }
  switch(c.buffer[0])
  {
    case '0':
      printf("Conectando al server...\n");
      break;
    case '1':
      printf("Usuario incorrecto\n");
      break;
    case '2':
      printf("Clave incorrecta\n");
  }
  close(c.sockfd);
  exit(0);
}