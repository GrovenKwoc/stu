#include<stdio.h>
#include<stdlib.h>

int main(int argc,char* argv[])
{
    int arr[]={1,7,9,5,3,11,453,87};
    int i,j;
    for(i=0;i<8;i++)
    {
       printf("%d ",arr[i]);
    }

    printf("\n");

    for(i=0;i<8;i++)
    {
       int minind=i;
       for(j=i+1;j<8;j++)
       {
           if(arr[minind]>arr[j])
           {
              minind=j;
           }
       }
       
       if(minind!=i)
       {
         int temp=arr[i];
         arr[i]=arr[minind];
         arr[minind]=temp;
       }
    }

     for(i=0;i<8;i++)
    {
       printf("%d ",arr[i]);
    }

    printf("\n");

    return EXIT_SUCCESS;
}
