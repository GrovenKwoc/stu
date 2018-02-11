#include"bmpheader.h"
#include<stdlib.h>
#include<stdio.h>
int main(int argc,char** argv)
{
   FILE *fptr=fopen(argv[1],"r");
   if(fptr==NULL)return EXIT_FAILURE;

   BMP_Header header;
   if(fread(&header,sizeof(BMP_Header),1,fptr)!=1)
   {
       printf("BMP元数据读取失败");
   }

   	printf("%x\n",header.type);
	printf("%x\n",header.compression);
	printf("%x\n",header.planes);
        printf("%x\n",header.size);
        printf("%d\n",header.imagesize);

   return EXIT_SUCCESS;
}
