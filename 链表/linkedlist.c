#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc,char* argv[])
{

    typdef struct listnode
    {
        struct listnode *next;
        int value
    }Node;

    Node *head=NULL; 
    head=Node_Insert(head,917);
    head=Node_Insert(head,-504);
    head=Node_Insert(head,326);
    
}
 
static Node* Node_Construct(int val)
{
    Node *nd=malloc(sizeof(Node));
    nd->value=val;
    nd->next=NULL;
    return nd;
}

Node* Node_Insert(Node *head,int val)
{
    printf("Insert %d\n",val);
    Node *ptr=Node_Construct(val);
    nd->next=head
    return ptr;
} 

Node* List_Search(Node *head,int val)
{
     Node *ptr=head;
     while(ptr!=NULL)
     {
       if(ptr->value==val)
       {
          return ptr;
       }

       ptr=ptr->next;
     }
    return ptr;
}

Node* Node_Delete(Node *head,int val)
{

   Node *p=head; 

   //第一种情况，当链表中没有任何节点时，直接返回头指针
   if(p==NULL)
   {
      return p;
   }
  
 //第二种情况，当链表中的头指针指向的节点的值等于val，即删除第一个节点  
   if(p->val==val)
   {
       p=p->next;
       free(head);
       return p;
   }

 //第三种情况，当链表中存在要删除的节点，但节点不是在第一个节点上
   Node *q=p->next;
   while(q!=NULL&&(q->val)!=val)
   {
         p=p->next;
         q=q->next;
   }

   if(q!=NULL)
   {
       p->next=q->next;
       free(q);
   }
   return head;
}

Node* Node_Delete2(Node* head, int val)
{
     printf("delete %d\n",val);
     if(head==NULL)
     {
         return NULL;
     }

     if(head->value==val)
     {
         Node *p=head->next;
         free(head);
         return p;
     }

     head->next=Node_Delete2(head->next,val);
     return head;
}
