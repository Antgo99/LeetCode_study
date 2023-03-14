/*
    20230313
    找到离根节点最近的叶子结点，即叶子结点的左孩子和右孩子都为空
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
    int minDepth(TreeNode* root) {
        int min_depth=0;
        queue<TreeNode*> que;
        if(root != NULL) que.push(root);
        while(!que.empty()){
            int size = que.size();
            min_depth++;
            for(int i=0;i<size;i++){
                TreeNode* node = que.front();
                que.pop();
                if(node->left == NULL && node->right == NULL){
                    return min_depth;
                }
                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);
            }
        }
        return min_depth;
    }
};
