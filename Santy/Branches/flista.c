#include "flista.h"

/*guarda el principio y fin de una lista*/
void inicializacion (ListaI *lista)
{
  lista->inicio = NULL;
  lista->fin = NULL;
  lista->TAM = 0;
}

/* visualizacion de la lista */
void visualizacion (ListaI * lista){
  Producto *actual;
  actual = lista->inicio;
  while (actual != NULL)
  {
      printf ("%s\n",actual->Mercaderia);
      printf ("%s\n",actual->precio);
      printf ("%s\n",actual->id);
      actual = actual->siguiente;
      }
}

/* agrega al inicio de la lista */
int nodo_inicio(ListaI * lista, char *dato,char *precio,char *id){
  Producto *nuevo_producto;
  if ((nuevo_producto = (Producto *) malloc (sizeof (Producto))) == NULL)
    return -1;
  if ((nuevo_producto->Mercaderia = (char *) malloc (sizeof (dato))) == NULL)
    return -1;
  if ((nuevo_producto->precio = (char *) malloc (sizeof (precio))) == NULL)
    return -1;
  if ((nuevo_producto->id = (char *) malloc (sizeof (id))) == NULL)
    return -1;
  
    if(lista->TAM == 0)
    {
        strcpy (nuevo_producto->Mercaderia, dato);
        strcpy (nuevo_producto->precio, precio);
        strcpy (nuevo_producto->id, id);
        nuevo_producto->siguiente = NULL;
        lista->inicio = nuevo_producto;
        lista->fin = nuevo_producto;
        lista->TAM++;        
    }
    else
    {
        strcpy (nuevo_producto->Mercaderia, dato);
        strcpy (nuevo_producto->precio, precio);
        strcpy (nuevo_producto->id, id);
        nuevo_producto->siguiente = lista->inicio;
        lista->inicio = nuevo_producto;
        lista->TAM++;
    } 
  return 0;
}

/*agrega al final de la lista */
int nodo_final(ListaI * lista, Producto * actual, char *dato){
  Producto *nuevo_producto;
  if ((nuevo_producto = (Producto *) malloc (sizeof (Producto))) == NULL)
    return -1;
  if ((nuevo_producto->Mercaderia = (char *) malloc (sizeof (dato)))
      == NULL)
    return -1;
      if(lista->TAM == 0)
    {
        strcpy (nuevo_producto->Mercaderia, dato);
        nuevo_producto->siguiente = NULL;
        lista->inicio = nuevo_producto;
        lista->fin = nuevo_producto;
        lista->TAM++;
    }
    else
    {
        strcpy (nuevo_producto->Mercaderia, dato);
        actual->siguiente = nuevo_producto;
        nuevo_producto->siguiente = NULL;
        lista->fin = nuevo_producto;
        lista->TAM++;
    }
  return 0;
}

/* eliminacion al inicio de la lista */
int eliminar_inicio (ListaI * lista){
  if (lista->TAM == 0)
    return -1;
  Producto *sup_Producto;
  sup_Producto = lista->inicio;
  lista->inicio = lista->inicio->siguiente;
  if (lista->TAM == 1)
    lista->fin = NULL;
  free (sup_Producto->Mercaderia);
  free (sup_Producto);
  lista->TAM--;
  return 0;
}

/* agrega en la posicion solicitada */
int agregar_elemento_posicion (ListaI * lista, char *dato, int pos)
{
  if (lista->TAM < 2)
    return -1;
  if (pos < 1 || pos >= lista->TAM)
    return -1;
  Producto *actual;
  Producto *nuevo_producto;
  int i;
  if ((nuevo_producto = (Producto *) malloc (sizeof (Producto))) == NULL)
    return -1;
  if ((nuevo_producto->Mercaderia = (char *) malloc (50 * sizeof (char)))
      == NULL)
    return -1;
  actual = lista->inicio;
  for (i = 1; i < pos; ++i)
    actual = actual->siguiente;
  if (actual->siguiente == NULL)
    return -1;
  strcpy (nuevo_producto->Mercaderia, dato);
  nuevo_producto->siguiente = actual->siguiente;
  actual->siguiente = nuevo_producto;
  lista->TAM++;
  return 0;
}

/* eliminar un Producto despues de la posicion solicitada */
int eliminar_elemento_posicion (ListaI * lista, int pos){
  if (lista->TAM <= 1 || pos < 1 || pos >= lista->TAM)
    return -1;
  int i;
  Producto *actual;
  Producto *sup_Producto;
  actual = lista->inicio;
  for (i = 1; i < pos; ++i)
    actual = actual->siguiente;
  sup_Producto = actual->siguiente;
  actual->siguiente = actual->siguiente->siguiente;
  if(actual->siguiente == NULL)
          lista->fin = actual;
  free (sup_Producto->Mercaderia);
  free (sup_Producto);
  lista->TAM--;
  return 0;
}

/* destruir la lista */
void destruir (ListaI *lista){
  while (lista->TAM > 0)
    eliminar_inicio (lista);
}
///------------------lista de listas

/*guarda el principio y fin de una lista*/
void inicializacionLista (ListaDeL *lista)
{
  lista->inicio = NULL;
  lista->fin = NULL;
  lista->TAM = 0;
}
///----------------------------------
int new_menu(ListaDeL *lista){
    if ((lista= (ListaDeL *) malloc (sizeof (ListaDeL))) == NULL)
    return -1;
    inicializacionLista (lista);
    return 0;
    }
//----------------
int lista_inicio(ListaDeL * lista, char *dato){
   Lista *nuevo_lista;
  if ((nuevo_lista = (Lista *) malloc (sizeof (Lista))) == NULL)
    return -1;
  if ((nuevo_lista->Nombre= (char *) malloc (sizeof (dato))) == NULL)
    return -1;
  if ((nuevo_lista->ListaMenu= (ListaI *) malloc (sizeof (ListaI))) == NULL)
    return -1;
  inicializacion (nuevo_lista->ListaMenu);
    if(lista->TAM == 0)
    {
        strcpy (nuevo_lista->Nombre, dato);
        nuevo_lista->siguiente = NULL;
        lista->inicio = nuevo_lista;
        lista->fin = nuevo_lista;
        lista->TAM++;
    }
    else
    {
        strcpy (nuevo_lista->Nombre, dato);
        nuevo_lista->siguiente = lista->inicio;
        lista->inicio = nuevo_lista;
        lista->TAM++;
    } 
  return 0;
}
/* visualizacion de la lista */
void visualizacionLista (ListaDeL * lista){
  Lista *actual;
  actual = lista->inicio;
  while (actual != NULL)
  {
      printf ("%s\n",actual->Nombre);
      actual = actual->siguiente;
      }
}
