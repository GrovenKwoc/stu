//person.c
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"person.h"

PersonDatabase* Person_read(char* filename)
{
    FILE *fptr=fopen(filename,"r");
    if(fptr==NULL)
    {
      printf("file open fail\n");
      return NULL;
    }
    
    PersonDatabase *perdb=malloc(sizeof(PersonDatabase));
    if(perdb==NULL)
    {
        fclose(fptr);
        return NULL;
    }

    int numPerson=0;
    int longestName=0;
    
    while(!feof(fptr))
    {
       int age;
       if(fscanf(fptr,"%d",&age)==1)
       {
           numPerson++;
           int nameLength=0;
           while((!feof(fptr))&& (fgetc(fptr)!='\n'))
           {
                nameLength++;
           }

           nameLength++;

           if(longestName<nameLength)
           {
               longestName=nameLength;
           }
       }
    }

    perdb->number=numPerson;
    perdb->person=malloc(sizeof(Person*)*numPerson);

    char* name=malloc(sizeof(char)*longestName);

    int ind=0;

    fseek(fptr,0,SEEK_SET);

    while(!feof(fptr))
    {
         int age;
         if(fscanf(fptr,"%d",&age)==1)
         {
             fgetc(fptr);
             fgets(name,longestName,fptr);
             
             char *chptr=strchr(name,'\n');
             if(chptr!=NULL)
             {
                *chptr='\0';
             }
             perdb->person[ind]=malloc(sizeof(Person));
             perdb->person[ind]->age=age;

             perdb->person[ind]->name=strdup(name);
             ind++;
         }
    }

    free(name);
    fclose(fptr);
    return perdb;
}


static void Person_writeHelp(FILE *fptr,PersonDatabase *perdb)
{
     int ind;
     for(ind=0;ind<perdb->number;ind++)
     {
         fprintf(fptr,"%d %s\n",perdb->person[ind]->age,perdb->person[ind]->name);
     }
}


void Person_print(PersonDatabase* perdb)
{
     printf("-------------------------------------------------\n");
     Person_writeHelp(stdout,perdb);
}


int Person_write(char *filename,PersonDatabase *perdb)
{
     if(perdb==NULL)
     {
         return 0;
     }

     FILE *fptr=fopen(filename,"w");
     if(fptr==NULL)
     {
         return 0;
     }

     Person_writeHelp(fptr,perdb);
     fclose(fptr);
     return 1;
}



static int compareByName(const void *p1,const void *p2)
{
    const Person ** pp1=(const Person **)p1;
    const Person ** pp2=(const Person **)p2;

    const Person const *pv1=*pp1;
    const Person const *pv2=*pp2;

    return strcmp(pv1->name,pv2->name);

}



void Person_sortByName(PersonDatabase* perdb)
{
    qsort(perdb->person,perdb->number,sizeof(Person*),compareByName);
}

static int compareByAge(const void *p1,const void *p2)
{
    const Person **pp1=(const Person**)p1;
    const Person **pp2=(const Person**)p2;

    const Person * pv1=*pp1;
    const Person * pv2=*pp2;
    return ((pv1->age)-(pv2->age));
}

void Person_sortByAge(PersonDatabase *perdb)
{
   qsort(perdb->person,perdb->number,sizeof(Person*),compareByAge);
}

void Person_destruct(PersonDatabase *perdb)
{
    int ind;
    for(ind=0;ind<perdb->number;ind++)
    {
      free(perdb->person[ind]->name);
      free(perdb->person[ind]);
    }
    free(perdb->person);
    free(perdb);
}
