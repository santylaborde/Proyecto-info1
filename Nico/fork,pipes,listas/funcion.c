//agregar funcion de matar procesos hijos
#include "header.h"
void listen_buffet(void)
{
  char buffer[TAM];
  int w_fifo, r_fifo, numbytes;
  
  w_fifo = open(FIFO,O_WRONLY);
  r_fifo = open(FIFO2,O_RDONLY);
  while(1)
  {
    numbytes = read(r_fifo,buffer,TAM);
    buffer[numbytes-1]='\0';
    write(w_fifo,buffer,strlen(buffer)+1);
  }
  close(r_fifo);
  close(w_fifo);
  exit(0);
}

void mostrar_pedido(void)
{
  int r_fifo, numbytes;
  char buffer[TAM]; 
  PEDIDO *inicio=NULL, *new, *aux=NULL;
  
  r_fifo = open(FIFO,O_RDONLY);
  while(1)
  {
  numbytes = read(r_fifo,buffer,TAM);
  buffer[numbytes]='\0';
  new=(PEDIDO *)malloc(sizeof(PEDIDO));
  tostruct(buffer,&new);
  add_nodofinal(&inicio,new,&aux);
  system("clear");
  ver_lista(inicio);
  }

  close(r_fifo);
  exit(0);
}

void tostruct(char *buff,PEDIDO **new)
{
  int i, j, k=0, len=0;
  char aux[TAM];
  void (* opcion[4])(char *, PEDIDO **)={pedido,precio,usuario,hora};
  
  for(i=0; buff[i] != '\0'; i++)
  {
    if(buff[i] == '.')
      len++;
  }
  i=0;
  while(k <= len && buff[i] != '\0')
  {
    /*Copio en un auxiliar una parte del buffer */
    for(j=0; buff[i] != '.' && buff[i] != '\0'; i++, j++)
      aux[j] = buff[i];
    aux[j]='\0';
    opcion[k](aux,new);
    k++;
    i++;
  }
  return;
}
/**
 * @fn void add_nodofinal(TYPESTRUCT **, TYPESTRUCT *, TYPESTRUCT **);
 * @details La funcion se encargara de agregar un nodo al final de una lista
 * la cual se recibe por parametros.
 * @param inicio Recibe el puntero de comienzo a la lista, si esta vacio lo carga
 * con el nuevo nodo a agregar a la lista.
 * @param new Contiene la direccion de memoria del nuevo nodo a agregar
 * @param aux Es un auxiliar que sirve para enlazar la lista.
 * @return void
 * @author Nicolás M. Campos
 * @date 15-11-16
 */

void add_nodofinal(TYPESTRUCT **inicio, TYPESTRUCT *new, TYPESTRUCT **aux)
{
  new->next=NULL;
  if(*inicio==NULL)
    *inicio=new;
  else
    (*aux)->next=new;
  *aux=new;
}
void fail(int fd)
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
/**
 * @fn int precio(char *buff, PEDIDO **)
 * @brief Convierte de una valor en ascii a un valor decimal. Solo para numeros sin coma.
 * @details se necesita el string.h
 * @param buff Puntero a la string que se quiere pasar a decimal
 * @param new Puntero donde carga el precio en una estructura nueva
 * @return El valor en decimal del string pasado por parametro. -1 en caso de error.
 * @author Nicolás M. Campos
 */
void precio(char *buff, PEDIDO **new)
{
  int aux, i, len, r=0, multiplicador=1;
  len=strlen(buff);
  for(i=1;i<len;i++)
    multiplicador*=10;
  for(i=0;buff[i]!='\0';i++)
  {
    aux=(buff[i]-'0');
    if(aux <= 9 && aux >= 0)
    {
      r+=(aux*multiplicador);
      multiplicador/=10;
    }
    else
      fail(-1);
  }
  (*new)->precio=r;
  return;
}

void pedido(char *buff, PEDIDO **new)
{
  (*new)->pedido=(char *)malloc(strlen(buff)+1);
  strcpy((*new)->pedido , buff);
  return;
}

void usuario(char *buff, PEDIDO **new)
{
  (*new)->usuario=(char *)malloc(strlen(buff)+1);
  strcpy((*new)->usuario , buff);
  return;
}

void hora(char *buff, PEDIDO **new)
{
  strcpy((*new)->hora , buff);
  return;
}

void handler(int s)
{
    while(wait(NULL)>0);
}

void ver_lista(PEDIDO *inicio)
{
  while(inicio != NULL)
  {
    printf("Pedido: %s\n",inicio->pedido);
    printf("Precio $%d\n",inicio->precio);
    printf("Usuario: %s\n",inicio->usuario);
    printf("Hora de retiro: %s\n",inicio->hora);
    inicio = inicio->next;
  }
}