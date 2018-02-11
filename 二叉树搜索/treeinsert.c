#include<stdlib.h>
#include"tree.h"

static TreeNode * TreeNode_construct(int val)
{
    TreeNode *tn;
    tn=malloc(sizeof(TreeNode));
    tn->left=NULL;
    tn->right=NULL;
    tn->value=val;
    return tn;
}

TreeNode *Tree_insert(TreeNode *tn,int val)
{
    if(tn==NULL) return TreeNode_construct(val);
    if(val==(tn->value)) return tn;//不插入相同值的节点
    if(val<(tn->value))
    {
        tn->left=Tree_insert(tn->left,val);
    }else 
    {
        tn->right=Tree_insert(tn->right,val);
    }

    return tn;
}
