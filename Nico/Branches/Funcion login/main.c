#include "header.h"
int main(void)
{
  ALUMNO *aux, *h=NULL, *last;
  char user[TAM];
  char pass[TAM];
  int i;
  printf("Carga de lista de usuarios\n");
  for(i=0;i<3;i++)
  {
    aux=(ALUMNO *)malloc(sizeof(ALUMNO));
    printf("ingrese usuario:");
    scanf("%s",aux->nombre);
    //printf("ingrese clave:");
    //scanf("%s",aux->clave);
    aux->next=NULL;
    if(h==NULL)
      h=aux;
    else
      last->next=aux;
    last=aux;
  }
  printf("usuario:");
  scanf("%s",user);
  printf("clave:");
  scanf("%s",pass);
  i=login(user,pass,h);
  if(i==0)
    printf("Bienvenido\n");
  else
    printf("Usuario o clave incorrecta\n");
  exit(0);
}
