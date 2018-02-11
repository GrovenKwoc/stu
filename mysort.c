//mysort.c
#include<stdio.h>
static void swap(int* a,int* b)
{
  int t=*a;
  *a=*b;
  *b=t;
}

void mysort(int *arr,int len)
{
  //place the smallest value at the beginning

  int ind1;
  int ind2;

  for(ind1=0;ind1<len;ind1++)
  {
    int minind=ind1;
    for(ind2=ind1+1;ind2<len;ind2++)
    {
      if(arr[minind]>arr[ind2])
      {
        minind=ind2;//the index of the smallest value
      }
    }

    if(minind!=ind1)
    {
      //move the smallest value to the right place

      swap(&arr[ind1],&arr[minind]);
    }
  }
}
