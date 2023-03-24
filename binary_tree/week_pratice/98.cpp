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
    //一颗二叉搜索数在中序遍历下是按顺序输出的，且还是升序
    vector<int> res;
    void traversal(TreeNode* root){
        if(root == NULL) return;
        traversal(root->left);
        res.push_back(root->val);
        traversal(root->right);
    }
    bool isValidBST(TreeNode* root) {
        traversal(root);
        for(int i=1;i<res.size();i++){
            if(res[i] <= res[i-1]) return false;
        }
        return true;
    }
};
