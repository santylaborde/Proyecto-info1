#include "flista.h"
/*guarda el principio y fin de una lista*/
void inicializacion (Lista *lista)
{
  lista->inicio = NULL;
  lista->fin = NULL;
  lista->TAM = 0;
}
/* agrega en una lista vacia */
int elemento_en_lista_vacia(Lista * lista, char *dato)
{
  Producto *nuevo_producto;
  if ((nuevo_producto = (Producto *) malloc (sizeof (Producto))) == NULL)
    return -1;
  if ((nuevo_producto->Mercaderia = (char *) malloc (50 * sizeof (char)))
      == NULL)
    return -1;
  strcpy (nuevo_producto->Mercaderia, dato);
  nuevo_producto->siguiente = NULL;
  lista->inicio = nuevo_producto;
  lista->fin = nuevo_producto;
  lista->TAM++;
  return 0;
}

/* visualizacion de la lista */
void visualizacion (Lista * lista){
  Producto *actual;
  actual = lista->inicio;
  while (actual != NULL){
      printf ("%s\n",actual->Mercaderia);
      actual = actual->siguiente;
  }
}

/* agrega al inicio de la lista */
int agregar_inicio_lista (Lista * lista, char *dato){
  Producto *nuevo_producto;
  if ((nuevo_producto = (Producto *) malloc (sizeof (Producto))) == NULL)
    return -1;
  if ((nuevo_producto->Mercaderia = (char *) malloc (50 * sizeof (char)))
      == NULL)
    return -1;
  strcpy (nuevo_producto->Mercaderia, dato);
  nuevo_producto->siguiente = lista->inicio;
  lista->inicio = nuevo_producto;
  lista->TAM++;
  return 0;
}

/*agrega al final de la lista */
int agregar_fin_lista (Lista * lista, Producto * actual, char *dato){
  Producto *nuevo_producto;
  if ((nuevo_producto = (Producto *) malloc (sizeof (Producto))) == NULL)
    return -1;
  if ((nuevo_producto->Mercaderia = (char *) malloc (50 * sizeof (char)))
      == NULL)
    return -1;
  strcpy (nuevo_producto->Mercaderia, dato);
  actual->siguiente = nuevo_producto;
  nuevo_producto->siguiente = NULL;
  lista->fin = nuevo_producto;
  lista->TAM++;
  return 0;
}

/* eliminacion al inicio de la lista */
int eliminar_inicio (Lista * lista){
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
int agregar_elemento_posicion (Lista * lista, char *dato, int pos)
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
int eliminar_elemento_posicion (Lista * lista, int pos){
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
void destruir (Lista *lista){
  while (lista->TAM > 0)
    eliminar_inicio (lista);
}

/*crea e inicializa el menu*/
int new_menu (struct ListaMenu  *Menu)
{
    if((Menu->Bebidas = (Lista *) malloc (sizeof(Lista))) == NULL)
    return -1;
    inicializacion (Menu->Bebidas);
    if((Menu->Postres = (Lista *) malloc (sizeof(Lista))) == NULL)
    return -1;
    inicializacion (Menu->Postres);
    if((Menu->Ensaladas = (Lista *) malloc (sizeof(Lista))) == NULL)
    return -1; 
    inicializacion (Menu->Ensaladas);
    if((Menu->MenuEst = (Lista *) malloc (sizeof(Lista))) == NULL)
    return -1;
    inicializacion (Menu->MenuEst);
    if((Menu->MenuDia = (Lista *) malloc (sizeof(Lista))) == NULL)
    return -1;
    inicializacion (Menu->MenuDia);
    if((Menu->Buffer = (char *) malloc (50 * sizeof(char)))== NULL)
    return -1;
return 0;
}
