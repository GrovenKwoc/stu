#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int comparestrp(const void *arg1,const void *arg2);

int main(int argc,char *argv[])
{
   int ar;
   if(argc<2)
   {
   fprintf(stderr,"Usage: %s <string>...\n",argv[0]);
   return EXIT_FAILURE;
   }

   qsort(&argv[0],argc,sizeof(char*),comparestrp);
   
   for(ar=0;ar<argc;ar++)
   {
      printf("%s\n",argv[ar]);
   }
   return EXIT_SUCCESS;
}

int comparestrp(const void *arg1,const void *arg2)
{
   const char* const *ptr1=(const char**)arg1;
   const char* const *ptr2=(const char**)arg2;
   const char *str1=*ptr1;
   const char *str2=*ptr2;
   return strcmp(str1,str2);

   
}

