#include"bmpfile.h"
#include<stdio.h>
void BMP_color(BMP_Image *img,int clr)
{
   int pxl; 
   for(pxl=clr;pxl<(img->data_size);pxl++)
   {
         if((pxl%3)!=clr)img->data[pxl]=0;
   }
   
} 
int main(int argc,char* argv[])
{
    printf("运行成功");
    BMP_Image *img=BMP_open(argv[1]);
    printf("读取成功");
    BMP_color(img,2);
    printf("改色成功");
    BMP_save(img,argv[2]);
    printf("保存成功");
    BMP_destroy(img);
    return 1;

}
