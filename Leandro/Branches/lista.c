#include "flista.h"
int main(void)
{
    //primer lista de lista
    int k=1,id=0,precio=0;
    char buffer [1024];
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
    scanf("%d",&precio);
    nodo_inicio (Menu->inicio->ListaMenu,buffer,precio,id);
    id++;
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
    scanf("%d",&precio);
    nodo_inicio (Menu->inicio->ListaMenu,buffer,precio,id);
    id++;
    printf("agregar nodo 1 o 2 salir");
    scanf("%d",&k);
    }   
    visualizacion (Menu->inicio->ListaMenu);
    visualizacionLista(Menu);
    return 0;
}
