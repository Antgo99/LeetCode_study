/*
 * @Author: Antgo99 616677561@qq.com
 * @Date: 2023-03-22 15:14:28
 * @LastEditors: Antgo99 616677561@qq.com
 * @LastEditTime: 2023-03-22 15:46:01
 * @FilePath: \LeetCode\binary_tree\week_practice\236.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};

class Solution {
public:
    /*
        chatgpt思路：1.首先，从根节点开始遍历二叉树。
                    2.如果当前节点为null，返回null。
                    3.如果当前节点为p或q，则返回当前节点。
                    4.递归左子树，返回左子树中p、q的最近公共祖先。
                    5.递归右子树，返回右子树中p、q的最近公共祖先。
                    6.如果左子树返回的结果为null，说明p、q均不在左子树中，返回右子树的结果。
                    7.如果右子树返回的结果为null，说明p、q均不在右子树中，返回左子树的结果。
                    8.如果左右子树均不为null，说明p、q分别在左右子树中，当前节点即为最近公共祖先，返回当前节点。

        自底向上查找公共祖先
        二叉树利用回溯进行自底向上的查找
        而后序遍历就是天然的回溯过程
    */
    TreeNode* traversal(TreeNode* root, TreeNode* p, TreeNode* q){
        TreeNode* left;
        TreeNode* right;
        if(root == NULL || root == p || root == q) return root;

        left = traversal(root->left,p,q);
        right = traversal(root->right,p,q);
        if(left == NULL) return right;
        if(right == NULL) return left;
        return root;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return traversal(root,p,q);
    }
};
