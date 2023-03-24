/*
 * @Author: Antgo99 616677561@qq.com
 * @Date: 2023-03-22 16:49:44
 * @LastEditors: Antgo99 616677561@qq.com
 * @LastEditTime: 2023-03-22 20:46:04
 * @FilePath: \LeetCode\binary_tree\week_practice\669.cpp
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
        如果当前节点的值小于low，则需要将其左子树全部剪掉；
        同理，如果当前节点的值大于high，则需要将其右子树全部剪掉。
        对于剩余的节点，需要递归地对其左右子树进行修剪。修剪后的左右子树成为当前节点的新左右子树，然后返回当前节点即可。
    */
    TreeNode* deleteNode(TreeNode* node,int low,int high){
        if(node == NULL) return node;
        if(node->val < low){//删掉左子树 并且递归解决右子树中不满足的情况
            return deleteNode(node->right,low,high);
        }
        if(node->val > high){//删掉右子树 并且递归解决左子树中不满足的情况
            return deleteNode(node->left,low,high);
        }
        node->left = deleteNode(node->left,low,high);
        node->right = deleteNode(node->right,low,high);
        return node;
    }
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        return deleteNode(root,low,high);
    }
};
