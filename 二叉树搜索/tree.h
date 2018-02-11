#ifndef TREE_H
#define TREE_H
#include<stdio.h>

typedef struct treenode
{
    struct treenode *left;
    struct treenode *right;
    int value;
}TreeNode;

// 将数值v插到root为根节点的二叉搜索树中
//并返回新的根节点
TreeNode *Tree_insert(TreeNode *root,int v);

//在root为根节点的二叉搜索树中搜索特定值v
//并返回v对应的节点
//没有找到对应节点时返回NULL
TreeNode *Tree_search(TreeNode *root,int v);

//在root为根节点的二叉搜索树中删除节点值为v的节点
//并返回剩下的树的根节点
//当树为空时，返回null
TreeNode *Tree_delete(TreeNode *root,int v);

//遍历输出二叉搜索树中的值
void Tree_print(TreeNode *root);

//删除全部节点
void Tree_destroy(TreeNode *root);

#endif

