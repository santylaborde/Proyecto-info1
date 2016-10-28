#include "header.h"
int login(char *user, char *pass, ALUMNO *h)
{
  ALUMNO *a;
  while(h!='\0')
  {
     if(!strcmp(h->nombre,user))
     {
       if(!strcmp(h->clave,pass))
	 return 0;
     }
     a=h->next;
     h=a; 
  }
  return 1;
}