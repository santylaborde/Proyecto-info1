#include "header.h"

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

