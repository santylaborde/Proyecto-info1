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
} Lista;

/* punteros que forman una unica lista con las listas de menu */
typedef struct ListaMenu
{
    Lista * Bebidas;
    Lista * Postres;
    Lista * Ensaladas;
    Lista * MenuEst;
    Lista * MenuDia;
    char  * Buffer;
}ListaMenu;

/* guarda el principio y fin de una lista */
void inicializacion (Lista *lista);

/* agrega en una lista vacia */
int elemento_en_lista_vacia(Lista * lista, char *dato);

/* visualizacion de la lista */
void visualizacion (Lista * lista);

/* agrega al inicio de la lista */
int agregar_inicio_lista (Lista * lista, char *dato);

/* agrega al final de la lista */
int agregar_fin_lista (Lista * lista, Producto * actual, char *dato);

/* eliminacion al inicio de la lista */
int eliminar_inicio (Lista * lista);

/* agrega en la posicion solicitada */
int agregar_elemento_posicion (Lista * lista, char *dato, int pos);

/* eliminar un Producto despues de la posicion solicitada */
int eliminar_elemento_posicion (Lista * lista, int pos);

/* destruir la lista */
void destruir (Lista *lista);

/* crea e inicializa el menu */
int new_menu (struct ListaMenu  *Menu);
