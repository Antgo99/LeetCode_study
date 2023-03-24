/*
 * @Author: Antgo99 616677561@qq.com
 * @Date: 2023-03-22 16:18:16
 * @LastEditors: Antgo99 616677561@qq.com
 * @LastEditTime: 2023-03-22 16:42:34
 * @FilePath: \LeetCode\binary_tree\week_practice\450.cpp
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
        首先，我们判断当前节点是否为空。如果是，直接返回 None。如果当前节点的值等于要删除的值 key，我们需要进行删除操作。
        在删除操作中，我们首先判断当前节点是否存在左右子树，如果只存在一颗子树，则直接用该子树替代当前节点即可。
        如果同时存在左右子树，我们需要找到右子树中的最小节点 min_node，用 min_node 的值替换当前节点的值，然后在右子树中递归删除 min_node。
        如果当前节点的值大于要删除的值 key，说明要删除的节点在当前节点的左子树中，我们递归进入左子树中查找并删除。
        如果当前节点的值小于要删除的值 key，说明要删除的节点在当前节点的右子树中，我们递归进入右子树中查找并删除。
        最后，返回更新后的根节点。
    */
    TreeNode* find_min_node(TreeNode* root){
        while(root->left){
            root = root->left;
        }
        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) return root;
        if(root->val == key){
            if(root->left == NULL) return root->right;
            if(root->right == NULL) return root->left;
            TreeNode* min_node = find_min_node(root->right);
            root->val = min_node->val;
            root->right = deleteNode(root->right,min_node->val);
        }
        if(root->val > key) root->left = deleteNode(root->left,key);
        if(root->val < key) root->right = deleteNode(root->right,key);
        return root;
    }
};
