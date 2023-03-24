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
    void traversal(TreeNode* node,int path,vector<int>& res){
        path += node->val;
        if(node->left == NULL && node->right ==NULL){
            res.push_back(path);
        }
        if(node->left) traversal(node->left,path,res);
        if(node->right) traversal(node->right,path,res);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == NULL) return false;
        int path=0;
        vector<int> res;
        traversal(root,path,res);
        for(int i=0;i<res.size();i++){
            if(targetSum == res[i]){
                return true;
            }
        }
        return false;
    }
};
