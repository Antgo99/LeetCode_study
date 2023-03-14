/*
    20230313
    没什么特色
*/
#include<iostream>
#include<queue>
#include<vector>

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
    int maxDepth(TreeNode* root) {
        int depth=0;
        queue<TreeNode*> que;
        if(root != nullptr) que.push(root);
        while(!que.empty()){
            int size = que.size();
            for(int i=0;i<size;i++){
                TreeNode* node = que.front();
                que.pop();
                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);
            }
            depth++;
        }
        return depth;
    }
};
