#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};

class Solution {
public:
    /*
        通过递归的方式在二叉搜索树中插入一个新节点。
        从根节点开始，若新节点的值小于当前节点的值，则在当前节点的左子树中继续查找；
        若新节点的值大于当前节点的值，则在当前节点的右子树中继续查找；
        直到找到一个空节点，将新节点插入该空节点位置。
    */
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == NULL) return new TreeNode(val);
        if(root->val > val) root->left = insertIntoBST(root->left,val);
        if(root->val < val) root->right = insertIntoBST(root->right,val);
        return root;
    }
};
