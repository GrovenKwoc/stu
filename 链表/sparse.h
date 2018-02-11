//sparse.h
#ifndef SPARSE_H
#define SPARSE_H
typedef struct linked{
    int index;
    int value;
    struct linked *next;
}Node;

//从文件中读取稀疏数组并将数组返回
//读取失败时返回NULL
Node* List_read(char *filename);

//将稀疏数组写入文件
//成功写入时返回1,否则返回0
int List_save(char* filename,Node *arr);

//将两个数组融合
//两个输入的数组不变
//而新生成的数组不占用两个输入数组的内存
Node *List_merge(Node *arr1,Node *arr2);

//释放数组的所有节点
void *List_destroy(Node *arr);

#endif
