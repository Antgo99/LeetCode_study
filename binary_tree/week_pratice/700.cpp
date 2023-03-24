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
    TreeNode* searchBST(TreeNode* root, int val) {
        //递归
        //终止条件
        if(root == NULL || root->val == val) return root;
        //单层递归逻辑
        TreeNode* result = NULL;
        if(root->val > val) result = searchBST(root->left,val);
        if(root->val < val) result = searchBST(root->right,val);
        return result;
    }

    //迭代法
    TreeNode* searchBST(TreeNode* root, int val){
        while(root != NULL){
            if(root->val > val) root = root->left;
            else if(root->val < val) root = root->right;
            else return root;
        }
        return NULL;
    }
};
