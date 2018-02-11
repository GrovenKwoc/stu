#include<stdlib.h>
#include"tree.h"
TreeNode *Tree_delete(TreeNode* tn,int val)
{
    if(tn==NULL)return NULL;
    if(val<(tn->value))
    {
        tn->left=Tree_delete(tn->left,val);
        return tn;
    }

     if(val>(tn->value))
    {
        tn->right=Tree_delete(tn->right,val);
        return tn;
    }

    if((tn->left)==NULL&&(tn->right)==NULL)
    {
       free(tn);
       return NULL;
    }

    if((tn->left)==NULL)
    {
        TreeNode *rc=tn->right;
        free(tn);
        return rc;
    }

    if((tn->right)==NULL)
    {
        TreeNode *lc=tn->left; 
        free(tn);
        return lc;
    }

    TreeNode *su=tn->right;
    while((su->left)!=NULL)
    {
        su=su->left;
    }
    tn->value=su->value;
    su->value=val;
    tn->right=Tree_delete(tn->right,val);
    return tn;
}
