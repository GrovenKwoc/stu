#include<stdio.h>
#include<stdlib.h>

int main(int argc,char* argv[])
{
    int arr[]={1,5,9,10,8,7,4,23};
    int i;
    for(i=0;i<8;i++)
    {
        printf("%d ",arr[i]);
    }

    printf("\n");

    for(i=0;i<7;i++)
    {
       for(int j=0;j<6-i;j++)
       {
          if(arr[j]>arr[j+1])
          {
              int temp=arr[j];
              arr[j]=arr[j+1];
              arr[j+1]=temp;
          }
       }
    }

    for(i=0;i<8;i++)
    {
        printf("%d ",arr[i]);
    }

    return EXIT_SUCCESS;
}
