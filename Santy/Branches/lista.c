#include "flista.h"
int main(void)
{
    //primer lista de lista
    int k=1;
    char buffer[1024], precio[1024], id[1024];
    ListaDeL *Menu=NULL;
    Menu= (ListaDeL *) malloc (sizeof (ListaDeL));
    inicializacionLista (Menu);
    
    
    printf("nombre de la lista ");
    scanf("%s",buffer);
    lista_inicio(Menu,buffer);
    while(k==1)
    {
    printf("producto");
    scanf("%s",buffer);
    printf("precio");
    scanf("%s", precio);
    printf("ID:");
    scanf("%s", id);
    nodo_inicio (Menu->inicio->ListaMenu,buffer,precio,id);
    printf("agregar nodo 1 o 2 salir");
    scanf("%d",&k);
    }
    visualizacion (Menu->inicio->ListaMenu);
    visualizacionLista(Menu);
    printf("nombre de la lista ");
    scanf("%s",buffer);
    lista_inicio(Menu, buffer);
    k=1;
       while(k==1)
    {
    printf("producto");
    scanf("%s",buffer);
     printf("precio");
    scanf("%s", precio);
    nodo_inicio (Menu->inicio->ListaMenu,buffer,precio,id);
    printf("ID:");
    scanf("%s", id);
    printf("agregar nodo 1 o 2 salir");
    scanf("%d",&k);
    }   
    visualizacion (Menu->inicio->ListaMenu);
    visualizacionLista(Menu);
    return 0;
}
