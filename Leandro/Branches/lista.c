#include "flista.h"
int main(void)
{
    //para crear una lista hay que declarar un puntero a la strcuk lista 
    ListaMenu  Menu;
    int k=1;
    //se reserva memoria e inicializa el menu
    new_menu (&Menu);
    scanf("%s",Menu.Buffer);
    elemento_en_lista_vacia (Menu.Bebidas, Menu.Buffer);
    printf("quieres seguir agregando 1 para si ");
    scanf("%d",&k);
    while(k==1)
    {
    scanf("%s",Menu.Buffer);
    agregar_inicio_lista (Menu.Bebidas,Menu.Buffer);
    printf("quieres seguir agregando 1 para si ");
    scanf("%d",&k);
    }
    visualizacion (Menu.Bebidas);
    return 0;
}

