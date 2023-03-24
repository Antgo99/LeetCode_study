/*
 * @Author: Antgo99 616677561@qq.com
 * @Date: 2023-03-20 16:50:19
 * @LastEditors: Antgo99 616677561@qq.com
 * @LastEditTime: 2023-03-20 17:24:04
 * @FilePath: \LeetCode\binary_tree\reverse\572.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include<iostream>
#include<vector>
#include<stack>
#include<queue>
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
    bool isSem(TreeNode* left,TreeNode* right){//判断两棵树是否相等
        if(left != NULL && right == NULL) return false;
        else if(left == NULL && right != NULL) return false;
        else if(left == NULL && right == NULL) return true;
        else if(left->val != right->val) return false;

        bool leftside = isSem(left->left,right->left);
        bool rightside = isSem(left->right,right->right);
        bool isside = leftside & rightside;

        return isside;
    }

    bool dfs(TreeNode* left,TreeNode* right){
        if(!left) return false;
        return isSem(left,right) || dfs(left->left,right) || dfs(left->right,right);//深搜left的左孩子和右孩子来比较right
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return dfs(root,subRoot);
    }
};
