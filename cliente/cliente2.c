#include "info1.h"
int main(void)
{
  CLIENTE c;int aux=0;
  MENU m;
  if((c.he = gethostbyname(IP)) == NULL)
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
    perror("send");
  if(send(c.sockfd,c.pass,strlen(c.pass)+1,0)==-1)
    perror("send");
  
  if((c.numbytes = recv(c.sockfd,c.buffer,TAM,0)) == -1)
    perror("recv");
  c.buffer[c.numbytes]='\0';
  printf("%s\n",c.buffer);
  strcpy(m.Menu,c.buffer);
  scanf("%d",&aux);
  while(aux!=-1)
  {
    if(aux!=0)
    {
      if(send(c.sockfd,&aux,sizeof(aux),0)==-1)
	perror("send");
      if((c.numbytes = recv(c.sockfd,c.buffer,TAM,0)) == -1)
	perror("recv");
      c.buffer[c.numbytes]='\0';
      printf("%s\n",c.buffer);
    }
    else
      printf("%s\n",m.Menu);
    scanf("%d",&aux);
  }
  close(c.sockfd);
  exit(0);
}