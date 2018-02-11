#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct
{
  unsigned char *data;
  int size;
  int used;
}DecPack;



DecPack* DecPack_create(int size)
{
  DecPack* dp=malloc(sizeof(DecPack));
  if(dp==NULL) return NULL;
  if(size<=0)return NULL;

  dp->size=size;
  dp->used=0;
  if(size&1==1)size++;
  
  dp->data=malloc(sizeof(unsigned char)*(size>>1));
  if(data==NULL){
        free(dp);
        return NULL;
  }

  return dp;
}


void DecPack_insert(DeckPack *dp,int num)
{
    if(dp==NULL)return;
    if(num<0||num>9)return;
    int used=dp->used;
    if(used>=dp->size)
    {
         unsigned char *newchar =malloc(sizeof(unsigned char)*size);
         int iter;
         for(iter=0;iter<dp->used;iter++)
         {
            newchar[iter>>1]=dp->data[iter>>1];
         }
         dp->size<<1;
         free(dp->data);
         dp->data=newchar;
    }

    if(used&1!=0)
    {
         unsigned char top4=dp->data[used>>1]&0xF0;
         dp->data[used>>1]=top4+num;
  
    }else
    {
         dp->data[used>>1]&=0;
         dp->data[used>>1]=val<<4;
    }

    dp->used++;

}
