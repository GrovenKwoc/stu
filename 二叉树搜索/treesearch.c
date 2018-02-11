#include<stdlib.h>
#include"tree.h"

TreeNode * Tree_search(TreeNode *tn,int val)
{
    if(tn==NULL)return NULL;//NOT FOUND
     
    if(val==(tn->value))return tn;
 
    if(val<(tn->value)) return Tree_search(tn->left,val);

    return Tree_search(tn->right,val);
}
