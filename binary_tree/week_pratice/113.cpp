/*
 * @Author: Antgo99 616677561@qq.com
 * @Date: 2023-03-21 15:44:43
 * @LastEditors: Antgo99 616677561@qq.com
 * @LastEditTime: 2023-03-21 20:31:11
 * @FilePath: \LeetCode\binary_tree\week_practice\113.cpp
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
    vector<vector<int>> res;
    vector<int> path;
    void traversal(TreeNode* node,int pathSum){
        if(node->left == NULL && node->right == NULL && pathSum == 0){
            res.push_back(path);
        }

        if(node->left){
            path.push_back(node->left->val);
            pathSum -= node->left->val;
            traversal(node->left,pathSum);
            pathSum += node->left->val;//回溯
            path.pop_back();//回溯
        }

        if(node->right){
            path.push_back(node->right->val);
            pathSum -= node->right->val;
            traversal(node->right,pathSum);
            pathSum += node->right->val;//回溯
            path.pop_back();//回溯
        }
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(root == NULL) return res;
        path.push_back(root->val);
        traversal(root,targetSum - root->val);
        return res;
    }
};
