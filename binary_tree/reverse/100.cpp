/*
 * @Author: Antgo99 616677561@qq.com
 * @Date: 2023-03-20 16:44:40
 * @LastEditors: Antgo99 616677561@qq.com
 * @LastEditTime: 2023-03-20 16:49:28
 * @FilePath: \LeetCode\binary_tree\reverse\100.cpp
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p != NULL && q == NULL) return false;
        else if(p == NULL && q != NULL) return false;
        else if(p == NULL && q == NULL) return true;
        else if(p->val != q->val) return false;

        bool leftside = isSameTree(p->left,q->left);
        bool rightside = isSameTree(p->right,q->right);
        bool midside = leftside & rightside;
        return midside;
    }
};
