#include<stdlib.h>
#include<stdio.h>

int main(int argc,char *argv[])
{
    unsigned char a=5;//0000 0101
    int b=4;//0000 0100

    printf("%d",a^b);//1;
}

