/*
  读取迷宫文件，并输出迷宫大小，出口，和起点的坐标
*/
#include<stdio.h>
#include<stdlib.h>
int main(int argc,char* argv[])
{
    FILE *fptr;
    int ch;
    int row=0;
    int column=0;
    /*
    int numberBrick=0;
    int exitRow,exitColumn;
    int startRow,startColumn;
    */
    int numberColumn,numberRow;
    int **mazeArr;

    if(argc<2){
        printf("need to provide the file's name.\n");
        return EXIT_FAILURE;
    }

    fptr=fopen(argv[1],"r");
    if(fptr==NULL){
 	printf("file open failed");
	return EXIT_FAILURE;
    }

    numberColumn=0;
    
    do{
       ch=fgetc(fptr);
       /*
       switch(ch)
       {
           case '*':
               numberBrick++;
 	       break;
           case 'E':
               exitRow=row;
               exitColumn=column;
               break;
           case 's':
               startRow=row;
               startColumn=column;
               break;
       }
       */
       if(ch!=EOF)
       {
           if(ch=='\n')
           {
              row++;
              numberColumn=column;
              column=0;
           }
           else{
              column++;
           }
       }
    }while(ch!=EOF);

    numberRow=row;
    mazeArr=malloc(numberRow*sizeof(int *));
    for(row=0;row<numberRow;row++)
    {
        mazeArr[row]=malloc(numberColumn*sizeof(int));
    }
    fseek(fptr,0,SEEK_SET);

    row=0;
    column=0;

    do{
        ch=fgetc(fptr);
        if(ch!=EOF)
        {
             if(ch=='\n')
             {
                  row++;
                  column=0;
             }else
             {
                  mazeArr[row][column]=ch;
                  column++;
             }
        }
    }while(ch!=EOF);

    fclose(fptr);
    printf("The mazeArr has %d rows and %d columns.\n",numberRow,numberColumn);
    /*printf("The file has %d bricks.\n",numberBrick);
    printf("The exit is at (%d,%d).\n",exitRow,exitColumn);
    printf("The starting location is at (%d,%d).\n",startRow,startColumn);
    */

    for(row=0;row<numberRow;row++)
    {
         for(column=0;column<numberColumn;column++)
         {
              printf("%c",mazeArr[row][column]);
 
         }
        printf("\n");
 
    } 

    for(row=0;row<numberRow;row++)
    {
           free(mazeArr[row]);
    }
     
    free(mazeArr);
    return EXIT_SUCCESS;
}


