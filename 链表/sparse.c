//sparse.c
#include<stdio.h>
#include<stdlib.h>
#include"sparse.h"

static Node* Node_create(int ind,int val);
static Node* List_insert(Node *head,int ind,int val);
static Node* List_copy(Node *head);
Node* List_read(char *filename)
{
    FILE *fptr=fopen(filename,"r");
    if(fptr==NULL)return NULL;
    int ind;
    int cal;
    Node *head=NULL;
    while(fscanf(fptr,"%d %d",&ind,&val)==2)
    {
        head=List_insert(head,ind,val);
    }

    fclose(fptr);
    return head;
}

int List_save(char* filename,Node *arr)
{
    FILE *fptr=fopen(filename,"w");
    if(fptr==NULL)
    {
        return 0;
    }  
    while(arr!=NULL)
    {
         fprintf(fptr,"%d %d\n",arr->index,arr->value);
         arr=arr->next;
    }
    fclose(fptr);
    return 1;   
}

Node* List_merge(Node* arr1,Node* arr2)
{
    Node *arr3=List_copy(arr1);
    while(arr2!=NULL)
    {
         arr3=List_insert(arr2,arr2->index,arr2->value);
         arr2=arr2->next;
    }

    return arr3;
}

void List_destroy(Node *arr)
{
   if(arr==NULL)return;
   while(arr!=NULL)
   {
      Node *ptr=arr->next;
      free(arr);
      arr=ptr;
   }

}

static Node* Node_create(int ind,int val)
{
    Node *nd=malloc(sizeof(Node));
    if(nd==NULL)
    {
       return NULL;
    }

    nd->index=ind;
    nd->value=val;
    nd->next=NULL;

    return nd;
}

static Node* List_insert(Node *head,int ind,int val)
{
    if(val==0)
    {
       return head;
    }

    if(head==NULL)
    {
      return Node_create(ind,val);
    }

    if((head->index)>ind)
    { 
        Node *ptr=Node_create(ind,val);
        ptr->next=head;
        return ptr;
    }

    if((head->index)==ind)
    {
        head->value+=val;
        if((head->value)==0)
        {
            Node *ptr=head->next;
            free(head);
            return ptr;
        }
        return head;
    }

    head->next=List_insert(head->next,ind,val);
    return head;
}   

Node *List_copy(Node *arr)
{
    Node *arr2=NULL;
    while(arr!=NULL)
    {
        arr2=List_insert(arr2,arr->index,arr->value);
        arr=arr->next;
    }
    return arr2;
}
