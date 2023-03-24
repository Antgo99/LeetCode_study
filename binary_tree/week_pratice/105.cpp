/*
 * @Author: Antgo99 616677561@qq.com
 * @Date: 2023-03-21 21:15:44
 * @LastEditors: Antgo99 616677561@qq.com
 * @LastEditTime: 2023-03-21 21:37:26
 * @FilePath: \LeetCode\binary_tree\week_practice\105.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
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
    TreeNode* traversal(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size() == 0) return NULL;

        int rootValue = preorder[0];
        TreeNode* root = new TreeNode(rootValue);

        int index;
        for(index=0;index<inorder.size();index++){
            if(inorder[index] == rootValue) break;
        }

        vector<int> leftinorder(inorder.begin(),inorder.begin()+index);
        vector<int> rightinorder(inorder.begin()+index+1,inorder.end());

        vector<int> leftpreorder(preorder.begin()+1,preorder.begin()+1+leftinorder.size());
        vector<int> rightpreorder(preorder.begin()+1+leftinorder.size(),preorder.end());

        root->left = traversal(leftpreorder,leftinorder);
        root->right = traversal(rightpreorder,rightinorder);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size() == 0 || inorder.size() == 0) return NULL;
        return traversal(preorder,inorder);
    }
};
