/*
 * @Author: Antgo99 616677561@qq.com
 * @Date: 2023-03-21 20:37:32
 * @LastEditors: Antgo99 616677561@qq.com
 * @LastEditTime: 2023-03-21 21:11:05
 * @FilePath: \LeetCode\binary_tree\week_practice\106.cpp
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
    TreeNode* traversal(vector<int>& inorder, vector<int>& postorder){
        //1.数组为0，即是空节点
        if(postorder.size() == 0) return NULL;

        //2.取后续数组的最后一个元素，即是根节点
        int rootValue = postorder[postorder.size() - 1];
        TreeNode* root = new TreeNode(rootValue);

        //3.以根节点作为切割点 在中序数组中找到切割点
        int index;
        for(index=0;index<inorder.size();index++){
            if(inorder[index] == rootValue) break;
        }

        //4.切割中序数组，切成左数组和右数组 左闭右开
        //[0,index) [index+1,end)
        vector<int> leftinorder(inorder.begin(),inorder.begin()+index);
        vector<int> rightinorder(inorder.begin()+index+1,inorder.end());

        //后续数组要切割掉根节点
        postorder.resize(postorder.size()-1);

        //5.按照中序数组来切割后序数组，切成左数组和右数组 左闭右开
        //[0,leftorder.size()) [leftorder.size(),end)
        vector<int> leftpostorder(postorder.begin(),postorder.begin()+leftinorder.size());
        vector<int> rightpostorder(postorder.begin()+leftinorder.size(),postorder.end());

        //6.递归处理左区间和右区间
        root->left = traversal(leftinorder,leftpostorder);
        root->right = traversal(rightinorder,rightpostorder);

        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size() == 0 || postorder.size() == 0) return NULL;
        return traversal(inorder,postorder);
    }
};
