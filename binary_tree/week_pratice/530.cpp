/*
 * @Author: Antgo99 616677561@qq.com
 * @Date: 2023-03-22 14:21:03
 * @LastEditors: Antgo99 616677561@qq.com
 * @LastEditTime: 2023-03-22 14:29:10
 * @FilePath: \LeetCode\binary_tree\week_practice\530.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};

class Solution {
public:
    vector<int> res;
    void traversal(TreeNode* root){
        if(root == NULL) return;
        traversal(root->left);
        res.push_back(root->val);
        traversal(root->right);
    }
    int getMinimumDifference(TreeNode* root) {
        traversal(root);
        int min_difference = INT_MAX;
        for(int i=1;i<res.size();i++){
            if(res[i] - res[i-1] < min_difference) min_difference = res[i] - res[i-1];
        }
        return min_difference;
    }
};
