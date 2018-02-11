//bmpfile.h
#ifndef _BMPFILE_H_
#define _BMPFILE_H_
#include "bmpimage.h"

//通过给定文件名打开BMP文件
//如果打开成功返回一个指向B<MP图像的指针
//如果失败返回空指针
BMP_Image* BMP_open(const char *filename);

//将BMP文件保存成指定的名称
//如果失败返回0
//如果成功返回1
int BMP_save(const BMP_Image *image,const char *filename);

//释放BMP结构体的内存
void BMP_destroy(BMP_Image *image);
#endif
