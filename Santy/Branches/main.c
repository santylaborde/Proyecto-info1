#include "santy.h"

int main (void)
{
    FILE *fd;
    lista1 *seccion;
    lista1 *inicio;
    char archivo[TAM];
    int k=1;
    
    seccion= (lista1 *) malloc(sizeof(lista1));
    inicio= seccion;
    
    printf("Ingrese el nombre de su base de datos:\t");
    scanf("%s", archivo);
    
    fd= fopen(archivo, "r");
    
    if(fd==0)
    {
        printf("No existe la base de datos. ¿Desea crearla? SI: 1   NO: 2\t");
        scanf("%d",& k);
        while(k==1)
        {
            nueva_seccion(&seccion);
            
            printf("¿Desea ingresar otra sección? SI: 1   NO: 2\t");
            scanf("%d",& k);
            
            if(k==1)
            {
                seccion->next= (lista1 *) malloc(sizeof(lista1));
                seccion= seccion->next;
            }
        }
        seccion->next= NULL;
        
        crear_backup(inicio, archivo);
        printf("Su base de datos se creo existosamente\n");
    }
    
    else
    {
        printf("Existe la base de datos. ¿Desea cargarla? SI: 1   NO: 2\t");
        scanf("%d", &k);
        if(k==1)
        {
            leer_archivo(fd, &inicio);
            visualizar(inicio);
        }
    }
         
return 0;
}


