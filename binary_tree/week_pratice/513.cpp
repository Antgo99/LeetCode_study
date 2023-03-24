/*
 * @Author: Antgo99 616677561@qq.com
 * @Date: 2023-03-21 14:42:37
 * @LastEditors: Antgo99 616677561@qq.com
 * @LastEditTime: 2023-03-21 15:29:57
 * @FilePath: \LeetCode\binary_tree\week_practice\513.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<math.h>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};

class Solution {
public:
    //自己是用层次遍历写的，代码有点冗余
    int findDepth(TreeNode* node,int depth){
        queue<TreeNode*> que;
        if(node != NULL) que.push(node);
        while(!que.empty()){
            int size = que.size();
            depth++;
            for(int i=0;i<size;i++){
                TreeNode* cur = que.front();
                que.pop();
                if(cur->left) que.push(cur->left);
                if(cur->right) que.push(cur->right);
            }
        }
        return depth;
    }
    int findBottomLeftValue(TreeNode* root) {
        if(root->left == NULL && root->right == NULL) return root->val;
        int depth = findDepth(root,1);
        int leftDepth = 1;
        int leftValue = INT_MAX;
        queue<TreeNode*> que;
        if(root != NULL) que.push(root);
        while(!que.empty()){
            int size = que.size();
            leftDepth++;
            for(int i=0;i<size;i++){
                TreeNode* cur = que.front();
                que.pop();
                if(cur->left == NULL && cur->right == NULL && leftDepth == depth){
                    leftValue = cur->val;
                    break;
                }
                if(cur->left) que.push(cur->left);
                if(cur->right) que.push(cur->right);
                // if(cur->left){
                //     if(cur->left->left == NULL && cur->left->right == NULL && leftDepth + 1 == depth){
                //         leftValue =  cur->left->val;
                //         break;
                //     }
                //     que.push(cur->left);
                // }
                // if(cur->right){
                //     if(cur->right->left == NULL && cur->right->right == NULL && leftDepth + 1 == depth){
                //         leftValue =  cur->right->val;
                //         break;
                //     }
                //     que.push(cur->right);
                // }
            }
            if(leftValue != INT_MAX) break;
        }
        return leftValue;
    }

    //递归
    int maxDepth = INT_MIN;
    int res;
    void traversal(TreeNode* node,int depth){
        //找到叶子结点
        if(node->left == NULL && node->right == NULL){
            if(depth > maxDepth){
                maxDepth = depth;
                res = node->val;
            }
        }

        if(node->left) traversal(node->left,depth+1);
        if(node->right) traversal(node->right,depth+1);
    }

    int findBottomLeftValue_2(TreeNode* root){
        traversal(root,0);
        return res;
    }

    //迭代
    int findBottomLeftValue_3(TreeNode* root){
        queue<TreeNode*> que;
        int res;
        if(root != NULL) que.push(root);
        while(!que.empty()){
            int size = que.size();
            for(int i=0;i<size;i++){
                TreeNode* cur = que.front();
                que.pop();
                if(i == 0) res = cur->val;//最后一行的第一个元素
                if(cur->left) que.push(cur->left);
                if(cur->right) que.push(cur->right);
            }
        }
        return res;
    }
};
