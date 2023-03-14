/*
    20230313
*/
#include<iostream>
#include<queue>
#include<vector>
#include<stack>
#include<algorithm>

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
    //层次遍历
    TreeNode* invertTree(TreeNode* root) {
        queue<TreeNode*> que;
        if(root != NULL) que.push(root);
        while(!que.empty()){
            TreeNode* node;
            TreeNode* node_tmp;
            int size = que.size();
            for(int i=0;i<size;i++){
                node = que.front();
                que.pop();
                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);
                node_tmp = node->left;
                node->left = node->right;
                node->right = node_tmp;
            }
        }
        return root;
    }

    //迭代遍历
    TreeNode* invertTree_iterate(TreeNode* root){
        stack<TreeNode*> st;
        if(root != NULL) st.push(root);
        while(!st.empty()){
            TreeNode* node = st.top();
            if(node != NULL){
                st.pop();
                if(node->right) st.push(node->right);//右
                if(node->left) st.push(node->left);//左
                st.push(node);//中
                st.push(NULL);
            }else{
                st.pop();
                node = st.top();
                st.pop();
                swap(node->left,node->right);
            }
        }
        return root;
    }
};
