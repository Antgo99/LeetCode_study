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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        queue<TreeNode*> que;
        if(root != NULL) que.push(root);
        while(!que.empty()){
            int size = que.size();
            double max_level=0;
            for(int i=0;i<size;i++){
                TreeNode* node = que.front();
                que.pop();
                max_level += node->val;
                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);
            }
            res.push_back(max_level / size);
        }
        return res;
    }
};
