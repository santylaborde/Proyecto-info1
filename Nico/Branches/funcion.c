#include "header.h"
int login(char*user, ALUMNO*h, char*pass)
{
  ALUMNO *a;
  while(h!=NULL)
  {
     if(!strcmp(h->nombre,user))
       return 0;
     a=h->next;
     h=a; 
  }
  return 1;
}