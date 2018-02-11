//redirect.c
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "mysort.h"

int main(int argc,char** argv)
{
  if(argc!=2)
  {
    printf("only one argument accepted");
    return EXIT_FAILURE;
  }

  int number=strtol(argv[1],NULL,10);
  int ind;
  for(ind=0;ind<number;ind++)
  {
    int val;
    scanf("%d",&val);
    printf("%d\n",val);
  }
}
