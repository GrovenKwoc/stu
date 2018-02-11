//decpack.c
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"decpack.h"

DecPack* DecPack_create(int size)
{
    DecPack *dp=malloc(sizeof(DecPack));
    if(dp==NULL)
    {
        return NULL;
    }

    dp->size=size;
    dp->used=0;

    if(size%2==1)size++;
    dp->data =malloc(sizeof(unsigned char)*(size/2));

    if(dp->data==NULL)
    {
      free(dp);
      return NULL;
     }

    return dp;
}


void DecPack_insert(DecPack *dp,int val)
{
    if(dp==NULL)return;
    if(val<0||val>9)return;
    
    int used=dp->used;
    if(used==dp->size)
    {
       unsigned char * newdata= malloc(sizeof(unsigned char)*dp->size);
       int iter;
       for(iter=0;iter<used;iter++)
       {
            newdata[iter/2]=dp->data[iter/2];
       }
       (dp->size)*=2;
       free(dp->data);
       dp->data=newdata;
    }

    if(used%2==0)
    {
        dp->data[used/2]=(val<<4);
    }else
    {
        unsigned char upper=dp->data[used/2]&0XF0;
        dp->data[used/2]=upper+val;
    }
    (dp->used)++;
    
}


int DecPack_delete(DecPack* dp)
{
     if(dp==NULL)return -1;
     if(dp->used==0)return -1;
     
     int val;

     dp->used--;
     int used=dp->used;

     if(used%2==0)val=dp->data[used/2]>>4;
     else val=(dp->data[used/2]) &0X0F;

     return val;  
}

void DecPack_print(DecPack *dp)
{
     if(dp==NULL)return;
     int iter;
     int used=dp->used;
     for(iter=0;iter<used;iter++)
     {
         if(iter%2==0){
            printf("%d",dp->data[iter/2]>>4);
         }else{
            printf("%d",(dp->data[iter/2]&0X0F));
         }
     }

     printf("\n");
}

void DecPack_destroy(DecPack *dp)
{
    if(dp==NULL) return;
    free(dp->data);
    free(dp);

}
