/*
 * @Author: Antgo99 616677561@qq.com
 * @Date: 2023-03-21 14:33:52
 * @LastEditors: Antgo99 616677561@qq.com
 * @LastEditTime: 2023-03-21 14:41:27
 * @FilePath: \LeetCode\binary_tree\week_practice\404.cpp
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
    int sumOfLeftLeaves(TreeNode* root) {
        queue<TreeNode*> que;
        int leftSum = 0;
        if(root != NULL) que.push(root);
        while(!que.empty()){
            int size = que.size();
            for(int i=0;i<size;i++){
                TreeNode* node = que.front();
                que.pop();
                if(node->left){
                    que.push(node->left);
                    if(node->left->left == NULL && node->left->right == NULL) leftSum += node->left->val;//找到左子叶节点即可
                }
                if(node->right) que.push(node->right);
            }
        }
        return leftSum;
    }
};
