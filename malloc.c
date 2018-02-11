#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(void)
{
  int num;
  printf("How many numbers are you going to enter?\n");
  scanf("%d",&num);
  int *arr1=malloc(num*sizeof(int));
  for(int i=0;i<num;i++)
  {
    printf("The %d number is: ",i+1);
    scanf("%d",&arr1[i]);
  }

  int sum=0;
  for(int i=0;i<num;i++)
  {
    sum+=arr1[i]; 
  }

  printf("The average is %f",sum*1.0/num);
  free(arr1);
  return EXIT_SUCCESS;
}
