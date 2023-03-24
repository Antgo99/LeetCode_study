/*
 * @Author: Antgo99 616677561@qq.com
 * @Date: 2023-03-21 22:10:48
 * @LastEditors: Antgo99 616677561@qq.com
 * @LastEditTime: 2023-03-21 22:29:52
 * @FilePath: \LeetCode\binary_tree\week_practice\617.cpp
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
    //递归
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        //前序遍历
        if(root1 == NULL) return root2;
        if(root2 == NULL) return root1;
        root1->val += root2->val;//中
        root1->left = mergeTrees(root1->left,root2->left);
        root1->right = mergeTrees(root1->right,root2->right);
        return root1;
    }
};
