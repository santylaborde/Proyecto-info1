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
/* Elementos de cada lista */
typedef struct ProductoLista
{
  char * Mercaderia;
  int precio;
  int id;
  struct ProductoLista *siguiente;
} Producto;
/* estructura identificar el inicio y final */
typedef struct ListaIdentificar
{
  Producto *inicio;
  Producto *fin;
  int TAM;
} ListaI;
/* lista de lista */
typedef struct Lista
{
    ListaI  *ListaMenu;
    char    *Nombre; //nombre de la lista
    struct Lista *siguiente;
}Lista;
typedef struct ListaIdentificarListta
{
  Lista *inicio;
  Lista *fin;
  int TAM;
} ListaDeL;

/* guarda el principio y fin de una lista */
void inicializacion (ListaI *lista);

/* visualizacion de la lista */
void visualizacion (ListaI * lista);

/* agrega al inicio de la lista */
int nodo_inicio (ListaI * lista, char *dato, int precio,int id);//cambiados 

/* agrega al final de la lista */
int nodo_final (ListaI * lista, Producto * actual, char *dato);//cambiados

/* eliminacion al inicio de la lista */
int eliminar_inicio (ListaI * lista);

/* agrega en la posicion solicitada */
int agregar_elemento_posicion (ListaI * lista, char *dato, int pos);

/* eliminar un Producto despues de la posicion solicitada */
int eliminar_elemento_posicion (ListaI * lista, int pos);

/* destruir la lista */
void destruir (ListaI *lista);
//--------------lista a lista--------------//
/* agrega una lista */
int lista_inicio(ListaDeL * lista, char *dato);

/* inicializa la lista*/
void inicializacionLista (ListaDeL *lista);

/* visualizacion de la lista */
void visualizacionLista (ListaDeL * lista);

/*inicializa la lista*/
int new_menu(ListaDeL *lista);
