/*
 * @Author: Antgo99 616677561@qq.com
 * @Date: 2023-03-20 15:29:03
 * @LastEditors: Antgo99 616677561@qq.com
 * @LastEditTime: 2023-03-20 16:43:13
 * @FilePath: \LeetCode\binary_tree\reverse\101.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include<iostream>
#include<vector>
#include<stack>
#include<queue>
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
    bool compare(TreeNode* left,TreeNode* right){
        //首先排除左右节点存在空的情况
        if(left == NULL && right != NULL) return false;
        else if(left != NULL && right == NULL) return false;
        else if(left == NULL && right == NULL) return true;
        else if(left->val != right->val) return false;

        bool outside = compare(left->left,right->right);//左节点的左孩子和右节点的右孩子比较
        bool inside = compare(left->right,right->left);//左节点的右孩子和右节点的左孩子比较
        bool midside = outside & inside;
        return midside;
    }

    bool isSymmetric(TreeNode* root) {
        //递归
        if(root == NULL) return true;
        return compare(root->left,root->right);
    }

    //迭代 用的队列
    bool isSymmetric_2(TreeNode* root){
        if(root == NULL) return true;
        queue<TreeNode*> que;
        que.push(root->left);
        que.push(root->right);

        while(!que.empty()){
            TreeNode* leftNode = que.front();que.pop();
            TreeNode* rightNode = que.front();que.pop();
            if(!leftNode && !rightNode) continue;
            if(!leftNode || !rightNode || leftNode->val != rightNode->val) return false;//左右节点中存在一个不为空的情况和节点值不相等的情况 直接返回false

            que.push(leftNode->left);//左左
            que.push(rightNode->right);//右右
            que.push(leftNode->right);//左右
            que.push(rightNode->left);//右左
        }
        return true;
    }
};
