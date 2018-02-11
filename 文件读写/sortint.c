//sortint.c
#include<stdio.h>
#include<stdlib.h>
int comparefunc(const void* arg1,const void* arg2)
{
    const int* ptr1=(const int*)arg1;
    const int* ptr2=(const int*)arg2;
    const int val1=*ptr1;
    const int val2=*ptr2;

    if(val1<val2) return -1;
    if(val1==val2) return 0;
    return 1;
    
}

int main(int argc,char* argv[])
{
    if(argc!=3)   return EXIT_FAILURE;
     
    FILE *inf;
    inf=fopen(argv[1],"r");
    if(inf==NULL) return EXIT_FAILURE;
    
    int int_count=0,val;
    while(fscanf(inf,"%d",&val)==1)
    {
        int_count++;
    }

    int *arr;
    arr=malloc(int_count*sizeof(int));
    if(arr==NULL)
    {
      fclose(inf);
      return EXIT_FAILURE;
    }

    fseek(inf,0,SEEK_SET);
    
    int ind=0;
    while(fscanf(inf,"%d",&val)==1)
    {
      arr[ind]=val;
      ind++;
    }

    qsort(&arr[0],int_count,sizeof(int),comparefunc);

    fclose(inf);
     
    FILE *outf;
    outf=fopen(argv[2],"w");
    if(outf==NULL)
    {
    free(arr);
    return EXIT_FAILURE;
    }
    
    for(ind=0;ind<int_count;ind++)
    {
      fprintf(outf,"%d\n",arr[ind]);
    }

    fclose(outf);
    free(arr);
    return EXIT_SUCCESS;

}
