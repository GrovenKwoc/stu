#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char* argv[])
{
  if(argc<2)
  {
   printf("请输入1个以上的数字才能计算平均值");
   return EXIT_FAILURE;
  }

  int* arr2=malloc(argc*sizeof(int));
  if(arr2==NULL)
  {
    printf("malloc fails");
    return EXIT_FAILURE;
  }
  int iter;
  for(iter=1;iter<argc;iter++)
  {
    arr2[iter]=(int)strtol(argv[iter],NULL,10);
  }

  printf("The sum of ");
  int sum=0;
  for(iter=1;iter<argc;iter++)
  {
    printf("%d ",arr2[iter]);
    sum+=arr2[iter];
  }

  printf(" is %d",sum);
  return EXIT_SUCCESS;
}
