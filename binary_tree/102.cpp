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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> que;
        vector<vector<int>> res;
        if(root != NULL) que.push(root);
        while(!que.empty()){
            int size = que.size();
            vector<int> path;
            for(int i=0;i<size;i++){
                TreeNode* node = que.front();
                que.pop();
                path.push_back(node->val);
                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);
            }
            res.push_back(path);
        }
        return res;
    }

    //递归 在力扣上会超时
    void order(TreeNode* cur,vector<vector<int>>& res,int depth){
        if(cur == NULL) return;
        if(res.size() == depth) res.push_back(vector<int>());
        while(cur != NULL){
            res[depth].push_back(cur->val);
            order(cur->left,res,depth+1);
            order(cur->right,res,depth+1);
        }
    }

    vector<vector<int>> levelOrder_2(TreeNode* root){
        vector<vector<int>> res;
        int depth=0;
        order(root,res,depth);
        return res;
    }
};
