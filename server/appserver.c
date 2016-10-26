#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/wait.h>
#include <signal.h>
#include <netdb.h>
#include <fcntl.h>

#define BUFFER		1024
#define BACKLOG		10  //listen ()
#define PORT		12345
#define BUFFER1		40 //largo del vector para guardar user y pass
#define CantUser	4 //cantidad de usuarios

#define MENUU       "menu.txt"
#define MENUEST     "MenuEst.txt"
#define MENUDIA     "Menudeldia.txt"
#define MENUES      "Menues.txt"
#define BEBIDA      "Bebidas.txt"
#define ENSALADA    "Ensaladas.txt"
#define POSTRE      "Postres.txt"

#define USUARIO     "usuario.txt"
#define DEBUG

typedef struct server
{
    //bind(), socket(), send(), recv()
    int sockfd, numbytes;
    char user[BUFFER1], password[BUFFER1];
    struct sockaddr_in server_addr;
    socklen_t size;
    //accept()
    struct sockaddr_in client_addr;
    int new_sockfd;
    //read() y write()
    char buffer[BUFFER];
    int choice;
}SERVER;

typedef struct cliente
{
    //socket(), send(), recv()
    int sockfd, numytes;
    //connect()
    struct sockaddr_in server_addr;
    socklen_t size;
}CLIENTE;

typedef struct menu
{
    //datos menu
    char Menu[BUFFER];      //para el menu general
    char MenuEst[BUFFER];   //para el menu estudiantil
    char Post[BUFFER];      //para los postres
    char MenuDia[BUFFER];   //menu del dia
    char Beb[BUFFER];       //Bebidas
    char Ensal[BUFFER];     //Ensaladas
    char Menues[BUFFER];    //Menues
    char aux[BUFFER];
}MENU;

typedef struct user
{
    //datos user
    char User[CantUser][BUFFER1];	//matriz para user y pass
    char aux[BUFFER1];			//auxiliar 
    char buffer;
}USER;

void handler(int);
int login(char*, char*,USER*);
int login_pass (char*, int, int, USER*);
void fail (int,char *);
void child_process(int,MENU*,USER*);
void menu_principal(int, MENU*);
void load_menu(MENU*);
void load_user(USER*);
void op1(MENU *,int,int);
void op2(MENU *,int,int);
void op3(MENU *,int,int);
void op4(MENU *,int,int);
void op5(MENU *,int,int);
void op6(MENU *,int,int);
int main (void)
{

    SERVER s;
    MENU m;
    USER u;
    //abrimos socket
    fail(s.sockfd= socket(AF_INET, SOCK_STREAM, 0),"Socket");
    
    //cargamos datos server
    s.server_addr.sin_family= AF_INET;
    s.server_addr.sin_port= htons(PORT);
    s.server_addr.sin_addr.s_addr=INADDR_ANY;
    memset(s.server_addr.sin_zero, '\0', 8);
    
    //reservamos el puerto
    s.size= sizeof (struct sockaddr);
    fail(bind(s.sockfd,(struct sockaddr*) &s.server_addr, s.size),"Bind");
    
    //cargamos datos
    load_menu(&m);
    load_user(&u);
    
    //nos quedamos escuchando
    fail(listen(s.sockfd, BACKLOG),"Listen");
    
    //manipulamos sigchild
    signal(SIGCHLD, handler);
    
    //concurrencia
    while(1)
    {
        //atendemos cliente
        fail(s.new_sockfd= accept(s.sockfd,(struct sockaddr *) &s.client_addr, &s.size),"accept");
        if(s.new_sockfd!=-1)
        {
	  printf("Se recibio una conexion\n");
            if(!fork()) //proceso hijo
            {
                close (s.sockfd);
                child_process(s.new_sockfd,&m,&u);
            }
            //proceso padre
            close(s.new_sockfd);
        }
    }
  exit(0);
}
//proceso hijo

void child_process(int sockfd,MENU *menu,USER *usr)
{
  SERVER s;
  //mensaje de bienvenida
  fail(send(sockfd,"BIENVENIDO\n", 20, 0),"send");

  //recibimos datos de loggeo
  fail(s.numbytes= recv(sockfd, s.user, BUFFER1, 0),"recv");
  s.user[s.numbytes]='\0';
  fail(s.numbytes= recv(sockfd, s.password, BUFFER1, 0),"recv");
  s.password[s.numbytes]='\0';
  //loggeo
  if(login(s.user, s.password,usr)==0)
      menu_principal(sockfd,menu);
  else
      fail(send(sockfd,"Usuario o clave incorrecta", 100, 0),"send");
  close(sockfd);
  exit(0);
  return;
}

//menu principal
void menu_principal(int sockfd,MENU *menu)
{
    SERVER s;
    int k=0;
    void (*opciones[7])(MENU *,int,int)={op1,op2,op3,op4,op5,op6};
    fail(send(sockfd,menu->Menu,strlen(menu->Menu)+1, 0),"send");
    fail(s.numbytes= recv(sockfd, &s.choice, 2, 0),"recv"); 
    opciones[s.choice-1](menu,sockfd,k);
    
}
//Funciones de opciones
void op1(MENU *menu,int sockfd, int k)	//menu del dia
{
    fail(send(sockfd,menu->MenuDia,strlen(menu->MenuDia)+1, 0),"send");
    return;
}
void op2(MENU *menu,int sockfd, int k)	//menu estudiantil
{
    fail(send(sockfd,menu->MenuEst,strlen(menu->MenuEst)+1, 0),"send");
}
void op3(MENU *menu,int sockfd, int k)	//menues
{
    fail(send(sockfd,menu->Menues,strlen(menu->Menues)+1, 0),"send");
}
void op4(MENU *menu,int sockfd, int k)	//bebidas
{
    int choice,i,j,a;
    fail(send(sockfd,menu->Beb,strlen(menu->Beb)+1, 0),"send");
    fail(recv(sockfd, &choice, 2, 0),"recv");
    for(i=0;i<BUFFER;i++)
    {
      if(menu->Beb[i]==(choice+'0'))
      {
	if(menu->Beb[i+1]=='-')
	{
	  for(j=i+2,a=0;menu->Beb[j]!='\n';j++,a++)
	      menu->aux[a]=menu->Beb[j];
	    printf("%s\n",menu->aux);
	}
      }
    }
    /*
    if(k!=0)
    {
    for(i=0;i<BUFFER;i++)
    {
      if(menu->Beb[i]==(k+'0'))
      {
	if(menu->Beb[i+1]=='-')
	{
	    for(j=i+2,a=0;menu->Beb[j]!='\n';j++,a++)
	      menu->aux[a]=menu->Beb[j];
	    printf("%s\n"menu->aux);
	}
      }
	  
    }
    }*/
}
void op5(MENU *menu,int sockfd, int k)	//postres
{
  fail(send(sockfd,menu->Post,strlen(menu->Post)+1, 0),"send");
}
void op6(MENU *menu,int sockfd, int k)	//ensalada
{
  fail(send(sockfd,menu->Ensal,strlen(menu->Ensal)+1, 0),"send");
}

//Cargo menu
void load_menu(MENU *menu)
{
    int fd,aux;
    
    //Cargo datos del menu
    fd=open(MENUU,O_RDONLY);
    aux=read(fd,menu->Menu,BUFFER);
    menu->Menu[aux]='\0';
    close(fd);
    
    fd=open(MENUEST,O_RDONLY);
    aux=read(fd,menu->MenuEst,BUFFER);
    menu->MenuEst[aux]='\0';
    close(fd);
    
    fd=open(MENUDIA,O_RDONLY);
    aux=read(fd,menu->MenuDia,BUFFER);
    menu->MenuDia[aux]='\0';
    close(fd);
    
    fd=open(MENUES,O_RDONLY);
    aux=read(fd,menu->Menues,BUFFER);
    menu->Menues[aux]='\0';
    close(fd);
    
    fd=open(POSTRE,O_RDONLY);
    aux=read(fd,menu->Post,BUFFER);
    menu->Post[aux]='\0';
    close(fd);
    
    fd=open(BEBIDA,O_RDONLY);
    aux=read(fd,menu->Beb,BUFFER);
    menu->Beb[aux]='\0';
    close(fd);
    
    fd=open(ENSALADA,O_RDONLY);
    aux=read(fd,menu->Ensal,BUFFER);
    menu->Ensal[aux]='\0';
    close(fd);
    
    return;
}

//Cargo usuarios
void load_user(USER *usr)
{
    int i,j;
    FILE *fd;
    
    fd=fopen(USUARIO,"r");
    usr->buffer=(char)fgetc(fd);
    for(i=0;usr->buffer!='!' && i<4;i++)
    {
	for(j=0;usr->buffer!='\n';j++)
	{
	      usr->aux[j]=usr->buffer;
	      usr->buffer=(char)fgetc(fd);
	}
	usr->aux[j]='\0';
	strcpy(usr->User[i],usr->aux);
	usr->buffer=(char)fgetc(fd);
    }
    fclose(fd);
    return;
}

//logeo
//___________________________________________________________________________________________________
int login(char*usr, char*pass, USER *us)
{
  int i,j=0,r;
  while(j<CantUser)
  {
      for(i=j;us->User[i][0]!=usr[0];i++,j++)
      {
	  if(j==CantUser)
	    return -1;
      }
      for(r=0;us->User[i][r]!=' ';r++)
	  us->aux[r]=us->User[i][r];
      us->aux[r]='\0';
      if(!strcmp(us->aux,usr))  //si  el nombre de usuario es verdadero
      {
          i=login_pass(pass,r+1,i,us);
	  return i;
      }
      j++;
  }
  return -1;
}

int login_pass(char*pass, int i, int k, USER *us)
{
  int j,m;
  for(m=i,j=0;us->User[k][m]!='\0';m++,j++)
      us->aux[j]=us->User[k][m];
  us->aux[j]='\0';
  j=strcmp(us->aux,pass);
  return j;
}
//___________________________________________________________________________________________________

void handler(int s)
{
    while(wait(NULL)>0);
#ifdef DEBUG	
    printf("Elimine hijo\n");
#endif
    return;
}

//___________________________________________________________________________________________________
void fail (int fd,char *s)
{
    if (fd==-1)
      perror(s);
    return;
}