//mystring.c
#include "mystring.h"
#include <stdlib.h>
#include <ctype.h>

int my_strlen(const char* str)
{
  if(str==NULL)
    {
     return EXIT_FAILURE;
    }
  
  int count=0;
  while(*str!='\0')
   {
     count++;
     str++;
   }

   return count;
  
}


int my_countchar(const char* str,char c)
{
  int count=0;
  while(*str!='0')
   {
     if(*str==c)
      {
        count++;
      }
     str++;
   }

   return count;
}


void my_strupper(char *str)
{
  while(*str!='\0')
   {
     *str=toupper(*str);
     str++;
   }

}

char* my_strchr(const char* str,char ch)
{
  while(*str!='\0'){
     if(*str==ch){
       return str;
     }
     str++;
  }
  return NULL;
}



