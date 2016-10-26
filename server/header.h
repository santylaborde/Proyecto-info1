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
void op1(MENU *,int);
void op2(MENU *,int);
void op3(MENU *,int);
void op4(MENU *,int);
void op5(MENU *,int);
void op6(MENU *,int);