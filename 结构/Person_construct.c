#include"person.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

Person * Person_construct(int y,int m,int d,char* n)
{
    Person *p=NULL;
    p=malloc(sizeof(Person));
    if(p==NULL)
    {
       printf("分配失败");
       return NULL;
    }
    p->year=y;
    p->month=m;
    p->date=d;
    p->name=malloc(sizeof(char)*(strlen(n)+1));

    if((p->name)==NULL)
    {
      free(p);
      printf("name属性分配失败");
      return NULL;
    }

    strcpy(p->name,n);
    return p;
}
