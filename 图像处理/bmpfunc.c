//bmpfunc.c
#include<stdio.h>
#include<stdlib.h>
#include"bmpfile.h"

#define MAGIC_VALUE 0X4D42
#define BITS_PER_PIXEL 24
#define NUM_PLANE 1
#define COMPRESSION 0
#define BITS_PER_BYTES 8

//如果头文件是无效的，返回0
//如果头文件是有效的，返回1
static int checkHeader(BMP_Header *hdr)
{
    if((hdr->type)!=MAGIC_VALUE)return 0;
    if((hdr->bits)!=BITS_PER_PIXEL) return 0;
    if((hdr->planes)!=NUM_PLANE)return 0;
    if((hdr->compression)!=COMPRESSION)return 0;

    return 1;
}


//关闭打开的文件并释放内存
BMP_Image *cleanUp(FILE *fptr,BMP_Image *img)
{
    if(fptr!=NULL)
    {
        fclose(fptr);
    }

    if(img!=NULL)
    {
        if((img->data)!=NULL)
        {
             free(img->data);
        }
      free(img);
    }
 return NULL;
}


BMP_Image *BMP_open(const char *filename)
{
    FILE *fptr=NULL;
    BMP_Image *img=NULL;
    fptr=fopen(filename,"r");
    if(fptr==NULL){

        return cleanUp(fptr,img);
    }

    img=malloc(sizeof(BMP_Image));
    if(img==NULL)
    {
        return cleanUp(fptr,img);
    }

    if(fread(&(img->header),sizeof(BMP_Header),1,fptr)!=1) return cleanUp(fptr,img);

    if(checkHeader(&(img->header))==0) return cleanUp(fptr,img);

    img->data_size=(img->header).size-sizeof(BMP_Header);
    img->width=(img->header).width;
    img->height=(img->header).height;
    img->bytes_per_pixel=(img->header).bits/BITS_PER_PIXEL;

    img->data=malloc(sizeof(unsigned char)*(img->data_size));

    if(img->data==NULL)return cleanUp(fptr,img);

    if(fread(img->data,sizeof(char),img->data_size,fptr)!=(img->data_size))return cleanUp(fptr,img);

    char onebyte;
    if(fread(&onebyte,sizeof(char),1,fptr)!=0) return cleanUp(fptr,img);

    fclose(fptr);
    return img;   
}  

int  BMP_save(const BMP_Image *img,const char *filename)
{
     FILE *fptr=NULL;
     fptr=fopen(filename,"w");
     if(fptr==NULL) return 0;
     
     if(fwrite(&(img->header),sizeof(BMP_Header),1,fptr)!=1)
     {
           fclose(fptr);
           return 0;
     }
    
     if(fwrite(&(img->data),sizeof(char),img->data_size,fptr)!=(img->data_size))
     {
          fclose(fptr);
          return 0;
     }

     fclose(fptr);
     return 1;
}


void BMP_destroy(BMP_Image *img)
{
         free(img->data);
         free(img);
}

