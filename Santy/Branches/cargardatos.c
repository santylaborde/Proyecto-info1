    #include "flista.h"
    #define PATH "Comidas.txt"
    #define NUM 20
    int cargar_lista (ListaDeL *);
    int leer_archivo (FILE *, ListaDeL *);

    int main (void)
    {
        FILE * fd;
        ListaDeL * seccion;
        Lista *actual;
        Producto *aux;
        char buffer[NUM];
       
        
        seccion= (ListaDeL *) malloc (sizeof (ListaDeL));
        inicializacionLista (seccion);
        

        if((fd= fopen(PATH, "rw"))== 0)  //cargar datos en lista, crear archivo y hacer backup
        {
            cargar_lista(seccion);
            
            visualizacionLista(seccion);
            visualizacion (seccion->inicio->ListaMenu);
            
            printf("Cantidad de Secciones: %d\n", seccion->TAM);
            
            fd= fopen(PATH, "w+");
            
            actual = seccion->inicio;
            while (actual != NULL)
            {
                fputs (actual->Nombre, fd);
                fputc (' ',fd);
                aux= actual->ListaMenu->inicio;
                while(aux != NULL)
                {
                    fputs (actual->ListaMenu->inicio->Mercaderia, fd);
                    fputc (' ',fd);
                    fputc ('$',fd);
                    fputs (actual->ListaMenu->inicio->precio, fd);
                    fputc (' ',fd);
                    fputc ('#',fd);
                    fputs (actual->ListaMenu->inicio->id, fd);
                    fputc (' ',fd);
                    aux= aux->siguiente;
                    fputc (' ',fd);
                }
                actual = actual->siguiente;
                fputc ('\n', fd);
            }
        }

        else                            //leer archivo y cargar datos en listas
        {
                fscanf(fd,"%s", buffer);
                lista_inicio(seccion,buffer);
                visualizacionLista(seccion);
                
                if(!strcmp(buffer, "Bebidas"))
                {
                    leer_archivo(fd, seccion);
                }
                
                fscanf(fd,"%s", buffer);
                lista_inicio(seccion,buffer);
                visualizacionLista(seccion);
                
                if(!strcmp(buffer,"Platos"))
                {
                    leer_archivo(fd, seccion);
                }
                
                fscanf(fd,"%s", buffer);
                lista_inicio(seccion,buffer);
                visualizacionLista(seccion);
                
                if(!strcmp(buffer, "Postres"))
                {
                    leer_archivo(fd, seccion);
                }
                
                fscanf(fd,"%s", buffer);
                lista_inicio(seccion,buffer);
                visualizacionLista(seccion);
                
                if(!strcmp(buffer, "Ensaladas"))
                {
                    leer_archivo(fd, seccion);
                }
                
                fscanf(fd,"%s", buffer);
                lista_inicio(seccion,buffer);
                visualizacionLista(seccion);
                
                if(!strcmp(buffer, "MenuEstudiantil"))
                {
                    leer_archivo(fd, seccion);
                }
                
                fscanf(fd,"%s", buffer);
                lista_inicio(seccion,buffer);
                visualizacionLista(seccion);
                
                if(!strcmp(buffer, "MenuDelDia"))
                {
                    leer_archivo(fd, seccion);
                }
                                
        }
        
        fclose(fd);
        return 0;
    }
    
//*********************************************************************
//FUNCION PARA CARGAR LISTA POR CONSOLA

    int cargar_lista(ListaDeL *seccion)
    {
        char nombre[NUM], id[NUM], precio[NUM];
        int  k=1;
        
        while(k==1)
        {
            printf("Nombre de la sección:\t");
            scanf("%s",nombre);
            lista_inicio(seccion,nombre);
            while(k==1)
            {
                printf("Producto:\t");
                scanf("%s", nombre);
                printf("Precio:\t");
                scanf("%s", precio);
                printf("ID:\t");
                scanf("%s", id);
                nodo_inicio (seccion->inicio->ListaMenu,nombre,precio,id);
                printf("¿Agregar más productos? SI: 1   NO: 2\t");
                scanf("%d",&k);
            }
            printf("¿Agregar más secciones? SI: 1   NO: 2\t");
            scanf("%d",&k);
        }
        
    return 0;
    }

//*********************************************************************
//FUNCION PARA CARGAR LISTA POR ARCHIVOS

    int leer_archivo (FILE *fd, ListaDeL *seccion)
    {
        int FLAG=0;
        char nombre[NUM], id[NUM], precio[NUM];
        
        while(FLAG!=1) //cambiarlo por '\n' //NO LLEGA NUNCA A LEER EL FIN!
        {

            fscanf(fd, "%s", nombre);
            fscanf(fd, "%s", precio);
            fscanf(fd, "%s", id);
                                                
            if(!strcmp(nombre,"FIN"))
                    FLAG=1;
                        
            visualizacion (seccion->inicio->ListaMenu);
            nodo_inicio (seccion->inicio->ListaMenu,nombre,precio,id);
            
        }
        
    return 0;
    }

