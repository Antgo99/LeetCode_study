/*
 * @Author: Antgo99 616677561@qq.com
 * @Date: 2023-03-22 15:46:07
 * @LastEditors: Antgo99 616677561@qq.com
 * @LastEditTime: 2023-03-22 16:02:53
 * @FilePath: \LeetCode\binary_tree\week_practice\235.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
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
        1.从根节点开始遍历树，如果根节点为空或等于其中一个目标节点，则返回根节点。
        2.如果目标节点都在根节点的左侧，那么继续在根节点的左子树中查找它们的最近公共祖先。
        3.如果目标节点都在根节点的右侧，那么继续在根节点的右子树中查找它们的最近公共祖先。
        4.如果目标节点分别在根节点的左右子树中，那么根节点就是它们的最近公共祖先。
    */
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL || root == p || root == q) return root;
        if(root->val > p->val && root->val > q->val) return lowestCommonAncestor(root->left,p,q);
        else if(root->val < p->val && root->val < q->val) return lowestCommonAncestor(root->right,p,q);
        else return root;
    }
};
