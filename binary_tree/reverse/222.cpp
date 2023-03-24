/*
 * @Author: Antgo99 616677561@qq.com
 * @Date: 2023-03-20 19:43:58
 * @LastEditors: Antgo99 616677561@qq.com
 * @LastEditTime: 2023-03-20 19:47:30
 * @FilePath: \LeetCode\binary_tree\reverse\222.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include<iostream>
#include<queue>
#include<vector>
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
    int countNodes(TreeNode* root) {
        if(root == NULL) return 0;
        int nodeCount=0;
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()){
            int size = que.size();
            for(int i=0;i<size;i++){
                TreeNode* node = que.front();
                que.pop();
                nodeCount++;
                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);
            }
        }
        return nodeCount;
    }
};
