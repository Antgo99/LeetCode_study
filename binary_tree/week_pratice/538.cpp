/*
 * @Author: Antgo99 616677561@qq.com
 * @Date: 2023-03-22 21:22:57
 * @LastEditors: Antgo99 616677561@qq.com
 * @LastEditTime: 2023-03-22 21:57:31
 * @FilePath: \LeetCode\binary_tree\week_practice\538.cpp
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
    /*
        1.定义一个变量sum，初始化为0。
        2.对于树中的每个节点，将其值加上sum，然后更新sum的值为新节点值。
        3.递归遍历树的右子树，重复上述步骤。
        4.递归遍历树的左子树，重复上述步骤。
        5.返回根节点。
    */
    int sum=0;
    void traversal(TreeNode* root){
        if(root == NULL) return;
        traversal(root->right);
        root->val += sum;
        sum = root->val;//更新为新的节点的值
        traversal(root->left);
    }
    TreeNode* convertBST(TreeNode* root) {
        traversal(root);
        return root;
    }

};
