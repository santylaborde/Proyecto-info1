#include "santy.h"

//*********************************************************************
int nueva_seccion(lista1 **seccion)
{
    int  k=1;
    lista2 *aux= (*seccion)->producto;
    
    printf("Nombre de la sección:\t");
    scanf("%s",(*seccion)->nombre);
    
    aux= (lista2 *) malloc(sizeof(lista2));
    (*seccion)->inicio= aux;
    
        while(k==1)
        {         
            printf("Producto:\t");
            scanf("%s",aux->mercaderia);
            printf("Precio:\t");
            scanf("%s",aux->precio);
            printf("ID:\t");
            scanf("%s",aux->id);
            
            printf("¿Agregar más productos? SI: 1   NO: 2\t");
            scanf("%d",& k);
            
            if(k==1)
            {
                aux->next= (lista2 *) malloc(sizeof(lista2));
                aux= aux->next;
            }            
        }
        aux->next= NULL;

return 0;    
}
//*********************************************************************

//*********************************************************************
void visualizar (lista1 *inicio)
{
    lista1 *aux= inicio;
    lista2 *aux2;
    
    while(aux!=NULL)
    {
        printf("%s:\n", aux->nombre);
        aux2= aux->inicio;
        
        while(aux2!=NULL)
        {
            printf("%s\t", aux2->mercaderia);
            printf("%s\t", aux2->precio);
            printf("%s\n", aux2->id);
            
            aux2= aux2->next;
        }
        
    aux= aux->next;
    }
    
    return;
}
//*********************************************************************

//*********************************************************************
int leer_archivo(FILE *fd, lista1 **inicio)
{
    char buffer[TAM];
    lista1 *aux= *inicio;
    lista2 *aux2;
    int FLAG;
    
    while(!feof(fd))
    {
        FLAG=1;
        
        fscanf(fd, "%s", aux->nombre);
        aux2= (lista2 *) malloc(sizeof(lista2));
        aux->inicio= aux2;
        
        while(FLAG!=0)
        {
            fscanf(fd, "%s", buffer);

            if(!strcmp(buffer, "FIN"))
            {
                aux2->next= NULL;
                FLAG=0;
            }
            else
            {
                strcpy(aux2->mercaderia, buffer);
                fscanf(fd, "%s", aux2->precio);
                fscanf(fd, "%s", aux2->id);
            
                aux2->next= (lista2 *) malloc(sizeof(lista2));
                aux2= aux2->next;
            }
        }

        aux->next= (lista1 *) malloc(sizeof(lista1));
        aux= aux->next;
    }

aux->next= NULL;

return 0;
}
//*********************************************************************

//*********************************************************************
void crear_backup(lista1 *inicio, char *archivo)
{
    FILE *fd;
    lista1 *aux= inicio;
    lista2 *aux2;
    fd= fopen(archivo, "w+");
    
    while(aux!=NULL)
    {
        fputs(aux->nombre, fd);
        fputc(' ', fd);
        
        aux2= aux->inicio;
        while(aux2!=NULL)
        {
            fputs(aux2->mercaderia, fd);
            fputc(' ', fd);
            fputs(aux2->precio, fd);
            fputc(' ', fd);
            fputs(aux2->id, fd);
            fputc(' ', fd);
            
            aux2= aux2->next;
        }
        aux= aux->next;
        fputc('\n', fd);
    }
    
    fclose(fd);
    
return;
}
//*********************************************************************
