#include "header.h"
int login(char *user, char *pass, ALUMNO *h)
{
  ALUMNO *a;
  while(h!=NULL)
  {
     if(!strcmp(h->nombre,user))
     {
       if(!strcmp(h->nombre,pass))
	 return 0;
     }
     a=h->next;
     h=a; 
  }
  return 1;
}