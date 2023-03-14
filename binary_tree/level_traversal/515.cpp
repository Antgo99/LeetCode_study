/*
    20230313
    最大值的初始值设置为int类型的最小值即可，INT_MIN
*/
#include<iostream>
#include<queue>
#include<vector>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};

class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        queue<TreeNode*> que;
        vector<int> res;
        if(root != NULL) que.push(root);
        while(!que.empty()){
            int size = que.size();
            int max = INT32_MIN;
            for(int i=0;i<size;i++){
                TreeNode* node = que.front();
                que.pop();
                if(max < node->val) max = node->val;
                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);
            }
            res.push_back(max);
        }
        return res;
    }
};
