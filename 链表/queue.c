#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
     int value;
     struct Node* next; 
}Node;

int main(int argc,char* argv[])
{
       
}

/*栈结构的插入方法（先进后出）
Node* List_insert(Node *head,int val)
{
    Node* p=Node_construct(val);
    p->next=head;
    return p;
}
*/

//队列结构的插入方法（先进先出）
Node* List_insert(Node *head,int val)
{
    if(head==NULL)
    {
     return Node_construct(val);
    }
 
    head->next=List_insert(head->next,val);   
   
}

Node* Node_construct(int val)
{
    Node* ptr=malloc(sizeof(Node));
    ptr->value=val;
    ptr->next=NULL;
    return ptr;
}
